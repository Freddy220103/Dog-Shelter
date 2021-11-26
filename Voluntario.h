//
// Creado por Alfredo Gómez Mendoza A01704189 el 10/11/2021.
//
#ifndef VOLUNTARIO_H_
#define VOLUNTARIO_H_
#include<string>
#include "Refugio.h"

using namespace std;

class Voluntario{
    protected:
    string nombre; //nombre del voluntario
    int edad; //edad del voluntario
    int colaborador_experimentado; //¿Tiene experiencia como voluntario? Se pone que sí (1) sólo si ya cumplio más de 40 horas de servicio, sino se pone 0
    int horas_cumplidas;
    int telefono;
public:
    Refugio refugi;
    Voluntario(): nombre("Voluntario"),edad(16), colaborador_experimentado(0), horas_cumplidas(0), telefono(442324435),refugi(refugi){
        anadir_voluntario(refugi);
    };

    Voluntario(string nom, int eda, int exp, int horas, int tel, Refugio ref):nombre(nom),edad(eda),colaborador_experimentado(exp),
    horas_cumplidas(horas),telefono(tel),refugi(ref){
        anadir_voluntario(ref);
    };


    string get_nombre();
    int get_edad();
    int get_tel();
    //setters de voluntario
    void set_nombre(string);
    void set_edad(int);
    void set_horas(int);
    void set_tel(int);
    //Función hecha para checar si el voluntario tiene experiencia trabajando previamente o no
    string colab_exp();
    //añade un voluntario al contador del refugio de voluntarios
    void anadir_voluntario(Refugio);
};

string Voluntario::get_nombre(){
    return nombre;
}

int Voluntario::get_edad(){
    return edad;
}
int Voluntario::get_tel(){
    return telefono;

}
void Voluntario::set_nombre(string nom){
    nombre = nom;
}

void Voluntario::set_edad(int eda){
    edad = eda;
}

void Voluntario::set_horas(int horas){
    horas_cumplidas=horas;
}

void Voluntario::set_tel(int tel) {
    telefono=tel;
}
string Voluntario::colab_exp(){
    string text1;
    text1="";
    if (horas_cumplidas>40){
        text1="Tiene experiencia con el refugio";
        colaborador_experimentado=1;
    }
    else{
        text1="No tiene experiencia con el refugio";
        colaborador_experimentado=0;
    }

    return text1;
}

void Voluntario::anadir_voluntario(Refugio ref) {
    refugi=ref;
    refugi.set_num_volunt();
    //ejemplo de agregación
}
#endif
