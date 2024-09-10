#include <string>

using namespace std;

class Utility {
    char cipherType;
    string inputFile;
    string outputFile;
    string key;
    char operation;

    public:
        Utility(char ciphertype, string inputFile, string outputFile, string key, char operation) : 
            cipherType(cipherType), inputFile(inputFile), outputFile(outputFile), key(key), operation(operation){}
        
};