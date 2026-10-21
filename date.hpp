#ifndef DATE_HPP
#define DATE_HPP
#include <string>

class Date{
    int dia;
    int mes;
    int ano;
public:
    Date(int d=1, int m=1, int a=2026);
    ~Date();
    std::string formatarData();
};

#endif //DATE_HPP