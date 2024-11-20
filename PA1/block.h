#ifndef BLOCK_H_DEFINED
#define BLOCK_H_DEFINED

#include <vector>

class Block
{
public:
    std::string textInput;
    std::string key;
    std::string paddedInput;
    std::string hexInput;

    Block() = delete;
    Block(std::string input, std::string key);
    // these should be in block class
    void PadInputText();
    bool CheckPadding(int inputByteTotal);
    // std::string AddPadding();
    void AddPadding();
    std::vector<std::string> Get16ByteSubstrings();
    void Encrypt();
    std::string XOR(std::string substr);
    std::string Swap(std::string xorString);
};

#endif
