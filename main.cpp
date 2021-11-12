#include <iostream>
#include <string>
#include "Perro.h"
#include "Voluntario.h"
#include "Adoptante.h"
using namespace std;
int main(){

    //Se crea un voluntario con datos iniciales
    Voluntario gabriel ("Gabriel", 22,0,40,442343434);
    //en caso que el voluntario haya cambiado su número de teléfono
    gabriel.set_tel(442345678);
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

    //se crea un adoptante
    Adoptante benjamin("Carrizales", 22, "Reinaldo", 0,0);
    //info determinada por usuario
    //Mediante los setters, modificaremos los atributos del adoptante
    benjamin.set_nombre("Benjamin Carrizales"); benjamin.set_edad(23);benjamin.set_perro("Rodo");
    //El usuario determinara que cambiar
    benjamin.set_alimento(1);//El usuario que use el programa checa que el adoptante le proporcione alimento
    benjamin.set_veterinario(1);//El usuario que use el programa checa que el adoptante pueda llevar al perro al veterinario
    //Esto lo define mediante 1 o 0, siendo 0 que no cumple y 1 que si.
    cout<<benjamin.get_nombre()<<" de "<<benjamin.get_edad()<<" quiere adoptar a "<<benjamin.get_perro()<<endl;
    cout<<"¿Puede alimentar al perro?: "<<benjamin.get_alimento()<<endl; cout<<"¿Puede llevar al perro al veterinario?: "<<benjamin.get_iralvet()<<endl;
    cout<<benjamin.adoptar()<<endl; //Si es correcto todo el proceso, el usuario puede adoptar
    //Con esto podemos buscar la info de los perros y enseñarselas al usuario
    //pero antes el usuario puede actualizarla en caso que no lo esté
    Perro rodo("Cocker", 2, .3,0, "Jugueton",//creamos al perro
               "Con ninos y perros",0, 1, 0,0); //info determinada
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
    rodo.adoptado(1);

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
    rodo.~Perro();

    return 0;
}

