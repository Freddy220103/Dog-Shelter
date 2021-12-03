//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
// Actualizado el 02/12/21
//Parte de herencia
#ifndef LIMPIEZA_H_
#define LIMPIEZA_H_
#include "Voluntario.h"

//se hereda de la clase voluntario
//clase hija
class Limpieza : public Voluntario{
    private:
    //atributos privados
    //estos atributos representan si las tareas se cumplieron o no
        bool perros_banados;
        bool mantas_limpias;
        bool limpiar_desechos;

    public:
        Limpieza() : Voluntario() {};
        Limpieza(string nombre, int edad, int colaborador_experimentado, int horas_cumplidas, int telefono,
                 bool perros_banados, bool mantas_limpiadas, bool limpiar_desechos) :
                Voluntario(nombre, edad, colaborador_experimentado, horas_cumplidas, telefono) {};

        //métodos para cambiar el estado de las tareas mediante console ins y outs
        void limpiar_desecho();
        void banar_perros();
        void limpiar_mantas();

         /*método para checar si se cumplieron todas las tareas, además pregunta si se quieren
        agregar horas de trabajo en caso que se hayan acabado todas las tareas*/
        string tareas_cumplidas();
};

//definición de métodos

    void Limpieza::limpiar_desecho(){
        limpiar_desechos=0;
        cout<<"¿El voluntario ya limpio los desechos designados? Verdero=1/Falso=0"<<endl;
        cin>>limpiar_desechos;
    }
    void Limpieza::banar_perros(){
        perros_banados=0;
        cout<<"¿El voluntario ya banio a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>perros_banados;
    }
    void Limpieza::limpiar_mantas(){
        mantas_limpias=0;
        cout<<"¿El voluntario ya limpio los desechos designados? Verdero=1/Falso=0"<<endl;
        cin>>mantas_limpias;
    }


    string Limpieza::tareas_cumplidas(){
        cout<<"Actividades de: "<<get_nombre()<<endl;

        //se pregunta el estado de las tareas mediante los métodos para despues usar los valores que regresen
        limpiar_desecho();
        banar_perros();
        limpiar_mantas();
        string text;
        text="";

        //dependiendo del if statement se cambia el texto a regresar
        if (perros_banados==1 &&mantas_limpias==1&&limpiar_desechos==1){
            text="Las tareas de "+get_nombre()+" han sido completadas";


            /*ya que el usuario cumplió con sus tareas, se le pregunta al usuario si quiere agregarle horas de trabajo
          al voluntario*/
            int horas;
            horas=0;
            bool opcion;
            opcion=0;

            cout<<"\n¿Desea agregar mas horas cumplidas al voluntario(debido a que el voluntario ya termino sus tareas)? Verdadero=1,Falso=0"
                <<endl;
            cin>>opcion;

            //dependiendo del booleano se le agregaran horas
            if (opcion==1){
                cout<<"Introduzca el numero de horas a agregar"<<endl;
                cin>>horas;//se agregan las horas que indique el usuario
                agrega_horas(horas);
            }
        }
        else{
            text="No se cumplieron todas las tareas";
        }
        return text;
}
#endif
