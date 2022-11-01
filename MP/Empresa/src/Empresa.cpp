#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if defined(WIN32) || defined(_WIN32)
    #include "..\headers\Cliente.h"         // definicion de la clase oceano
    #include "..\headers\Fecha.h"   
    #include "..\headers\Contrato.h"        // definicion de la clase Contrato
    #include "..\headers\ContratoTP.h"      // definicion de la clase ContratoTP
    #include "..\headers\ContratoMovil.h"   // definicion de la clase ContratoMovil
    #include "..\headers\Empresa.h"         // definicion de la clase mosquito*
#else
    #include "../headers/Cliente.h"         // definicion de la clase oceano
    #include "../headers/Fecha.h"
    #include "../headers/Contrato.h"        // definicion de la clase Contrato
    #include "../headers/ContratoTP.h"      // definicion de la clase ContratoTP
    #include "../headers/ContratoMovil.h"   // definicion de la clase ContratoMovil
    #include "../headers/Empresa.h"         // definicion de la clase mosquito*
#endif


/*
    * Obviamente es definicion de la clase empresa lo que pasa que
      soy muy gracioso JAJAJ
*/


void Empresa::cargarDatos() { 
    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002); 
    this->clientes[0] = new Cliente(75547001, "Peter Lee", f1); 
    this->clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000)); 
    this->clientes[2] = new Cliente(37000017, "Luis Bono", f2); 
    this->nClientes=3; 

    this->contratos[0] = new ContratoMovil(75547001, f1, 0.12, 110, "DANES");       //habla 110m a 0.12€/m 
    this->contratos[1] = new ContratoMovil(75547001, f2, 0.09, 170, "DANES");       //habla 170m a 0.09€/m 
    this->contratos[2] = new ContratoTP(37000017, f3, 250);                         //habla 250m (300m a 10€, exceso 0.15€/m) 
    this->contratos[3] = new ContratoTP(75547001, f1, 312);                         //habla 312m (300m a 10€, exceso 0.15€/m) 
    this->contratos[4] = new ContratoMovil(45999000, f2, 0.10, 202, "ESPAÑOL");     //habla 202m a 0.10/m 
    this->contratos[5] = new ContratoMovil(75547001, f2, 0.15, 80, "DANES");        //habla 80m a 0.15€/m 
    this->contratos[6] = new ContratoTP(45999000, f3, 400);                         //habla 400m (300m a 10€, exceso 0.15€/m) 
    this->nContratos=7; 
} 

void Empresa::ver(){

    std::cout << "Clientes: \n";

    std::cout   << "La Empresa tiene " << nClientes 
                << " clientes y "<< nContratos << " contratos"<<std::endl;
    
    std::cout << "Clientes:" << std::endl;
    for (int i = 0; i < nClientes; i++) 
        std::cout << *clientes[i] << std::endl;

    std::cout << "\nContratos:\n";

    for (int i = 0; i < nContratos; i++) { 
        ContratoTP* contrat = dynamic_cast<ContratoTP*>(contratos[i]);
        if(contrat) std::cout << *contrat << std::endl;
        else std::cout << *(ContratoMovil*)contratos[i] << std::endl; 
    }
    return ;
}

void Empresa::crearContrato(){

    int tipoContrato     = 0;
    long int dniContrato = 0;
    int dia, mes, anio;
    int existe = 0;

    char nombreCliente[100] = {};

    std::cout << "Introduzca el DNI del usuario, (SIN LETRA): ";
    std::cin  >> dniContrato;
    existe = buscarCliente(dniContrato);

    if (existe == -1){
        std::cout << "Nombre del cliente: ";
        std::cin.ignore();
        std::cin.getline(nombreCliente, 100);
    }

    std::cout   << "Fecha del contrato: " << std::endl <<"Dia: ";
    std::cin    >> dia;

    std::cout   << "Mes: ";
    std::cin    >> mes;

    std::cout   << "Año (espero que se imprima vien la n con '~' encima): ";
    std::cin    >> anio;

    Fecha fechaContrato(dia, mes, anio);

    if(existe == -1){
        Cliente* nuevoCliente = new Cliente(dniContrato, nombreCliente, fechaContrato);
        altaCliente(nuevoCliente);
    }

    std::cout   << std::endl
                << "Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): \n"
                << "(Si no metes un entero crashea el programa, tu elijes)" 
                << std::endl;
    std::cin    >> tipoContrato;  


    switch (tipoContrato){

        case 1:{
            unsigned int minutosHablados = 0;

            std::cout   << "Cuantos minutos ha hablado este usuario ?"
                        << " (Maximo 2^32 minutos): ";

            std::cin    >> minutosHablados;

            ContratoTP* nuevoContratitoTP = new ContratoTP(dniContrato, fechaContrato, minutosHablados);

            contratos[nContratos++] = nuevoContratitoTP;
        }break;

        case 2:{
            int   minutosHablados     = 0;
            float precioMinuto        = 0;

            char nacionalidad[100]  = {};

            std::cout   << "Cuantos minutos ha hablado el usuario ? :";
            std::cin    >> minutosHablados;

            std::cout   << "A cuanto le sale el minuto al usuario ? :";
            std::cin    >> precioMinuto;

            std::cout   << "Cual es la nacionalidad de nuestro usuario ?\n"
                        << "Por el bien de la ejecucion de este programa espero que no sean mas de 100 caracteres\n";
            std::cin    >> nacionalidad;

            ContratoMovil* nuevoContratitoMovilito = new ContratoMovil( dniContrato, fechaContrato, 
                                                                        precioMinuto, minutosHablados, 
                                                                        nacionalidad);

            contratos[nContratos++] = nuevoContratitoMovilito;

        }break;

        default:{
            std::cout << "Habia 2 opcions '1' y '2' y lo has hecho mal..." << std::endl;
        }
            break;
    }

    return ;
}

void Empresa::descuento(int poercentaje){
    for(int i = 0; i<nContratos; i++){
        ContratoMovil* aux = dynamic_cast<ContratoMovil*>(contratos[i]);
        if(aux){
            int newPrecio = aux->getPrecioMinuto() * (100/poercentaje);
            aux->setPrecioMinuto(newPrecio);
        }
    }
    return ;
}

void Empresa::altaCliente(Cliente* nuevoCliente){
    clientes[nClientes++] = nuevoCliente;
}

void Empresa::ordenaContratos(){


    /*
            UN ESQUEMA TEACHER DE COMO FUNSIONA EL ALGORITMO QUE VIENE
            A CONTINUACION


            $ -> Contrato a eliminar
            # -> Contrato que no se quiere eliminar (solo mover)
            - -> nullptr

             0 1 2 3 4 5 6 7 8 9  
             ___________________
            |$ $ # $ # # $ # # #
            |- - # - # # - # # #
            |# - - - # # - # # #
            |# # - - - # - # # #
            |# # # - - - - # # #
            |# # # # - - - # # #
            |# # # # # - - - # #
            |# # # # # # - - - #
            |# # # # # # # - - -
        */

    int primerNulo = 0;

    for(int i = nContratos-1; i>=0; i--){
        if(contratos[i] == nullptr){
            primerNulo      = i;
        }
    }

    for(int j = primerNulo+1; j<nContratos; j++){
        if(contratos[j] != nullptr){
            contratos[primerNulo] = contratos[j];
            contratos[j] = nullptr;
            
            for(int i = primerNulo+1; i<nContratos;i++)
                if(contratos[i] == nullptr){
                    primerNulo = i;
                    break;
                }

        }

    }
}

bool Empresa::cancelarContrato(int nContrato){
    nContrato--; // El usuario da la posicion empezando por 1 no por 0
    if (nContrato >= nContratos) return false;
    else {
        delete contratos[nContrato];
        contratos[nContrato] = nullptr;
        ordenaContratos();
        nContratos--;
    }
    return true;
}

bool Empresa::bajaCliente(long int dni){

    int posicionCliente = buscarCliente(dni);
    int contratosEliminados = 0;
    if (posicionCliente == -1) return false;
    bool encontrado = false;

    for(int i = nContratos-1; i>=0 && !encontrado; i--){
        if(contratos[i]->getDniContrato() == dni){
            delete contratos[i];
            contratos[i]    = nullptr;
            contratosEliminados++;
            encontrado = true;
        }
    }

    while(posicionCliente != -1){
	
        ordenaContratos();
        
        delete clientes[posicionCliente];
        clientes[posicionCliente] = nullptr;


        /*
            ORDENAR LOS CLIENTES

            TEACHER, PARA ESTE ALGORITMO NO HAY ESQUEMA QUE ES UN COPIA PEGA DE UNA ARRAY
            A UNA AUXILIAR COMPROBANDO QUE LO QUE COPIA NO ES NULL.  :)

        */

        Cliente* auxClientes[100];
        int posicion = 0;
        for(int i = 0; i<nClientes; i++){
            if (clientes[i] != nullptr){
                auxClientes[posicion++] = clientes[i];
            }
        }
        nClientes = posicion;
        for(int i = 0; i<nClientes;i++){
            clientes[i] = auxClientes[i];
        }

        
        posicionCliente = buscarCliente(dni);
        nContratos -= contratosEliminados;
    }
    return true;
}

int Empresa::nContratosTP(){
    return nContratos;
}

int Empresa::buscarCliente(long int dni){
    for (int i = 0; i<nClientes; i++)
        if(clientes[i] != nullptr && dni == clientes[i]->getDni()) return i;
    return -1;
}

Empresa::~Empresa(){
    for(int i = 0; i<nContratos; i++){
        delete contratos[i];
    }
    for(int i = 0; i<nClientes; i++){
        delete clientes[i];
    }
}