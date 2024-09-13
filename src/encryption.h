#pragma once
#include <string>

class Encryption {
public:
    Encryption();

    static std::string SimpleReplacement(const std::string &str, int shift);

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
};