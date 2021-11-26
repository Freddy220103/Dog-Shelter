//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
//Parte de herencia
#ifndef ALIMENTACION_H_
#define ALIMENTACION_H_
#include "Voluntario.h"
class Alimentacion : public Voluntario{
private:
    bool perros_alimentados;
    bool limpiar_comederos;
    bool agua_llenado;
public:
    Alimentacion() : Voluntario() {};
    Alimentacion(string nombre, int edad, int colaborador_experimentado, int horas_cumplidas, int telefono,
            Refugio refugio, bool perros_banados, bool mantas_limpiadas, bool limpiar_desechos) :
    Voluntario(nombre, edad, colaborador_experimentado, horas_cumplidas, telefono,
            refugio) {};

    void alimentar();
    void limpieza();
    void llenado_agua();
    string tareas_cumplidas();
};
    void Alimentacion::alimentar(){
        perros_alimentados=0;
        cout<<"¿El voluntario ya alimentó a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>perros_alimentados;
    }
    void Alimentacion::limpieza(){
        limpiar_comederos=0;
        cout<<"¿El voluntario ya alimentó a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>limpiar_comederos;
    }
    void Alimentacion::llenado_agua(){
        agua_llenado=0;
        cout<<"¿El voluntario ya alimentó a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>agua_llenado;
    }

    string Alimentacion::tareas_cumplidas(){
        cout<<"Actividades de: "<<get_nombre()<<endl;
        llenado_agua();
        limpieza();
        alimentar();
        string text;
        text="";
        if (agua_llenado==1 && limpiar_comederos==1&&perros_alimentados==1){
            text="Las tareas de "+get_nombre()+" han sido completadas";
        }
        else{
            text="No se cumplieron todas las tareas";
        }
        return text;
    }
#endif
