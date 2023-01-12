#ifndef MENUCONFIGURACIONES_H_INCLUDED
#define MENUCONFIGURACIONES_H_INCLUDED
void desplegarMenuConfiguracion();

void menuConfiguracion(){

    int opcion;
    bool salir=false;

     while(!salir){
        desplegarMenuConfiguracion();
        cin>>opcion;
        rlutil::setColor(rlutil::WHITE);
        system("cls");
        switch(opcion){
        case 1:
            if(backupLibros()){
                cout<<"COPIA REALIZADA."<<endl;
            }
            else{
                cout<<"No pudo realizarse la copia de seguridad"<<endl;
            }
            getch();
            system("cls");
            break;
        case 2:
            if(backupSocios()){
               cout<<"COPIA REALIZADA."<<endl;
            }
            else{
                cout<<"No pudo realizarse la copia de seguridad"<<endl;
            }
            getch();
            system("cls");
            break;
        case 3:
            if(backupPrestamos()){
               cout<<"COPIA REALIZADA."<<endl;
            }
            else{
                cout<<"No pudo realizarse la copia de seguridad"<<endl;
            }
            getch();
            system("cls");
            break;
        case 4:
            if(restaurarLibros()){
                cout<<"RESTAURACION REALIZADA"<<endl;
            }
            else{
                cout<<"No pudo realizarse la restauracion"<<endl;
            }
            getch();
            system("cls");
            break;
        case 5:
            if(restaurarSocios()){
                cout<<"RESTAURACION REALIZADA"<<endl;
            }
            else{
                cout<<"No pudo realizarse la restauracion"<<endl;
            }
            system("pause");
            system("cls");
            break;
        case 6:
            if(restaurarPrestamos()){
                cout<<"RESTAURACION REALIZADA"<<endl;
            }
            else{
                cout<<"No pudo realizarse la restauracion"<<endl;
            }
            getch();
            system("cls");
            break;
        case 0:
            salir=true;
            break;
        default:
            gotoxy(30,10);
            rlutil::setColor(rlutil::RED);
            cout<<"Opcion incorrecta."<<endl;
            cout<<endl;
            rlutil::setColor(rlutil::WHITE);
            getch();
            system("cls");
            break;
        }
    }
}


void desplegarMenuConfiguracion(){

    lineaIzquierdaMarron();
    lineaDerechaMarron();
    gotoxy(15,2);
    lineaColorMarron();
    gotoxy(30,3);
    rlutil::setColor(rlutil::BROWN);
    cout<<"SECCIÓN DE SOCIOS "<<endl;
    gotoxy(15,4);
    lineaColorMarron();
    gotoxy(20,6);
    cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE LIBROS"<<endl;
    gotoxy(20,7);
    cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE SOCIOS"<<endl;
    gotoxy(20,8);
    cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE PRESTAMOS"<<endl;
    gotoxy(20,9);
    cout<<"4) RESTAURAR EL ARCHIVO DE LIBROS"<<endl;
    gotoxy(20,10);
    cout<<"5) RESTAURAR EL ARCHIVO DE SOCIOS"<<endl;
    gotoxy(20,11);
    cout<<"6) RESTAURAR EL ARCHIVO DE PRESTAMOS"<<endl;
    gotoxy(15,13);
    lineaColorMarron();
    gotoxy(20,14);
    cout<<"0) REGRESAR AL MENU PRINCIPAL"<<endl;
    gotoxy(15,15);
    lineaColorMarron();
    gotoxy(25,18);
    cout<<"     Opcion elegida:               ";
}



#endif // MENUCONFIGURACIONES_H_INCLUDED
