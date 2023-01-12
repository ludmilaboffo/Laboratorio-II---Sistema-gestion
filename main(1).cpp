#include <iostream>
#include <cstring>
#include <ctype.h>
#include <windows.h>
using namespace std;
#include <ctime>
#include "rlutil.h"
#include "funcionesGraficas.h"
#include "funcionesGlobales.h"
#include "claseFecha.h"
#include "claseDireccion.h"
#include "claseLibros.h"
#include "claseSocios.h"
#include "clasePrestamo.h"
#include "claseHistorial.h"
#include "funcionesLibros.h"
#include "funcionesSocio.h"
#include "funcionesPrestamo.h"
#include "funcionesReportes.h"
#include "funcionesHistorial.h"
#include "funcionesConfiguraciones.h"
#include "menuLibros.h"
#include "menuSocios.h"
#include "menuPrestamos.h"
#include "menuReportes.h"
#include "menuConfiguraciones.h"
int main(){

    setlocale(LC_ALL,"Spanish");


    bienvenida();

    int opcion;
    while(true){
    menuPrincipal();
    cin>>opcion;
    rlutil::setColor(rlutil::WHITE);
    system("cls");

        switch(opcion){
        case 1:
            menuLibros();
            system("cls");
            break;
        case 2:
            menuSocios();
            system("cls");
            break;
        case 3:
                menuPrestamos();
                system("cls");
                break;
        case 4:
            menuReportes();
            system("cls");
            break;
        case 5:
            menuConfiguracion();
            system("cls");
            break;
        case 0:
            gotoxy(30,10);
            rlutil::setColor(rlutil::LIGHTRED);
            cout<<"Programa finalizado"<<endl;
            gotoxy(30,11);
            cout<<"¡Hasta la próxima!"<<endl;
            rlutil::setColor(rlutil::WHITE);
            gotoxy(30,20);
            return 0;
            break;
        default:
            gotoxy(30,10);
            rlutil::setColor(rlutil::RED);
            cout<<"Opcion incorrecta."<<endl;
            cout<<endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            break;
        }
    }
}
