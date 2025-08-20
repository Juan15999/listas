#include <iostream>
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

//Hacer recursiva en casa
//Borra la lista y libera la memoria.
lista destruir(lista l){

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
            return(pertenece_2(l,n));
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
           return cons(quitar(tail(l), n), head(l));
        }
    }
}