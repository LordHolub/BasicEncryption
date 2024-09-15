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

string Encryption::PolibyusSquare(const string &str){
    string encryption_str = "";
    string temp = "";
    if(str.size() != 1 && str.size()){
        short out_of_range = 0;

        for(char ch : str){
            temp += letters[ch];
        }
        for(size_t i = 0; ; i += 4){
            short j = i + 2;
            bool swi = false;

            if(i > (temp.size() - 1)){
                i = 1;
                j = i + 2;
                out_of_range++;
            }
            if(j > (temp.size() - 1)){
                j = 1;
                swi = true;
            }
            if(out_of_range == 2)
                break;
            
            encryption_str += temp[i];
            encryption_str += temp[j];

            if(swi){
                i = -1;
                swi = false;
                out_of_range++;
            }
        }
    }
    else 
        return str;
    
    temp = encryption_str;
    encryption_str = "";
    for(size_t i = 0; i < temp.size(); i += 2)
        encryption_str += numbers[temp.substr(i, 2)];

    return encryption_str;
}

string Encryption::DePolibyusSquare(const string &str){
    string decryption_str = "";
    string temp;

    if(str.size() != 1 && str.size()){
        for(char ch : str)
            temp += letters[ch];
        
        for(short i = temp.size() - 1; i >= temp.size() / 2; i--){
            short j = i - temp.size() / 2;

            decryption_str += temp[i];
            decryption_str += temp[j];
        }
    }
    else
        return str;
    
    reverse(decryption_str.begin(), decryption_str.end());
    temp = decryption_str;
    decryption_str = "";
    for(size_t i = 0; i < temp.size(); i += 2)
        decryption_str += numbers[temp.substr(i, 2)];

    return decryption_str;
}

string Encryption::CipherTrithemius(const string &str, short shift, bool decryption)
{
    string encryption_str = "";
    for (char ch : str)
    {
        if (shift > 26)
            shift = 0;
        if (decryption)
            if(ch - shift < 'a')
                encryption_str += 'z' - ('a' - ch);
            else
                encryption_str += ch - shift;
        else
            if(ch + shift > 'z')
                encryption_str += 'a' + (ch - 'z');
            else
                encryption_str += ch + shift;
        shift++;
    }
    return encryption_str;
}

string Encryption::CipherPermutation(const string &str)
{
    string encryption_str = "";
    if (str.size() > 1)
    {
        for (size_t i = 0; i < str.size(); i += 2)
        {
            try
            {
                encryption_str += str.at(i + 1);
            }
            catch (exception)
            {
            }
            encryption_str += str[i];
        }
    }
    return encryption_str;
}

Encryption::Encryption() {};
Encryption::~Encryption() {};