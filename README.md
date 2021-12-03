# TC1033.2 Adopción de perros.
Proyecto desarrollado durante la clase de TC1033.2. 
Desarrollado por Alfredo Gómez Mendoza A01704189.
Última versión creada el 02/12/21

## Contexto

El proyecto consitirá en apoyar refugios de perros como el de Huellitas Seguras de Querétaro. Muchos de estos refugios para perros buscan dar en adopción a los perros que se encuentran viviendo ahí. Para facilitar el proceso, mediante sus redes o eventos, ponen en adopción a sus perros. Para que el proceso de adopción sea más efectivo, los refugios guardan la información de cada perro para después enseñarle esta información al público. Sin embargo, muchas veces esta información se llega a perder o no se modifica adecuadamente, siendo una de las posibles consecuencias, inconsistencias en la información guardada de los perros.

Otro factor importante en estos refugios es la de los voluntarios. En muchos refugios caninos hay muchos colaboradores trabajando, causando una necesidad de guardar la información de quienes están trabajando para usarla en caso de emergencia o para contactar a los voluntarios. Es por esto que el código también tiene integrado una clase de Voluntario para poder registrar todo esto. 

Como muchos voluntarios son nuevos en el lugar, el usuario puede checar que voluntarios tienen experiencia trabajando en el refugio. Una de las utilidades de esto, es que en vez de instruir voluntario por voluntario, puede hacer que los voluntarios con experiencia instruyan a los nuevos colaboradores del lugar. 

Otro problema con los voluntarios es que muchos de estos no cumplen sus tareas. Para esto, el usuario puede guardar en el código, mediante booleanos, si el usuario cumplió sus tareas o no.

Por parte de la adopción, el proceso llega a ser tardado o cansado. Esto se debe a que el refugio tiene que estar totalmente seguro si el adoptante tiene los criterios necesarios para adoptar. La solución que viene en el código es la de checar el estatus del adoptante mediante métodos y decirnos si el adoptante es capaz de adoptar o no.

## ¿A quién va dirigido?

El usuario que manejaría el proyecto sería alguna persona con algún conocimiento de programación que este encargado del registro o sea alguien que maneje o lidere el refugio. Debido a que el programa no tiene una interfaz gráfica, el usuario que haga uso del código, debe tener algún conocimiento de programación para hacer un mejor uso del código.

## Funcionalidad

Debido a las problemáticas presentadas, he creado este programa en C++ para tener un control más eficaz y elaborado. Siendo la función principal la de guardar información del Refugio, sus voluntarios, adoptantes y sus perros. Por ejemplo, en el caso de los perros, se guardan datos (atributos en clases) como  raza, tamaño, edad, si esta enfermo o no, si esta vacunado o no, si esta esterilizado, sexo, si convive con otros (perros, animales o niños), nivel de energía (calmado, juguetón). 

Para accesar a la información registrada de cada clase (Refugio, Perro, Adoptante, Voluntario y sus clases hijas), se usan métodos que recuperan la información de los objetos (como perro_info(), voluntario_info(), estatus(), etc). Estos métodos usan getters de sus clases y se comunican a traves de la consola para poder obtener la información de una manera más sencilla y amigable.

Sin embargo el código tiene la posibilidad de realizar otras funciones mediante el uso de métodos. 

El refugio tiene métodos los cuales tienen la capacidad de decirle al usuario si se necesitan más camas para los perros, si hay aún espacio para albergar más perros y si se alcanza el límite de voluntarios. 

La clase Perro, además de dejarnos guardar información, nos permite crear un adoptante para cuando el usuario comience el proceso de adopción. Siendo este adoptante creado con atributos o datos (nombre, edad) definidos por el usuario mediante constructores y la clase cambiarinfo() [esta clase cambia los atributos del objeto mediante el uso de los setters de la clase a la cual pertenece el objeto]. También, al momento de crear al adoptante mediante la composición, se asigna el adoptante al perro en cuestión.

La clase Voluntario, habilita al usuario guardar la información de sus voluntarios como el nombre, el teléfono, la edad y su experiencia. Esto es definido mediante constructores y editado mediante la funcion cambiarinfo() [que usa los setters de su clase perteneciente]. Siendo el dato de las horas cumplidas un atributo importante para el método colab_exp(). Con este método, se puede checar si el voluntario creado, tiene la experiencia para ser considerado como un voluntario experimentado.  El código considera a un voluntario experimentado cuando tiene más de 40 horas de servicio en el refugio cumplidas, siendo la misma función la que cambia este estatus. Sin embargo, el usuario que use el código tiene que registrar las horas cumplidas mediante la función cambiarinfo() o agregarhoras() y llamar a la función de colab_exp.

Para poder asignar tareas, mediante herencia proveniente de la clase Voluntario, se crean tres tipos de voluntario (Encargado, Limpieza y Alimentacion). Esto es realizado para poder monitorear que las tareas del refugio si se cumplan. El encargado o usuario puede modificar el estatus del cumplimiento de estas tareas mediante métodos propios de las clases heredadas o hijas.

A fin de agilizar el proceso de adopción, el código crea un objeto de la clase adoptante mediante el uso de la clase perro, siendo de esta manera más fácil de asignar un adoptante a un perro o cambiarlo. Otra ventaja de usar la composición de perro y adoptante, es que sólo se crea un adoptante cuando el perro existe, dandonos la posibilidad de registrar información sólo cuando un objeto perro sea creado.

Mediante métodos, el estatus del adoptante es determinado y mediante la consola le hace saber al usuario si el adoptante es capaz de adoptar o no.


En el caso que el programa tenga mucha información acumulada, la clase perro le permite al usuario poder elegir si eliminar la información de los perros que ya no necesite (eliminando el objeto creado previamente por el usuario mediante un destructor).


## ¿Cómo funciona?

La persona que corra este código, tiene la posibilidad de crear objetos en el main.cpp, siendo el primer objeto creado el refugio mismo. Al momento que este refugio sea creado, se le asignaran valores a sus atributos mediante el uso de un constructor. En el código, el objeto de clase Refugio es nombrado "huellas_seguras". Por consiguiente el código enseña la información vital que el usuario tiene que saber mediante el método estatus. En el caso que se quiera modificar la información del Refugio, se puede usar el método cambiarinfo().

Posteriormente se crea un voluntario (gabriel) mediante el uso de la composición. Siendo los objetos de la clase Voluntario un componente de la clase Refugio. Mediante el método creado en la clase Refugio, agregaEncargado, se llama a un constructor para crear al objeto gabriel.  Se crea de esta manera para poder manejar la información de la clase Voluntario de una mejor manera. Además, este proceso nos ayuda a crear objetos más fácilmente. Siendo este método de creación de objetos aplicado también para la clase Perro.

Después de haber creado al objeto, se llaman las funciones de voluntario_info() y cambiar_info() para visualizar la información del objeto, para posteriormente dar la oportunidad de cambiar la información asignada al usuario. Debido a que el objeto Gabriel es el encargado, se puede suponer que ya es un voluntario experimentado, por esto no se llama a la funcion colab_exp(). 

checar si el usuario ya es un voluntario experimentado. También se llama a la función anadir_voluntario(), que agrega una unidad al contador (numero_voluntarios)  que tiene el objeto huellas_seguras para poder usarlo en staff_necesario(). 

Para poder tener diferentes tipos de voluntarios, mediante la herencia se crean nuevas clases que designan nuevos atributos y tareas a los objetos heredados de la clase Voluntario(). En el código podemos ver tres tipos (Alimentacion, Limpieza y Encargado). 

A pesar de ser clases heredadas, Encargado, Limpieza y Alimentacion presentan algunas similitudes. Siendo la más notable el cambio de tareas debido al tipo de voluntario que son. Otra diferencia se presenta durante la creación de los objetos de tipo Limpieza y Alimentacion, que a diferencia de los objetos Encargado, al ser creados mediante los métodos AgregaLimpieza() y AgregaAlimentacion(), llaman a la función nuevo_volunt() que agrega un voluntario al contador de número de voluntarios totales encontrado en la clase Refugio. 

A diferencia de la clase Encargado, que lo más recomendable es que el código sólo tenga un objeto de este tipo, los objetos de tipo Limpieza y Alimentacion, son objetos que son creados y aniadidos a una lista que guarda sus tipos de objeto respectivamente. Siendo esto un fenómeno que también sucede con la clase Perro.

Después de haber creado los objetos heredados de Voluntario, dar la opción de mostrar su información y de cambiar la información mediante el uso del método cambiarinfo(), se procede a llamar sus funciones respectivas pagar_deudas() y tareas_cumplidas() para ver si los voluntarios han cumplido todas sus tareas asignadas. En el caso que los voluntarios creados, hayan cumplido sus tareas, se da la opción de agregar las horas de trabajo que determine la persona que use el código mediante console ins y outs.

Para crear el perro (rodo), se crea un adoptante dummy o de prueba. Este dummy es definido junto a todos los atributos pertenecientes al constructor perro llamado por el método agregaPerro() de la clase Refugio. Así como los voluntarios tipo Limpieza y Alimentacion llaman a la funcion nuevo_volunt, los objetos tipo perro llaman a la función anadir_perro(), que agrega una unidad al contador (numero_perros) que tiene el objeto huellas_seguras (de tipo Refugio) para poder usarlo posteriormente en su método perros_admitidos(). 

Después de haber creado el objeto de la clase Perro, se despliega la información de esta (los atributos que tiene) y se llama a la función cambiarinfo (que funciona mediante el uso de setters) para dar la posibilidad de cambiar la información del perro. Para comenzar el proceso de adopción, se crea un objeto de tipo Adoptante con atributos que el usuario decide ingresar y se le asigna al perro. 

El main después de esto, llama a la función adoptante_info() y cambiar info(), para desplegar la información y dar la opción de poder cambiar la información del adoptante en caso de algún error cometido.

Con lo anterior, el código llama a el método de Perro "adoptar()", con el propósito de realizar el proceso de adopción. Al final, se tiene que desplegar en la consola si se puede adoptar al perro o no (esto es determinado por métodos y atributos de la clase Adoptante, los cuales podemos acceder debido a la composición que tiene Adoptante con la clase Perro). En el caso que se adopte el contador de perros del refugio disminuirá.

Seguidamente del último proceso, el código cambia la información del perro creado (rodo), mediante el uso de setters en un método creado en la clase Perro y despliega toda su información mediante el uso de perroinfo(). 

Por último el código despliega de nuevo la información obtenida mediante el método de status() del objeto huellas_seguras, si faltan camas, hay espacio para perros y si hay espacio para que más voluntarios se anoten. Es importante considerar que esta información fue cambiando durante el transcurso del código, debido a que se aceptaron nuevos voluntarios y  perros fueron adoptados como ingresados en el refugio.


## ¿Para qué es bueno el programa? ¿Áreas de oportunidad?

El programa es bueno para registrar información de objetos. Sin embargo, un área de oportunidad o a considerar es que el usuario, al no tener una IDE, tiene que registrar todo en el código y la consola, siendo esto una tarea compleja o frustante para algunas personas. Sin embargo, durante las últimas versiones del código, se implementaron métodos en las clases que integran directamente los setters o getters para desplegar/registrar información de una manera más eficaz y amigable. Siendo en vez de llamar al main() 10 setters/getters de un objeto, sólo se llama un método que contiene la mayoría de setters/getters  

En futuras versiones, puede que se implemente un menú mediante el uso de while loops e if statements en el archivo main(). Esto con el objetivo de darle la oportunidad a más personas de usar el código sin tantas complicaciones al momento de llamar métodos/funciones y repetir la acción que se eliga del menú cuantás veces el usuario desee. 

Otra área de oportunidad importante es que el programa sólo se comunicará mediante la consola.
