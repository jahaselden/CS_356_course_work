#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "block.h"

using namespace std;

Block::Block(string textInput, string key) : textInput(textInput), key(key) {}

void Block::PadInputText()
{
    int inputByteTotal = textInput.size();
    cout << "text input size before padding: " << textInput.size() << endl;
    int padding = CheckPadding(inputByteTotal);
    // cout << "padding remainder: " << padding << endl;
    if (padding != 0)
    {
        AddPadding();
    }
    cout << "text input size after padding: " << textInput.size() << endl;
}

bool Block::CheckPadding(int inputByteTotal)
{
    int remainder = inputByteTotal % 16;
    return remainder == 0;
}

// this might need to be 0x81
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
        cout << "textInput size: " << textInput.size() << endl;
        cout << textInput.substr(i, bytes) << endl;
        substrings.push_back(textInput.substr(i, bytes));
    }
    return substrings;
}

// converting from char -> ascii -> hex
// cast int to char
void Block::Encrypt()
{
    PadInputText();
    vector<string> substrings = Get16ByteSubstrings();
    for (int i = 0; i < substrings.size(); i++)
    {
        // cout << "substrings: " << substrings.at(i) << endl;
        substrings.at(i) = XOR(substrings.at(i));
        // substrings.at(i) = Swap(substrings.at(i));
    }
}

string Block::XOR(string substr)
{
    string xorOutput = substr;
    for (int i = 0; i < 16; ++i)
    {
        // cout << "xor output at " << i << ": " << xorOutput.at(i) << endl;
        // cout << "key at " << i << ": " << key.at(i) << endl;
        // cout << "substr at " << i << ": " << substr.at(i) << endl;
        xorOutput.at(i) = key.at(i) ^ substr.at(i);
    }
    // cout << "xor output: " << xorOutput << endl;
    return xorOutput;
}

string Block::Swap(string xorString)
{
    int start = 0;
    int end = xorString.size() - 1;
    string outputSwap = xorString;

    while (start < end)
    {
        if (outputSwap.at(start) % 2 == 1)
        {
            char temp = outputSwap.at(start);
            // cout << "temp: " << temp << endl;
            outputSwap.at(start) = outputSwap.at(end);
            // cout << "end to front: " << outputSwap[start] << endl;
            outputSwap.at(end) = temp;
            // cout << "front to end: " << outputSwap[end] << endl;
            // cout << "swap output: " << outputSwap << endl;
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