#ifndef FUNCIONESCONFIGURACIONES_H_INCLUDED
#define FUNCIONESCONFIGURACIONES_H_INCLUDED


/*-----------------          P R O T O T I P O S        ------------------------*/

bool backupLibros();
bool backupPrestamos();
bool backupSocios();
bool restaurarLibros();
bool restaurarPrestamos();
bool restaurarSocios();


/*--------------------------------------------------------------------------------
        Funciones de back up para los diferentes archivos
--------------------------------------------------------------------------------*/


bool backupLibros(){
    FILE *p;
    p=fopen("libros.bkp", "wb"); // crea el archivo vacio
    if(p==NULL) return false;

    Libros obj;
    int pos=0;

    while(obj.leerDeDisco(pos)){ //leo de a un archivo
        fwrite(&obj, sizeof(Libros) ,1, p); // escribo en el archivo bak lo que hay en dat
        pos++;
    }
    fclose(p);
    return true;
}


bool backupSocios(){
    FILE *p;
    p=fopen("socios.bkp", "wb");
    if(p==NULL) return false;
    Socios obj;
    int pos=0;

    while(obj.leerDeDisco(pos)){
        fwrite(&obj, sizeof (Socios), 1, p);
        pos++;
    }
    fclose(p);
    if(pos==0)return false;
    return true;
}

bool backupPrestamos(){
      FILE *p;

    p=fopen("prestamos.bkp", "wb");
    if(p==NULL) return false;

    Prestamos obj;
    int pos=0;

    while(obj.leerDeDisco(pos)){
        fwrite(&obj, sizeof(Prestamos) ,1, p);
        pos++;
    }
    fclose(p);
    if(pos==0) return false;

    return true;
}


/*--------------------------------------------------------------------------------
        Funcion que restauran los archivos .dat copiando lo que tienen los
        archivos de backup en el .dat vacio
--------------------------------------------------------------------------------*/



bool restaurarLibros(){

    FILE *p;
    p=fopen("libros.bkp", "rb");
    if(p==NULL) return false;
    Libros obj;
    bool leyo=0;
    FILE *paux;
    paux=fopen(RUTA_LIBROS, "wb");
    if(paux==NULL)return false;
    while(fread(&obj, sizeof (Libros), 1, p)==1){
        fwrite(&obj, sizeof(Libros) ,1, paux);
        leyo=1;
    }
    fclose(paux);
    fclose(p);
    if(leyo==0)return false;
    return true;
}

bool restaurarSocios(){

    FILE *p;
    p=fopen("socios.bkp", "rb");
    if(p==NULL) return false;
    Socios obj;
    bool leyo=0;
    FILE *paux;
    paux=fopen(RUTA_SOCIOS, "wb");
    if(paux==NULL)return false;
    while(fread(&obj, sizeof (Socios), 1, p)==1){
        fwrite(&obj, sizeof(Socios) ,1, paux);
        leyo=1;
    }
    fclose(paux);
    fclose(p);
    if(leyo==0)return false;
    return true;
}

bool restaurarPrestamos(){
    FILE *p;
    p=fopen("prestamos.bkp", "rb");
    if(p==NULL) return false;
    Prestamos obj;
    bool leyo=0;
    FILE *paux;
    paux=fopen(RUTA_PRESTAMOS, "wb");
    if(paux==NULL)return false;
    while(fread(&obj, sizeof (Prestamos), 1, p)==1){
        fwrite(&obj, sizeof(Prestamos) ,1, paux);
        leyo=1;
    }
    fclose(paux);
    fclose(p);
    if(leyo==0)return false;
    return true;
}


#endif // FUNCIONESCONFIGURACIONES_H_INCLUDED
