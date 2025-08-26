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
    l=snoc(l, 4);
    l=snoc(l, 5);
    l=snoc(l, 6);
    l=snoc(l, 7);
    imprimir_lista(l);
    l=intercambiar_posiciones(l, 6, 2);
    imprimir_lista(l);
    l=intercambiar_posiciones(l, 5, 4);
    imprimir_lista(l);
     l=intercambiar_posiciones(l, 1, 7);
    imprimir_lista(l);
    l=intercambiar_posiciones(l, 5, 3);
    imprimir_lista(l);
    l=intercambiar_posiciones(l, 1, 1);
    imprimir_lista(l);
    l=intercambiar_posiciones(l, 17, 8);
    return 0;
}