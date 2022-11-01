#include <iostream>
#include <iomanip>
#include <string>

#if defined(WIN32) || defined(_WIN32)
    #include "..\headers\Fecha.h"
#else
    #include "../headers/Fecha.h"
#endif


Fecha::Fecha(int d, int m, int a){
    setFecha(d, m, a);
}

int Fecha::getDia() const{
    return day;
}

int Fecha::getMes() const{
    return month;
}

int Fecha::getAnio() const{
    return year;
}

bool Fecha::bisiesto() const{
    if(!(year%4) && (year%100 || !(year%400))) return true;
    else return false;
}

void Fecha::setFecha(int d, int m, int a){
    year    = a;

    int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((*this).bisiesto()){
        dias[1] = 29;
    }

    // TODO 
    // SI 'M' ES MAS GRANDE QUE 12 O MENOR QUE 0 LIADITA COS INDEX OUT OF RANGE
    int diamax = dias[m-1];

    if(d>diamax){ 
        day = diamax;
    }
    else day = d;

    if(m > 12) month = 12;
    else if (m <= 0) month = 1;
    else month = m;

}

void Fecha::ver() const {
    std::cout   << std::setw(2) << std::setfill('0') << day 
                << "/" << std::setw(2) << std::setfill('0') 
                << month << "/" << year;
}

Fecha Fecha::operator+(int i) const{    

    int _year    = this->year;
    int _day     = this->day;
    int _month   = this->month;
    int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if((*this).bisiesto()){
        dias[2] = 29;
    }


    int diamax = dias[this->month-1];
    _day++;
    if(_day>diamax){ 
        _day     = 1;
        _month++;
    }

    if(_month > 12){ 
        _month = 12;
        _year++;
    }
    else if (_month <= 0) _month = 1;

    return Fecha(_day, _month, _year);
}

Fecha operator+(int i, Fecha f){
    f.setFecha(f.getDia()+i, f.getMes(), f.getAnio());
    return f;
}

Fecha Fecha::operator++(){
    int dias[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((*this).bisiesto()){
        dias[2] = 29;
    }
    int diamax = dias[month];

    day++;
    if (day>diamax){
        day = 1;
        month++;
        if(month>12){
            month = 1;
            year++;
        }
    }
    return *this;
}

Fecha Fecha::operator++(int _i){
    ++(*this);
    return *this;
}

Fecha Fecha::operator=(Fecha f){
    (*this).setFecha(f.getDia(), f.getMes(), f.getAnio());
    return *this;
}

std::ostream& operator<<(std::ostream& s, Fecha f){
    
    char date[11] = {};     // 01/10/2002
    sprintf(date, "%.2d/%.2d/%d", f.getDia(), f.getMes(), f.getAnio());

    return (s<<date) ;
}

// DONT FORGET TO FREE THE MEMORY AFTER USING THIS FUNCTION !!
// NO OLVIDAR LIBERAR LA MEMORIA TRAS UTILIZAR ESTA FUNCION !! 
const char* uselessMonthFunction(Fecha aux) {
    char meses[][4] = {"ene", "feb", "mar", "abr", "may", "jun",
                       "jul", "ago", "sep", "oct", "nov", "dic"};
    char* date = new char[16];
    sprintf(date, "%.2d %s %d", aux.getDia(), meses[aux.getMes()-1], aux.getAnio());
    return date;
}