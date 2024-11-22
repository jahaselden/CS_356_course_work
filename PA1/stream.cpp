#include <string>
#include "stream.h"

using namespace std;

Stream::Stream(string textInput, string key) : textInput(textInput), key(key) {}

string Stream::Encrypt(){
    XOR();
}

string Stream::XOR(){
    
}