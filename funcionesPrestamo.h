#ifndef FUNCIONESPRESTAMO_H_INCLUDED
#define FUNCIONESPRESTAMO_H_INCLUDED
/*-----------------          P R O T O T I P O S        ------------------------*/

int contarPrestamos();
bool altaPrestamo();
void listarPrestamos();
int prestarLibro();
int prestarSocio();
void bajaLibro(int id);
void mostrarNombreLibro(int id);
void mostrarNombreSocio(int id);
bool listarLibrosPrestados();


/*--------------------------------------------------------------------------------
        Funcion que recibe el ID de un prestamo y devuelve la posicion donde
        se ha encontrado en el registro (de estar activo)
--------------------------------------------------------------------------------*/
int buscarIDprestamo(int ID){

    Prestamos obj;
    int pos=0;

    while(obj.leerDeDisco(pos)){
        if(obj.getIDPrestamo()==ID && obj.getEstadoPrestamo()){
            return pos;
        }
        pos++;
    }
    return -1;
}
/*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de prestamos y cuenta la cantidad de registros
        devolviendo la posicion del ultimo registro que encontró
--------------------------------------------------------------------------------*/

int contarPrestamos(){
    Prestamos obj;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        pos++;
    }
    return pos;
}

 /*--------------------------------------------------------------------------------
        Funcion que asigna un ID autonumerico (desde 1) al prestamo que vaya a dar
        de alta. Hace la carga del registro y lo graba en el registro
        Ademas se asegura que tanto el ID del libro como el ID del socio esten
        ya en sus respectivos registros. Al ID del libro le cambia al estado
        a false pues ya no está disponible
        Ambos mostrar me permiten ver el ID del libro y del socio con cuales se
        realiza la transaccion
--------------------------------------------------------------------------------*/
bool altaPrestamo(){


    Prestamos obj;
    Libros libro;
    int idLib, idSoc, pos, numID, posLib;

    lineaColorCyan();
    cout<<"         ALTA DE PRESTAMO        "<<endl;
    lineaColorCyan();
    cout<<endl;
    pos=contarPrestamos();
    if(pos<0) return false;

    numID=pos+1;
    obj.setIDPrestamo(numID);
    cout<<"ID PRESTAMO "<<numID<<endl;

    idLib=prestarLibro();
    if(idLib<0)return false;
    mostrarNombreLibro(idLib);

    idSoc=prestarSocio();
    if(idSoc<0) return false;
    mostrarNombreSocio(idSoc);


    posLib=buscarIDLibros(idLib);
    libro.leerDeDisco(posLib);
    libro.setDisponibilidad(false);
    libro.modificarEnDisco(posLib);

    obj.setIDSocioPrestado(idSoc);
    obj.setIDLibroPrestado(idLib);

    obj.CargarPrestamo();
    return obj.grabarEnDisco();
}

 /*--------------------------------------------------------------------------------
        Funcion que busca la posicion de un libro segun su ID y la devuelve
        para poder realizar el prestamo
--------------------------------------------------------------------------------*/
int prestarLibro(){
    int ID, pos=0;
    cout<<"ID DEL LIBRO A PRESTAR: ";
    cin>>ID;
    pos=buscarIDLibros(ID);
    Libros lib;
    lib.leerDeDisco(pos);

    if(pos<0 ||!lib.getDisponibilidad()){
        return -1;
    }

    return ID;
}

 /*--------------------------------------------------------------------------------
        Funcion que busca la posicion de un socio segun su ID y la devuelve
        para poder ver su nombre
--------------------------------------------------------------------------------*/
int prestarSocio(){
    int ID, pos=0;

    cout<<"ID DEL SOCIO: ";
    cin>>ID;
    pos=buscarIDSocio(ID);
    if(pos<0){
        return pos;
    }

    return ID;
}
/*--------------------------------------------------------------------------------*/
 void listarPrestamos(){


    Prestamos obj;
    int pos=0;
    lineaColorCyan();
    cout<<"                    PRESTAMOS   "<<endl;
    lineaColorCyan();
    while(obj.leerDeDisco(pos)==1){
       if(obj.getEstadoPrestamo()){
            cout<<endl;
            obj.MostrarPrestamo();
            cout<<"NOMBRE LIBRO: ";
            mostrarNombreLibro(obj.getIDLibroPrestado());
            cout<<endl;
            cout<<"NOMBRE SOCIO: ";
            mostrarNombreSocio(obj.getIDSocioPrestado());
            cout<<endl;
            lineaColorCyan();
       }
        pos++;
    }
 }

/*--------------------------------------------------------------------------------
        Funcion que pide un ID de socio y lo muestra solo si lo ha podido
        encontrar o el estado del registro es true
--------------------------------------------------------------------------------*/

 bool listarPrestamoID(){

  Prestamos obj;
  int pos=0;
  int ID;

   lineaColorCyan();
   cout<<"Ingrese el numero de ID: ";
   cin>>ID;
   pos=buscarIDprestamo(ID);
   if(pos<0) return false;
        cout<<endl;
        obj.leerDeDisco(pos);
        obj.MostrarPrestamo();
        return true;
 }
 /*--------------------------------------------------------------------------------
        Funcion que cambia el estado de un libro no disponible (prestado)
        cuando se devuelve y que a la vez, da de baja dicho registro de
        prestamo
        (Baja logica de registro prestamo + alta logica del libro)
--------------------------------------------------------------------------------*/
 bool devolverLibro(){
    Libros lib;
    Prestamos pres;
    int posLib=0, idLib;
    int pos=0;
    int id;

    lineaColorCyan();
    cout<<"Ingrese el ID prestamo a cancelar: ";
    cin>>id;
    pos=buscarIDprestamo(id);
    if(pos<0) return false;

    pres.leerDeDisco(pos);
    idLib=pres.getIDLibroPrestado();
    posLib=buscarIDlibrosPrestados(idLib);
    if(posLib<0) return false;

    lib.leerDeDisco(posLib);
    lib.setDisponibilidad(true);
    lib.modificarEnDisco(posLib);
    pres.setEstadoPrestamo(false);

    return pres.modificarEnDisco(pos);
 }


/*--------------------------------------------------------------------------------
        Funcion que busca en el archivo de prestamos los libros que esten
        prestados y los lista
--------------------------------------------------------------------------------*/
bool listarLibrosPrestados(){
    int pos=0, id, pos2;
    Prestamos pres;
    Libros lib;
    lineaColorAmarilla();
    cout<<"          LIBROS PRESTADOS    "<<endl;
    lineaColorAmarilla();
    cout<<endl;
    while(pres.leerDeDisco(pos)){
        if(pres.getEstadoPrestamo()){
            id=pres.getIDLibroPrestado(); // get del ID libro en el registro de prestamos
            pos2=buscarIDlibrosPrestados(id); // lo busca en el registro de libros prestado
            if(pos2<0) return false;
            lib.leerDeDisco(pos2); // si existe, hace un leer de disco en esa posicion
            lib.MostrarLibro(); // y muestra el nombre
            cout<<endl;
        }
        pos++;
    }
    return true;
}

#endif // FUNCIONESPRESTAMO_H_INCLUDED
