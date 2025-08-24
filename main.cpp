#include <iostream>
#include <cstdlib>
#include <ctime>
#include "listas.h"
using namespace std;

int main(){
    srand(time(0));
    lista l =crear();
    l=snoc(l, 1);
    l=snoc(l, 2);
    l=snoc(l, 3);
    l=snoc(l, 3);
    l=snoc(l, 4);
    l=snoc(l, 4);
    l=snoc(l, 5);
    imprimir_lista(l);
    l=eliminar_repetidos(l);
    imprimir_lista(l);
    return 0;
}