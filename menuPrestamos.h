#ifndef MENUPRESTAMOS_H_INCLUDED
#define MENUPRESTAMOS_H_INCLUDED

void desplegarMenuPrestamos();
void lineaColorCyan();
void menuPrestamos();

void menuPrestamos(){
    int opcion;
    bool salir=false;

    while(!salir){
    desplegarMenuPrestamos();
    cin>>opcion;
    rlutil::setColor(rlutil::WHITE);
    system("cls");
        switch(opcion){
        case 1:
            if(!altaPrestamo()){
                cout<<endl<<"Carga incorrecta";
                getch();
                system("cls");
                break;
            }
            cout<<endl<<"Carga finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 2:
            if(!listarPrestamoID()){
                cout<<endl<<"No se pudo ense�ar el ID porque no existe o est� dado de baja."<<endl;
                getch();
                system("cls");
                break;
            }
            cout<<endl<<"Muestra finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 3:
            listarPrestamos();
            cout<<endl<<"Muestra finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 4:
             if(!devolverLibro()){
                cout<<"No se pudo realizar la devoluci�n."<<endl;
                getch();
                system("cls");
                break;
             }
            cout<<"Devoluci�n realizada con �xito"<<endl;
            getch();
            system("cls");
            break;
        case 5:
            desplegarHistorial();
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

 void desplegarMenuPrestamos(){

    lineaDerechaCyan();
    lineaIzquierdaCyan();
    gotoxy(15,2);
    lineaColorCyan();
    gotoxy(30,3);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<<"SECCI�N DE PR�STAMOS"<<endl;
    gotoxy(15,4);
    lineaColorCyan();
    gotoxy(20,6);
    cout<<"1) REALIZAR UN PR�STAMO"<<endl;
    gotoxy(20,7);
    cout<<"2) MOSTRAR UN PR�STAMO POR ID"<<endl;
    gotoxy(20,8);
    cout<<"3) MOSTRAR TODOS LOS PR�STAMOS"<<endl;
    gotoxy(20,9);
    cout<<"4) DEVOLVER UN LIBRO PRESTADO"<<endl;
    gotoxy(20,10);
    cout<<"5) HISTORIAL DE PR�STAMOS"<<endl;
    gotoxy(15,12);
    lineaColorCyan();
    gotoxy(20,13);
    cout<<"0) REGRESAR AL MEN� PRINCIPAL"<<endl;
    gotoxy(15,14);
    lineaColorCyan();
    gotoxy(25,17);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<<"     Opcion elegida:               ";
}





#endif // MENUPRESTAMOS_H_INCLUDED
