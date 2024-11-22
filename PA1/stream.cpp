#include <string>
#include <iostream>
#include "stream.h"

using namespace std;

Stream::Stream(string textInput, string key) : textInput(textInput), key(key) {}

string Stream::Encrypt()
{
    return XOR();
}

string Stream::Decrypt()
{
    return XOR();
}

string Stream::XOR()
{
    string xorCipher = textInput;
    // cout << "text before cipher: " << xorCipher << endl;
    int index = 0;
    while (index < textInput.size())
    { 
        for (int i = 0; i < key.size(); ++i)
        {
            char xorChar = key.at(i) ^ textInput.at(index);
            xorCipher.at(index) = xorChar;
            // cout << "cipher text in progress: " << xorCipher << endl;
            ++index;
        }
    }
    // cout << "final cipher: " << xorCipher << endl;
    return xorCipher;
}