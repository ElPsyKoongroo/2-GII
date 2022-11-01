#include <iostream>
#include "Contrato.h"
#ifndef CONTRATOSITO_TP
#define CONTRATOSITO_TP

#define precioExcesoMinuto 0.15

class ContratoTP: public Contrato{

    static  int     limiteMinutos;
    static  float   precio;
    int             minutosHablados;


    public:
        friend std::ostream& operator<<(std::ostream& out, const ContratoTP& c);

        ContratoTP(long int dni, Fecha f, int minutos);

        ContratoTP(const ContratoTP& c);

        int getMinutosHablados() const{return minutosHablados;};

        static int getLimiteMinutos();

        static float getPrecio();

        static void setTarifaPlana(int newMinutos, float newPrecio);
        
        void   setMinutosHablados(int newMinutosHablados);

        void ver() const;

        float factura() const;

};


#endif