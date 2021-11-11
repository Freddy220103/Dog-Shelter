# TC1033.2
Proyecto desarrollado durante la clase de TC1033.2. 

El proyecto consitirá en apoyar refugios de perros como el de Huellitas Seguras de Querétaro. Muchos de estos refugios para perros buscan dar en adopción a los perros que se encuentran viviendo ahí. Para facilitar el proceso, mediante sus redes o eventos, ponen en adopción a sus perros. Para que el proceso de adopción sea más efectivo, los refugios guardan la información de cada perro para después enseñarle esta información al público. Sin embargo, muchas veces esta información se llega a perder o no se modifica adecuadamente, siendo una de las posibles consecuencias, inconsistencias en la información guardada de los perros.

Debido a esto, he creado este programa en C++ para tener un control más eficaz y elaborado. El programa constará de guardar la información de los perros que estén en el refugio, guardando datos (atributos en clases) como color, especie, tamaño, edad, si esta enfermo o no, si esta vacunado o no, si esta esterilizado, sexo, si convive con otros (perros, animales o niños), nivel de energía (calmado, juguetón) y cuando llegó al refugio. 

El usuario que manejaría el proyecto sería alguna persona con conocimientos de programación que este encargado del registro o sea alguien que maneje o lidere el refugio. Debido a que el programa no tiene una interfaz gráfica, el usuario tiene que tener algún conocimiento de programación previo para poder usar el código (puede que esto sea cambiado en el futuro, pero por el momento se quedará así).

La persona que corra este código, tiene la posibilidad de crear objetos en el main.cpp, poniendo el nombre del perro a este objeto. Al momento que el perro sea registrado (o el objeto sea creado), se le pondrán por default datos (atributos) predefinidos. Sin embargo, sí el usuario busca modificar estos datos, puede ajustar los datos a su conveniencia mediante funciones como métodos set. Entre las funciones de set, podriamos encontrar por ejemplo la función de cambiar_edad(), dónde el usuario editará la edad del perro. El usuario también puede mediante la función de Adopcion() cambiar el estado del perro a adoptado. 

Otros métodos que encontraremos serán los get de la información previamente mencionada (esta por decidirse que información será pública, privada o protegida). Estos métodos pueden ayudar al usuario a saber la información registrada de los perros mediante esta función.  Entre las funciones de get podemos encontrar get_edad().

En el caso que el programa tenga mucha información acumulada, el usuario podría elegir si eliminar la información de un perro que lleve mucho tiempo sin usarse debido a que el perro fue adoptado (eliminando el objeto creado previamente por el usuario mediante un destructor).

