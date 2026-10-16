#include <iostream>
#include <string>
#include "date.hpp"

using namespace std;

std::ostream& operator<<(std::ostream& out, const Data &data){
    out << data.dia << "/" << data.mes << "/" << data.ano;
    return out;
}

bool Data::operator==(const Data &d2){
        return this->dia == d2.dia && this->mes == d2.mes && this->ano == d2.ano;
}