#include <iostream>
#include <cstdlib>
#include <ctime>
#include "listas.h"
using namespace std;

int main(){
    srand(time(0));
    lista l =crear();
    l=llenar(l, 17);
    imprimir_lista(l);
    imprimir_reves(l);
    return 0;
}