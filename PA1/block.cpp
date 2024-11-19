#include <string>
#include <iostream>
#include <fstream>
#include "block.h"

using namespace std;

Block::Block(string textInput, string key) : textInput(textInput), key(key) {}

// these should be in Block class
void Block::PadInputText()
{
    int inputByteTotal = textInput.size();
    cout << "text input before padding: " << textInput << endl;
    int padding = CheckPadding(inputByteTotal);
    cout << "padding remainder: " << endl;
    if (padding != 0)
    {
        addPadding(padding);
    }
    cout << "text input after padding: " << textInput << endl;
}

int Block::CheckPadding(int inputByteTotal)
{
    int remainder = inputByteTotal % 16;
    return remainder;
}

// this might need to be 81
void Block::addPadding(int padding)
{
    for (int i = 0; i < padding; i++)
    {
        textInput += '0';
    }
}

// converting from char -> ascii -> hex
//  cast int to char

void Block::XOR()
{
}

void Block::Swap()
{
}