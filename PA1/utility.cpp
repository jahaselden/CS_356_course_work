#include <string>
#include <iostream>
#include <fstream>
#include "utility.h"
#include "block.h"

using namespace std;

Utility::Utility(char *argv[])
    : cipherType(*argv[1]), inputFilePath(argv[2]), outputFilePath(argv[3]), keyFilePath(argv[4]), operation(*argv[5]), byteIndex(0) {}

Utility::Utility(char cipher, string ipf, string ofp, string ktf, char op)
    : cipherType(cipher), inputFilePath(ipf), outputFilePath(ofp), keyFilePath(ktf), operation(op), byteIndex(0) {}

void Utility::VerifyNumInputArgs(int argc) // static
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

void Utility::WriteToOutputFile(string txt)
{
    ofstream outfile(outputFilePath);

    // cout << "txt: " << txt << endl;
    outfile << txt;
    outfile.close();
}

void Utility::RetrieveAndValidateInputArgs()
{
    VerifyCipherType();
    RetrieveInputFileText();
    RetrieveKey();
    VerifyOpMode();
}

void Utility::Run()
{
    if (cipherType == 'B')
    {
        RunBlockCipher();
    }
    if (cipherType == 'S')
    {
        RunStreamCipher();
    }
}

void Utility::RunBlockCipher()
{
    string cipherText;
    Block block = Block(GetTextInput(), GetKey());
    if (operation == 'E')
    {
        cipherText = block.Encrypt();
        WriteToOutputFile(cipherText);
    }
    else
    {
        cipherText = block.Decrypt();
        WriteToOutputFile(cipherText);
        // cout << "decrypted text: " << cipherText << endl;
    }
}

void Utility::RunStreamCipher()
{
    // string cipherText;
    // Stream stream = Stream(GetTextInput(), GetKey());
    // if (operation == 'E')
    // {
    //     cipherText = stream.Encrypt();
    //     WriteToOutputFile(cipherText);
    // }
    // else
    // {
    //     cipherText = stream.Decrypt();

    // }
}

string Utility::GetTextInput()
{
    return this->plaintextInput;
}

string Utility::GetKey()
{
    return this->plaintextKey;
}