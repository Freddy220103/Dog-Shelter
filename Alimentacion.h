//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
// Actualizado el 02/12/21
//Parte de herencia
#ifndef ALIMENTACION_H_
#define ALIMENTACION_H_
#include "Voluntario.h"

//se hereda de la clase voluntario
//clase hija
class Alimentacion : public Voluntario{
private:

    //atributos privados
    //estos atributos representan si las tareas se cumplieron o no
    bool perros_alimentados;
    bool limpiar_comederos;
    bool agua_llenado;
public:
    Alimentacion() : Voluntario() {};
    Alimentacion(string nombre, int edad, int colaborador_experimentado, int horas_cumplidas, int telefono,
                 bool perros_alimentados, bool limpiar_comederos, bool agua_llenado) :
    Voluntario(nombre, edad, colaborador_experimentado, horas_cumplidas, telefono) {};

    //métodos para cambiar el estado de cumplimiento de las tareas
    void alimentar();
    void limpieza();
    void llenado_agua();

    /*método para checar si se cumplieron todas las tareas, además pregunta si se quieren
        agregar horas de trabajo en caso que se hayan acabado todas las tareas*/
    string tareas_cumplidas();
};

//definicion de métodos

    void Alimentacion::alimentar(){
        perros_alimentados=0;
        cout<<"¿El voluntario ya alimento a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>perros_alimentados;
    }
    void Alimentacion::limpieza(){
        limpiar_comederos=0;
        cout<<"¿El voluntario ya alimento a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>limpiar_comederos;
    }
    void Alimentacion::llenado_agua(){
        agua_llenado=0;
        cout<<"¿El voluntario ya alimento a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>agua_llenado;
    }

    string Alimentacion::tareas_cumplidas(){
        cout<<"Actividades de: "<<get_nombre()<<endl;

        //se pregunta el estado de las tareas mediante los métodos para despues usar los valores que regresen
        llenado_agua();
        limpieza();
        alimentar();
        string text;
        text="";

        //dependiendo del if statement se cambia el texto a regresar
        if (agua_llenado==1 && limpiar_comederos==1&&perros_alimentados==1){
            text="Las tareas de "+get_nombre()+" han sido completadas";

            int horas;
            horas=0;
            bool opcion;
            opcion=0;

            /*ya que el usuario cumplió con sus tareas, se le pregunta al usuario si quiere agregarle horas de trabajo
         al voluntario*/
            cout<<"¿Desea agregar mas horas cumplidas al voluntario(debido a que el voluntario ya termino sus tareas)? Verdadero=1,Falso=0"
                <<endl;
            cin>>opcion;

            //dependiendo del booleano se le agregaran horas
            if (opcion==1){
                cout<<"Introduzca el numero de horas a agregar"<<endl;
                cin>>horas;
                agrega_horas(horas);//se agregan las horas que indique el usuario
            }
        }
        else{
            text="No se cumplieron todas las tareas";
        }
        return text;
    }
#endif
