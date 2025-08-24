#include <iostream>
#include <cstdlib>
#include <ctime>
#include "listas.h"
using namespace std;


struct nodo_lista{
    int dato;
    lista sig;
};

//Crea la lista.
lista crear(){
    return NULL;
}

//Agrega n al principio de la lista.
lista cons(lista l, int n){
    lista aux=new(nodo_lista);
    aux->dato=n;
    aux->sig=l;
    return aux;
}

//Agrega n al final de la lista. (Snoc al reves es cons jsjsj). 
lista snoc(lista l, int n){
    lista aux=new(nodo_lista);
    aux->dato=n;
    aux->sig=NULL;
    lista laux=l;
    if(l!=NULL){
        while(laux->sig!=NULL){
            laux=laux->sig;
        }
        laux->sig=aux;
    } else {
        l=aux;
    }   
    return l;
}

//Devuelve true si la lista está vacía.
bool vacia(lista l){
    return (l==NULL);
}

//Devuelve true si n está en la lista.
bool pertenece(lista l, int n){
    bool bandera=false;
    if(l!=NULL){
        while(l->sig!=NULL && bandera==false){
            if(l->dato==n){
                bandera=true;
            }
            l=l->sig;
        }
    }  
    return bandera;
}

//Quita n de la lista l.
lista quitar(lista l, int n){
    lista laux=l, ant;
    while(laux->dato!=n && laux->sig!=NULL){
        ant=laux;
        laux=laux->sig;
    }
    if (laux->dato==n){
        if(laux==l) {
            l=laux->sig;
        } else {
        ant->sig=laux->sig;
        }
        delete laux;
    }
    return l;
}

//retorna la cantidad de elementos en la lista.
int contar(lista l){
    int cantidad=0;
    while(l!=NULL){
        cantidad++;
        l=l->sig;
    }
    return cantidad;
}

//Borra la lista y libera la memoria.
lista destruir(lista l){
    if(vacia(l)){
        return nullptr;
    } else {
        destruir(tail(l));
        delete l;
        return nullptr;
    }
}

//Borrar recursiva Juan´s version
lista destruir_lista(lista l){
    if (vacia(l)){
        return nullptr;
    } else{
        destruir_lista(l->sig);
        delete l;
        return nullptr;
    }
}

//Retorna el primer elemento de la lista l. Pre: lista no vacía.
int head(lista l){
    return l->dato;
}

//Retorna una lista sin el primer elemento.
lista tail(lista l){
    return l->sig;
}

//Cuenta sin acceder a la estructura interna de los datos y de forma recursiva.
int contar_2(lista l){
    if(vacia(l)){
        return 0;
    } else {
        return 1+contar_2(tail(l));
    }
}

//Es tipo pertenece pero recursiva y sin estructura interna.
bool pertenece_2(lista l, int n){
    if(vacia(l)){
        return false;
    } else {
        if(head(l)==n){
            return true;
        } else {
            return(pertenece_2(tail(l),n));
        }
     }
}

//Es snoc pero recursivo y sin estructura interna.
lista snoc_2(lista l, int n){
    if(vacia(l)){
        return cons(l,n);
    } else {
        return cons(snoc_2(tail(l),n), head(l));
    }
}

//Devuelve una nueva lista sin el elemento n.
lista quitar_2(lista l, int n){
    if(vacia(l)){
        return crear();
    } else {
        if(head(l)==n){
            return tail(l);
        } else {
           return cons(quitar_2(tail(l), n), head(l));
        }
    }
}

//Imprime en orden los contenidos de una lista l
void imprimir_lista(lista l){
    while (l!=NULL){
        cout << l->dato << " ";
        l=l->sig;
    }
    cout << endl;
}

//Devuelve a l con elementos random, tantos como cantidadElementos
lista llenar(lista l,int cantidadElementos){
    for( int i=1; i<=cantidadElementos; i++){
        l=cons(l, rand() % 101);
    }
    return l;
    }

//Imprime uno si uno no.
void imprimir_gracioso(lista l){
    bool bandera=true;
    while (l!=NULL){
        if(bandera){
            cout << l->dato << " ";
            l=l->sig;
            bandera = !bandera;
        } else {
            l=l->sig;
            bandera = !bandera;
        }
    }
    cout << endl;
}

//Imprime solo pares...
void imprimir_solo_pares(lista l){
     while (l!=NULL){
        if(l->dato%2==0){
        cout << l->dato << " ";
        }
        l=l->sig;
     }
    cout << endl;
}

//Imprime la lista al revés.
void imprimir_reves(lista l){
    if(l!=NULL){
        imprimir_reves(tail(l));
        cout << l->dato << ' ';
    }
}