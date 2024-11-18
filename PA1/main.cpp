#include <bitset>
#include <iostream>

#include "utility.h"

using namespace std;

// 5 args from command line
// 1. cipher type: B or S / block or stream
// 2. input file path: plaintext input file in ASCII format
// 3. output file path: specified by user - created and written to by program
// 4. keyFilePath file path: conrains symmetric keyFilePath in ASCII format
// 5. mode of operation: E or S / encryption or decryption

// examples of how program will be executed: (more in test file)
//  ./cipher B b-e-input.txt b-e-output.txt b-e-keyFilePath.txt E
//  ./cipher S s-d-input.txt s-d-output.txt s-d-keyFilePath.txt D

// block cipher pseudocode

// retrieve input - utility.cpp
// read whole input string from the input file
// store in string (an array of chars) - use size() to return number of bytes in string

// retrieve keyFilePath from file and store in string? same way as above

// 1. encrypt - block
// take 16 byte substrings as blocks until end of string is reached

// pad - separate method?
//  if substring < 16
// pad difference of bytes to reach 16

// encrypt using XOR - separate method?
// for each byte of input substring (starting from left side - 0)
// XOR input index with correlated keyFilePath index

int main(int argc, char *argv[])
{
    // printing input for test
    // cout << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << " " << argv[5] << endl;

    Utility::VerifyInputArgs(argc);

    Utility utility = Utility(argv);

    utility.RetrieveInputArgs();

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
}