#include <bitset>
#include <iostream>

#include "utility.h"
#include "block.h"

using namespace std;

int main(int argc, char *argv[])
{
    Utility::VerifyNumInputArgs(argc);

    char cipher = *argv[1];
    std::string inputFilePath = argv[2];
    std::string outputFilePath = argv[3];
    std::string keyFilePath = argv[4];
    char operation = *argv[5];
    Utility utility = Utility(cipher, inputFilePath, outputFilePath, keyFilePath, operation);

    utility.RetrieveAndValidateInputArgs();
    utility.Run();
}