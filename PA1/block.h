#ifndef UTILITY_H_DEFINED
#define UTILITY_H_DEFINED

#include <string>

using namespace std;

class Block
{
public:
    string textInput;
    string key;
    string paddedInput;
    string hexInput;

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
