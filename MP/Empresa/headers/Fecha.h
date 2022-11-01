#ifndef FECHASITA_H
#define FECHASITA_H

#include <iostream>

class Fecha{
    int day, month, year;


    public:
        Fecha(int d, int m, int a);

        int getDia() const;

        int getMes() const;

        int getAnio() const;

        bool bisiesto() const;

        void setFecha(int d, int m, int a);
        
        void ver() const;

        Fecha operator++();

        Fecha operator++(int i);

        Fecha operator=(Fecha f);

        Fecha operator+(int i) const;

        friend std::ostream& operator<<(std::ostream& s, Fecha f);

};

Fecha operator+(int i, Fecha f);

const char* uselessMonthFunction(Fecha aux);
#endif