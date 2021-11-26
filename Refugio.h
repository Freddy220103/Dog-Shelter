//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
//
#ifndef REFUGIO_H_
#define REFUGIO_H_
#include<string>
using namespace std;

class Refugio{
private:
    string nombre_ref; //nombre refugio
    int numero_camas; //número de camas
    int numero_perros; //número de perros
    int numero_voluntarios;
    int capacidad_max;
    int staff_max;
public:
    Refugio(): nombre_ref("Nombre"),numero_camas(100), numero_perros(0),numero_voluntarios(0),capacidad_max(0),
    staff_max(0){};
    Refugio(string nom, int camas, int perros, int voluntarios, int cap_max, int staff): nombre_ref(nom),numero_camas(camas),
    numero_perros(perros), numero_voluntarios(voluntarios),capacidad_max(cap_max),staff_max(staff){};


    string get_nombre();
    int get_num_camas();
    int get_num_perros();
    int get_num_volunt();
    int get_maxcap();
    int get_staff_max();

    //setters de voluntario
    void set_nombre(string);
    void set_num_camas(int);
    void adoptar_perros();
    void nuevo_perro();
    void set_num_volunt();
    void set_max_cap(int);
    void set_staff_max(int);

    //Funciones únicas
    int camas_necesarias();
    string perros_admitidos();
    int staff_necesario();
    void status();

};

string Refugio::get_nombre(){
    return nombre_ref;
}
int Refugio::get_num_camas(){
    return numero_camas;
}
int Refugio::get_num_perros(){
    return numero_perros;
}
int Refugio::get_num_volunt(){
    return numero_voluntarios;
}
int Refugio::get_maxcap(){
    return capacidad_max;
}
int Refugio::get_staff_max(){
    return staff_max;
}
void Refugio::set_nombre(string nom){
    nombre_ref=nom;
}
void Refugio::set_num_camas(int camas){
    numero_camas=camas;
}
void Refugio::adoptar_perros(){
    numero_perros--;
}

void Refugio::nuevo_perro(){
    numero_perros++;
}
void Refugio::set_num_volunt(){
    numero_voluntarios++;
}
void Refugio::set_max_cap(int max){
    capacidad_max=max;
}
void Refugio::set_staff_max(int staff) {
    staff_max = staff;
}

int Refugio::camas_necesarias(){
    string text;
    int cam_necesarias;
    cam_necesarias=numero_camas-numero_perros;
    cam_necesarias=cam_necesarias*-1;
    return cam_necesarias;
}

string Refugio::perros_admitidos(){
    string text;
    text="";
   if (numero_perros>=capacidad_max){
       text="Ya no hay más espacio";
   }
   else{
       text="Aún hay espacio";
   }
   return text;
}
int Refugio::staff_necesario(){
    int volun_necesarios;
    volun_necesarios=staff_max-numero_voluntarios;
    return volun_necesarios;
}
void Refugio::status(){
    cout<<"El refugio tiene una capacidad de "<<capacidad_max<<" perros, de los cuales se encuentran "<<numero_perros
    <<" perros viviendo en el Refugio"<<endl;

    cout<<"El refugio tiene "<<numero_camas<<" camas de las cuales se requieren "<<camas_necesarias()<<" camas"
    <<endl;
    cout<<"El refugio requiere "<<staff_necesario()<<" voluntarios"<<endl;
}
#endif
