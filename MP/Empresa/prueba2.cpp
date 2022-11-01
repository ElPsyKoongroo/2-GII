#include <cstdlib>
#include <iostream>
#include <iomanip> //std::setprecision


#if defined(WIN32) || defined(_WIN32)
    #include "headers/Fecha.h"
    #include "headers/Contrato.h" // definicion de la clase Contrato
    #include "headers/ContratoTP.h" // definicion de la clase ContratoTP
    #include "headers/ContratoMovil.h" // definicion de la clase ContratoMovil
#else
    #include "headers/Fecha.h"
    #include "headers/Contrato.h" // definicion de la clase Contrato
    #include "headers/ContratoTP.h" // definicion de la clase ContratoTP
    #include "headers/ContratoMovil.h" // definicion de la clase ContratoMovil
#endif


using namespace std;
int main(int argc, char *argv[]) {
    Fecha f1(29,2,2001), f2(f1), f3(29,2,2004);
    cout << "Fechas: ";
    f1.ver(); cout << ", "; f2.ver(); cout << ", "; f3.ver(); cout << endl;
    Contrato *p = new Contrato(75547111, f1), c(23000111, Fecha(2,2,2002));
    cout << ContratoTP::getLimiteMinutos() << " - " << ContratoTP::getPrecio() << endl;

    ContratoTP ct1(17333256, f1, 250); //habla 250 minutoe
    ContratoTP ct2(12555100, f3, 320); //habla 320 minutos
    ContratoTP ct3(ct1);
    ContratoMovil cm1(17333256, f1, 0.12, 100, "ESPAÑOL"); //habla 100 minutos
    ContratoMovil cm2(17000000, Fecha(3,3,2003), 0.10, 180, "FRANCES"); //habla 180 minutos
    ContratoMovil cm3(cm2);
    p->ver(); cout << "\n"; c.ver(); cout << endl;
    ct1.ver(); cout << endl; ct2.ver(); cout << "\n"; ct3.ver(); cout << "\n";
    cm1.ver(); cout << endl; cm2.ver(); cout << "\n"; cm3.ver(); cout << "\n";
    cout << p->getIdContrato() << ct2.getIdContrato() << cm2.getIdContrato() << endl;
    cout << setprecision(2) << fixed; //a partir de aqui float se muestra con 2 decimales

    cout << "Facturas: " << ct1.factura() <<"-"<< ct2.factura() <<"-"<< cm1.factura() << endl;
    ContratoTP::setTarifaPlana(350, 12); //350 minutos por 12 euros
    p->setDniContrato(cm1.getDniContrato());
    ct3.setFechaContrato(p->getFechaContrato()+1);
    cm3.setNacionalidad(cm1.getNacionalidad());
    cm2.setPrecioMinuto(cm1.getPrecioMinuto()+0.02);
    cm1.setMinutosHablados(ct2.getMinutosHablados()/2);
    ct1.setMinutosHablados(cm3.getMinutosHablados()*2);
    cout << *p << "\n" << c << endl;
    cout << ct1 << endl << ct2 <<"\n"<< ct3 <<"\n"<< cm1 <<"\n"<< cm2 <<endl<< cm3 << endl;


    /* 

        PRACTICA 1 PARTE 3

    */

    Contrato* t[4];
    t[0] = p;
    t[1] = &c;
    t[2] = &ct2;
    t[3] = &cm1;
    cout << "\n-- Datos de los contratos: -- \n";
    t[3]->setDniContrato(75547111);
    for (int i = 0; i < 4; i++) {
        t[i]->setFechaContrato(t[i]->getFechaContrato() + 2);
        t[i]->ver();
        cout << endl;
    }
    system("PAUSE");
    return 0;
}   


/*

Fechas: 28/02/2001, 28/02/2001, 29/02/2004
300 - 10
75547111 (1 - 28/02/2001)
23000111 (2 - 02/02/2002)
17333256 (3 - 28/02/2001) 250m, 300(10)
12555100 (4 - 29/02/2004) 320m, 300(10)
17333256 (5 - 28/02/2001) 250m, 300(10)
17333256 (6 - 28/02/2001) 100m, ESPAÑOL 0.12
17000000 (7 - 03/03/2003) 180m, FRANCES 0.1
17000000 (8 - 03/03/2003) 180m, FRANCES 0.1
147
Facturas : 10.00-13.00-12.00
17333256 (1 - 28 feb 2001) 
23000111 (2 - 02 feb 2002)
17333256 (3 - 28 feb 2001) 360m, 350(12.00) - 13.50€
12555100 (4 - 29 feb 2004) 320m, 350(12.00) - 12.00€
17333256 (5 - 01 mar 2001) 250m, 350(12.00) - 12.00€
17333256 (6 - 28 feb 2001) 160m, ESPAÑOL 0.12 - 19.20€
17000000 (7 - 03 mar 2003) 180m, FRANCES 0.14 - 25.20€
17000000 (8 - 03 mar 2003) 180m, ESPAÑOL 0.10 - 18.00€ 

--------------------------------

    myPtr = &Contrato
            &ContratoTP

    Safely converts pointers and references to classes up, down, and 
    sideways along the inheritance hierarchy."

    If the cast is successful, dynamic_cast returns a 
    value of type new-type. If the cast fails and new-type is a 
    pointer type, it returns a null pointer of that type. If the cast 
    fails and new-type is a reference type, it throws an exception that 
    matches a handler of type std::bad_cast.

*/