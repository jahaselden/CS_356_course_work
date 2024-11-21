#ifndef UTILITY_H_DEFINED
#define UTILITY_H_DEFINED

class Utility
{
public:
    char cipherType, operation;
    std::string inputFilePath, outputFilePath, keyFilePath;
    int byteIndex;

    std::string plaintextInput;
    std::string plaintextKey;

    Utility() = delete;
    Utility(char *argv[]);
    Utility(char, std::string, std::string, std::string, char);
    static void VerifyNumInputArgs(int argc);
    void VerifyCipherType();
    void RetrieveInputFileText();
    void RetrieveKey();
    void VerifyOpMode();
    void RetrieveAndValidateInputArgs();
    void Run();
    void RunBlockCipher();
    void RunStreamCipher();
    void WriteToOutputFile(std::string);
    std::string GetTextInput();
    std::string GetKey();
    // method for writing to output file
};

#endif