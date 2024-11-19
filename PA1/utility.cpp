#include <string>
#include <iostream>
#include <fstream>
#include "utility.h"
#include "block.h"
// #include "stream.h"

using namespace std;

Utility::Utility(char *argv[])
    : cipherType(*argv[1]), inputFilePath(argv[2]), outputFilePath(argv[3]), keyFilePath(argv[4]), operation(*argv[5]), byteIndex(0) {}

Utility::Utility(char cipher, string ipf, string ofp, string ktf, char op)
    : cipherType(cipher), inputFilePath(ipf), outputFilePath(ofp), keyFilePath(ktf), operation(op), byteIndex(0) {}

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

// Block Utility::CreateBlockObject(){
//     return new Block(utility.GetTextInput(), utility.GetKey());
// }

// Stream Utility::CreateStreamObject(){
//     //return new Stream( )
// }

// char Utility::GetCipherType(){
//     return this.cipherType;
// }

// char Utility::GetOpType(){
//     return this.operation;
// }

// string Utility::GetTextInput(){
//     return this.plaintextInput;
// }

// string Utility::GetKey(){
//     return this.plaintextKey;
// }
// if cipher is B
    // if operation is encrypt
        // encrypt
    // else operation is decrypt
        // decrypt

// if cipher is S
    // if operation is encrypt
        // encrypt
    // else operation is decrypt
        // decrypt
