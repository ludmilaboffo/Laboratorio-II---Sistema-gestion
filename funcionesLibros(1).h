#ifndef FUNCIONESLIBROS_H_INCLUDED
#define FUNCIONESLIBROS_H_INCLUDED

/*-----------------          P R O T O T I P O S        ------------------------*/

int buscarIDLibros(int ID);
int buscarIDlibrosPrestados(int ID);
int contarLibros();
bool altaLibro();
void listarLibros();
bool listarLibrosPorID();
bool modificarAutor();
void bajaLibro(int id);
void mostrarNombreLibro(int id);
void mostrarNombreLibroPrestado(int id);
void mostrarOrdenado(Libros *vLibros, int cant);
void mostrarVector(Libros *vLibros, int cant);
void ordenarAlfabeticamente();


/*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de LIBROS y devuelve la posicion donde
        se encontró el id siempre que el estado sea true
--------------------------------------------------------------------------------*/

int buscarIDLibros(int ID){

    Libros objeto;
    int pos=0;

    while(objeto.leerDeDisco(pos)){
        if(objeto.getIDLibro()==ID && objeto.getEstadoLibro()){
            return pos;
        }
        pos++;
    }
    return -1;
}


/*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de libros y devuelve la posicion donde
        se encontró el id siempre que el estado sea FALSE
        Sirve para poder buscar los libros que están prestados
--------------------------------------------------------------------------------*/

int buscarIDlibrosPrestados(int ID){

    Libros objeto;
    int pos=0;

    while(objeto.leerDeDisco(pos)){
        if(objeto.getIDLibro()==ID && !objeto.getDisponibilidad() && objeto.getEstadoLibro()){
            return pos;
        }
        pos++;
    }
    return -1;
}


/*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de libros y cuenta la cantidad de registros
        devolviendo la posicion del ultimo registro que encontró
--------------------------------------------------------------------------------*/

int contarLibros(){
    Libros objeto;
    int pos=0;

    while(objeto.leerDeDisco(pos)){
        pos++;
    }
    return pos;
 }


 /*--------------------------------------------------------------------------------
        Funcion que asigna un ID autonumerico al libro que vaya a dar
        de alta. Hace la carga del registro y lo graba en el registro
--------------------------------------------------------------------------------*/

 bool altaLibro(){

    int numID, pos=0;
    Libros objeto;

    lineaColorAmarilla();
    cout<<"          ALTA DE LIBRO       "<<endl;
    lineaColorAmarilla();

    pos=contarLibros();
    if(pos<0) return false;
    numID=pos+1;
    objeto.setIDLibro(numID);
    cout<<"EL NUMERO DE ID ES: "<<numID;
    cout<<endl<<endl;
    objeto.CargarLibro();
    system("cls");

    return objeto.grabarEnDisco();
 }
/*--------------------------------------------------------------------------------
        Funcion que lista todos los libros (estado activo) en el archivo
--------------------------------------------------------------------------------*/

 void listarLibros(){

    Libros objeto;
    int pos=0;

    lineaColorAmarilla();
    cout<<"         LIBROS DISPONIBLES             "<<endl;
    lineaColorAmarilla();
    while(objeto.leerDeDisco(pos)==1){
        if(objeto.getEstadoLibro()){
           cout<<endl;
            objeto.MostrarLibro();
            lineaColorAmarilla();
         }
        pos++;
    }
 }
/*--------------------------------------------------------------------------------
        Funcion que recibe por teclado el ID de un libro y si está disponible
        (estado activo) lo muestra
--------------------------------------------------------------------------------*/
bool listarLibrosPorID(){
    Libros objeto;
    int pos=0;
    int ID;

   lineaColorAmarilla();
   cout<<"Ingrese el numero de ID: ";
   cin>>ID;
   pos=buscarIDLibros(ID);
   if(pos<0){
        cout<<"No puede mostrarse el registro."<<endl;
        cout<<"Fue eliminado o no existe"<<endl;
        return false;
   }
        cout<<endl;
        objeto.leerDeDisco(pos);
        objeto.MostrarLibro();
        return true;
 }

/*--------------------------------------------------------------------------------
        Funcion que permite modificar el autor a un libro disponible (no prestado)
--------------------------------------------------------------------------------*/

bool modificarAutor(){

    int ID, pos;
    Libros objeto;
    char autor[40]={ };

    lineaColorAmarilla();
    cout<<"Ingrese el ID del libro que desea modificar: ";
    cin>>ID;
    pos=buscarIDLibros(ID);

    if(pos<0) return false;
    objeto.leerDeDisco(pos);
    cout<<"Ingrese el nuevo autor: ";
    cargarCadena(autor, 40);
    objeto.setNombreAutor(autor);
    return objeto.modificarEnDisco(pos);
 }
/*--------------------------------------------------------------------------------
        Funcion que da de baja logica un libro
--------------------------------------------------------------------------------*/
  void bajaLibro(int id){
    Libros objeto;
    int pos=0;
    pos=buscarIDLibros(id);
    if(pos>=0){
        objeto.leerDeDisco(pos);
        objeto.setEstadoLibro(false);
        objeto.modificarEnDisco(pos);
    }
 }
/*--------------------------------------------------------------------------------
        Funcion que recibe el ID de un libro, busca su posicion y luego
        hace una lectura del archivo para enseñarlo si está dispobile
--------------------------------------------------------------------------------*/

void mostrarNombreLibro(int id){

    Libros obj;
    int pos=0;

    pos=buscarIDLibros(id);
    if(pos>=0){
        obj.leerDeDisco(pos);
        if(obj.getIDLibro()==id){
            cout<<obj.getNombreLibro()<<endl;
        }
     }
 }

/*--------------------------------------------------------------------------------
        Funcion que recibe el ID de un libro, busca su posicion y luego
        hace una lectura del archivo para enseñarlo si está PRESTADO
--------------------------------------------------------------------------------*/
void mostrarNombreLibroPrestado(int id){

    Libros obj;
    int pos=0;

    pos=buscarIDlibrosPrestados(id);
    if(pos>=0){
        obj.leerDeDisco(pos);
        if(obj.getIDLibro()==id && obj.getEstadoLibro()){
            lineaColorAmarilla();
            cout<<obj.getNombreLibro()<<endl;
            cout<<endl;
        }
     }
 }

/*--------------------------------------------------------------------------------
        Funcion que pide el ID de un libro y realiza la baja lógica del mismo
--------------------------------------------------------------------------------*/

 bool bajaLogicaLibro(){

    int pos, id;
    Libros obj;
    bool borro;

    cout<<"INGRESE EL ID DEL LIBRO A DAR DE BAJA: ";
    cin>>id;
    while(id<0){
        cout<<"ID INCORRECTO. Vuelva a intentar: ";
        cin>>id;
    }

    pos=buscarIDLibros(id);
    if(pos<0){
        cout<<"El libro ha sido dado de baja no existe."<<endl;
        return false;
    }

    obj.leerDeDisco(pos);
    cout<<"EL LIBRO A DAR DE BAJA HA SIDO: "<<obj.getNombreLibro()<<endl;
    obj.setEstadoLibro(false);
    borro=obj.modificarEnDisco(pos);
    return borro;
 }

/*--------------------------------------------------------------------------------
        Funcion que crea un vector dinamico donde almacenar objetos de la
        clase libro con el tamaño que contarLibros devuelve. Setea las propiedades
        que va a  necesitar y luego llama a mostrarOrdenado
--------------------------------------------------------------------------------*/
void ordenarAlfabeticamente(){
    Libros *vLibros;
    int cant=contarLibros();
    vLibros= new Libros[cant];
    if(vLibros==NULL){
        cout<<"No se pudo asignar la memoria"<<endl;
        return;
    }

    Libros obj;
    for(int i=0; i<cant; i++){
        obj.leerDeDisco(i);
            vLibros[i].setNombreLibro(obj.getNombreLibro());
            vLibros[i].setIDLibro(obj.getIDLibro());
            vLibros[i].setEstadoLibro(obj.getEstadoLibro());
            vLibros[i].setDisponibilidad(obj.getDisponibilidad());
    }
    lineaColorVerde();
    cout<<endl<<"        LIBROS DE LA A a la Z "<<endl;
    lineaColorVerde();
    mostrarOrdenado(vLibros,cant);
    delete [] vLibros; // ejecuta el destructor de cada objeto del vector
}

/*--------------------------------------------------------------------------------
        Recorre el vector dinamico realizando burbujeo (lo recorre en dos bucles)
        para asegurarse de evaluar todos los elementos del vector.
        Con strcmpr compara las cadenas y las ordena de A a Z utilizando
        un auxiliar
--------------------------------------------------------------------------------*/

void mostrarOrdenado(Libros * vLibros, int cant){

    Libros aux;
    for(int i=0; i<cant; i++){
     for(int j=0; j<cant;j++){
        if(strcmp(vLibros[i].getNombreLibro(),vLibros[j].getNombreLibro())<0){
            aux.setNombreLibro(vLibros[i].getNombreLibro());
            aux.setIDLibro(vLibros[i].getIDLibro());
            aux.setEstadoLibro(vLibros[i].getEstadoLibro());
            aux.setDisponibilidad(vLibros[i].getDisponibilidad());

            vLibros[i].setNombreLibro(vLibros[j].getNombreLibro());
            vLibros[i].setIDLibro(vLibros[j].getIDLibro());
            vLibros[i].setEstadoLibro(vLibros[j].getEstadoLibro());
            vLibros[i].setDisponibilidad(vLibros[j].getDisponibilidad());

            vLibros[j].setNombreLibro(aux.getNombreLibro());
            vLibros[j].setIDLibro(aux.getIDLibro());
            vLibros[j].setEstadoLibro(aux.getEstadoLibro());
            vLibros[j].setDisponibilidad(aux.getDisponibilidad());
       }
     }
  }
        mostrarVector(vLibros, cant);
}

void mostrarVector(Libros * vLibros, int cant){

  for(int i=0; i<cant; i++){
    if(vLibros[i].getEstadoLibro()==true){
    cout<<endl<<vLibros[i].getNombreLibro()<<endl;
    cout<<"ID: "<<vLibros[i].getIDLibro()<<endl;
    if(!vLibros[i].getDisponibilidad())cout<<"ESTADO:   PRESTADO"<<endl;
    cout<<"ESTADO:   DISPONIBLE"<<endl;
    cout<<endl;
    lineaColorVerde();
    cout<<endl;
    }
  }
}


#endif // FUNCIONESLIBROS_H_INCLUDED
