#ifndef FUNCIONESSOCIO_H_INCLUDED
#define FUNCIONESSOCIO_H_INCLUDED

/*-----------------          P R O T O T I P O S        ------------------------*/

bool comprobarDeudas(int id);
int buscarIDSocio(int ID);
void listarSocios();
bool listarSociosID();
int contarSocios();
bool altaSocio();
void listarSocios();
bool listarLibrosAdeudados();
bool bajaDeSocio();
bool comprobarDeudas(int id);


/*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de socios y devuelve la posicion donde
        se encontró el id siempre que el estado sea true
--------------------------------------------------------------------------------*/

int buscarIDSocio(int ID){

    Socios objeto;
    int pos=0;

    while(objeto.leerDeDisco(pos)){
        if(objeto.getIDsocio()==ID && objeto.getEstadoSocio()==true){
            return pos;
        }
        pos++;
    }
    return -1;
}
/*--------------------------------------------------------------------------------
        Funcion que pide un ID de socio y lo muestra solo si lo ha podido
        encontrar o el estado del registro es true
--------------------------------------------------------------------------------*/

 bool listarSociosID(){

  Socios objeto;
  int pos=0;
  int ID;

   cout<<"Ingrese el numero de ID: ";
   cin>>ID;
   pos=buscarIDSocio(ID);
   if(pos<0){
        cout<<"No puede mostrarse el registro."<<endl;
        cout<<"Fue eliminado o no existe"<<endl;
        return false;
   }
        cout<<endl;
        objeto.leerDeDisco(pos);
        objeto.MostrarSocio();
        return true;
 }

/*--------------------------------------------------------------------------------
        Funcion que cuenta la cantidad de registros de socio que hay en
        el archivo socios.dat
--------------------------------------------------------------------------------*/

int contarSocios(){
    Socios objeto;
    int pos=0;

    while(objeto.leerDeDisco(pos)){
        pos++;
    }
    return pos;
 }
/*--------------------------------------------------------------------------------
        Funcion que establece un codigo autonumerico (a partir de 1) para los
        socios y hace la carga de la clase para luego grabar en el archivo
--------------------------------------------------------------------------------*/

 bool altaSocio(){

    int numID, pos=0;
    Socios objeto;
    lineaColorRojo();
    cout<<"            ALTA DE SOCIO       "<<endl;
    lineaColorRojo();

    pos=contarSocios();
    if(pos<0) return false;
    numID=pos+1;
    objeto.setIDSocio(numID);
    cout<<"EL NUMERO DE ID ES: "<<numID;
    cout<<endl<<endl;
    objeto.CargarSocio();

    system("cls");
    return objeto.grabarEnDisco();
 }
/*--------------------------------------------------------------------------------
        Funcion que lista todos los reg socios en el archivo (si están dados de alta)
--------------------------------------------------------------------------------*/

 void listarSocios(){

    Socios objeto;
    int pos=0;

    lineaColorRojo();
    cout<<"      LISTADO    DE    SOCIOS   "<<endl;
    lineaColorRojo();
    while(objeto.leerDeDisco(pos)){
        if(objeto.getEstadoSocio()){
            cout<<endl;
            objeto.MostrarSocio();
            lineaColorRojo();
        }
        pos++;
    }
 }

/*--------------------------------------------------------------------------------
        Funcion que recibe el id de un socio y muestra su nombre y apellido
--------------------------------------------------------------------------------*/

void mostrarNombreSocio(int id){

    Socios obj;
    int pos;

    pos=buscarIDSocio(id);
    if(pos>=0){
        obj.leerDeDisco(pos);
        if(obj.getIDsocio()==id){
            cout<<obj.getNombreSocio()<<" "<<obj.getApellidoSocio()<<endl;
            cout<<endl;
        }
     }
 }
/*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de prestamos buscando
    el ID del socio ingresado por teclado para enseñar qué libro adeuda
--------------------------------------------------------------------------------*/

 bool listarLibrosAdeudados(){

    int ID, idLib;
    int pos=0, pos2=0;
    Prestamos pres;
    Libros lib;

    cout<<"INGRESE EL ID DEL SOCIO QUE DESEA BUSCAR: ";
    cin>>ID;
    cout<<endl;
    system("cls");
    lineaColorRojo();
    cout<<"              DEUDAS          "<<endl;
    pos=buscarIDSocio(ID);
    if(pos<0){
        cout<<"No existe el socio ingresado."<<endl;
        return false;
    }
    lineaColorRojo();

    while(pres.leerDeDisco(pos)){
        if(ID==pres.getIDSocioPrestado()){
            idLib=pres.getIDLibroPrestado();
            pos2=buscarIDlibrosPrestados(idLib);
            lib.leerDeDisco(pos2);
            if(!lib.getEstadoLibro()){
                return false;
            }
            cout<<endl<<"Libro adeudado: "<<endl;
            lib.MostrarLibro();
            return true;
        }
        pos++;
    }
        return false;
 }

/*--------------------------------------------------------------------------------
        Funcion que permite dar de baja un socio (baja lógica) pero SOLO si el
        socio ya ha devuelto el libro que debia o no debe ninguno
--------------------------------------------------------------------------------*/
    bool bajaDeSocio(){

    int pos, id;
    Socios obj;
    bool borro;

    cout<<"INGRESE EL ID DEL SOCIO A DAR DE BAJA: ";
    cin>>id;
    while(id<0){
        cout<<"ID INCORRECTO. Vuelva a intentar: ";
        cin>>id;
    }

    pos=buscarIDSocio(id);
    if(pos<0) return false;
    bool debe=comprobarDeudas(id);
    if(debe){
        cout<<"No se puede dar de baja al socio hasta que devuelva el libro adeudado."<<endl;
        return false;
    }

    obj.leerDeDisco(pos);
    cout<<"EL SOCIO A DAR DE BAJA HA SIDO: "<<obj.getNombreSocio()<<" "<<obj.getApellidoSocio()<<endl;
    obj.setEstadoSocio(false);
    borro=obj.modificarEnDisco(pos);
    return borro;
 }

 /*--------------------------------------------------------------------------------
        Funcion que recorre el archivo de prestamos y chequea que el ID socio no
        este registrado en dicho archivo
 --------------------------------------------------------------------------------*/

bool comprobarDeudas(int id){

     Prestamos adeuda;
     int pos2=0;
     while(adeuda.leerDeDisco(pos2)){
        if(id==adeuda.getIDSocioPrestado() && adeuda.getEstadoPrestamo()){
            return true;
        }
        pos2++;
     }
        return false;
}

#endif // FUNCIONESSOCIO_H_INCLUDED
