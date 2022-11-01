#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

ContratoMovil::ContratoMovil(long int dni, Fecha f,
                             float p, int minutos,
                             const char* n):
                             Contrato(dni, f){
    
    nacionalidad = NULL;
    setPrecioMinuto(p);
    setMinutosHablados(minutos);
    setNacionalidad(n);

}

ContratoMovil::ContratoMovil(const ContratoMovil& c):
    Contrato(c.getDniContrato(), c.getFechaContrato()){
        nacionalidad    = nullptr;
        minutosHablados = c.minutosHablados;
        setNacionalidad(c.getNacionalidad());
        precio          = c.getPrecioMinuto();
}

float ContratoMovil::factura() const{
    return precio*minutosHablados;
}

void ContratoMovil::setNacionalidad(const char* n){
    if (nacionalidad != NULL){
        delete nacionalidad;
    }
    nacionalidad    = new char[strlen(n)+1]; 
    strcpy(nacionalidad, n);
}

void ContratoMovil::setPrecioMinuto(float newPrecio){
    precio = newPrecio;
}

void ContratoMovil::setMinutosHablados(int newMinutos){
    minutosHablados = newMinutos;
}

const char* ContratoMovil::getNacionalidad() const {
    char* returnedNacionalidad = new char[strlen(nacionalidad)+1];
    strcpy(returnedNacionalidad, nacionalidad);
    return returnedNacionalidad;
}

void ContratoMovil::ver() const{

    std::cout << dniContrato << "  (" << idContrato 
              << " - " << fechaContrato
              << ") " << minutosHablados << "m, " 
              << nacionalidad << " "
              << precio;
}

std::ostream& operator<<(std::ostream& out, const ContratoMovil& c){

    const char* formatedDate = uselessMonthFunction(c.getFechaContrato());
    
    out << c.getDniContrato() << "  (" << c.getIdContrato() << " - "
        << formatedDate << ") " << c.getMinutosHablados() << "m, "
        << c.getNacionalidad() << " " << c.getPrecioMinuto() << " - "
        << c.factura() << "€";

    delete [] formatedDate;
    return out;
}

ContratoMovil::~ContratoMovil(){
    delete [] nacionalidad;
}   