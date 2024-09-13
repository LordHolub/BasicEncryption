#pragma once
#include <string>

class Interface {
public:
    Interface();

    void CreateInterface(std::string &str);

    ~Interface();
private:
    int ToNumber(std::string &str_number);
};