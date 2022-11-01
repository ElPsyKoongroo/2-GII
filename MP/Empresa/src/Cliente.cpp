#include <iostream>
#include <cstring>


#if defined(WIN32) || defined(_WIN32)
    #include "..\headers\Cliente.h"
    #include "..\headers\Fecha.h"
#else
    #include "../headers/Fecha.h"
    #include "../headers/Cliente.h"
#endif


Cliente::Cliente(long int d, const char* n, Fecha f): fechaAlta(f){
    dni = d;
    name = new char[strlen(n)+1];
    strcpy(name, n);
}

long int Cliente::getDni() const{
    return dni;
}

void Cliente::setNombre(const char *n){
    delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
}

void Cliente::setFecha(Fecha f){
    fechaAlta = f;
}

const char* Cliente::getNombre() const{
    return name;
}

Fecha Cliente::getFecha() const{
    return fechaAlta;
}

bool Cliente::operator==(Cliente c) const{

    if(this->dni == c.dni) return true;
    return false;
}

std::ostream& operator<<(std::ostream& s, Cliente c){

    s << "DNI: " << c.dni << " Nombre: " << c.name;
    return s;
}

Cliente Cliente::operator=(Cliente c){
    (*this).setFecha(c.getFecha());
    (*this).setNombre(c.getNombre());
    (*this).dni = c.dni;
    return *this;
}

Cliente::~Cliente(){
    delete [] name;
}