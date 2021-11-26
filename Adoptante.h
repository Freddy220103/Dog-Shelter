//
// Creado por Alfredo Gómez Mendoza A01704189 el 10/11/2021.
//
#ifndef ADOPTANTE_H_
#define ADOPTANTE_H_
#include<string>
using namespace std;

class Adoptante{
private:
    string nombre;
    int edad;
    string perro_adoptado; //nombre del perro que será adoptado


public:
    bool proporcionar_alimento; //variable dónde se guarda si el adoptante puede proporcionarle alimento al perro
    bool ir_alveterinario; //variable dónde se guarda si el adoptante puede llevar al veterinario al perro en cuestión
    bool cumple_criterio; //Variable que determina si el adoptante es capaz de tener al perro, se pone 1 para true, 0 para false
    Adoptante(): nombre("Adoptante"),edad(20), perro_adoptado("Perro adoptado"), proporcionar_alimento(false), ir_alveterinario(false),cumple_criterio(false){};
    //constructores
    Adoptante(string nom, int eda, string perro, bool alimento, bool vet):
            nombre(nom), edad(eda), perro_adoptado(perro), proporcionar_alimento(alimento), ir_alveterinario(vet){};

    //getters de adoptante
    string get_nombre();
    int get_edad();
    string get_perro();
    bool get_alimento();
    bool get_iralvet();
    bool get_cumple();

    //setters de adoptante
    void set_nombre(string);
    void set_edad(int);
    void set_perro(string);
    void set_alimento(bool);
    void set_veterinario(bool);
    void cumple_criterios();

    //Método que checa si se puede adoptar
    string adoptar();
};

string Adoptante::get_nombre(){
    return nombre;
}

int Adoptante::get_edad(){
    return edad;
}

string Adoptante::get_perro(){
    return perro_adoptado;
}
bool Adoptante::get_alimento(){
    return proporcionar_alimento;
}
bool Adoptante::get_iralvet(){
    return ir_alveterinario;
}
bool Adoptante::get_cumple() {
    return cumple_criterio;

}

void Adoptante::set_nombre(string nom){
    nombre = nom;
}

void Adoptante::set_edad(int eda){
    edad = eda;
}

void Adoptante::set_perro(string perro){
    perro_adoptado=perro;
}

void Adoptante::set_alimento(bool alimento) {
    proporcionar_alimento=alimento;
}

void Adoptante::set_veterinario(bool vet) {
    ir_alveterinario=vet;
}
void Adoptante::cumple_criterios( ){
    if (proporcionar_alimento&&ir_alveterinario==true){
        cumple_criterio=true;
    }
    else{
        cumple_criterio=false;
    }
}
string Adoptante::adoptar(){

    string adopcion;
    adopcion="";
    if (cumple_criterio==false){
        adopcion="La adopción no puede realizarse debido a que no se cumplen los requisitos";
    }
    else if (edad<18){
        adopcion="La adopción no puede realizarse debido a que el adoptante es menor de edad";
    }
    else {
        adopcion = "El perro ha sido adoptado con éxito";
    }
    return adopcion;
}
#endif
