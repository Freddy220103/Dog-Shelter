//
// Creado por Alfredo Gómez Mendoza A01704189 el 10/11/2021.
// Actualizado el 02/12/21
//
#ifndef ADOPTANTE_H_
#define ADOPTANTE_H_
#include<string>
using namespace std;

class Adoptante{
private:

    //atributos privados
    string nombre;//nombre del adoptante
    int edad; //edad del adoptante
    string perro_adoptado; //nombre del perro que será adoptado


public:
    bool proporcionar_alimento; //variable dónde se guarda si el adoptante puede proporcionarle alimento al perro
    bool ir_alveterinario; //variable dónde se guarda si el adoptante puede llevar al veterinario al perro en cuestión
    bool cumple_criterio; //Variable que determina si el adoptante es capaz de tener al perro, se pone 1 para true, 0 para false

    //constructores
    Adoptante(): nombre("Adoptante"),edad(20), perro_adoptado("Perro adoptado"), proporcionar_alimento(false),
    ir_alveterinario(false),cumple_criterio(false){};

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
    void set_alimento(bool);
    void set_veterinario(bool);
    void cumple_criterios();

    //Métodos únicos

    string adoptar();//Método que checa si se puede adoptar

    void adoptante_info(); /*mediante este método, es más fácil checar la información del adoptante, se genera
                            un resumen en la consola*/

    void cambiarinfo(); /*se cambia la informacion mediante el uso de setters, se genera informacion en la consola
                        para que el usuario pueda meter su informacion de una manera más sencilla*/
};

//definicion de metodos

//getters de adoptante
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


//setters de adoptante
void Adoptante::set_nombre(string nom){
    nombre = nom;
}

void Adoptante::set_edad(int eda){
    edad = eda;
}

void Adoptante::set_alimento(bool alimento) {
    proporcionar_alimento=alimento;
}

void Adoptante::set_veterinario(bool vet) {
    ir_alveterinario=vet;
}

//Métodos especiales
void Adoptante::cumple_criterios( ){
    if (proporcionar_alimento&&ir_alveterinario==true){
        cumple_criterio=true;
    }
    else{
        cumple_criterio=false;
    }
}

//METODOS UNICOS
string Adoptante::adoptar(){

    //Regresamos un string debido a que no nos sirve regresar el valor booleano de cumple_criterio

    //generamos una variable que será regresada mediante el return
    string adopcion;
    adopcion="";

    //mediante un if statement checa si la variable cumple criterios es verdadera o falsa
    //con la decision anterior tomada por el if statement se cambia el texto
    if (cumple_criterio==false){
        adopcion="La adopción no puede realizarse debido a que no se cumplen los requisitos";
    }
    else if (edad<18){
        adopcion="La adopción no puede realizarse debido a que el adoptante es menor de edad";
    }
    else {
        adopcion = "El perro ha sido adoptado con exito";
    }

    //se regresa el texto
    return adopcion;
}

void Adoptante::cambiarinfo(){
    bool cambiarinfo;
    cambiarinfo=0;
    cout << "¿Desea cambiar la informacion del adoptante: " <<
         get_nombre() << " ? Verdadero=1/Falso=0" << endl;

    //se actualiza la variable de la cual depende el if statement
    cin >> cambiarinfo;

    if (cambiarinfo == 1) {

        //variables que nos indicarán si se quiere cambiar la info
        bool cambiaredad, cambiarnombre;
        cambiaredad = 0;
        cambiarnombre = 0;


        //variables dónde entrará la información para luego ser mandadas a su setter respectivo.
        string nombre;
        int edad;
        nombre = "";
        edad = 18;


        cout << "¿Desea cambiar el nombre del adoptante? Verdadero=1/Falso=0" << endl;
        cin >> cambiarnombre;

        //en caso que se quiera cambiar el nombre
        if (cambiarnombre == 1) {
            cout << "¿Cual seria el nuevo nombre?" << endl;
            cin >> nombre;
            set_nombre(nombre);
        }

        cout << "¿Desea cambiar la edad del adoptante? Verdadero=1/Falso=0" << endl;
        cin >> cambiaredad;

        //en caso que se quiera cambiar la edad
        if (cambiaredad == 1) {
            cout << "¿Cual seria la nueva edad?" << endl;
            cin >> edad;
            set_edad(edad);
        }

    }
}

//resumen de la información de adoptante mediante el uso de console communication
void Adoptante::adoptante_info() {
    cout << "\nNombre adoptante: " << get_nombre() << endl;
    cout << "Edad: " << get_edad() << endl;
    cout <<"Perro designado a adoptar: "<<get_perro()<<endl;
    cout<<"\n";
}

#endif
