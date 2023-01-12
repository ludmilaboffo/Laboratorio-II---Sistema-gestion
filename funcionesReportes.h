#ifndef FUNCIONESREPORTES_H_INCLUDED
#define FUNCIONESREPORTES_H_INCLUDED

/*-----------------          P R O T O T I P O S        ------------------------*/

void buscarMaximo(Libros * vLibros, int cant);
void buscarMasDeudas(Prestamos *vPrestamos,int cant);
bool crearVectorPrestamos(Prestamos *vPrestamos,int cant);
void buscarMasDeudas(int *vDeudas, int cant);
int cantidadPrestamos(int ID);
int encontrarSocioMasDeudas(int*vec, int tam);


/*--------------------------------------------------------------------------------
        Funcion que crea un vector dinamico de memoria donde almacenar objetos
        de la clase libro con el tamaño que devuelve contarLibros. Setea las
        propiedades con las cuales va a trabajar. Despues llama a buscar el max
        y enseña el libro de mas paginas
--------------------------------------------------------------------------------*/

void libroDisponibleMayor(){

    Libros *vLibros;
    int cant=contarLibros();
    vLibros= new Libros[cant];
    if(vLibros==NULL){
        cout<<"No se pudo asignar memoria";
        return;
    }

    Libros obj;
    for(int i=0; i<cant; i++){
        obj.leerDeDisco(i);
            vLibros[i].setNombreLibro(obj.getNombreLibro());
            vLibros[i].setIDLibro(obj.getIDLibro());
            vLibros[i].setFechaIngreso(obj.getFechaIngreso());
            vLibros[i].setNombreAutor(obj.getnombreAutor());
            vLibros[i].setPublicacion(obj.getPublicacion());
            vLibros[i].setCantidadPaginas(obj.getCantidadPaginas());
            vLibros[i].setEstadoLibro(obj.getEstadoLibro());
            vLibros[i].setDisponibilidad(obj.getDisponibilidad());
    }

    buscarMaximo(vLibros,cant);
    delete [] vLibros; // ejecuta el destructor de cada objeto del vector
}

/*--------------------------------------------------------------------------------
        Funcion que recorre el vector dinamico de objetos libros, se asegura
        que el estado sea true, y evalua cual es el maximo
--------------------------------------------------------------------------------*/
void buscarMaximo(Libros * vLibros, int cant){

    Libros aux;

    int maximo=0;


    for(int i=0; i<cant; i++){
    if(maximo<vLibros[i].getCantidadPaginas() && vLibros[i].getEstadoLibro()){
        maximo=vLibros[i].getCantidadPaginas();
        aux.setNombreLibro(vLibros[i].getNombreLibro());
        aux.setIDLibro(vLibros[i].getIDLibro());
        aux.setFechaIngreso(vLibros[i].getFechaIngreso());
        aux.setNombreAutor(vLibros[i].getnombreAutor());
        aux.setPublicacion(vLibros[i].getPublicacion());
        aux.setEstadoLibro(vLibros[i].getEstadoLibro());
        aux.setDisponibilidad(vLibros[i].getDisponibilidad());
    }
  }
        aux.setCantidadPaginas(maximo);
        lineaColorVerde();
        cout<<"EL LIBRO CON MÁS PÁGINAS ES: "<<endl;
        aux.MostrarLibro();
        cout<<"           CON "<<aux.getCantidadPaginas()<<" PÁGINAS."<<endl;
        lineaColorVerde();
}


/*--------------------------------------------------------------------------------
        Funcion que crea un vector dinamico de tipo entero donde se almacenan
        la cantidad de libros que debe un socio segun su id de socio
        Al final, busca la posicion en el archivo de socios de ese ID con
        mas deudas y muestra quien es
--------------------------------------------------------------------------------*/
void socioConMasDeudas(){
    int cant;
    int *vecPrestamos;
    cant=contarPrestamos();
    vecPrestamos= new int[cant];
    if(vecPrestamos==NULL){
      cout<<"No se pudo asignar la memoria"<<endl;
      return;
    }

    Prestamos obj;
    int pos=0;

    for(int i=0; i<cant; i++){
        obj.leerDeDisco(i);
        vecPrestamos[i]=cantidadPrestamos(obj.getIDSocioPrestado());
    }
    pos=encontrarSocioMasDeudas(vecPrestamos,cant);
    if(pos==0){
        cout<<"No hay deudas vigentes por el momento."<<endl;
        return;
    }
    obj.leerDeDisco(pos);  // con la posicion del socio con mas deudas en el archivo prestamos,
    int ID;
    ID=obj.getIDSocioPrestado();
    Socios reg;
    pos=buscarIDSocio(ID); // busco ese ID en el archivo de socios
    reg.leerDeDisco(pos); // leo el archivo en esa posicion
    lineaColorVerde();
    reg.MostrarSocio();  // muestro el registro de esa posicion
    lineaColorVerde();
    delete [] vecPrestamos;
}

/*--------------------------------------------------------------------------------
        Funcion que recibe un ID, recorre el archivo de prestamos comparando
        ese ID con el de los socios registrados y devuelve la cantidad de
        veces que lo encontro
--------------------------------------------------------------------------------*/

int cantidadPrestamos(int ID){
    Prestamos obj;
    int pos=0, cant=0;

    while(obj.leerDeDisco(pos)){
        if(obj.getIDSocioPrestado()==ID && obj.getEstadoPrestamo()){
            cant++;
        }
        pos++;
    }

    return cant;
}

/*--------------------------------------------------------------------------------
        Funcion que recibe el vector cargado ya con la cantidad de deudas
        por socio, lo recorre, busca la posicion del que es mayor y al encontrarla
        se guarda en posMax. Va a retornar la posicion en el archivo
        del socio con mas deudas
--------------------------------------------------------------------------------*/

int encontrarSocioMasDeudas(int *vec, int tam){

    int posMax=0;


    for(int i=0; i<tam; i++){
        if(vec[i]!=0 && vec[i]>posMax){
            posMax=i;
        }
    }
    return posMax;
}

/*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de libros y busca aquellos
        cuya fecha de ingreso coincida en el año al actual
--------------------------------------------------------------------------------*/

void librosDelAnioActual(){

    int pos=0;
    Libros obj;


    lineaColorVerde();
    cout<<"   LIBROS QUE SE REGISTRARON EN EL 2022: "<<endl;
    lineaColorVerde();
    while(obj.leerDeDisco(pos)){
        if(obj.getEstadoLibro() && obj.getFechaIngreso().getAnio()==2022){
            obj.MostrarLibro();
            lineaColorVerde();
            cout<<endl;
        }
        pos++;
    }
}

#endif // FUNCIONESREPORTES_H_INCLUDED

