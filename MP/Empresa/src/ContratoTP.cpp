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


int     ContratoTP::limiteMinutos = 300;
float   ContratoTP::precio        = 10;

ContratoTP::ContratoTP(long int dni, Fecha f, 
                       int minutos): Contrato(dni, f){

    minutosHablados = minutos;
}

ContratoTP::ContratoTP(const ContratoTP& c): 
  Contrato(c.getDniContrato(), c.getFechaContrato()){
    minutosHablados = c.getMinutosHablados();
    precio          = c.getPrecio();

}

/*  */

void ContratoTP::setMinutosHablados(int newMinutosHablados){
    minutosHablados = newMinutosHablados;
}

float ContratoTP::getPrecio(){ return precio; }

int ContratoTP::getLimiteMinutos(){ return limiteMinutos; }

void ContratoTP::setTarifaPlana(int newMinutos, float newPrecio){
    limiteMinutos = newMinutos;
    precio        = newPrecio;
}

float ContratoTP::factura() const { 
    return  precio + ((minutosHablados > limiteMinutos) ? 
                     (minutosHablados - limiteMinutos)*precioExcesoMinuto :
                     0) ;

}

void ContratoTP::ver() const{

    std::cout   << dniContrato   << "  ("   << idContrato 
                << " - " << fechaContrato << ") " 
                << minutosHablados << "m, "
                << limiteMinutos << "(" << precio <<")";

}

std::ostream& operator<<(std::ostream& out, const ContratoTP& c){


    /*  TODO REMOVE THIS COMMENT
        char meses[][4] = {"ene", "feb", "mar", "abr", "may", "jun",
                           "jul", "ago", "sep", "oct", "nov", "dic"};


        Fecha aux = c.getFechaContrato();
        char date[16] = {};
    */

    const char* formatedDate = uselessMonthFunction(c.getFechaContrato());

    out << c.getDniContrato() << "  (" << c.getIdContrato() << " - "
        << formatedDate << ") " << c.getMinutosHablados() << "m, "
        << c.getLimiteMinutos() << "(" << c.getPrecio() << ") "
        << " - " << c.factura() << "€";

    delete [] formatedDate;
    return out;

}