//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
//Parte de herencia
class Alimentacion :: public Voluntario{
private:
    bool perros_alimentados;
    bool limpiar_comederos;
    bool agua_llenado;
public:
    Alimentacion(){};
    bool alimentar(bool);
    bool limpieza(bool);
    bool llenado_agua(bool);
};