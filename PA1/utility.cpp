#include <string>
#include <iostream>
#include <fstream>
#include "utility.h"

using namespace std;

Utility::Utility(char *argv[])
    : cipherType(*argv[1]), inputFilePath(argv[2]), outputFilePath(argv[3]), keyFilePath(argv[4]), operation(*argv[5]), byteIndex(0) {}

void Utility::VerifyInputArgs(int argc) // static
{
    if (argc != 6)
    {
        cout << "Ivalid Number of Arguments" << endl;
        exit(1);
    }
}

void Utility::VerifyCipherType()
{
    if (cipherType != 'B' && cipherType != 'S')
    {
        cout << cipherType << endl;
        cout << "Invalid Function Type" << endl;
        exit(1);
    }
}

void Utility::RetrieveInputFileText()
{
    ifstream inputFile(inputFilePath);

    if (!inputFile)
    {
        cout << "Input File Does Not Exist" << endl;
        exit(1);
    }

    string line;

    while (getline(inputFile, line))
    {
        plaintextInput += line;
        plaintextInput += "\n";
    }

    plaintextInput.pop_back(); // accommodate discrepancy in last newline
    inputFile.close();
}

void Utility::CreateOutputFile()
{
    fstream file;
    file.open(outputFilePath, ios::out);

    if (!file)
    {
        cout << "Error in Creating File" << endl;
    }

    file.close();
}

void Utility::RetrieveKey()
{
    // if key file does not exist
    ifstream keyFile(keyFilePath);
    if (!keyFile.is_open())
    {
        cout << "Key File Does Not Exist" << endl;
        exit(1);
    }

    string line;

    while (getline(keyFile, line))
    {
        plaintextKey += line;
    }
    keyFile.close();
}

void Utility::VerifyOpMode()
{
    if (operation != 'E' && operation != 'D')
    {
        cout << "Invalid Mode Type\n";
        exit(1);
    }
}

void Utility::RetrieveInputArgs()
{
    VerifyCipherType();
    RetrieveInputFileText();
    CreateOutputFile();
    RetrieveKey();
    VerifyOpMode();
}

// these should be in Block class
void Utility::PadInputText()
{
    int inputByteTotal = plaintextInput.size();

    int padding = checkPadding(inputByteTotal);
    if (padding != 0)
    {
        addPadding(padding);
    }
}

int Utility::checkPadding(int inputByteTotal)
{
    int remainder = inputByteTotal % 16;
    return remainder;
}

void Utility::addPadding(int padding)
{
    for (int i = 0; i < padding; i++)
    {
        plaintextInput += '0';
    }
}
