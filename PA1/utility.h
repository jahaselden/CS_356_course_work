#ifndef UTILITY_H_DEFINED
#define UTILITY_H_DEFINED

using namespace std;

class Utility
{
public:
    char cipherType, operation;
    string inputFilePath, outputFilePath, keyFilePath;
    int byteIndex;

    string plaintextInput;
    string plaintextKey;

    Utility() = delete;
    Utility(char *argv[]);
    static void VerifyInputArgs(int argc);
    void VerifyCipherType();
    void RetrieveInputFileText();
    void CreateOutputFile();
    void RetrieveKey();
    void VerifyOpMode();
    void RetrieveInputArgs();

    //these should be in block class
    void PadInputText();
    int checkPadding(int inputByteTotal);
    void addPadding(int padding);
};

#endif