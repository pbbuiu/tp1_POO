#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

using namespace std;

class Data{
    int dia;
    int mes;
    int ano;
public:
    Data(int d, int m, int a): dia(d), mes(m), ano(a){}
    friend std::ostream& operator<<(std::ostream& out, const Data &data);
    bool operator==(const Data &d2);
};
#endif //DATE_H