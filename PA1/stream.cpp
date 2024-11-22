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
    int max = textInput.size();
    int index = 0;
    while (index < max)
    {
        for (int i = 0; i < key.size(); ++i)
        {
            char xorChar = key.at(i) ^ textInput.at(index);
            xorCipher.at(index) = xorChar;
            ++index;
        }
    }
    return xorCipher;
}