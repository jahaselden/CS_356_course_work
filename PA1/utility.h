#ifndef UTILITY_H_DEFINED
#define UTILITY_H_DEFINED

using namespace std;

class Utility
{
public:
    char cipherType;
    string inputFilePath;
    string outputFilePath;
    string key;
    char operation;

    string plaintextInput;

    Utility() = delete;
    Utility(char *argv[]);
    // Utility(char ciphertype, string inputFile, string outputFilePath, string key, char operation);
    static void VerifyInputArgs(int argc);
    void VerifyCipherType();
    void RetrieveInputFile();
    void RetrieveOutputFile();
    void RetrieveKey();
    void VerifyOpMode();
    void RetrieveInput();
};

#endif