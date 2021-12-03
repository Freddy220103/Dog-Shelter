//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
// Actualizado el 02/12/21

//Herencia
#ifndef ENCARGADO_H_
#define ENCARGADO_H_
#include "Voluntario.h"

//se hereda de la clase voluntario
//clase hija
class Encargado : public Voluntario {
public:

    //constructores
    Encargado() : Voluntario() {};

    Encargado(string nombre, int edad, int colaborador_experimentado, int horas_cumplidas, int telefono)
            : Voluntario(nombre, edad, colaborador_experimentado, horas_cumplidas, telefono) {};


    //métodos únicos
    string pagar_deudas(); /*método para checar si el encargado ya pago las deudas, además pregunta si se quieren
                            agregar horas de trabajo en caso que se hayan acabado todas las tareas*/

};

//definicion de métodos

    string Encargado::pagar_deudas() {
        //se pregunta aquí mismo si ya se pagaron las deudas mediante console ins y outs
        bool cumplir;
        string text;
        text="";
        cout<<"¿El encargado ya pago las deudas?"<<" Verdadero=1/Falso=0"<<endl;
        cin>>cumplir;
        cout<<"";

        //dependiendo del booleano, se cambiara el texto que tiene que regresar la función
        if(cumplir==1){
            text="El encargado "+get_nombre()+ " ha pagado las deudas correspondidas\n";


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

                //se agregan las horas que indique el usuario
                cin>>horas;
                agrega_horas(horas);
            }
        }
        else{
            text="El encargado "+get_nombre()+ " no ha pagado las deudas correspondidas\n";
        }
        return text;
    }



#endif
