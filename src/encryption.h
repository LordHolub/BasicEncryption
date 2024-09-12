#pragma once
#include <string>

class Encryption {
public:
    Encryption();

    static std::string RSimpleReplacement(std::string &str, int step);
    static std::string LSimpleReplacement(std::string &str, int step);

    ~Encryption();
};