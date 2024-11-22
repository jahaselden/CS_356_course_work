#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "block.h"

using namespace std;

Block::Block(string textInput, string key) : textInput(textInput), key(key) {}

string Block::Encrypt()
{
    // cout << "text bytes before padding: " << textInput.size() << endl;
    PadInputText();
    // cout << "text bytes after padding: " << textInput.size() << endl;
    // cout << "text input before encryption: " << textInput << endl;
    vector<string> substrings = Get16ByteSubstrings();
    for (int i = 0; i < substrings.size(); i++)
    {
        // cout << "substring[" << i << "] before encrypt: " << substrings.at(i) << endl;
        substrings.at(i) = XOR(substrings.at(i));
        // cout << "substring[" << i << "] after xor: " << substrings.at(i) << endl;
        substrings.at(i) = Swap(substrings.at(i));
        // cout << "substring[" << i << "] after swap: " << substrings.at(i) << endl;
    }
    string encryptedCipher;
    for (string substr : substrings)
    {
        encryptedCipher.append(substr);
    }
    return encryptedCipher;
}

void Block::PadInputText()
{
    int inputByteTotal = textInput.size();
    bool pad = CheckPadding(inputByteTotal);
    if (!pad)
    {
        AddPadding();
    }
}

bool Block::CheckPadding(int inputByteTotal)
{
    int remainder = inputByteTotal % 16;
    return remainder == 0;
}

void Block::AddPadding()
{
    while (textInput.size() % 16 != 0)
    {
        textInput.push_back(static_cast<char>(0x81));
    }
}

vector<string> Block::Get16ByteSubstrings()
{
    size_t bytes = 16;
    vector<string> substrings;
    for (size_t i = 0; i < textInput.size(); i += bytes)
    {
        substrings.push_back(textInput.substr(i, bytes));
    }
    return substrings;
}

string Block::XOR(string substr)
{
    string xorOutput = substr;
    for (int i = 0; i < 16; ++i)
    {
        char xorChar = key.at(i) ^ substr.at(i);
        xorOutput.at(i) = xorChar; // could be one line?
    }
    return xorOutput;
}

string Block::Swap(string xorString)
{
    int start = 0;
    int end = xorString.size() - 1;
    string outputSwap = xorString;

    while (start < end)
    {
        if (key.at(start) % 2 == 1)
        {
            char temp = outputSwap.at(start);
            outputSwap.at(start) = outputSwap.at(end);
            outputSwap.at(end) = temp;
            ++start;
            --end;
        }
        else
        {
            ++start;
        }
    }
    return outputSwap;
}

string Block::Decrypt()
{
    vector<string> substrings = Get16ByteSubstrings();
    for (int i = 0; i < substrings.size(); i++)
    {
        // cout << "substring[" << i << "] before swap: " << substrings.at(i) << endl;
        substrings.at(i) = Swap(substrings.at(i));
        // cout << "substring[" << i << "] before swap: " << substrings.at(i) << endl;
        substrings.at(i) = XOR(substrings.at(i));
    }

    // remove padding
    char pad = 0x81;
    string paddedSubstr = substrings.at(substrings.size() - 1);
    int unpad_index = paddedSubstr.find(pad);
    substrings.at(substrings.size() - 1) = paddedSubstr.substr(0, unpad_index);

    cout << substrings.at(substrings.size() - 1) << endl;
    string decryptedCipher;
    for (string substr : substrings)
    {
        decryptedCipher.append(substr);
    }
    return decryptedCipher;
}