//
// Creado por Alfredo Gómez Mendoza A01704189 el 18/11/2021.
//Parte de herencia
class Limpieza :: public Voluntario{
    private:
        bool perros_banados;
        bool mantas_limpiadas;
        bool limpiar_desechos;
    public:
        Limpieza(){};
        bool limpiar_desechos(bool);
        bool bañar_perros(bool);
        bool limpiar_mantas(bool);
};
