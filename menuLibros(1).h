#ifndef MENULIBROS_H_INCLUDED
#define MENULIBROS_H_INCLUDED


void desplegarMenuLibros();
void lineaColor();
////////////////////// MENU LIBROS:
void menuLibros(){

    int opcion;
    bool salir=false;

    while(!salir){
    desplegarMenuLibros();
    cin>>opcion;
    rlutil::setColor(rlutil::WHITE);
    system("cls");
        switch(opcion){
        case 1:
            if(!altaLibro()){ cout<<"Carga incorrecta."; break;}
            cout<<endl<<"Carga finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 2:
            if(!listarLibrosPorID()){
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
            listarLibros();
            cout<<endl<<"Muestra finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 4:
                ordenarAlfabeticamente();
                getch();
                system("cls");
                break;
        case 5:
            if(!listarLibrosPrestados()){
                cout<<"No se puede mostrar el listado.";
                getch();
                system("cls");
                break;
            }
            cout<<endl<<"Muestra finalizada"<<endl;
            getch();
            system("cls");
            break;
        case 6:
             if(!bajaLogicaLibro()){
                cout<<"ERROR."<<endl;
                getch();
                system("cls");
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
            cout<<"Opción incorrecta."<<endl;
            cout<<endl;
            rlutil::setColor(rlutil::WHITE);
            getch();
            system("cls");
            break;
        }
    }
 }



void desplegarMenuLibros(){

    lineaIzquierdaAmarilla();
    lineaDerechaAmarilla();
    gotoxy(15,2);
    lineaColorAmarilla();
    gotoxy(30,3);
    rlutil::setColor(rlutil::YELLOW);
    cout<<"SECCIÓN DE LIBROS "<<endl;
    gotoxy(15,4);
    lineaColorAmarilla();
    gotoxy(20,6);
    cout<<"1) AGREGAR NUEVO LIBRO"<<endl;
    gotoxy(20,7);
    cout<<"2) MOSTRAR UN LIBRO POR ID"<<endl;
    gotoxy(20,8);
    cout<<"3) MOSTRAR TODOS LOS LIBROS"<<endl;
    gotoxy(20,9);
    cout<<"4) MOSTRAR ORDENADOS LA A a la Z"<<endl;
    gotoxy(20,10);
    cout<<"5) MOSTRAR LIBROS PRESTADOS"<<endl;
    gotoxy(20,11);
    cout<<"6) DAR DE BAJA UN LIBRO"<<endl;
    gotoxy(15,12);
    lineaColorAmarilla();
    gotoxy(20,13);
    cout<<"0) REGRESAR AL MENU PRINCIPAL"<<endl;
    gotoxy(15,14);
    lineaColorAmarilla();
    gotoxy(25,16);
    rlutil::setColor(rlutil::YELLOW);
    cout<<"     Opcion elegida:               ";
}





#endif // MENULIBROS_H_INCLUDED
