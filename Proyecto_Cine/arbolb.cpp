#include "arbolb.h"
#include "iostream"
#include "QDebug"
#include <QMessageBox>

using std::cout;
using std::endl;



bool ArbolB::buscarNodo(Pagina* actual, Movie* cl, int& k)
{
    int index;
    bool encontrado;
    if (*cl < *actual->Oclave(1))
    {
        encontrado = false;
        index = 0;
    }
    else
    { // orden descendente
        index = actual->Ocuenta();
        while (*cl < *actual->Oclave(index) && (index > 1))
            index--;
        encontrado = *cl == *actual->Oclave(index);
    }
    k = index;
    return encontrado;
}

Pagina* ArbolB::buscar(Movie* cl, int& n)
{
    return buscar(raiz, cl, n);
}

Pagina* ArbolB::buscar(Pagina* actual, Movie* cl, int& n)
{
    if (actual == nullptr)
    {
        return nullptr;
    }
    else
    {
        bool esta = buscarNodo(actual, cl, n);
        if (esta) // la clave se encuentra en el nodo actual
            return actual;
        else
            return buscar(actual->Orama(n), cl, n); // llamada recursiva
    }
}

void ArbolB::insertar(Movie* cl)
{
    qDebug() << "Inserting movie: " << cl->getTitle();
    raiz = insertar(raiz, cl);
    if (raiz->Ocuenta() > orden)
    {
        Pagina* temp = new Pagina(orden);
        temp->Prama(0, raiz);
        dividirNodo(raiz, nullptr, raiz, 1);
        raiz = temp;
    }
    qDebug() << "Raiz " << raiz->Ocuenta();
}

// método privado
Pagina* ArbolB::insertar(Pagina* raiz, Movie* cl)
{
    bool subeArriba;
    Movie* mediana = nullptr;
    Pagina* nd = nullptr;

    if (raiz == nullptr)
    {
        Pagina* p = new Pagina(orden);
        p->Pcuenta(1);
        p->Pclave(1, cl);
        p->Prama(0, raiz);
        p->Prama(1, nd);
        raiz = p;
    }
    else
    {
        subeArriba = empujar(raiz, cl, mediana, nd);
        if (subeArriba)
        {
            if (raiz->nodoLLeno())
            {
                dividirNodo(raiz, mediana, nd, raiz->Ocuenta() + 1);
            }
            else
            {
                subeArriba = false;
                meterPagina(raiz, mediana, nd, raiz->Ocuenta());
            }
        }
    }
    return raiz;
}

bool ArbolB::empujar(Pagina* actual, Movie* cl, Movie*& mediana, Pagina*& nuevo)
{
    int k;
    bool subeArriba = false;
    if (actual == nullptr)
    {
        subeArriba = true;
        mediana = cl;
        nuevo = nullptr;
    }
    else
    {
        bool esta;
        esta = buscarNodo(actual, cl, k);
        if (esta)
            throw std::runtime_error("Clave duplicada");

        Movie* tempMediana = new Movie();
        Pagina* tempNuevo = nullptr;
        subeArriba = empujar(actual->Orama(k), cl, tempMediana, tempNuevo);

        if (subeArriba)
        {
            if (actual->nodoLLeno())
                dividirNodo(actual, tempMediana, tempNuevo, k);
            else
            {
                subeArriba = false;
                meterPagina(actual, tempMediana, tempNuevo, k);
            }
        }
    }
    return subeArriba;
}

void ArbolB::meterPagina(Pagina* actual, Movie* cl,
                         Pagina* ramaDr, int k)
{
    // desplaza a la derecha los elementos para hacer un hueco
    for (int i = actual->Ocuenta(); i >= k + 1; i--)
    {
        actual->Pclave(i + 1, actual->Oclave(i));
        actual->Prama(i + 1, actual->Orama(i));
    }
    // pone la clave y la rama derecha en la posición k+1
    actual->Pclave(k + 1, cl);
    actual->Prama(k + 1, ramaDr);
    // incrementa el contador de claves almacenadas
    actual->Pcuenta(actual->Ocuenta() + 1);
}

void ArbolB::dividirNodo(Pagina* actual, Movie* mediana,
                         Pagina*& nuevo, int pos)
{
    int i, posMdna, k;
    Pagina* nuevaPag;
    k = pos;
    // posición de clave mediana
    posMdna = (k <= orden / 2) ? orden / 2 : orden / 2 + 1;
    nuevaPag = new Pagina(orden);
    for (i = posMdna + 1; i <= orden; i++)
    {
        nuevaPag->Pclave(i - posMdna, actual->Oclave(i));
        nuevaPag->Prama(i - posMdna, actual->Orama(i));
    }
    nuevaPag->Pcuenta((orden - 1) - posMdna);
    actual->Pcuenta(posMdna);

    if (k <= orden / 2)
        meterPagina(actual, mediana, nuevo, pos);
    else
    {
        pos = k - posMdna;
        meterPagina(nuevaPag, mediana, nuevo, pos);
    }

    mediana = actual->Oclave(actual->Ocuenta());
    nuevaPag->Prama(0, actual->Orama(actual->Ocuenta()));
    actual->Pcuenta(actual->Ocuenta());
    nuevo = nuevaPag;
}

void ArbolB::escribir()
{
    escribir(raiz, 1);
}

void ArbolB::escribir(Pagina* r, int h)
{
    int i;
    if (r != nullptr)
    {
        for (i = 1; i <= r->Ocuenta() / 2; i++)
        {
            escribir(r->Orama(i), h + 5);
            cout << endl;
        }
        for (i = 1; i <= r->Ocuenta(); i++)
        {
            for (int j = 0; j <= h; j++)
                cout << " ";
            cout << r->Oclave(i)->getTitle() << endl;
        }
        for (i = r->Ocuenta() / 2 + 1; i <= r->Ocuenta(); i++)
            escribir(r->Orama(i), h + 5);
        cout << endl;
    }
}

void ArbolB::listarCreciente()
{
    inOrden(raiz->Orama(0));
}

void ArbolB::inOrden(Pagina* r)
{
    if (r)
    {
        inOrden(r->Orama(0));
        for (int k = 1; k <= r->Ocuenta(); k++)
        {
            cout << r->Oclave(k)->getTitle() << " ";
            inOrden(r->Orama(k));
        }
    }
}

std::string ArbolB::traverseAndCollect(Pagina* node)
{
    std::string result = "";
    if (node)
    {
        for (int k = 0; k < node->Ocuenta(); k++)
        {
            if (node->Oclave(k))
            {
                result += node->Oclave(k)->getTitle() + " " + node->Oclave(k)->getGenre() + " " + std::to_string(node->Oclave(k)->getYear()) + "\n";
            }
            if (node->Orama(k))
            {
                result += traverseAndCollect(node->Orama(k));
            }
        }
    }
    return result;
}

std::string ArbolB::collectMovieInfo()
{
    return traverseAndCollect(raiz);
}

void ArbolB::write()
{
    write(raiz, 1);
}

void ArbolB::write(Pagina* r, int h)
{

    int i;
    if (r != nullptr)
    {
        for (i = 1; i <= r->Ocuenta() / 2; i++)
        {
            write(r->Orama(i), h + 5);
            cout << endl;
        }
        for (i = 1; i <= r->Ocuenta(); i++)
        {
            for (int j = 0; j <= h; j++)
                cout << " ";
            cout << r->Oclave(i)->getTitle() << " " << r->Oclave(i)->getGenre() << " " << r->Oclave(i)->getYear() << endl;
        }
        for (i = r->Ocuenta() / 2 + 1; i <= r->Ocuenta(); i++)
            write(r->Orama(i), h + 5);
        cout << endl;
    }
}

Movie* ArbolB::searchByTitle(const std::string& title)
{
    return searchByTitle(raiz, title);
}

Movie* ArbolB::searchByTitle(Pagina* node, const std::string& title)
{
    if (node)
    {
        int index = 1;
        while (index <= node->Ocuenta() && title > node->Oclave(index)->getTitle())
        {
            index++;
        }

        if (index <= node->Ocuenta() && title == node->Oclave(index)->getTitle())
        {
            // Movie with the title found in this node
            return node->Oclave(index);
        }
        else if (node->Orama(index - 1))
        {
            // Search in the appropriate subtree
            return searchByTitle(node->Orama(index - 1), title);
        }
        else
        {
            // Movie with the title not found
            return nullptr;
        }
    }
    else
    {
        // Tree is empty
        return nullptr;
    }
}


