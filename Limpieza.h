//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
//Parte de herencia
#ifndef LIMPIEZA_H_
#define LIMPIEZA_H_
#include "Voluntario.h"
class Limpieza : public Voluntario{
    private:
        bool perros_banados;
        bool mantas_limpias;
        bool limpiar_desechos;
    public:
        Limpieza() : Voluntario() {};
        Limpieza(string nombre, int edad, int colaborador_experimentado, int horas_cumplidas, int telefono,
                Refugio refugio, bool perros_banados, bool mantas_limpiadas, bool limpiar_desechos) :
                Voluntario(nombre, edad, colaborador_experimentado, horas_cumplidas, telefono,
                refugio) {};

        void limpiar_desecho();
        void banar_perros();
        void limpiar_mantas();
        string tareas_cumplidas();
};

    void Limpieza::limpiar_desecho(){
        limpiar_desechos=0;
        cout<<"¿El voluntario ya limpió los desechos designados? Verdero=1/Falso=0"<<endl;
        cin>>limpiar_desechos;
    }
    void Limpieza::banar_perros(){
        perros_banados=0;
        cout<<"¿El voluntario ya baño a lo perros que se le designaron? Verdero=1/Falso=0"<<endl;
        cin>>perros_banados;
    }
    void Limpieza::limpiar_mantas(){
        mantas_limpias=0;
        cout<<"¿El voluntario ya limpió los desechos designados? Verdero=1/Falso=0"<<endl;
        cin>>mantas_limpias;
    }
    string Limpieza::tareas_cumplidas(){
        cout<<"Actividades de: "<<get_nombre()<<endl;
        limpiar_desecho();
        banar_perros();
        limpiar_mantas();
        string text;
        text="";
        if (perros_banados==1 &&mantas_limpias==1&&limpiar_desechos==1){
            text="Las tareas de "+get_nombre()+" han sido completadas";
        }
        else{
            text="No se cumplieron todas las tareas";
        }
        return text;
}
#endif
