#include <iostream>
#include "Contrato.h"
#include "ContratoMovil.h"
#include "ContratoTP.h"
#include "Cliente.h"

#ifndef EMPRESITA_H
#define EMPRESITA_H

class Empresa{

    int nClientes;
    int nContratos;
    Cliente*    clientes[100];
    Contrato*  contratos[100];

    protected:

        int buscarCliente(long int dni);

        void altaCliente(Cliente* nuevoCliente);

        void ordenaContratos();
    
    public:

        //Empresa();

        void cargarDatos();

        void ver();

        void crearContrato();

        void descuento(int porcentaje);
        
        bool cancelarContrato(int nContrato);

        bool bajaCliente(long int dni);

        int nContratosTP();

        ~Empresa();

};



#endif