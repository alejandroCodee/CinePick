#ifndef PAGINA_H
#define PAGINA_H

#include "Movie.h"

typedef int tipoClave;
class Pagina;
typedef Pagina * PPagina;
class Pagina
{
protected:
    Movie *claves;
    PPagina *ramas;
    int cuenta;
private:
    int m; //máximo número de claves que puede almacenar la página
public:
    // crea una página vacía de un cierto orden dado
    Pagina (int orden)
    {
        m = orden;
        claves = new Movie[orden];
        ramas = new PPagina[orden];
        cuenta = 0;
        for (int k = 0; k < orden; k++)
            ramas[k] = nullptr;
    }
    // decide si un nodo está lleno
    bool nodoLLeno()
    {
        return (cuenta == m - 1);
    }
    // decide si una página tiene menos de la mitad de claves
    bool nodoSemiVacio()
    {
        return (cuenta < m / 2);
    }
    // obtener la clave que ocupa la posición i en el array de claves
   Movie* Oclave(int i) const { return &claves[i]; }
    // cambiar la clave que ocupa la posición i en el array de claves
    void Pclave(int i, Movie* clave) { claves[i] = *clave; }
    // obtener la rama que ocupa la posición i en el array de ramas
    Pagina* Orama(int i){ return ramas[i];}
    // cambiar la rama que ocupa la posición i en el array de ramas
    void Prama(int i, Pagina * p) { ramas[i] = p;}
    // obtener el valor de cuenta
    int Ocuenta(){ return cuenta;}
    // cambiar el valor de cuenta
    void Pcuenta( int valor) { cuenta = valor;}
};
#endif // PAGINA_H
