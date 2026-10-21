#include "date.hpp"
#include <string>

using namespace std;

Date::Date(int d, int m, int a): dia(d), mes(m), ano(a){}

Date::~Date() {}

std::string Date::formatarData(){
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
}