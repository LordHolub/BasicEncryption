#pragma once
#include <string>

class Interface {
public:
    Interface();

    void CreateInterface();

    ~Interface();
private:
    int ToNumber(std::string &str_number);
};