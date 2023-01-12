#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

 class Fecha{

    private:

    int dia;
    int mes;
    int anio;

    public:
    void Cargar();
    void MostrarFecha();

    ///sets
    void setDia(int elDia){dia=elDia;}
    void setAnio(int elAnio){anio=elAnio;}
    void setMes(int elMes){ mes=elMes;}
    /// gets
    int getMes(){return mes;}
    int getAnio(){return anio;}
    int getDia(){return dia;}

    ///constructor

     Fecha(int d=0, int m=0, int a=0){
        dia=d;
        mes=m;
        anio=a;
    }
 };

bool validarFecha(int dia, int mes, int anio);
bool anioBisiesto(int anio);
Fecha devolverFechaActual();
int validarDia();
int validarAnio();
int validarMes();


void Fecha::Cargar(){
    int m, a, d;
    Fecha fechAct;

    d=validarDia();
    m=validarMes();
    a=validarAnio();

    while(!validarFecha(d,m,a)){
        d=validarDia();
        m=validarMes();
        a=validarAnio();
    }
    fechAct=devolverFechaActual();
    if(fechAct.getAnio()<a){
        cout<<"El año no puede ser mayor al actual"<<endl;
        fechAct.MostrarFecha();
        cout<<"REINTENTE";
        cout<<endl;
        d=validarDia();
        m=validarMes();
        a=validarAnio();
    }
    if(fechAct.getAnio()==a && fechAct.getMes()<m){
        cout<<"El mes no puede ser mayor al mes actual"<<endl;
        fechAct.MostrarFecha();
        cout<<"REINTENTE";
        cout<<endl;
        d=validarDia();
        m=validarMes();
        a=validarAnio();
    }
    if(fechAct.getAnio()==a && fechAct.getMes()==m && fechAct.getDia()<d){
        cout<<"El prestamo debe ser actual, no futuro. Fecha de hoy: "<<endl;
        fechAct.MostrarFecha();
        cout<<"REINTENTE";
        cout<<endl;
        d=validarDia();
        m=validarMes();
        a=validarAnio();
    }
    setAnio(a);
    setMes(m);
    setDia(d);
 }


 void Fecha::MostrarFecha(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
 }



 // funciones globales que trabajan con la clase fecha


int validarDia(){
    int d;
    cout<<"DÍA: ";
    cin>>d;
    while(d>31 || d<1){
        cout<<"INVÁLIDO. VUELVA A INGRESAR."<<endl;
        cout<<"DÍA: ";
        cin>>d;
    }
    return d;
}
int validarMes(){
    int m;
    cout<<"MES: ";
    cin>>m;
    while(m>12 || m<1){
        cout<<"INVÁLIDO. VUELVA A INGRESAR."<<endl;
        cout<<"MES: ";
        cin>>m;
    }
    return m;
}

int validarAnio(){
    int a;
    cout<<"AÑO: ";
    cin>>a;
    while(a>2022 || a<1500){
        cout<<"INVÁLIDO. VUELVA A INGRESAR."<<endl;
        cout<<"AÑO: ";
        cin>>a;
    }
    return a;
}
 /// valida que el dia, mes y año ingresados sean correctos en el formato del calendario
bool validarFecha(int dia, int mes, int anio){


       if(dia>30 && mes==4){
            cout<<"Abril tiene treinta días. Re-ingrese"<<endl;
            return false;
       }
       if(dia>30 && mes==6){
            cout<<"Junio tiene treinta días. Re-ingrese"<<endl;;
            return false;
        }
       if(dia>30 && mes==9){
            cout<<"Septiembre tiene treinta días. Re-ingrese"<<endl;;
            return false;
        }
        if(dia>30 && mes==11){
            cout<<"Noviembre tiene treinta días. Re-ingrese"<<endl;
            return false;
        }
     if(!anioBisiesto(anio) && mes==2 && dia>28){
            cout<<"Febrero tiene veintiocho días. Re-ingrese"<<endl;
            return false;
        }
     else if(anioBisiesto(anio) && dia>29 && mes==2){
            cout<<"AÑO BISCIESTO"<<endl;
            cout<<"Febrero tiene veintinueve días. Re-ingrese"<<endl;
            return false;
        }
        return true;
}

/// determina si un año es bisiesto o no
bool anioBisiesto(int anio){
    if((anio%4==0) || (anio%100!=0 && anio%400==0)){
        return true;
    }
    return false;
}

bool validarCreacion(Fecha nueva){

    Fecha creacion;

    creacion.setAnio(1995);
    creacion.setMes(12);
    creacion.setDia(8);

    if(nueva.getAnio()<creacion.getAnio()){
        cout<<"La biblioteca fue fundada en el año 1995."<<endl;
        return false;
    }
    if(nueva.getAnio()==creacion.getAnio() && nueva.getMes()<creacion.getMes()){
        cout<<"La biblioteca fue fundada en diciembre."<<endl;
        return false;
    }
    if((nueva.getAnio()==creacion.getAnio()) && (nueva.getMes()==creacion.getMes()) && (nueva.getDia()<creacion.getDia())){
        cout<<"La biblioteca fue fundada un día ocho."<<endl;
        return false;
    }
    return true;
}




bool validarPublicacion(Fecha ingreso, Fecha publicacion){

    if(ingreso.getAnio()<publicacion.getAnio()){
        cout<<"El libro ingresó a la biblioteca en el año: "<<ingreso.getAnio()<<endl;
        return false;
    }
    if(ingreso.getAnio()==publicacion.getAnio() && ingreso.getMes()<publicacion.getMes()){
        cout<<"El libro ingresó en el mismo año que se publicó, pero en el mes: "<<ingreso.getMes()<<endl;
        return false;
    }
    if((ingreso.getAnio()==publicacion.getAnio()) && (ingreso.getMes()==publicacion.getMes()) && (ingreso.getDia()<publicacion.getDia())){
        cout<<"El libro ingresó en el mismo año y mes de la publicación, pero en el día: "<<ingreso.getDia()<<endl;
        return false;
    }
    return true;
}


/// con un struct de la libreria ctime devuelve la fecha actual en un objeto de la clase fecha
Fecha devolverFechaActual(){
    Fecha actual;
    time_t t;
    t= time(NULL);
    struct tm *fecha;
    fecha=localtime(&t);
    actual.setDia(fecha->tm_mday);
    actual.setMes(fecha->tm_mon+1);
    actual.setAnio(fecha->tm_year+1900);
    return actual;
}


#endif // CLASEFECHA_H_INCLUDED
