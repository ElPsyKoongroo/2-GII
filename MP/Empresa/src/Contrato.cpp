#include <iostream>

#if defined(WIN32) || defined(_WIN32)
    #include "..\headers\Fecha.h"
    #include "..\headers\Contrato.h" // definicion de la clase Contrato
    #include "..\headers\ContratoTP.h" // definicion de la clase ContratoTP
    #include "..\headers\ContratoMovil.h" // definicion de la clase ContratoMovil
#else
    #include "../headers/Fecha.h"
    #include "../headers/Contrato.h" // definicion de la clase Contrato
    #include "../headers/ContratoTP.h" // definicion de la clase ContratoTP
    #include "../headers/ContratoMovil.h" // definicion de la clase ContratoMovil
#endif



int Contrato::idCounter = 1;



Contrato::Contrato(long int dni, Fecha fecha): fechaContrato(fecha) {
    dniContrato = dni;
    idContrato  = idCounter++;
}

Contrato::Contrato(const Contrato& c): 
Contrato(c.getDniContrato(), c.getFechaContrato()){

    //idContrato = idCounter++;
}

void Contrato::setDniContrato(long int newDni){
    dniContrato = newDni;
    return ;    /*No se necesita pero lo he puesto y me da pena quitarlo*/
}

void Contrato::setFechaContrato(Fecha newFecha){
    fechaContrato = newFecha;
}

void Contrato::ver() const{
    std::cout << dniContrato << "  (" << idContrato << " - " << fechaContrato << ") ";
}

int Contrato::getIdContrato() const{
    return idContrato;
}

long int Contrato::getDniContrato() const{
    return dniContrato;
}


float Contrato::factura() const{
    return 0.0;
}

Fecha Contrato::getFechaContrato() const{
    return fechaContrato;
}

Contrato::~Contrato(){

    /*
        SOLO ESPERO QUE NO HAYA MEMORY LEAKS. <3
    */
}


std::ostream& operator<<(std::ostream& out, const Contrato& c){
    out << c.getDniContrato() << "  (" << c.getIdContrato() << " - " << uselessMonthFunction(c.getFechaContrato()) << ")" ;
    return out;
}

