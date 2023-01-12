#ifndef CLASESOCIOS_H_INCLUDED
#define CLASESOCIOS_H_INCLUDED

const char* RUTA_SOCIOS= "socios.dat";

 class Socios{

    private:

    int IDSocio;
    char nombreSocio[40];
    char apellidoSocio[40];
    Direccion direccionSocio;
    int numeroDeTelefono;
    bool estadoSocio;

    public:

    /// Sets
    void setIDSocio(int id){IDSocio=id;}
    void setNombreSocio(const char*nom){strcpy(nombreSocio,nom);}
    void setApellidoSocio(const char* ap){strcpy(apellidoSocio,ap);}
    void setEstadoSocio(bool es){estadoSocio=es;}
    void setNumeroTelefono(int num){numeroDeTelefono=num;}
    void setDireccionSocio(Direccion dir){direccionSocio=dir;}
    /// Gets
    int getIDsocio(){return IDSocio;}
    const char* getNombreSocio(){return nombreSocio;}
    const char* getApellidoSocio(){return apellidoSocio;}
    Direccion getDireccionSocio(){return direccionSocio;}
    int getTelefonoSocio(){return numeroDeTelefono;}
    bool getEstadoSocio(){return estadoSocio;}

    ///otros metodos
    void CargarSocio();
    void MostrarSocio();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
    ~Socios(){
    }
};


void Socios::CargarSocio(){


    char nombre[40];
    char apellido[40];

    cout<<"ID SOCIO: "<<IDSocio;
    cout<<endl;
    cout<<"NOMBRE: ";
    cargarCadena(nombre,40);
    setNombreSocio(nombre);
    cout<<endl;
    cout<<"APELLIDO: ";
    cargarCadena(apellido,40);
    setApellidoSocio(apellido);
    cout<<endl;
    cout<<"NUMERO DE TELEFONO (2924):";
    cin>>numeroDeTelefono;
    while(numeroDeTelefono<0){
        cout<<"No existe ese numero. Ingrese un numero valido."<<endl;
        cin>>numeroDeTelefono;
    }
    cout<<endl;
    cout<<"DIRECCION: "<<endl;
    direccionSocio.CargarDireccion();
    bool validarDireccion=validarProvincia(direccionSocio);
    while(!validarDireccion){
            cout<<"Vuelva a ingresar: "<<endl;
            direccionSocio.CargarDireccion();
            validarDireccion=validarProvincia(direccionSocio);
    }
    cout<<endl;

    estadoSocio=true;
}


void Socios::MostrarSocio(){

        cout<<"ID SOCIO: "<<IDSocio;
        cout<<endl;
        cout<<"NOMBRE: "<<nombreSocio;
        cout<<endl;
        cout<<"APELLIDO: "<<apellidoSocio;
        cout<<endl;
        cout<<"TELEFONO: "<<numeroDeTelefono;
        cout<<endl;
        cout<<"DIRECCION: "<<endl;
        cout<<endl;
        direccionSocio.MostrarDireccion();
        cout<<endl;
}


bool Socios::leerDeDisco(int pos){

    FILE *p;
    p=fopen(RUTA_SOCIOS,"rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Socios),0);
    bool leyo= fread(this, sizeof(Socios),1,p);
    fclose(p);
    return leyo;
}

bool Socios::grabarEnDisco(){
    FILE *p;

    p=fopen(RUTA_SOCIOS,"ab");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof (Socios),1,p);
    fclose(p);
    return grabo;
}


bool Socios::modificarEnDisco(int pos){
    FILE * p;
    p=fopen(RUTA_SOCIOS,"rb+");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Socios),0);
    bool modifico=fwrite(this, sizeof (Socios),1,p);
    fclose(p);
    return modifico;
 }




#endif // CLASESOCIOS_H_INCLUDED
