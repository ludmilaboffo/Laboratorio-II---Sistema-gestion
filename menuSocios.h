#ifndef MENUSOCIOS_H_INCLUDED
#define MENUSOCIOS_H_INCLUDED
////////////////////// MENU SOCIOS:

void desplegarMenuSocios();

void menuSocios(){

    int opcion;
    bool salir=false;

    while(!salir){
    desplegarMenuSocios();
    cin>>opcion;
    rlutil::setColor(rlutil::WHITE);
    system("cls");
        switch(opcion){
        case 1:
            if(!altaSocio()){ cout<<"Carga incorrecta"; break;}
            cout<<endl<<"Carga finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 2:
            if(!listarSociosID()){
                cout<<endl<<"Retorno al menú."<<endl;
                getch();
                system("cls");
                break;
            }
            cout<<endl<<"Muestra finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 3:
            listarSocios();
            cout<<endl<<"Muestra finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 4:
            if(!listarLibrosAdeudados()){
                cout<<"No adeuda libros."<<endl;
                getch();
                system("cls");
                break;
            }
            getch();
            system("cls");

            break;
        case 5:
            if(!bajaDeSocio()){
                cout<<endl<<"No ha podido realizarse la baja del socio."<<endl;
                getch();
                system("cls");
                break;
            }
            cout<<endl<<"Baja realizada."<<endl;
            getch();
            system("cls");
            break;
        case 0:
            salir=true;
            break;
        default:
            gotoxy(30,10);
            rlutil::setColor(rlutil::RED);
            cout<<"Opción incorrecta."<<endl;
            cout<<endl;
            rlutil::setColor(rlutil::WHITE);
            getch();
            system("cls");
            break;
        }
    }
 }



void desplegarMenuSocios(){

    lineaIzquierdaRojo();
    lineaDerechaRojo();
    gotoxy(15,2);
    lineaColorRojo();
    gotoxy(30,3);
    rlutil::setColor(rlutil::LIGHTRED);
    cout<<"SECCIÓN DE SOCIOS "<<endl;
    gotoxy(15,4);
    lineaColorRojo();
    gotoxy(20,6);
    cout<<"1) AGREGAR NUEVO SOCIO"<<endl;
    gotoxy(20,7);
    cout<<"2) MOSTRAR UN SOCIO POR ID"<<endl;
    gotoxy(20,8);
    cout<<"3) MOSTRAR TODOS LOS SOCIOS"<<endl;
    gotoxy(20,9);
    cout<<"4) MOSTRAR LOS LIBROS QUE ADEUDA UN SOCIO"<<endl;
    gotoxy(20,10);
    cout<<"5) DAR DE BAJA UN SOCIO"<<endl;
    gotoxy(15,11);
    lineaColorRojo();
    gotoxy(20,12);
    cout<<"0) REGRESAR AL MENÚ PRINCIPAL"<<endl;
    gotoxy(15,13);
    lineaColorRojo();
    gotoxy(25,16);
    rlutil::setColor(rlutil::LIGHTRED);
    cout<<"     Opcion elegida:               ";
}

#endif // MENUSOCIOS_H_INCLUDED
