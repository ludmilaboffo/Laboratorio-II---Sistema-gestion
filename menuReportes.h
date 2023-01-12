#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void desplegarMenuReportes();

void menuReportes(){

    int opcion;
    bool salir=false;

    while(!salir){
    desplegarMenuReportes();
    cin>>opcion;
    rlutil::setColor(rlutil::WHITE);
    system("cls");
        switch(opcion){
        case 1:
            if(!modificarAutor()){
                cout<<endl<<"No puede modificarse el autor porque el id libro no existe o est� dado de baja."<<endl;
                getch();
                system("cls");
                break;
            }
            cout<<endl<<"Modificaci�n realizada."<<endl;
            getch();
            system("cls");
            break;
        case 2:
            socioConMasDeudas();
            getch();
            system("cls");
            break;
        case 3: librosDelAnioActual();
            getch();
            system("cls");
            break;
        case 4:
            libroDisponibleMayor();
            getch();
            system("cls");
            break;
        case 5:
                getch();
                system("cls");
                break;
        case 0:
            salir=true;
            break;
        default:
            gotoxy(30,10);
            rlutil::setColor(rlutil::RED);
            cout<<"Opci�n incorrecta."<<endl;
            cout<<endl;
            rlutil::setColor(rlutil::WHITE);
            getch();
            system("cls");
            break;
        }
    }
  }


void desplegarMenuReportes(){

    lineaIzquierdaVerde();
    lineaDerechaVerde();
    gotoxy(15,2);
    lineaColorVerde();
    gotoxy(30,3);
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout<<"SECCI�N DE REPORTES "<<endl;
    gotoxy(15,4);
    lineaColorVerde();
    gotoxy(20,7);
    cout<<"1) CAMBIAR EL NOMBRE DE AUTOR "<<endl;
    gotoxy(20,8);
    cout<<"2) SOCIO QUE M�S LIBROS ADEUDA"<<endl;
    gotoxy(20,9);
    cout<<"3) LIBROS QUE INGRESARON EN EL A�O ACTUAL"<<endl;
    gotoxy(20,10);
    cout<<"4) EL LIBRO CON M�S PAGINAS"<<endl;
    gotoxy(15,11);
    lineaColorVerde();
    gotoxy(20,12);
    cout<<"0) REGRESAR AL MEN� PRINCIPAL"<<endl;
    gotoxy(15,13);
    lineaColorVerde();
    gotoxy(25,15);
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout<<"     Opcion elegida:               ";
}


#endif // MENUREPORTES_H_INCLUDED
