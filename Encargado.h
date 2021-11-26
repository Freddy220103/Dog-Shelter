//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
//Parte de herencia
#ifndef ENCARGADO_H_
#define ENCARGADO_H_
#include "Voluntario.h"
class Encargado : public Voluntario {
public:
    Encargado() : Voluntario() {};


    Encargado(string nombre, int edad, int colaborador_experimentado, int horas_cumplidas, int telefono,
              Refugio refugio) : Voluntario(nombre, edad, colaborador_experimentado, horas_cumplidas, telefono,
                                            refugio) {};

    string pagar_deudas();
/*Encargado (string nombre, int edad, int colaborador_experimentado,int horas_cumplidas, int telefono):
            Voluntario(nom, name, age, experience, position){};
    Voluntario(): nombre("Voluntario"),edad(16), colaborador_experimentado(0), horas_cumplidas(0), telefono(442324435){};*/
};

    string Encargado::pagar_deudas() {
        bool cumplir;
        string text;
        text="";
        cout<<"¿El encargado ya pago las deudas?"<<" Verdadero=1/Falso=0"<<endl;
        cin>>cumplir;
        cout<<"";
        if(cumplir==1){
            text="El encargado "+get_nombre()+ " ha pagado las deudas correspondidas";
        }
        else{
            text="El encargado "+get_nombre()+ " no ha pagado las deudas correspondidas";
        }
        return text;
    }
#endif

