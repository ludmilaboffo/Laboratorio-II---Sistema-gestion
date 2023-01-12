#ifndef CLASEPRESTAMO_H_INCLUDED
#define CLASEPRESTAMO_H_INCLUDED


const char* RUTA_PRESTAMOS="prestamos.dat";

class Prestamos{

    private:
        int IDSocio;
        int IDLibro;
        int IDPrestamo;
        Fecha fechaPrestamo;
        bool estadoPrestamo;

    public:
        /// Sets
        void setIDSocioPrestado(int soc){IDSocio=soc;}
        void setIDLibroPrestado(int lib){IDLibro=lib;}
        void setIDPrestamo(int pres){IDPrestamo=pres;}
        void setFechaPrestamo(Fecha prestamo){fechaPrestamo=prestamo;}
        void setEstadoPrestamo(bool estado){estadoPrestamo=estado;}
       ///gets
        int getIDSocioPrestado(){return IDSocio;}
        int getIDLibroPrestado(){return IDLibro;}
        int getIDPrestamo(){return IDPrestamo;}
        Fecha getFechaPrestamo(){return fechaPrestamo;}
        bool getEstadoPrestamo(){return estadoPrestamo;}

        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool modificarEnDisco(int pos);
        void CargarPrestamo();
        void MostrarPrestamo();
        ~Prestamos(){
        }
};



void Prestamos::MostrarPrestamo(){
        cout<<"ID PRÉSTAMO: "<<IDPrestamo<<endl;
        cout<<endl;
        cout<<"ID LIBRO: "<<IDLibro<<endl;
        cout<<endl;
        cout<<"ID SOCIO: "<<IDSocio<<endl;
        cout<<endl;
        cout<<"FECHA PRÉSTAMO: "<<endl;
        fechaPrestamo.MostrarFecha();
        cout<<endl;
}

void Prestamos::CargarPrestamo(){


        cout<<"FECHA PRÉSTAMO: "<<endl;
        fechaPrestamo.Cargar();
        bool validarFecha=validarCreacion(fechaPrestamo);
        while(!validarFecha){
            cout<<"La fecha de préstamo no puede ser anterior a la fundación de la biblioteca."<<endl;
            fechaPrestamo.Cargar();
            validarFecha=validarCreacion(fechaPrestamo);
        }
        setFechaPrestamo(fechaPrestamo);
        estadoPrestamo=true;
}

bool Prestamos::leerDeDisco(int pos){

    FILE *p;
    p=fopen(RUTA_PRESTAMOS,"rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Prestamos),0);
    bool leyo= fread(this, sizeof(Prestamos),1,p);
    fclose(p);
    return leyo;
}

bool Prestamos::grabarEnDisco(){
    FILE *p;

    p=fopen(RUTA_PRESTAMOS,"ab");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof (Prestamos),1,p);
    fclose(p);
    return grabo;
}


bool Prestamos::modificarEnDisco(int pos){
    FILE * p;
    p=fopen(RUTA_PRESTAMOS,"rb+");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Prestamos),0);
    bool modifico=fwrite(this, sizeof (Prestamos),1,p);
    fclose(p);
    return modifico;
 }




#endif // CLASEPRESTAMO_H_INCLUDED
