#ifndef CLASELIBROS_H_INCLUDED
#define CLASELIBROS_H_INCLUDED

const char* RUTA_LIBROS="libros.dat";

class Libros{

     int IDlibros;
     Fecha fechaIngresoLibro;
     Fecha publicacion;
     char nombreDelLibro[40];
     char nombreDelAutor[40];
     int cantidadPaginas;
     bool estadoLibro;
     bool disponibilidad;

     public:

     ///Sets
     void setIDLibro(int l){IDlibros=l;}
     void setFechaIngreso(Fecha fech){fechaIngresoLibro=fech;}
     void setNombreLibro(const char* nomLib){strcpy(nombreDelLibro,nomLib);}
     void setNombreAutor(const char* nombAut){strcpy(nombreDelAutor,nombAut);}
     void setCantidadPaginas(int cant){cantidadPaginas=cant;}
     void setEstadoLibro(bool e){estadoLibro=e;}
     void setPublicacion(Fecha pub){publicacion=pub;}
     void setDisponibilidad(bool dis){disponibilidad=dis;}
     ///Gets
    int getIDLibro(){return IDlibros;}
    Fecha getFechaIngreso(){return fechaIngresoLibro;}
    Fecha getPublicacion(){return publicacion;}
    const char* getNombreLibro(){return nombreDelLibro;}
    const char* getnombreAutor(){return nombreDelAutor;}
    bool getEstadoLibro(){return estadoLibro;}
    int getCantidadPaginas(){return cantidadPaginas;}
    bool getDisponibilidad(){return disponibilidad;}


    void CargarLibro();
    void MostrarLibro();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);

    ~Libros(){
    }
};


 void Libros::CargarLibro(){
    char libro[40]={ };
    char autor[40]={ };

    cout<<"LIBRO: ";
    cargarCadena(libro,40);
    setNombreLibro(libro);
    cout<<endl;
    cout<<"AUTOR: ";
    cargarCadena(autor,40);
    setNombreAutor(autor);
    cout<<endl;
    cout<<"CANTIDAD DE PAGINAS: ";
    cin>>cantidadPaginas;
    while(cantidadPaginas<0){
        cout<<"El dato no es válido, vuelva a intentar: ";
        cin>>cantidadPaginas;
    }
    Fecha ingreso;
    cout<<"FECHA DE INGRESO A LA BIBLIOTECA: "<<endl;
    cout<<endl;
    ingreso.Cargar();
    bool validarIngreso=validarCreacion(ingreso);
    while(!validarIngreso){
        cout<<"La fecha de ingreso no puede ser anterior a la creacion de la biblioteca."<<endl;
        cout<<"Vuelva a intentar: "<<endl;
        cout<<endl;
        ingreso.Cargar();
        validarIngreso=validarCreacion(ingreso);
    }
    setFechaIngreso(ingreso);
    cout<<"FECHA DE PUBLICACIÓN DEL LIBRO: "<<endl;
    cout<<endl;
    publicacion.Cargar();
    bool validarPub=validarPublicacion(ingreso,publicacion);
    while(!validarPub){
        cout<<"La fecha de publicación no puede ser posterior a la de ingreso a la biblioteca."<<endl;
        cout<<"Vuelva a intentar: "<<endl;
        cout<<endl;
        publicacion.Cargar();
        validarPub=validarPublicacion(ingreso,publicacion);
    }
    setPublicacion(publicacion);
    estadoLibro=true;
    disponibilidad=true;
 }


 void Libros::MostrarLibro(){

        cout<<"ID LIBRO: "<<IDlibros;
        cout<<endl;
        cout<<"LIBRO: "<<nombreDelLibro;
        cout<<endl;
        cout<<"AUTOR: "<<nombreDelAutor;
        cout<<endl;
        cout<<"CANTIDAD DE PAGINAS: "<<cantidadPaginas;
        cout<<endl;
        cout<<"FECHA DE INGRESO: "<<endl;
        fechaIngresoLibro.MostrarFecha();
        cout<<"FECHA DE PUBLICACION DEL LIBRO: "<<endl;
        publicacion.MostrarFecha();
        cout<<endl;
        if(!disponibilidad){
            cout<<"ESTADO:       PRESTADO"<<endl;
        }
        else{
            cout<<"ESTADO:        DISPONIBLE"<<endl;
        }
 }

 bool Libros::leerDeDisco(int pos){

    FILE *p;
    p=fopen(RUTA_LIBROS,"rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Libros),0);
    bool leyo= fread(this, sizeof(Libros),1,p);
    fclose(p);
    return leyo;
}

bool Libros::grabarEnDisco(){
    FILE *p;

    p=fopen(RUTA_LIBROS,"ab");
    if(p==NULL) return false;
    bool grabo=fwrite(this, sizeof (Libros),1,p);
    fclose(p);
    return grabo;
}


bool Libros::modificarEnDisco(int pos){
    FILE * p;
    p=fopen(RUTA_LIBROS,"rb+");
    if(p==NULL) return false;
    fseek(p,pos*sizeof(Libros),0);
    bool modifico=fwrite(this, sizeof (Libros),1,p);
    fclose(p);
    return modifico;
 }



#endif // CLASELIBROS_H_INCLUDED
