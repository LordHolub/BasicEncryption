#include "headers.h"

string Encryption::RSimpleReplacement(string &str, int step){
    string encryption_name;

    for(size_t i = 0; i < str.size(); i++){
        char ch = tolower(str[i]);
        int dif = static_cast<int>('z' - ch);

        if(step > dif){
            if(i == 0)
                encryption_name += toupper('a' + (step - dif - 1));
            else
                encryption_name += 'a' + (step - dif - 1);
        }
        else{
            if(i == 0)
                encryption_name += toupper(ch + step);
            else
                encryption_name += ch + step;
        }
    }
    return encryption_name;
}

string Encryption::LSimpleReplacement(string &str, int step){
    string decryption_str;

    for(size_t i = 0; i < str.size(); i++){
        char ch = tolower(str[i]);
        int dif = static_cast<int>(ch - 'a');

        if(step > dif){
            if(i == 0)
                decryption_str += toupper('z' - (step - dif - 1));
            else
                decryption_str += 'z' - (step - dif - 1);
        }
        else{
            if(i == 0)
                decryption_str += toupper(ch - step);
            else
                decryption_str += ch - step;
        }
    }
    return decryption_str;
}

Encryption::Encryption() {};
Encryption::~Encryption() {};