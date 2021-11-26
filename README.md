# TC1033.2 Adopción de perros.
Proyecto desarrollado durante la clase de TC1033.2. 

## Contexto

El proyecto consitirá en apoyar refugios de perros como el de Huellitas Seguras de Querétaro. Muchos de estos refugios para perros buscan dar en adopción a los perros que se encuentran viviendo ahí. Para facilitar el proceso, mediante sus redes o eventos, ponen en adopción a sus perros. Para que el proceso de adopción sea más efectivo, los refugios guardan la información de cada perro para después enseñarle esta información al público. Sin embargo, muchas veces esta información se llega a perder o no se modifica adecuadamente, siendo una de las posibles consecuencias, inconsistencias en la información guardada de los perros.

Otro factor importante en estos refugios es la de los voluntarios. En muchos refugios caninos hay muchos colaboradores trabajando, causando una necesidad de guardar la información de quienes están trabajando para usarla en caso de emergencia o para contactar a los voluntarios. Es por esto que el código también tiene integrado una clase de Voluntario para poder registrar todo esto. 

Como muchos voluntarios son nuevos en el lugar, el usuario puede checar que voluntarios tienen experiencia trabajando en el refugio. Una de las utilidades de esto, es que en vez de instruir voluntario por voluntario, puede hacer que los voluntarios con experiencia instruyan a los nuevos colaboradores del lugar. 

Otro problema con los voluntarios es que muchos de estos no cumplen sus tareas. Para esto, el usuario puede guardar en el código, mediante booleanos, si el usuario cumplió sus tareas o no.

Por parte de la adopción, el proceso llega a ser tardado o cansado. Esto se debe a que el refugio tiene que estar totalmente seguro si el adoptante tiene los criterios necesarios para adoptar. La solución que viene en el código es la de checar el estatus del adoptante mediante métodos y decirnos si el adoptante es capaz de adoptar o no.

## ¿A quién va dirigido?

El usuario que manejaría el proyecto sería alguna persona con conocimientos de programación que este encargado del registro o sea alguien que maneje o lidere el refugio. Debido a que el programa no tiene una interfaz gráfica, el usuario tiene que tener algún conocimiento de programación previo para poder usar el código.

## Funcionalidad

Debido a esto, he creado este programa en C++ para tener un control más eficaz y elaborado. Siendo la función principal la  de guardar información del Refugio, sus voluntarios, adoptantes y sus perros. Por ejemplo, en el caso de los perros, se guardan datos (atributos en clases) como  raza, tamaño, edad, si esta enfermo o no, si esta vacunado o no, si esta esterilizado, sexo, si convive con otros (perros, animales o niños), nivel de energía (calmado, juguetón). 

Para accesar a la información registrada de cada clase (Refugio, Perro, Adoptante, Voluntario), se usan los métodos get respectivos de cada atributo escrito para cada clase y sus objetos. Entre las funciones de get podemos encontrar get_edad().

Sin embargo el código tiene la posibilidad de realizar otras funciones mediante el uso de métodos. 

El refugio tiene métodos los cuales tienen la capacidad de decirle al usuario si se necesitan más camas para los perros, si hay aún espacio para albergar más perros y si se alcanza el límite de voluntarios. 

La clase Perro, además de dejarnos guardar información, nos permite crear un adoptante para cuando el usuario comience el proceso de adopción. Siendo este adoptante creado con atributos o datos (nombre, edad) definidos por el usuario mediante constructores y setters. También, al momento de crear al adoptante mediante la composición, se asigna el adoptante al perro en cuestión.

La clase Voluntario, habilita al usuario guardar la información de sus voluntarios como los nombre, los teléfono, las edad y su experiencia. Esto se definido mediante constructores y editado mediante setters. Siendo este último dato usado por el método colab_exp(). Con este método, se puede checar si el voluntario creado, tiene la experiencia para ser considerado como un voluntario experimentado.  El código considera a un voluntario experimentado cuando tiene más de 40 horas de servicio en el refugio cumplidas, siendo la misma función la que cambia este estatus. Sin embargo, el usuario que use el código tiene que registrar las horas cumplidas mediante la función set_horas y llamar a la función de colab_exp.

Para poder asignar tareas, mediante herencia proveniente de la clase Voluntario, se crean tres tipos de voluntario (Encargado, Limpieza y Alimentacion). Esto es realizado para poder monitorear que las tareas del refugio si se cumplan. El encargado o usuario puede modificar el estatus del cumplimiento de estas tareas mediante setters.

En el caso que el programa tenga mucha información acumulada, la clase perro le permite al usuario poder elegir si eliminar la información de los perros que ya no necesite (eliminando el objeto creado previamente por el usuario mediante un destructor).

A fin de agilizar el proceso de adopción, el código checa el estatus del adoptante mediante métodos y le dice al usuario si el adoptante es capaz de adoptar o no.

## ¿Cómo funciona?

La persona que corra este código, tiene la posibilidad de crear objetos en el main.cpp, siendo el primer objeto creado el refugio mismo. Al momento que este refugio sea creado, se le asignaran valores a sus atributos mediante el uso de un constructor. En el código, el objeto de clase Refugio es nombrado "huellas_seguras".

Posteriormente se crea un voluntario (gabriel) con el mismo método anteriormente mencionado. Se llaman las funciones de set_horas() y colab_exp() para checar si el usuario ya es un voluntario experimentado. También se llama a la función anadir_voluntario(), que agrega una unidad al contador (numero_voluntarios)  que tiene el objeto huellas_seguras para poder usarlo en staff_necesario(). 

Para poder tener diferentes tipos de voluntarios, mediante la herencia se crean nuevas clases que designan nuevos atributos y tareas a los objetos heredados de la clase Voluntario(). En el código podemos ver tres tipos (Alimentacion, Limpieza y Encargado).

Para crear el perro (rodo), se crea un adoptante dummy o de prueba. Este dummy es definido junto a todos los atributos pertenecientes al constructor perro. Más adelante en el código, este dummy es remplazado mediante el método crear_adoptante(), que cambia al objeto dummy por el adoptante creado por el método crear_adoptante(). También se llama a la función anadir_perro), que agrega una unidad al contador (numero_perros) que tiene el objeto huellas_seguras para poder usarlo posteriormente en su método perros_admitidos().

Con lo anterior, el código llama a el método de Perro "adoptar()", con el propósito de realizar el proceso de adopción. Al final, se tiene que desplegar en la consola si se puede adoptar al perro o no (esto es determinado por métodos y atributos de la clase Adoptante, los cuales podemos acceder debido a la composición que tiene Adoptante con la clase Perro). En el caso que se adopte el contador del refugio disminuirá.

Seguidamente del último proceso, el código cambia la información del perro creado (rodo), mediante el uso de setters y despliega toda su información mediante el uso de getters. 

Por último el código despliega la información obtenida mediante el método de status() del objeto huellas_seguras, si faltan camas, hay espacio para perros y si hay espacio para que más voluntarios se anoten.


## ¿Para qué es bueno el programa? ¿Áreas de oportunidad?

El programa es bueno para registrar información de objetos. Sin embargo, un área de oportunidad o a considerar es que el usuario, al no tener una IDE, tiene que registrar todo en el código y la consola, siendo esto una tarea compleja o frustante para algunas personas.  Además sólo se comunicará mediante la consola.
