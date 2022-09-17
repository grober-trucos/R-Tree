#ifndef R_TREE_H
#define R_TREE_H

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include "R_Nodo.h"
#include "R_MBR.h"

class R_Tree
{
public:
    R_Tree();
    void print_desmos();
    void insercion(pair<int, int> llave_tupla);
    void eliminacion(pair<int, int> llave_tupla);

protected:
    void condensar(R_Nodo *&nodo, deque<R_Nodo *> &nodos_eliminados);

    void insertar_entradas(R_Nodo *nodo);

    R_Nodo *hallar_hoja(R_Nodo *nodo, pair<int, int> llave_tupla);
    void print_desmos(R_Nodo *nodo, int &tupla_id);
    static bool comparar_x_tupla(pair<int, int> a, pair<int, int> b);
    static bool comparar_x_mbr(pair<R_MBR, R_Nodo *> a, pair<R_MBR, R_Nodo *> b);
    static bool comparar_y_tupla(pair<int, int> a, pair<int, int> b);
    static bool comparar_y_mbr(pair<R_MBR, R_Nodo *> a, pair<R_MBR, R_Nodo *> b);

    R_Nodo *partir_nodo_mbrs(R_Nodo *&nodo, R_Nodo *otro_nodo_interno);

    R_Nodo *partir_nodo_tuplas(R_Nodo *&nodo, pair<int, int> llave_tupla);

    R_Nodo *escoger_nodo(R_Nodo *nodo, pair<int, int> llave_tupla);

    void ajustar_arbol(R_Nodo *&objetivo, R_Nodo *nuevo_nodo);

private:
    R_Nodo *root;
};

#endif