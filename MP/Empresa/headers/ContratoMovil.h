#include <iostream>
#include "Contrato.h"
#ifndef CONTRATOSITO_MOVIL
#define CONTRATOSITO_MOVIL


class ContratoMovil: public Contrato{

    float       precio;
    int         minutosHablados;
    char*       nacionalidad;

    public:

    friend std::ostream& operator<<(std::ostream& out, const ContratoMovil& c);
    
    ContratoMovil(long int dni, Fecha f, 
                  float precio, int minutos,
                  const char* nacionalidad);

    ContratoMovil(const ContratoMovil& c);

    ~ContratoMovil();
    
    void ver() const;

    /* GETTERS */

    float factura() const;

    const char* getNacionalidad() const;

    int getMinutosHablados() const { return minutosHablados;};

    float getPrecioMinuto() const { return precio;};

    /* SETTERS */

    void setNacionalidad(const char* n);

    void setPrecioMinuto(float newPrecio);

    void setMinutosHablados(int newMinutos);


};


#endif