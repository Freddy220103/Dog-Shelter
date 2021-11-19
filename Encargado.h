//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
//Parte de herencia
class Encargado :: public Voluntario{
    private:
        int dinero_total;
    public:
        Encargado(){};
        string pagar_impuestos(int,int);
        int ganar_dinero(int);
        int gastar_dinero(int);
    };
