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
                cout<<endl<<"No se pudo enseñar el ID porque no existe o está dado de baja."<<endl;
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
                cout<<"No se pudo realizar la devolución."<<endl;
                getch();
                system("cls");
                break;
             }
            cout<<"Devolución realizada con éxito"<<endl;
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
            cout<<"Opción incorrecta."<<endl;
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
    cout<<"SECCIÓN DE PRÉSTAMOS"<<endl;
    gotoxy(15,4);
    lineaColorCyan();
    gotoxy(20,6);
    cout<<"1) REALIZAR UN PRÉSTAMO"<<endl;
    gotoxy(20,7);
    cout<<"2) MOSTRAR UN PRÉSTAMO POR ID"<<endl;
    gotoxy(20,8);
    cout<<"3) MOSTRAR TODOS LOS PRÉSTAMOS"<<endl;
    gotoxy(20,9);
    cout<<"4) DEVOLVER UN LIBRO PRESTADO"<<endl;
    gotoxy(20,10);
    cout<<"5) HISTORIAL DE PRÉSTAMOS"<<endl;
    gotoxy(15,12);
    lineaColorCyan();
    gotoxy(20,13);
    cout<<"0) REGRESAR AL MENÚ PRINCIPAL"<<endl;
    gotoxy(15,14);
    lineaColorCyan();
    gotoxy(25,17);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout<<"     Opcion elegida:               ";
}





#endif // MENUPRESTAMOS_H_INCLUDED
