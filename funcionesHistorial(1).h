#ifndef FUNCIONESHISTORIAL_H_INCLUDED
#define FUNCIONESHISTORIAL_H_INCLUDED

/*-----------------          P R O T O T I P O S        ------------------------*/
bool crearHistorial(int idSoc, int idLibro, Fecha prest, int pos);
void establecerHistorial();
void desplegarHistorial();


bool crearHistorial(int idSoc, int idLibro, Fecha prest, int pos){

    Socios soc;
    Historial historial;
    Libros lib;
    int pos2=0, pos3=0;

    historial.leerDeDisco(pos);
    historial.setFechaPrestamo(prest);
    historial.setIDLibro(idLibro);
    historial.setIDSocio(idSoc);
    pos2=buscarIDLibros(idLibro);
    if(pos2<0) return false;
    lib.leerDeDisco(pos2);
    historial.setNombreLibro(lib.getNombreLibro());
    pos3=buscarIDSocio(idSoc);
    if(pos3<0) return false;
    soc.leerDeDisco(pos3);
    historial.setNombreSocio(soc.getNombreSocio());
    historial.setFechaPrestamo(prest);

    return historial.grabarEnDisco();
}

void establecerHistorial(){

    Prestamos prest;
    int pos=0;

    while(prest.leerDeDisco(pos)){
        crearHistorial(prest.getIDSocioPrestado(),prest.getIDLibroPrestado(),prest.getFechaPrestamo(),pos);
     pos++;
    }
}


void desplegarHistorial(){

    char respuesta;

    cout<<"¿Se ha ingresado algún nuevo prestamo desde la última consulta? S/N"<<endl;
    cout<<"Respuesta:  ";
    cin>>respuesta;
    respuesta=toupper(respuesta);
    system("cls");
    if(respuesta=='S'){
        establecerHistorial();
    }

    lineaColorCyan();
    cout<<endl<<"           HISTORIAL DE PRESTAMOS        "<<endl;
    cout<<endl;
    lineaColorCyan();
    Historial his;
    int pos=0;
    while(his.leerDeDisco(pos)){

        his.mostrarHistorial();
         lineaColorCyan();
        pos++;
    }
    cout<<"Muestra finalizada."<<endl;
}
#endif // FUNCIONESHISTORIAL_H_INCLUDED
