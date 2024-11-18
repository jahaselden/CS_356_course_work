#ifndef UTILITY_H_DEFINED
#define UTILITY_H_DEFINED

class Block
{
public:
    std::string textInput;
    std::string key;
    std::string paddedInput;
    std::string hexInput;

    Block() = delete;
    Block(string input, string key);
    // these should be in block class
    void PadInputText();
    int CheckPadding(int inputByteTotal);
    void addPadding(int padding);
    void XOR();
    void Swap();
};

#endif
