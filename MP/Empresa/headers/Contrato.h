#include <iostream>
#include "Fecha.h"

#ifndef CONTRATOSITO_
#define CONTRATOSITO_


class Contrato{
    
    private:
        static int  idCounter;

    protected:
        long int    dniContrato;
        int         idContrato;
        Fecha       fechaContrato;

        virtual void setPrecioMinuto(float newPrecio) {};

        virtual void setMinutosHablados(int newMinutos) {};
        
        virtual void setNacionalidad(const char* newNacionalidad) {};

        virtual int getMinutosHablados(){return 0;};

        virtual const char* getNacionalidad(){return " ";};

        virtual float getPrecioMinuto(){return 0.0;};

    public:

        friend std::ostream& operator<<(std::ostream& out, const Contrato& c);
        
        Contrato(long int dni, Fecha fecha);

        Contrato(const Contrato& c);

        /* SETTERS */

        void setDniContrato(long int newDni);

        void setFechaContrato(Fecha newFecha);


        /* GETTERS */


        int getIdContrato() const;

        Fecha getFechaContrato() const;
        
        long int getDniContrato() const;

        virtual void ver() const;

        virtual float factura() const;

        virtual ~Contrato();


};


#endif