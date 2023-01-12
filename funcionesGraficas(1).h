#ifndef FUNCIONESGRAFICAS_H_INCLUDED
#define FUNCIONESGRAFICAS_H_INCLUDED


void lineaColorMagenta();
void lineaDerechaMagenta();
void lineaIzquierdaMagenta();
void lineaDerechaAmarilla();
void lineaIzquierdaAmarilla();
void lineaColorAmarilla();
void lineaColorGris();


void bienvenida(){
    gotoxy(15,5);
    lineaColorGris();
    gotoxy(20,7);
    cout<<"BIENVENIDOS AL SISTEMA DE LA BIBLIOTECA "<<endl;
    gotoxy(18,8);
    rlutil::setColor(rlutil::GREY);
    cout<<"'LOS AMIGOS DE SHAKESPEARE  -  DARREGUEIRA' "<<endl;
    rlutil::setColor(rlutil::WHITE);
    gotoxy(15,10);
    lineaColorGris();
    gotoxy(15,12);
   cout<<"-----> Presione cualquier tecla para ingresar"<<endl;
   gotoxy(15,14);
   cout<<"         ,..........   ..........,"<<endl;
   gotoxy(15,15);
   cout<<"     ,..,'          '.'          ',..,"<<endl;
   gotoxy(15,16);
   cout<<"    ,' ,'            :            ', ',"<<endl;
   gotoxy(15,17);
   cout<<"   ,' ,'             :             ', ',"<<endl;
   gotoxy(15,18);
   cout<<"  ,' ,'              :              ', ',"<<endl;
   gotoxy(15,19);
   cout<<" ,' ,'............., : ,.............', ',"<<endl;
   gotoxy(15,20);
   cout<<",'  '............   '.'   ............'  ',"<<endl;
   gotoxy(15,21);
   cout<<" '''''''''''''''''';''';''''''''''''''''''"<<endl;

    getch();
    system("cls");
}

void lineaColorMagenta(){
    rlutil::setColor(rlutil::LIGHTMAGENTA);

    for(int i=0; i<50;i++){
        //Sleep(10);
        cout<<"=";
    }
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
}



void lineaDerechaMagenta(){
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    for(int i=2; i<=13;i++){
        //Sleep(10);
        gotoxy(65,i);
        cout<<"+"<<endl;
    }
}


void lineaIzquierdaMagenta(){
  rlutil::setColor(rlutil::LIGHTMAGENTA);
    for(int i=2; i<=13;i++){
        gotoxy(14,i);
        cout<<"+"<<endl;
    }
}

//////////////////////////////////////////////////////////////////////

void lineaColorAmarilla(){
    rlutil::setColor(rlutil::YELLOW);
    for(int i=0; i<50;i++){
        //Sleep(10);
        cout<<"=";
    }
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
}

void lineaDerechaAmarilla(){
    rlutil::setColor(rlutil::YELLOW);
    for(int i=2; i<=14;i++){
       // Sleep(10);
        gotoxy(65,i);
        cout<<"+"<<endl;
    }
}

void lineaIzquierdaAmarilla(){
    rlutil::setColor(rlutil::YELLOW);
    for(int i=2; i<=14;i++){
        gotoxy(14,i);
            cout<<"+"<<endl;
    }
}

////////////////////////////////////////7
void lineaColorCyan(){
    rlutil::setColor(rlutil::LIGHTBLUE);
    for(int i=0; i<50;i++){
        cout<<"=";
    }
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
}



void lineaDerechaCyan(){
    rlutil::setColor(rlutil::LIGHTBLUE);
    for(int i=2; i<=13;i++){
        gotoxy(66,i);
        cout<<"+"<<endl;
    }
}

void lineaIzquierdaCyan(){
    rlutil::setColor(rlutil::LIGHTBLUE);
    for(int i=2; i<=13;i++){
            gotoxy(15,i);
            cout<<"+"<<endl;
    }
}


////////////////////////////////////////7
void lineaColorRojo(){
    rlutil::setColor(rlutil::LIGHTRED);
    for(int i=0; i<50;i++){
        //Sleep(5);
        cout<<"=";
    }
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
}



void lineaDerechaRojo(){
    rlutil::setColor(rlutil::LIGHTRED);
    for(int i=2; i<=13;i++){
        //Sleep(10);
        gotoxy(65,i);
        cout<<"+"<<endl;
    }
}

void lineaIzquierdaRojo(){
    rlutil::setColor(rlutil::LIGHTRED);
    for(int i=2; i<=13;i++){
        gotoxy(14,i);
            cout<<"+"<<endl;
    }
}


////////////////////////////////////////7
void lineaColorVerde(){
    rlutil::setColor(rlutil::LIGHTGREEN);
    for(int i=0; i<50;i++){
        //Sleep(5);
        cout<<"=";
    }
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
}



void lineaDerechaVerde(){
    rlutil::setColor(rlutil::LIGHTGREEN);
    for(int i=2; i<=14;i++){
        //Sleep(10);
        gotoxy(65,i);
        cout<<"+"<<endl;
    }
}

void lineaIzquierdaVerde(){
    rlutil::setColor(rlutil::LIGHTGREEN);
    for(int i=2; i<=14;i++){
            gotoxy(14,i);
            cout<<"+"<<endl;
    }
}



//////////
void lineaColorMarron(){
    rlutil::setColor(rlutil::BROWN);
    for(int i=0; i<53;i++){
        //Sleep(5);
        cout<<"=";
    }
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
}



void lineaDerechaMarron(){
    rlutil::setColor(rlutil::BROWN);
    for(int i=2; i<=15;i++){
        //Sleep(10);
        gotoxy(68,i);
        cout<<"+"<<endl;
    }
}

void lineaIzquierdaMarron(){
    rlutil::setColor(rlutil::BROWN);
    for(int i=2; i<=15;i++){
            gotoxy(14,i);
            cout<<"+"<<endl;
    }
}





//////////
void lineaColorGris(){
    rlutil::setColor(rlutil::GREY);
    for(int i=0; i<53;i++){
        Sleep(10);
        cout<<"=";
    }
    cout<<endl;
    rlutil::setColor(rlutil::WHITE);
}



void menuPrincipal(){
    lineaIzquierdaMagenta();
    lineaDerechaMagenta();
    gotoxy(15,2);
    lineaColorMagenta();
    gotoxy(30,3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout<<"MENÚ PRINCIPAL "<<endl;
    gotoxy(15,4);
    lineaColorMagenta();
    gotoxy(16,6);
    cout<<"     1) LIBROS "<<endl;
    gotoxy(16,7);
    cout<<"     2) SOCIOS "<<endl;
    gotoxy(16,8);
    cout<<"     3) PRÉSTAMOS "<<endl;
    gotoxy(16,9);
    cout<<"     4) REPORTES "<<endl;
    gotoxy(16,10);
    cout<<"     5) CONFIGURACIÓN"<<endl;
    gotoxy(15,11);
    lineaColorMagenta();
    gotoxy(16,12);
    cout<<"     0) SALIR "<<endl;
    gotoxy(15,13);
    lineaColorMagenta();
    gotoxy(25,16);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout<<"Opción elegida: ";
}



#endif // FUNCIONESGRAFICAS_H_INCLUDED
