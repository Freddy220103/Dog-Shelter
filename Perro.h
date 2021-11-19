//
// Creado por Alfredo Gómez Mendoza el 10 de noviembre de 2021

#include<string>
using namespace std;

class Perro{
private:
    string raza; //raza del perro
    int edad; //edad del perro
    float tam; //tamaño en m del perro
    int enfermo;    //0 si no está enfermo, 1 si lo está.
    int vacunado; //0 si no está vacunado, 1 si lo está.
    int esterilizado; //0 si no está esterilizado, 1 si lo está.
    int sexo; //0 si es macho, 1 si es hembra.
    string convivencia; //con quienes convive
    string energia; //cuanta energía tiene (calmado, juguetón)
    int estatus; //0 si no está adoptado, 1 si lo está.

public:
    ~Perro(){
        cout<<"La info del perro ha sido destruida"<<endl;
    }

    Perro(): raza("desconocido"),edad(0),tam(0.0),sexo(0),energia("Calmado"),
    convivencia("Sólo con perros"),enfermo(0), vacunado(0), estatus(0){}; //constructor

    Perro(string raz, int ed, float ta, int sex, string ener, string conv, int enf, int vac, int ester, int est):
    raza(raz), edad(ed), tam(ta), sexo(sex), energia(ener), convivencia(conv), enfermo(enf), esterilizado(ester), vacunado (vac)
    , estatus(est){};

    //getters de clase Perro
    string get_raza();
    int get_edad();
    float get_tam();
    string get_sexo();
    string get_energia();
    string get_convivencia();
    string get_enfermo();
    string get_vacunado();
    string get_esterilizado();
    string get_estatus();

    //setters para objetos con clase perro
    void set_raza(string);
    void set_edad(int);
    void set_tam(float);
    void set_sexo(int);
    void set_energia(string);
    void set_convivencia(string);
    void set_enfermo(int);
    void set_vacunado(int);
    void set_esterilizado(int);
    void adoptado(int);
};

string Perro::get_raza(){
    return raza;
}

int Perro::get_edad(){
    return edad;
}

float Perro::get_tam(){
    return tam;
}
string Perro::get_sexo(){
    string text1;
    text1="";

    if (sexo==0){
        text1="Es macho";
    }
    else{
        text1="Es hembra";
    }

    return text1;
}
string Perro::get_energia(){
    return energia;
}
string Perro::get_convivencia(){
    return convivencia;
}
string Perro::get_enfermo(){
    string text2;
    text2="";

    if (enfermo==0){
        text2="No esta enfermo";
    }
    else{
        text2="Esta enfermo";
    }
    return text2;
}
string Perro::get_vacunado(){
    string text3;
    text3="";

    if (vacunado==0){
        text3="No esta vacunado";
    }
    else{
        text3="Esta vacunado";
    }
    return text3;
}
string Perro::get_esterilizado(){
    string text4;
    text4="";

    if (esterilizado==0){
        text4="No esta esterilizado";
    }
    else{
        text4="Esta esterilizado";
    }
    return text4;
}

string Perro::get_estatus() {
    string text3;
    text3 = "";

    if (vacunado == 0) {
        text3 = "Todavía no lo adoptan";
    } else {
        text3 = "Adoptado";
    }
    return text3;
    //
}
void Perro::set_raza(string raz){
    raza = raz;
}

void Perro::set_edad(int ed){
    edad = ed;
}

void Perro::set_tam(float ta){
    tam = ta;
}

void Perro::set_sexo(int sex){
    sexo=sex;
}
void Perro::set_energia(string ener){
    energia=ener;
}
void Perro::set_convivencia(string conv){
    convivencia=conv;
}
void Perro::set_enfermo(int enf){
    enfermo=enf;
}
void Perro::set_vacunado(int vac){
    vacunado=vac;
}
void Perro::set_esterilizado(int ester){
    esterilizado=ester;
}
void Perro::adoptado(int est){
    estatus=est;
}