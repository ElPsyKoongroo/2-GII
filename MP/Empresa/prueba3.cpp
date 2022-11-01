#include <cstdlib>
#include <iostream>
#include <iomanip> //std::setprecision


#if defined(WIN32) || defined(_WIN32)

    /*
        NO SE GARANTIZA LA CORRECTA IMPRESION DE CARACTERES ESPECIALES DEL 
        ESPAÑOL CUANDO SE COMPILA Y SE EJECUTA EN WINDOWS
    */

    #include "headers/Fecha.h"
    #include "headers/Contrato.h"       // definicion de la clase Contrato
    #include "headers/ContratoTP.h"     // definicion de la clase ContratoTP
    #include "headers/ContratoMovil.h"  // definicion de la clase ContratoMovil
    #include "headers/Empresa.h"
#else
    #include "headers/Fecha.h"
    #include "headers/Contrato.h"           // definicion de la clase Contrato
    #include "headers/ContratoTP.h"         // definicion de la clase ContratoTP
    #include "headers/ContratoMovil.h"      // definicion de la clase ContratoMovil
    #include "headers/Empresa.h"
#endif

using namespace std;
int main(int argc, char *argv[]) {
    bool ok;
    Empresa Yoigo;
    cout << setprecision(2)
         << fixed; // a partir de aqui float se muestra con 2 decimales
    cout << endl << "APLICACION DE GESTION TELEFONICA\n" << endl;
    Yoigo.cargarDatos(); // crea 3 clientes y 7 contratos. metodo creado para no
                         // tener que meter datos cada vez que pruebo el programa
    Yoigo.ver();
    cout << "Yoigo tiene " << Yoigo.nContratosTP()
         << " Contratos de Tarifa Plana\n\n";
    
    
    //Yoigo.crearContrato(); // ContratoMovil a 37000017 el 01/01/2017 con 100m a
                           // 0.25
    //Yoigo.crearContrato(); // ContratoTP a 22330014 (pepe luis) el 2/2/2017 con
                           // 305m
    
    ok = Yoigo.cancelarContrato(28);    // este Contrato no existe
    if (ok)
        cout << "Contrato 28 cancelado\n";
    else
        cout << "El Contrato 28 no existe\n";
    ok = Yoigo.cancelarContrato(4);    // este Contrato si existe
    if (ok)
        cout << "El Contrato 4 ha sido cancelado\n";
    else
        cout << "El Contrato 4 no existe\n";
    ok = Yoigo.bajaCliente(75547001); // debe eliminar el cliente y sus 3 Contratos
    if (ok)
        cout << "El cliente 75547001 y sus Contratos han sido cancelados\n";
    else
        cout << "El cliente 75547001 no existe\n";
    Yoigo.ver();
    // Yoigo.descuento(20);
    cout << "\nTras rebajar un 20% la tarifa de los ContratosMovil...";
    Yoigo.ver();
    cout << "Yoigo tiene " << Yoigo.nContratosTP()
         << " Contratos de Tarifa Plana\n";
    system("PAUSE"); 
    return 0;
}

/*


    APLICACION DE GESTION TELEFONICA
    La Empresa tiene 3 clientes y 7 contratos
    Clientes:
    Peter Lee  (75547001 - 28 feb 2001)
    Juan Perez (45999000 - 29 feb 2000)
    Luis Bono  (37000017 - 31 ene 2002)
    Contratos:
    75547001 (1 - 28 feb 2001) 110m, DANES 0.12 - 13.20€
    75547001 (2 - 31 ene 2002) 170m, DANES 0.09 - 15.30€
    37000017 (3 - 01 feb 2002) 250m, 300(10.00) - 10.00€
    75547001 (4 - 28 feb 2001) 312m, 300(10.00) - 11.80€
    45999000 (5 - 31 ene 2002) 202m, ESPAÑOL 0.10 - 20.20€
    75547001 (6 - 31 ene 2002) 80m, DANES 0.15 - 12.00€
    45999000 (7 - 01 feb 2002) 400m, 300(10.00) - 25.00€
    Yoigo tiene    3    contratos de    Tarifa Plana
    ----------------------------------------------------------- PERFE
    Introduzca dni: 37000017
    Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): 2
    Fecha del contrato
    dia: 1 mes: 1 anio: 2017
    minutos hablados: 100
    Precio minuto: 0.25
    Nacionalidad: alemán

    Introduzca dni: 22330014
    Nombre del cliente: pepe luis
    dia: 2 mes: 2 anio: 2017
    Tipo de Contrato a abrir (1-Tarifa Plana, 2-Movil): 1
    Fecha del contrato
    dia: 2 mes: 2 anio: 2017
    minutos hablados: 305


    El contrato 28 no existe
    El contrato 4 ha sido cancelado
    El cliente 75547001 y sus contratos han sido cancelados
    La Empresa tiene 3 clientes y 5 contratos
    Clientes:
    Juan Perez (45999000 - 29 feb 2000)
    Luis Bono (37000017 - 31 ene 2002)
    pepe luis (22330014 - 02 feb 2017)
    Contratos: 
    37000017 (3 - 01 feb 2002 ) 250m, 300(10.00) - 10.00€ 
    45999000 (5 - 31 ene 2002 ) 202m, ESPAÑOL 0.10 - 20.20€
    45999000 (7 - 01 feb 2002 ) 400m, 300(10.00) - 25.00€
    37000017 (8 - 01 ene 2017 ) 100m, aleman 0.25 - 25.00€
    22330014 (9 - 02 feb 2017 ) 305m, 300(10.00) - 10.75€
    Tras rebajar un 20% la tarifa de los ContratosMovil...
    La Empresa tiene 3 clientes y 5 contratos
    Clientes:
    Juan Perez (45999000 - 29 feb 2000)
    Luis Bono (37000017 - 31 ene 2002)
    pepe luis (22330014 - 02 feb 2017)
    Contratos:
    37000017 (3 - 01 feb 2002 ) 250m, 300(10.00) - 10.00€
    45999000 (5 - 31 ene 2002 ) 202m, ESPAÑOL 0.08 - 16.16€
    45999000 (7 - 01 feb 2002 ) 400m, 300(10.00) - 25.00€ 
    37000017 (8 - 01 ene 2017 ) 100m, aleman 0.20 - 20.00€ 
    22330014 (9 - 02 feb 2017 ) 305m, 300(10.00) - 10.75€ 
    Yoigo tiene 3 contratos de Tarifa Plana
    Presione una tecla para continuar . . .

*/