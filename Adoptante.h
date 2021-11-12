#include<string>
using namespace std;

class Adoptante{
private:
    string nombre;
    int edad;
    string perro_adoptado; //nombre del perro que será adoptado
    int proporcionar_alimento; //variable dónde se guarda si el adoptante puede proporcionarle alimento al perro
    int ir_alveterinario; //variable dónde se guarda si el adoptante puede llevar al veterinario al perro en cuestión
    int cumple_criterio; //Variable que determina si el adoptante es capaz de tener al perro, se pone 1 para true, 0 para false

public:
    Adoptante(): nombre("Adoptante"),edad(20), perro_adoptado("Perro adoptado"), proporcionar_alimento(0), ir_alveterinario(0),cumple_criterio(0){};
    //constructores
    Adoptante(string nom, int eda, string perro, int alimento, int vet):
            nombre(nom), edad(eda), perro_adoptado(perro), proporcionar_alimento(alimento), ir_alveterinario(vet){};

    //getters de adoptante
    string get_nombre();
    int get_edad();
    string get_perro();
    int get_alimento();
    int get_iralvet();
    int get_cumple();

    //setters de adoptante
    void set_nombre(string);
    void set_edad(int);
    void set_perro(string);
    void set_alimento(int);
    void set_veterinario(int);
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
int Adoptante::get_alimento(){
    return proporcionar_alimento;
}
int Adoptante::get_iralvet(){
    return ir_alveterinario;
}
int Adoptante::get_cumple() {
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

void Adoptante::set_alimento(int alimento) {
    proporcionar_alimento=alimento;
}

void Adoptante::set_veterinario(int vet) {
    ir_alveterinario=vet;
}
void Adoptante::cumple_criterios( ){
    if (proporcionar_alimento&&ir_alveterinario==1){
        cumple_criterio=1;
    }
    else{
        cumple_criterio=0;
    }
}
string Adoptante::adoptar(){
    string adopcion;
    adopcion="";
    if (cumple_criterio==0){
        adopcion="La adopción no puede realizarse debido a que no se cumplen los requisitos";
    }
    else if (edad<18){
        adopcion="La adopción no puede realizarse debido a que el adoptante es menor de edad";
    }
    else {
        adopcion = "La adopcion cumple los requisitos";
    }
    return adopcion;
}