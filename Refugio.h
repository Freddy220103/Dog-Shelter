//
// Actualizado por Alfredo Gómez Mendoza A01704189 el 02/12/2021.
//
#ifndef REFUGIO_H_
#define REFUGIO_H_
#include<string>
//archivos necesarios para Refugio.h
#include "Perro.h"
#include "Encargado.h"
#include "Limpieza.h"
#include "Alimentacion.h"

using namespace std;

//clase Refugio
class Refugio{
    //atributos privados
private:
    //atributos que guardan información esencial del Refugio creado

    string nombre_ref; //nombre refugio
    int numero_camas; //número de camas
    int numero_perros; //número de perros
    int numero_voluntarios;//numero de voluntarios
    int capacidad_max; //capacidad máxima que tiene el refugio para adoptar perros
    int staff_max; //capacidad máxima del refugio para aceptar voluntarios

public:

    //Objetos creados mediante composición
    //dummy definido para poder crear a rodo (el perro o nuestro objeto de clase perro)

    Perro perros[300]; //array de objetos tipo Perro, con capacidad de 300 objetos.

    Encargado encargado; //encargado creado (se crea solo uno porque solo debe haber uno en vez de varios
    //                      a diferencia de los objetos como Perro y Limpieza que son varios )

    Limpieza limp_personal[100]; //array de objetos tipo Limpieza, con capacidad de 100 objetos.

    Alimentacion alimen_personal[100];//array de objetos tipo Alimentacion, con capacidad de 100 objetos.

    //Constructores con información necesaria por default y con capacidad de ser cambiadas por el usuario

    Refugio(): nombre_ref("Nombre"),numero_camas(100), numero_perros(0),numero_voluntarios(0),capacidad_max(0),
    staff_max(0){};

    Refugio(string nom, int camas, int perros, int voluntarios, int cap_max, int staff):
    nombre_ref(nom),numero_camas(camas),
    numero_perros(perros), numero_voluntarios(voluntarios),capacidad_max(cap_max),staff_max(staff){};

    //getters de los atributos privados de clase Refugio
    string get_nombre();
    int get_num_camas();
    int get_num_perros();
    int get_num_volunt();
    int get_maxcap();
    int get_staff_max();

    //setters de los atributos privados de clase Refugio (usados para cambiar la información registrada)
    void set_nombre(string);
    void set_num_camas(int);
    void set_num_perros(int);
    void set_num_volunt(int);
    void set_max_cap(int);
    void set_staff_max(int);

    //Métodos únicos

    void adoptar_perros(); //quita una unidad de numero_perros cada vez que se llama el método
    void nuevo_perro(); //agrega una unidad de numero_perros cada vez que se llama el método
    void nuevo_volunt(); //agrega una unidad de numero_voluntarios cada vez que se llama el método

    int camas_necesarias(); //regresa el número de camas necesarias para el refugio

    string perros_admitidos(); //regresa un texto que indica si se admiten perros o no

    int staff_necesario(); //regresa el número de voluntarios necesarios para el refugio

    void cambiarinfo(); //usa los setters para cambiar la informacion del refugio de una manera más amigable

    void status(); //mediante el uso de este método, se enseña en la consola el estatus del Refugio

    void agregaPerro(string,string,int,float,int,string,
                     string,int,int,int,int,int,Adoptante); //se crea un perro y se agrega al array perros

    void agregaEncargado(string, int,int, int,int); //se crea un encargado con atributos

    void agregaLimpieza(string, int,int,
                        int,int,int,bool,bool,bool); //se crea un voluntario de tipo Limpieza con sus respectivos
                        //                              atributos y se agrega a su respectivo array.

    void agregaAlimentacion(string, int,int, int,int,
                            int,bool,bool,bool);  //se crea un voluntario de tipo Encargado con sus respectivos
                            //                      atributos y se agrega a su respectivo array.
};

//definicion de metodos


//getters de Refugio
//todos regresan sus respectivos atributos declarados arriba
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

//getters de Refugio
//permiten modificar los atributos privados
void Refugio::set_nombre(string nom){
    nombre_ref=nom;
}
void Refugio::set_num_camas(int camas){
    numero_camas=camas;
}
void Refugio::set_num_perros(int perros){
    numero_perros=perros;
}
void Refugio::set_num_volunt(int voluntarios){
    numero_voluntarios=voluntarios;
}
void Refugio::set_max_cap(int max){
    capacidad_max=max;
}

void Refugio::set_staff_max(int staff) {
    staff_max = staff;
}

//Métodos únicos

void Refugio::adoptar_perros(){
    numero_perros--;//mediante lo anterior, se quita una unidad
}

void Refugio::nuevo_perro(){
    numero_perros++;//mediante lo anterior, se agrega una unidad
}
void Refugio::nuevo_volunt(){
    numero_voluntarios++;//mediante lo anterior, se agrega una unidad
}

int Refugio::camas_necesarias(){

    int cam_necesarias; //declaramos la variable que guardará el número de camas necesarias
    cam_necesarias=numero_camas-numero_perros; /*se resta el numero de camas menos el numero de perros
                                                 esto con el objetivo de ver cuantas camas se necesitan */
    if (cam_necesarias>=0){
        cam_necesarias=0; /*ya que sobran camas y no necesitamos saber ese dato, simplemente igualaremos a 0
 *                              a la variable*/
    }
    else{
        cam_necesarias=cam_necesarias*-1; /*debido a que el número de camas necesarias es un número positivo,
                                            multiplicamos por -1*/
    }
    return cam_necesarias; //regresamos el número de camas necesarias
}


string Refugio::perros_admitidos(){

    string text; //texto que regresará el método
    text=""; //le asignamos un valor tipo string

   if (numero_perros>=capacidad_max){ //si el número de perros es mayor a la capacidad máxima del refugio
       text="Ya no hay mas espacio";
   }
   else{ //si el número de perros es menor a la capacidad máxima
       text="Aun hay espacio";
   }
   return text; //regresa el texto
}
int Refugio::staff_necesario(){

    int volun_necesarios; //declaramos la variable numero de voluntarios necesarios
    volun_necesarios=staff_max-numero_voluntarios; /*restamos la capacidad máxima menos el número de voluntarios
                                                    que tenemos*/
    return volun_necesarios; //regresamos el valor de la variable
}


void Refugio::status(){ /*estatus del refugio (datos cómo número de camas, staff necesario son comunicados al
                         usuario mediante console outs)*/
    cout<<"Nombre refugio: "<<get_nombre();
    cout<<perros_admitidos()<<endl; //llamamos al método para ver si aún se pueden admitir perros
    cout<<"El refugio tiene una capacidad de "<<capacidad_max//capacidad máxima del refugio
    <<" perros, de los cuales se encuentran "<<get_num_perros() //numero de perros que hay
    <<" perros viviendo en el Refugio"<<endl;

    cout<<"El refugio tiene "<<get_num_camas()<<" camas de las cuales se requieren adquirir "/*imprimimos el número de camas
                                                                                en la consola*/
    <<camas_necesarias()<<" camas" //imprimos el número de camas que se requieren
    <<endl;

    cout<<"El refugio requiere "<<staff_necesario()<<" voluntarios"<<endl; /*imprimos el número necesario de
                                    voluntarios que faltan para llegar a la capacidad maxima de voluntarios*/
}

void Refugio::cambiarinfo(){

    bool cambiarinfo;
    cambiarinfo=0;
    cout << "\n¿Desea cambiar la informacion del refugio: " <<
         get_nombre() << "? Verdadero=1/Falso=0" << endl;

    //se actualiza la variable de la cual depende el if statement
    cin >> cambiarinfo;

    if (cambiarinfo == 1) {

        //variables que nos indicarán si se quiere cambiar la info
        bool cambiarcamas, cambiarperros, cambiarvolunt,cambiarmaxcap, cambiarnombre,cambiarmaxstaff;
        cambiarcamas = 0;
        cambiarmaxcap = 0;
        cambiarnombre = 0;
        cambiarmaxstaff = 0;
        cambiarperros=0;
        cambiarvolunt=0;


        //variables dónde entrará la información para luego ser mandadas a su setter respectivo.
        string nombre;
        int perros, camas, maxstaff,maxcap,volunt;
        nombre = "";
        perros = 100;
        camas= 100;
        maxstaff=100;
        maxcap=100;
        volunt=0;

        cout << "¿Desea cambiar el nombre del refugio? Verdadero=1/Falso=0" << endl;
        cin >> cambiarnombre;

        //en caso que se quiera cambiar el nombre del refugio
        if (cambiarnombre == 1) {
            cout << "¿Cual seria el nuevo nombre?" << endl;
            cin >> nombre;
            set_nombre(nombre);
        }

        cout << "¿Desea cambiar el numero de camas? Verdadero=1/Falso=0" << endl;
        cin >> cambiarcamas;

        //en caso que se quiera cambiar el número de camas
        if (cambiarcamas == 1) {
            cout << "¿Cuantas camas hay?" << endl;
            cin >>camas;
            set_num_camas(camas);
        }

        cout << "¿Desea cambiar el numero de voluntario? Verdadero=1/Falso=0" << endl;
        cout<<"Se reescribira el numero de voluntarios totales, en caso de ponerse 1, en vez de agregarle solo un voluntario al refugio"
                <<endl;
        cin >> cambiarvolunt;

        //en caso que se quiera cambiar el número de voluntarios
        if (cambiarvolunt == 1) {
            cout << "¿Cuantos voluntarios hay?" << endl;
            //no se agregan voluntarios, se reescribe el numero de voluntarios
            cin >> volunt;
            set_num_volunt(volunt);
        }

        cout << "¿Desea cambiar la capacidad de voluntarios? Verdadero=1/Falso=0" << endl;
        cin >> cambiarmaxstaff;

        //en caso que se quiera cambiar la capacidad maxima de voluntarios
        if (cambiarmaxstaff == 1) {
            cout << "¿Cual seria la nueva capacidad maxima de voluntarios?" << endl;
            cin >> maxstaff;
            set_staff_max(maxstaff);
        }
        cout << "¿Desea cambiar el numero de perros totales del refugio? Verdadero=1/Falso=0" << endl;
        cout<<"Se reescribira el numero de perros, en caso de ponerse 1, en vez de agregarle solo un perro al refugio"
            <<endl;
        cin >> cambiarperros;

        //en caso que se quiera cambiar las horas totales (no agregar, reescribir)
        if (cambiarperros == 1) {
            cout << "¿Cual seria el numero de perros totales del refugio?" << endl;
            cin >> perros;
            set_num_perros(perros);
        }

        cout << "¿Desea cambiar la capacidad de perros del refugio? Verdadero=1/Falso=0" << endl;
        cin >> cambiarmaxcap;

        //en caso que se quiera cambiar el telefono
        if (cambiarmaxcap == 1) {
            cout << "¿Cual seria la nueva capacidad de perros?" << endl;
            cin >> maxcap;
            set_max_cap(maxcap);
        }
    }
}


void Refugio::agregaPerro(string nombre,string raza,int edad,float tam,int sexo , //atributos necesarios para crear
                          string energia,string convivencia,int enfermo ,int vacunado,// al perro
                          int esterilizado, int estatus, int perronum,Adoptante adop){

    //creamos al perro que será asignado al array de perros, su posición en el array es designada mediante perronum
    perros[perronum] =  Perro(nombre,raza,edad,tam,sexo,energia,
                              convivencia,enfermo,vacunado,esterilizado, estatus,adop);

    nuevo_perro();//llamamos al método para que agregue un perro al contador de perros

}//

void Refugio::agregaEncargado(string nombre, int edad, //atributos del objeto encargado
                               int colaborador_experimentado, int horas_cumplidas, int telefono){

    //creamos al encargado con sus respectivos atributos
    encargado=Encargado(nombre,edad,colaborador_experimentado,horas_cumplidas,telefono);
}
void Refugio::agregaLimpieza(string nombre, int edad, //atributos del objeto limpieza a ser creado
                              int colaborador_experimentado, int horas_cumplidas, int telefono,int voluntarionum,
                              bool perros_banados,bool mantas_limpias,bool limpiar_desechos){

    /*creamos al voluntario de tipo limpieza que será asignado al array de limp_personal,
     su posición en el array es designada mediante voluntarionum*/

    limp_personal[voluntarionum]=Limpieza(nombre,edad, colaborador_experimentado,
                                        horas_cumplidas, telefono,perros_banados,
                                        mantas_limpias,limpiar_desechos);
    nuevo_volunt();//se agrega un voluntario al contador de voluntarios
}

void Refugio::agregaAlimentacion(string nombre, int edad, //atributos del objeto Alimentacion a ser creado
                             int colaborador_experimentado, int horas_cumplidas, int telefono,int voluntarionum,
                             bool perros_alimentados,bool limpiar_comederos,bool agua_llenado){

    /*creamos al voluntario de tipo alimentacion que será asignado al array de alimen_personal,
    su posición en el array es designada mediante voluntarionum*/

    alimen_personal[voluntarionum]=Alimentacion(nombre,edad, colaborador_experimentado,
                                          horas_cumplidas, telefono,perros_alimentados,
                                                limpiar_comederos,agua_llenado);

    nuevo_volunt();//se agrega un voluntario a su respectivo contador
}
#endif
