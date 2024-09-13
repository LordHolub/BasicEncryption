#pragma once
#include <string>

class Encryption {
public:
    Encryption();

    static std::string SimpleReplacement(const std::string &str, int shift);

    ~Encryption();
};