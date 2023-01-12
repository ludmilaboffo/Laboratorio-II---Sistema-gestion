#ifndef CLASEDIRECCION_H_INCLUDED
#define CLASEDIRECCION_H_INCLUDED

class Direccion{
    private:
        int numeroCasa;
        char nombreCalle[40];
        char nombreLocalidad[40];
        char nombreProvincia[40];

    public:
        /// constructor
        Direccion (){
            numeroCasa=250;
            strcpy(nombreCalle,"9 de Julio");
            strcpy(nombreLocalidad,"DARREGUEIRA");
            strcpy(nombreProvincia,"BUENOS AIRES");
        }
        void setLocalidad(const char* loc){strcpy(nombreLocalidad,loc);}
        void setNumeroCasa(int num){numeroCasa=num;}
        void setCalle(const char*calle){strcpy(nombreCalle,calle);}
        void setProvincia(const char*prov){strcpy(nombreProvincia,prov);}

        int getNumeroCasa(){return numeroCasa;}
        const char* getCalle(){return nombreCalle;}
        const char* getLocalidad(){return nombreLocalidad;}
        const char* getProvincia(){return nombreProvincia;}

        void CargarDireccion(){

            char calle[40], loc[40], prov[40];
            cout<<"Numero de vivienda: ";
            cin>>numeroCasa;
            while(numeroCasa<0){
                cout<<"Dato inválido, reintente: ";
                cin>>numeroCasa;
            }
            cout<<endl;
            cout<<"Calle: ";
            cargarCadena(calle,40);
            setCalle(calle);
            cout<<endl;
            cout<<"Localidad: ";
            cargarCadena(loc,40);
            setLocalidad(loc);
            cout<<endl;
            cout<<"Provincia: ";
            cargarCadena(prov,40);
            setProvincia(prov);
        }

        void MostrarDireccion(){
            cout<<"Numero de vivienda: "<<numeroCasa;
            cout<<endl;
            cout<<"Calle: "<<nombreCalle;
            cout<<endl;
            cout<<"Localidad: "<<nombreLocalidad;
            cout<<endl;
        }
};

    bool validarProvincia(Direccion aux){

        if(strcmp(aux.getProvincia(),"BUENOS AIRES")!=0){
            cout<<endl;
            cout<<"No puede haber un socio que sea de otra provincia"<<endl;
            cout<<"(Ingrese el nombre en mayusculas)"<<endl;
            return false;
        }
        return true;
    }

#endif // CLASEDIRECCION_H_INCLUDED
