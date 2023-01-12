#ifndef CLASEHISTORIAL_H_INCLUDED
#define CLASEHISTORIAL_H_INCLUDED


const char* RUTA_HISTORIAL="historial.dat";

class Historial{

    private:
        int idLibro;
        int idSocio;
        char nombreSocio[40];
        Fecha fechPrestamo;
        char nombreLibro[40];
        bool estado;
    public:
    ///sets
    void setIDSocio(int id){idSocio=id;}
    void setFechaPrestamo(Fecha pres){fechPrestamo=pres;}
    void setNombreSocio(const char*nom){strcpy(nombreSocio,nom);}
    void setNombreLibro(const char* nomLib){strcpy(nombreLibro,nomLib);}
    void setIDLibro(int l){idLibro=l;}
    /// gets
    int getIDsocio(){return idSocio;}
    Fecha getFechaPrestamo(){return fechPrestamo;}
    const char* getNombreSocio(){return nombreSocio;}
    int getIDLibro(){return idLibro;}
    const char* getNombreLibro(){return nombreLibro;}


        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool modificarEnDisco(int pos);


        void mostrarHistorial(){
        cout<<"ID SOCIO: "<<idSocio;
        cout<<endl;
        cout<<"NOMBRE SOCIO: "<<nombreSocio;
        cout<<endl;
        cout<<"ID LIBRO: "<<idLibro;
        cout<<endl;
        cout<<"NOMBRE LIBRO: "<<nombreLibro;
        cout<<endl;
        cout<<"FECHA DEL PRESTAMO: "<<endl;
        fechPrestamo.MostrarFecha();
        cout<<endl;
        }
};


bool Historial::leerDeDisco(int pos){

    FILE *p;
    p=fopen(RUTA_HISTORIAL,"rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Historial),0);
    bool leyo= fread(this, sizeof(Historial),1,p);
    fclose(p);
    return leyo;
}

bool Historial::grabarEnDisco(){
    FILE *p;

    p=fopen(RUTA_HISTORIAL,"ab");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof (Historial),1,p);
    fclose(p);
    return grabo;
}


bool Historial::modificarEnDisco(int pos){
    FILE * p;
    p=fopen(RUTA_HISTORIAL,"rb+");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Historial),0);
    bool modifico=fwrite(this, sizeof (Historial),1,p);
    fclose(p);
    return modifico;
 }



#endif // CLASEHISTORIAL_H_INCLUDED
