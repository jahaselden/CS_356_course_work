#ifndef STREAM_H_DEFINED
#define STREAM_H_DEFINED

#include <vector>

class Stream
{
public:
    std::string textInput;
    std::string key;
    std::string paddedInput;
    std::string hexInput;

    Stream() = delete;
    Stream(std::string input, std::string key);
    std::string Encrypt();
    std::string Decrypt();
    std::string XOR();
};

#endif
