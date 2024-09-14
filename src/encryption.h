#pragma once
#include <string>

class Encryption {
public:
    Encryption();

    static std::string SimpleReplacement(const std::string &str, int shift);
    static std::string PolibyusSquare(const std::string &str);
    static std::string DePolibyusSquare(const std::string& str);

    ~Encryption();
private:
    std::unordered_map<char, std::string> letters = {
        {'a', "11"}, {'b', "12"}, {'c', "13"}, {'d', "14"}, {'e', "15"},
        {'f', "21"}, {'g', "22"}, {'h', "23"}, {'j', "24"}, {'i', "24"},
        {'k', "25"}, {'l', "31"}, {'m', "32"}, {'n', "33"}, {'o', "34"},
        {'p', "35"}, {'q', "41"}, {'r', "42"}, {'s', "43"}, {'t', "44"},
        {'u', "45"}, {'v', "51"}, {'w', "52"}, {'x', "53"}, {'y', "54"},
        {'z', "55"},
    };
    std::unordered_map<std::string, char> numbers = {
        {"11", 'a'}, {"12", 'b'}, {"13", 'c'}, {"14", 'd'}, {"15", 'e'},
        {"21", 'f'}, {"22", 'g'}, {"23", 'h'}, {"24", 'i'}, {"25", 'k'},
        {"31", 'l'}, {"32", 'm'}, {"33", 'n'}, {"34", 'o'}, {"35", 'p'}, 
        {"41", 'q'}, {"42", 'r'}, {"43", 's'}, {"44", 't'}, {"45", 'u'},
        {"51", 'v'}, {"52", 'w'}, {"53", 'x'}, {"54", 'y'}, {"55", 'z'},
    };
};