//
// Creado por Alfredo Gómez Mendoza A01704189 el 10/11/2021.
//
// Actualizado el 02/12/21
#ifndef VOLUNTARIO_H_
#define VOLUNTARIO_H_
#include<string>

using namespace std;

//clase padre
class Voluntario{

    protected://son protected debido a que estos atributos se heredaran

    //atributos básicos que tendrán las clases heredadas o los tipos de voluntario
    string nombre; //nombre del voluntario
    int edad; //edad del voluntario
    int colaborador_experimentado; //¿Tiene experiencia como voluntario? Se pone que sí (1) sólo si ya cumplio más de 40 horas de servicio, sino se pone 0
    int horas_cumplidas;
    int horas_agregadas;
    int telefono;

    //getters de la clase voluntario (se heredarán tambien)
    string get_nombre();
    int get_edad();
    int get_tel();
    int get_horas();

    //setters de voluntario (se heredan tambien)
    void set_nombre(string);
    void set_edad(int);
    void set_horas(int); //se reescribe el numero de horas
    void agrega_horas(int); //Se agregan horas determinadas por el usuario
    void set_tel(int);

public:

    //constructores
    Voluntario(): nombre("Voluntario"),edad(16), colaborador_experimentado(0), horas_cumplidas(0), telefono(442324435){

    };

    Voluntario(string nom, int eda, int exp, int horas, int tel):nombre(nom),edad(eda),colaborador_experimentado(exp),
    horas_cumplidas(horas), telefono(tel){
    };

    //Métodos únicos

    string colab_exp();//se checa la experiencia del colaborador y se cambia de acuerdo a las horas que tiene cumplidas

    void voluntario_info();/*mediante este método, es más fácil checar la información del voluntario, se genera un
                            resumen en la consola*/

    void cambiar_info(); /*se cambia la informacion mediante el uso de setters, se genera informacion en la consola
                           para que el usuario pueda meter su informacion de una manera más sencilla*/
};

//definicion de metodos

//getters
string Voluntario::get_nombre(){
    return nombre;
}

int Voluntario::get_edad(){
    return edad;
}
int Voluntario::get_tel(){
    return telefono;

}
int Voluntario::get_horas(){
    return horas_cumplidas;
}

//setters
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

void Voluntario::agrega_horas(int horas_agregadas){
    horas_cumplidas=horas_cumplidas+=horas_agregadas;
}


string Voluntario::colab_exp() {

    //se guarda el resultado a regresar en la variable text1
    string text1;
    text1 = "";
    //se devuelve un valor string, ya que en este método no nos interesa el número de horas

    //dependiendo del if statement se cambia el texto
    if (horas_cumplidas > 40) {
        text1 = "Tiene experiencia con el refugio";

        //se cambia el estado del voluntario a experimentado
        colaborador_experimentado = 1;
    } else {
        text1 = "No tiene experiencia con el refugio";

        //se cambia el estado del voluntario a que no es experimentado
        colaborador_experimentado = 0;
    }

    //se regresa el texto de arriba
    return text1;
}

void Voluntario::voluntario_info() {

    //se da un resumen mediante el uso de getters y de console outs
    cout<<"Informacion del voluntario"<<endl;
    cout<<"\n";
    cout<<"---------------------------\n"<<endl;
    cout << "Nombre voluntario: " << get_nombre() << endl;
    cout << "Edad: " << get_edad() << endl;
    cout << "# de Telefono: " << get_tel() << endl;
    cout << "Horas cumplidas: " << get_horas()<<endl;
}


/*se pregunta mediante este método si se quiere cambiar la información, en el caso que sí, mediante setters lo
    permite*/
void Voluntario::cambiar_info(){
    bool cambiarinfo;
    cambiarinfo=0;
    cout << "\n¿Desea cambiar la informacion del voluntario: " <<
    get_nombre() << "? Verdadero=1/Falso=0" << endl;

    //se actualiza la variable de la cual depende el if statement
    cin >> cambiarinfo;

        if (cambiarinfo == 1) {

            //variables que nos indicarán si se quiere cambiar la info
            bool cambiartel, cambiaredad, cambiarnombre,cambiarhoras;
            cambiartel = 0;
            cambiaredad = 0;
            cambiarnombre = 0;
            cambiarhoras = 0;


            //variables dónde entrará la información para luego ser mandadas a su setter respectivo.
            string nombre;
            int edad, telefono, c_horas;
            nombre = "";
            edad = 18;
            telefono = 21324;
            c_horas=0;

            cout << "¿Desea cambiar el nombre del voluntario? Verdadero=1/Falso=0" << endl;
            cin >> cambiarnombre;

            //en caso que se quiera cambiar el nombre
            if (cambiarnombre == 1) {
                cout << "¿Cual seria el nuevo nombre?" << endl;
                cin >> nombre;
                set_nombre(nombre);
            }

            cout << "¿Desea cambiar la edad del voluntario? Verdadero=1/Falso=0" << endl;
            cin >> cambiaredad;

            //en caso que se quiera cambiar la edad
            if (cambiaredad == 1) {
                cout << "¿Cual seria la nueva edad?" << endl;
                cin >> edad;
                set_edad(edad);
            }

            cout << "¿Desea cambiar el telefono del voluntario? Verdadero=1/Falso=0" << endl;
            cin >> cambiartel;

            //en caso que se quiera cambiar el telefono
            if (cambiartel == 1) {
                cout << "¿Cual seria el nuevo telefono?" << endl;
                cin >> telefono;
                set_tel(telefono);
            }
            cout << "¿Desea cambiar el numero de horas del voluntario? Verdadero=1/Falso=0" << endl;
            cout<<"Se reescribira el numero de horas en caso de ponerse 1 en vez de agregarle horas al voluntario"
            <<endl;
            cin >> cambiarhoras;

            //en caso que se quiera cambiar las horas totales (no agregar, reescribir)
            if (cambiarhoras == 1) {
                cout << "¿Cual seria el numero de horas que ha cumplido el voluntario?" << endl;
                cin >> c_horas;
                set_horas(c_horas);
            }
        }
}

#endif
