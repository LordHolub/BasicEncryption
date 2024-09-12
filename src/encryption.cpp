#include "headers.h"

string Encryption::SimpleReplacement(const string &str, int shift){
    string encryption_str = "";

    for(char ch : str){

        if(isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            encryption_str += static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
        else
            encryption_str += ch;
    }
    
    return encryption_str;
}


Encryption::Encryption() {};
Encryption::~Encryption() {};