//
// Creado por Alfredo Gómez Mendoza A01704189 el 10/11/2021.
//
#include <iostream>
#include <string>
#include "Encargado.h"
#include "Limpieza.h"
#include "Alimentacion.h"
#include "Perro.h"
using namespace std;
int main(){
    //Se crea un refugio con datos iniciales
    Refugio huellas_seguras("Huellitas Seguras",30,32,70,90,90);//en este
    //constructor se define el número máximo de perros y voluntarios
    cout<<"Bienvenido a "<<huellas_seguras.get_nombre()<<endl;
    cout<<"El estatus actual del refugio es:"<<endl;//este método nos arroja el estatus básico del refugio
    huellas_seguras.status();
    //Se crea el encargado con datos iniciales
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;
    Encargado gabriel ("Gabriel",22,1,234,
                       22234456,huellas_seguras);
    cout<<"Nombre encargado: "<<gabriel.get_nombre()<<endl; cout<<"Edad: "<<gabriel.get_edad()<<endl;
    cout<<"# de Teléfono: "<<gabriel.get_tel()<<endl;
    //ponemos el método de pagar deudas para cambiar si se realizo la tarea o no
    cout<<gabriel.pagar_deudas()<<endl;
    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    //Se crea un voluntario de otro tipo con datos iniciales
    Limpieza lolito;
    //en caso que el voluntario haya cambiado su número de teléfono
    lolito.set_tel(442345678);
    //agregamos a gabriel al contador de voluntarios de huellas seguras
    //en caso que el voluntario haya cumplido años
    lolito.set_edad(53);
    //en caso que se quiera cambiar el nombre
    lolito.set_nombre("Manuel Fernandez");
    cout<<"El voluntario de limpieza "<<lolito.get_nombre()<<" de edad: "<<lolito.get_edad()
    <<" con el # de Teléfono: "<<lolito.get_tel()<<endl;
    //se checa el estado de sus tareas cumplidas
    cout<<lolito.tareas_cumplidas()<<endl;
    //Se le agrega una hora de trabajo por estar trabajando
    lolito.set_horas(41);
    //Se realiza la función colab exp para ver si el voluntario ya cumplio sus horas de servicio, para pasar a ser
    //colaborador experimentado
    lolito.colab_exp();
    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    //creamos otro tipo de voluntario
    Alimentacion maurice;
    //en caso que el voluntario haya cambiado su número de teléfono
    maurice.set_tel(442435678);
    //agregamos a gabriel al contador de voluntarios de huellas seguras
    //en caso que el voluntario haya cumplido años
    maurice.set_edad(65);
    //en caso que se quiera cambiar el nombre
    maurice.set_nombre("Maurice Duran");
    cout<<"El voluntario de alimentación "<<maurice.get_nombre()<<" de edad: "<<maurice.get_edad()
        <<" con el # de Teléfono: "<<maurice.get_tel()<<endl;
    //se checa el estado de sus tareas cumplidas
    cout<<maurice.tareas_cumplidas()<<endl;
    //Se le agrega una hora de trabajo por estar trabajando
    maurice.set_horas(12);
    //Se realiza la función colab exp para ver si el voluntario ya cumplio sus horas de servicio, para pasar a ser
    //colaborador experimentado
    maurice.colab_exp();
    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;
    //dummy definido para poder crear a rodo (el perro o nuestro objeto de clase perro)
    Adoptante dummy;
    Perro rodo("Cocker", 2, .3,0, "Jugueton",//creamos al perro
               "Con ninos y perros",0, 1, 0,0,dummy,huellas_seguras); //info determinada
    //rodo.anadir_perro(huellas_seguras);
               //setter de adoptante//
    rodo.set_adoptante(dummy);
    //se crea un adoptante
    rodo.crear_adoptante();
    rodo.adoptar();
    Perro rocky; //creamos otro perro
    //Mediante los setters, modificaremos los atributos del perro, (actualizamos la información)
    rodo.set_edad(15); //cambiamos la información determinada del perro rodo
    rodo.set_tam(.4);
    rodo.set_raza("Cocker");
    rodo.set_sexo(0);
    rodo.set_energia("Calmado");
    rodo.set_convivencia("Convive solo con perros");
    rodo.set_enfermo(0);
    rodo.set_vacunado(1);
    rodo.set_esterilizado(1);
    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;
    cout<<"Información del perro"<<endl;
 //Sacamos toda la información del perro que acabamos de cambiar para enseñarsela al usuario
    cout << "Raza:"<<rodo.get_raza()<<"\n";
    cout<<"Edad:"<<rodo.get_edad()<<"\n";
    cout<<"Tamano en m:"<<rodo.get_tam()<<"\n";
    cout<<"Sexo:"<<rodo.get_sexo()<<"\n";
    cout<<"Energia del perro:"<<rodo.get_energia()<<"\n";
    cout<<"¿Con quien convive?:"<<rodo.get_convivencia()<<"\n";
    cout<<"¿Esta enfermo?:"<<rodo.get_enfermo()<<"\n";
    cout<<"¿Esta vacunado?:"<<rodo.get_vacunado()<<"\n";
    cout<<"¿Esta esterilizado?:"<<rodo.get_esterilizado()<<"\n";
    cout<<"Estatus:"<<rodo.get_estatus()<<"\n";


    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;
    bool estatus;
    cout<<"¿Te gustaría checar el estatus del refugio? "<<huellas_seguras.get_nombre()<<" Verdadero=1/Falso=0"<<
    endl;cin>>estatus;
    if (estatus==1){
        cout<<"El estatus actual del refugio es:"<<endl;
        rodo.refugi.status();//se checa el estatus del refugio
    }

    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;
    if (rodo.get_estatus()=="Adoptado"){
        cout<<"¿Deseas destruir la información de Rodo? Verdadero=1, Falso=0"<<endl;
        bool opcion;
        cin>>opcion;
        if (opcion==true){
            rodo.~Perro();
            cout<<"La info del perro ha sido destruida"<<endl;
        }
    else{
        return 0;
    }
    }


}
