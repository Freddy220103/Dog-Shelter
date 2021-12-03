//
// Creado por Alfredo Gómez Mendoza el 10 de noviembre de 2021
// Actualizado el 02/12/21
#ifndef PERRO_H_
#define PERRO_H_
#include "Adoptante.h"//importamos para la composición
#include<string>
using namespace std;

class Perro{

private:
    //atributos privados
    string nombre; //nombre del perro
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

    Adoptante adoptant;/*adoptante al cual el perro será asignado (es creado mediante un método de Perro)
                        se declara público para poder ver su info en el main)*/
    //destructor
    ~Perro(){
    }

    //constructores
    Perro(): nombre("nombre"),raza("desconocido"),edad(0),tam(0.0),sexo(0),energia("Calmado"),
             convivencia("Solo con perros"),enfermo(0), vacunado(0), estatus(0){};

    Perro(string nom, string raz, int ed, float ta, int sex, string ener, string conv, int enf, int vac, int ester, int est,
          Adoptante adop):nombre(nom),raza(raz), edad(ed), tam(ta), sexo(sex), energia(ener), convivencia(conv), enfermo(enf),
                                       esterilizado(ester), vacunado (vac),estatus(est),adoptant(adop){};

    //getters de clase Perro
    string get_nombre();
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
    void set_nombre(string);
    void set_raza(string);
    void set_edad(int);
    void set_tam(float);
    void set_sexo(int);
    void set_energia(string);
    void set_convivencia(string);
    void set_enfermo(int);
    void set_vacunado(int);
    void set_esterilizado(int);
    void set_adoptante(Adoptante);//se asigna un adoptante al perro
    void set_estatus(int); //aquí terminan los setters y getters


    //METODOS ÚNICOS

    void crear_adoptante();//crea un adoptante al perro

    void adoptar();//le asigna un adoptante al perro

    void perroinfo(); /*mediante este método, es más fácil checar la información de perro, se genera un resumen en la
                        consola*/

    void cambiarinfo();/*se cambia la informacion mediante el uso de setters, se genera informacion en la consola
                        para que el usuario pueda meter su informacion de una manera más sencilla*/

};

//definicion de metodos


//getters de clase Perro
string Perro::get_nombre(){
    return nombre;
}
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
    //se regresa un string, debido a que nos interesa visualizar si es macho o hembra, no ver valores booleanos
    string text1;
    text1="";

    if (sexo==0){
        text1="Es macho";
    }
    else{
        text1="Es hembra";
    }

    return text1;//se regresa el texto tipo string
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
    //se realiza el mismo procedimiento que en get_sexo()
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
    //se realiza el mismo procedimiento que en get_sexo()
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
    //se realiza el mismo procedimiento que en get_sexo()
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
    //se realiza el mismo procedimiento que en get_sexo()
    if (estatus == 0) {
        text3 = "Todavia no lo adoptan";
    } else {
        text3 = "Adoptado";
    }
    return text3;
    //
}

//setters clase de Perro
void Perro::set_nombre(string nom){
    nombre=nom;
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
void Perro::set_estatus(int est){
    estatus=est;
}

void Perro::set_adoptante(Adoptante adop){
    adoptant=adop;
}

//Aquí empiezan métodos especiales

//uso de composición, usamos la clase adoptante
void Perro::crear_adoptante(){
    string nom, perro;
    int edad;

    //se le piden los datos del adoptante al usuario

    cout<<"\nIntroduce el nombre del adoptante"<<endl;
    cin>>nom;//se consiguen mediante console ins
    cout<<"Introduce la edad del adoptante"<<endl;
    cin>>edad;
    cout<<"Introduce el nombre del perro"<<endl;
    cin>>perro;

    /*se le ponen las variables de arriba que introdujo el usuario al constructor
     se crea al adoptante con la información declarada*/
    Adoptante a1(nom, edad, perro,false,false);
    adoptant=a1;
    cout<<"El adoptante fue creado con exito"<<endl; //cout que nos ayuda a saber si se realizo correctamente el método
}


//se usan métodos de adoptante
void Perro::adoptar(){

    //se checa si el adoptante cumple con todos los criterios para adoptar
    bool alimento,vet;
    cout<<"\n";
    cout<<"Proceso de adopcion: "<<endl;
    cout<<"\n";
    cout<<adoptant.get_nombre()<<" de "<<adoptant.get_edad()<<" quiere adoptar a "<<adoptant.get_perro()<<endl;

    //el usuario registra la información en variables para después meterlas en los setters del adoptado
    cout<<"¿El duenio puede brindarle alimento suficiente? (Verdadero=1/Falso=0)"<<endl;
    cin>>alimento;
    cout<<"¿El duenio puede llevarlo al veterinario? (Verdadero=1/Falso=0)"<<endl;
    cin>>vet;

    //se mete la información anterior a los setters de adoptante
    adoptant.set_alimento(alimento);
    adoptant.set_veterinario(vet);

    //se checa si el adoptante cumple los criterios
    adoptant.cumple_criterios();

    //se realiza la funcion de adoptar
    cout<<adoptant.adoptar()<<endl;

    //en base a lo anterior cambiamos el estatus del perro a adoptado o no
    if (adoptant.adoptar()=="El perro ha sido adoptado con exito"){
        set_estatus(1);
    }
    else{
        cout<<"El perro no pudo ser adoptado"<<endl;
    }
}



//mediante los gets, el método perroinfo() los usará para facilitar el acceso a la información de los perros.
//el método usa la consola para enseñar la información desde dónde es usado (el main)
void Perro::perroinfo() {

    //se usan los getters de perro
    cout<<"\n";
    cout<<"Informacion del perro: "<<get_nombre()<<endl;

    //Sacamos toda la información del perro que acabamos de cambiar para enseñarsela al usuario
    cout << "Raza:"<<get_raza()<<"\n";
    cout<<"Edad:"<<get_edad()<<"\n";
    cout<<"Tamano en m:"<<get_tam()<<"\n";
    cout<<"Sexo:"<<get_sexo()<<"\n";
    cout<<"Energia del perro:"<<get_energia()<<"\n";
    cout<<"¿Con quien convive?:"<<get_convivencia()<<"\n";
    cout<<"¿Esta enfermo?:"<<get_enfermo()<<"\n";
    cout<<"¿Esta vacunado?:"<<get_vacunado()<<"\n";
    cout<<"¿Esta esterilizado?:"<<get_esterilizado()<<"\n";
    cout<<"Estatus:"<<get_estatus()<<"\n";
}

//Mediante los setters, modificaremos los atributos del perro, (actualizamos la información)
//se hace de esta manera para que sea más fácil para el usuario escribir lo que quiere cambiar
void Perro::cambiarinfo(){
    bool cambiarinfo;
    cambiarinfo = 0;
    cout << "\n¿Desea cambiar la informacion del perro: " <<
         get_nombre() << " ? Verdadero=1/Falso=0" << endl;

    //se actualiza la variable de la cual depende el if statement
    cin >> cambiarinfo;
    if (cambiarinfo == 1) {

        //variables que nos indicarán si se quiere cambiar la info
        bool cambiarnombre, cambiaredad, cambiarraza,cambiarsexo,cambiarenergia,
        cambiarconv,cambiarenfermo,cambiarvacun,cambiarester,cambiartam;

        //variables dónde entrará la información para luego ser mandadas a su setter respectivo.

        cambiarnombre = 0; cambiaredad = 0; cambiarraza = 0; cambiarsexo=0; cambiarenergia=0;
        cambiarconv=0; cambiarenfermo=0; cambiarvacun=0; cambiarester=0; cambiartam=0;

        string nombre,raza,convivencia,energia;
        int edad,enfermo,esterilizado,sexo,vacunado;
        float tam;
        nombre = ""; raza=""; convivencia="", energia="";
        edad = 0; enfermo=0; esterilizado=0; sexo=0, vacunado=0;
        tam=0.0;

        cout << "¿Desea cambiar el nombre del perro? Verdadero=1/Falso=0" << endl;
        cin >> cambiarnombre;

        //en caso que se quiera cambiar el nombre
        if (cambiarnombre == 1) {
            cout << "¿Cual seria el nuevo nombre?" << endl;
            cin >> nombre;
            set_nombre(nombre);
        }

        cout << "¿Desea cambiar la edad del perro? Verdadero=1/Falso=0" << endl;
        cin >> cambiaredad;

        //en caso que se quiera cambiar la edad
        if (cambiaredad == 1) {
            cout << "¿Cual seria la nueva edad?" << endl;
            cin >> edad;
            set_edad(edad);
        }

        cout << "¿Desea cambiar la raza del perro? Verdadero=1/Falso=0" << endl;
        cin >> cambiarraza;

        //en caso que se quiera cambiar la raza del perro
        if (cambiarraza == 1) {
            cout << "¿Cual seria la nueva raza?" << endl;
            cin >> raza;
            set_raza(raza);
        }

        cout << "¿Desea cambiar la descrpicion de la convivencia que tiene el perro? Verdadero=1/Falso=0" << endl;
        cin >> cambiarconv;

        //en caso que se quiera cambiar la convivencia que presenta el perro
        if (cambiarconv == 1) {
            cout << "¿Cual seria la descripcion?" << endl;
            cout<<"Si agregas espacios a la descripcion, cambialos por un guion bajo (_)";
            cin >> convivencia;
            set_convivencia(convivencia);
        }

        cout << "¿Desea cambiar la descripcion de la energia que tiene el perro? Verdadero=1/Falso=0" << endl;
        cin >> cambiarenergia;

        //en caso que se quiera cambiar la energia que posee el perro
        if (cambiarenergia == 1) {
            cout << "¿Cual seria la descripcion?" << endl;
            cout<<"Si agregas espacios a la descripcion, cambialos por un guion bajo (_)"<<endl;
            cin >> energia;
            set_energia(energia);
        }

        cout << "¿Desea cambiar si el perro esta enfermo? Verdadero=1/Falso=0" << endl;
        cin >> cambiarenfermo;

        //en caso que se quiera cambiar si el perro esta enfermo
        if (cambiarenfermo == 1) {
            cout << "¿El perro esta enfermo? Verdadero=1/Falso=0" << endl;
            cin >> enfermo;
            set_enfermo(enfermo);
        }

        cout << "¿Desea cambiar si el perro esta esterilizado? Verdadero=1/Falso=0" << endl;
        cin >> cambiarester;

        //en caso que se quiera cambiar el estado de su esterilizacion
        if (cambiarester == 1) {
            cout << "¿El perro esta esterilizado? Verdadero=1/Falso=0" << endl;
            cin >> esterilizado;
            set_esterilizado(esterilizado);
        }

        cout << "¿Desea cambiar si el perro esta vacunado? Verdadero=1/Falso=0" << endl;
        cin >> cambiarvacun;

        //en caso que se quiera cambiar el estado de su vacunacion
        if (cambiarvacun == 1) {
            cout << "¿Ya se vacuno el perro? Verdadero=1/Falso=0" << endl;
            cin >> vacunado;
            set_vacunado(vacunado);
        }

        cout << "¿Desea cambiar el sexo del perro? Verdadero=1/Falso=0" << endl;
        cin >> cambiarsexo;

        //en caso que se quiera cambiar el sexo
        if (cambiarsexo == 1) {
            cout << "¿Cual es su sexo? Hembra=1/Macho=0" << endl;
            cin >> sexo;
            set_sexo(sexo);
        }

        cout << "¿Desea cambiar el tamanio del perro? Verdadero=1/Falso=0" << endl;
        cin >> cambiartam;

        //en caso que se quiera cambiar el tamaño
        if (cambiartam == 1) {
            cout << "¿Que tamanio tiene el perro en m" << endl;
            cin >> tam;
            set_tam(tam);
        }

    }



}
#endif
