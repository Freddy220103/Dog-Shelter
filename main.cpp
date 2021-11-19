//
// Creado por Alfredo Gómez Mendoza A01704189 el 10/11/2021.
//
#include <iostream>
#include <string>
#include "Voluntario.h"
using namespace std;
int main(){
    //Se crea un refugio con datos iniciales
    Refugio huellas_seguras("Huellitas Seguras",30,32,70,90,90);//en este
        //constructor se define el número máximo de perros y voluntarios

    //Se crea un voluntario con datos iniciales
    Voluntario gabriel ("Gabriel", 22,0,40,442343434,huellas_seguras);
    //en caso que el voluntario haya cambiado su número de teléfono
    gabriel.set_tel(442345678);
    //agregamos a gabriel al contador de voluntarios de huellas seguras
    gabriel.anadir_voluntario();
    //en caso que el voluntario haya cumplido años
    gabriel.set_edad(23);
    //en caso que se quiera cambiar el nombre
    gabriel.set_nombre("Juan Gabriel");
    cout<<"Nombre voluntario: "<<gabriel.get_nombre()<<endl; cout<<"Edad: "<<gabriel.get_edad()<<endl; cout<<"# de Teléfono: "<<gabriel.get_tel()<<endl;

    //Se le agrega una hora de trabajo por estar trabajando
    gabriel.set_horas(41);
    //Se realiza la función colab exp para ver si el voluntario ya cumplio sus horas de servicio, para pasar a ser
    //colaborador experimentado
    gabriel.colab_exp();

    //dummy definido para poder crear a rodo (el perro o nuestro objeto de clase perro)
    Adoptante dummy;
    Perro rodo("Cocker", 2, .3,0, "Jugueton",//creamos al perro
               "Con ninos y perros",0, 1, 0,0,dummy,huellas_seguras); //info determinada
    //setter de adoptante
    rodo.anadir_perro(); //se usa esta función cada vez que se crea un perro, así se contabiliza en el atributo del
    //objeto refugio
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

    //informacion final antes de cerrar el programa
    cout<<"¿Se ocupan camas?"<<endl;
    cout<<huellas_seguras.camas_necesarias()<<endl;
    cout<<"¿Hay espacio para más perros?"<<endl;
    cout<<huellas_seguras.perros_admitidos()<<endl;
    cout<<"¿Se requiere más voluntarios?"<<endl;
    cout<<huellas_seguras.staff_necesario()<<endl;

    cout<<"¿Deseas destruir la información de Rodo? Verdadero=1, Falso=0"<<endl;
    bool opcion;
    cin>>opcion;
    if (opcion==true){
        rodo.~Perro();
    }

    return 0;
}

