#ifndef ARBOLB_H
#define ARBOLB_H

#include "pagina.h"
#include "Movie.h"
#include "string"
#include "QDebug"
class ArbolB
{
protected:
    int orden;
    Pagina *raiz;
private:
    Pagina* buscar(Pagina* actual, Movie* cl, int &n);
    Pagina* insertar(Pagina* raiz, Movie* cl);
    std::string traverseAndCollect(Pagina* node);
    void inOrden(Pagina *r);
    void escribir( Pagina * r, int h);
    void write(Pagina* r, int h);
    Movie* searchByTitle(Pagina* node, const std::string& title);


public:



    ArbolB()
    {
        orden = 0;
        raiz = nullptr;
    }
    ArbolB(int m){
        orden = m;
        raiz = nullptr;
    }
    bool arbolBvacio()
    {
        if(raiz==nullptr){
            qDebug()<<"Ta vacio rey";
        }
        return raiz == nullptr;
    }


    bool buscarNodo(Pagina* actual, Movie* cl, int & k);
    Pagina * Oraiz(){ return raiz;}
    void Praiz( Pagina * r){ raiz = r;}
    int Oorden(){ return orden;}
    void Porden(int ord){ orden = ord;}
    void crear() { orden = 0; raiz = nullptr;}
    Pagina* buscar(Movie* cl, int &n);
    void insertar(Movie* cl);
    void eliminar(Movie* cl);
    bool empujar(Pagina* actual, Movie* cl, Movie*& mediana, Pagina*& nuevo);
    void meterPagina(Pagina* actual, Movie* cl, Pagina *ramaDr, int k);
    void dividirNodo(Pagina* actual, Movie* mediana, Pagina * &nuevo, int pos);
    void escribir( );
    void listarCreciente();
    std::string collectMovieInfo();
    void write();
    Movie* searchByTitle(const std::string& title);
};
#endif // ARBOLB_H
