//
// Creado por Alfredo Gómez Mendoza A01704189 el 10/11/2021.
// Actualizado el 02/12/21
//

//archivos usados
#include <iostream>
#include <string>
#include "Encargado.h"
#include "Limpieza.h"
#include "Alimentacion.h"
#include "Refugio.h"
using namespace std;


int main(){
    //Se crea un refugio con datos iniciales
    Refugio huellas_seguras("Huellitas Seguras",30,32,70,90,90);//en este
    // en este constructor se define el número máximo de perros y voluntarios predeterminado

    //se dice el nombre del refugio mediante un get
    cout<<"\nBienvenido a "<<huellas_seguras.get_nombre()<<endl;

    cout<<"El estatus actual del refugio es:"<<endl;//este método nos arroja el estatus básico del refugio
    huellas_seguras.status();

    //fin de parte de creación de refugio y de la impresión del estatus

    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;

    //se da la posibilidad de cambiar la info del usuario
    huellas_seguras.cambiarinfo();
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;

    //Se crea el encargado con datos iniciales
    huellas_seguras.agregaEncargado("Gabriel",22,1,234,
                       22234456);

    //se checa la información que tiene el encargado actualmente
    huellas_seguras.encargado.voluntario_info();

    /*se pregunta mediante cambiar.info() si se quiere cambiar la información, en el caso que sí, mediante setters lo
    permite*/
    huellas_seguras.encargado.cambiar_info();

    //ponemos el método de pagar deudas para cambiar si se realizo la tarea o no
    cout<<huellas_seguras.encargado.pagar_deudas()<<endl;

    //fin de parte de encargado

    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;

    //se le asigna un número de voluntario
    int voluntarionum;
    voluntarionum=2;

    //Se crea un voluntario de otro tipo con datos iniciales
    huellas_seguras.agregaLimpieza("Lolito",22,0,234,
                                    22234456,voluntarionum,0,0,0);

    //se muestra la informacion del voluntario tipo limpieza
    huellas_seguras.limp_personal[voluntarionum].voluntario_info();

    //llamamos al método para ver si quiere cambiar la información del voluntario básica
    huellas_seguras.limp_personal[voluntarionum].cambiar_info();

    cout<<huellas_seguras.limp_personal[voluntarionum].tareas_cumplidas()<<endl;
    //Se checa si sus tareas fueron cumplidas, tambien le da la posibilidad al usuario de agregar horas

    //Se realiza la función colab exp para ver si el voluntario ya cumplio sus horas de servicio, para pasar a ser
    //colaborador experimentado
    huellas_seguras.limp_personal[voluntarionum].colab_exp();

    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;


    //creamos otro tipo de voluntario
    int voluntarionum2;
    voluntarionum2=3;

    //constructor con info determinada
    huellas_seguras.agregaAlimentacion("Maurice",43,0,0,
                                   22234456,voluntarionum2,0,0,0);

    //se le da la capacidad al usuario de checar y cambiar los atributos del objeto
    huellas_seguras.alimen_personal[voluntarionum2].voluntario_info();
    huellas_seguras.alimen_personal[voluntarionum2].cambiar_info();

    //Se realiza la función colab exp para ver si el voluntario ya cumplio sus horas de servicio, para pasar a ser
    //colaborador experimentado
    huellas_seguras.alimen_personal[voluntarionum2].colab_exp();

    //se checa el estado de sus tareas cumplidas y da la opcion de agregar horas cumplidas al voluntario
    cout<<huellas_seguras.alimen_personal[voluntarionum2].tareas_cumplidas()<<endl;

    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;

    //dummy definido para poder crear a rodo (el perro o nuestro objeto de clase perro)
    Adoptante dummy;

    //numero de perro
    int perronum;
    //se asigna su valor
    perronum=1;

    //se crea el perro mediante un constructor
    huellas_seguras.agregaPerro("Rodo","Cocker",2,.3,0,"Jugueton",
                                "Con ninos y perros",0,1,0,0,
                                perronum,dummy);

    //checamos la información que tiene el perro
    huellas_seguras.perros[perronum].perroinfo();

    //método con setters y console outs de perro para cambiar su información
    huellas_seguras.perros[perronum].cambiarinfo();

    //se crea un adoptante
    huellas_seguras.perros[perronum].crear_adoptante();

    //se checa la información del adoptante creado para después preguntarle al usuario si desea cambiar la información
    huellas_seguras.perros[perronum].adoptant.adoptante_info();
    huellas_seguras.perros[perronum].adoptant.cambiarinfo();

    //se llama al método adoptar
    huellas_seguras.perros[perronum].adoptar();

    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;

    //se despliega la informacion del perro
    huellas_seguras.perros[perronum].perroinfo();



    //si el perro es adoptado, se le resta una unidad al contador de perros en el objeto refugio
    if(huellas_seguras.perros[perronum].get_estatus()=="Adoptado"){
        huellas_seguras.adoptar_perros();//se quita el perro en caso que se llegue a adoptar
    }

    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;
    /*se da la posibilidad de volver a ver el estado del refugio despues de las modificaciones hechas mediante
    setters y funciones de otras clases*/
    bool estatus;
    cout<<"¿Te gustaria checar el estatus del refugio? "<<huellas_seguras.get_nombre()<<" Verdadero=1/Falso=0"<<
    endl;cin>>estatus;

    if (estatus==1){
        cout<<"El estatus actual del refugio es:"<<endl;
         huellas_seguras.status();//se checa el estatus del refugio
    }

    cout<<" "<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" "<<endl;

    //se da la opcion de destruir la info del perro para liberar memoria
    if (huellas_seguras.perros[perronum].get_estatus()=="Adoptado"){
        cout<<"¿Deseas destruir la informacion de "+huellas_seguras.perros[perronum].get_nombre()+"? Verdadero=1, Falso=0"<<endl;
        bool opcion;
        cin>>opcion;
        if (opcion==true){
            huellas_seguras.perros[perronum].~Perro();
            cout<<"La info. del perro ha sido destruida"<<endl;
        }
    else{
        return 0;
    }
    }


}
