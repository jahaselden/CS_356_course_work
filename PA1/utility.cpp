#include <string>
#include <iostream>
#include <fstream>
#include "utility.h"

using namespace std;

Utility::Utility(char *argv[]) : cipherType(*argv[1]), inputFilePath(argv[2]), outputFilePath(argv[3]), key(argv[4]), operation(*argv[5]) {}

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
    if (cipherType != 'B' || cipherType != 'S')
    {
        cout << "Invalid Function Type" << endl;
        exit(1);
    }
}

void Utility::RetrieveInputFile()
{
    // if input file does not exist
    ifstream inputFile(inputFilePath);

    if (!inputFile.is_open())
    {
        cout << "Input File Does Not Exist" << endl;
        exit(1);
    }

    while (getline(inputFile, plaintextInput))
    {
        cout << plaintextInput << endl;
    }

    // else
    // do something - check instructions
}

void Utility::RetrieveOutputFile()
{
    // create output file to write to
}

void Utility::RetrieveKey()
{
    // if key file does not exist
    //  cout << "Key File Does Not Exist"
    //  exit(1);
    // else
    // save key as string? idk - come back
}

void Utility::VerifyOpMode()
{
    if (operation != 'E' || operation != 'D')
    {
        cout << "Invalid Mode Type\n";
        exit(1);
    }
}

// retrieve input - utility.cpp
// read whole input string from the input file
// store in string (an array of chars) - use size() to return number of bytes in string
void Utility::RetrieveInput()
{
    cout << cipherType << "\n";
    VerifyCipherType();

    cout << operation << "\n";
    VerifyOpMode();
}
