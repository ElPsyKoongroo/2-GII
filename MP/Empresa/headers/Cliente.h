
#ifndef CLIENTESITO_H
#define CLIENTESITO_H

#include "Fecha.h"
#include <iostream>

class Cliente{
    long int    dni;
    char*       name;
    Fecha       fechaAlta;

    public:
        Cliente(long int d, const char *n, Fecha f);

        void setNombre(const char *n);

        void setFecha(Fecha f);

        bool operator==(Cliente c) const;
        
        long int getDni() const;

        const char* getNombre() const;

        friend std::ostream& operator<<(std::ostream& s, Cliente c);

        Fecha getFecha() const;

        Cliente operator=(Cliente c);

        ~Cliente();
};

#endif