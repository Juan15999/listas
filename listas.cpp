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
        while(l!=NULL && bandera==false){
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

//Elimina repetidos de la lista.
lista eliminar_repetidos(lista l){
    if (vacia(l)){
        return l;
    } else {
        lista controlador=l;
        while(controlador!=NULL){
            lista avanzador=controlador->sig, ayu_avanzador=controlador;
            while(avanzador!=NULL){
                if(controlador->dato==avanzador->dato){
                    ayu_avanzador->sig=avanzador->sig;
                    delete avanzador;
                    avanzador=ayu_avanzador->sig;
                } else{
                avanzador=avanzador->sig;
                ayu_avanzador=ayu_avanzador->sig;
                }
            }
            controlador=controlador->sig;
        }
    return l;
    }
}

//Intercambia las posiciones de dos elementos de la lista l.
lista intercambiar_posiciones(lista l, int n, int m){
    if(vacia(l)){
        cout << "La lista no contiene los elementos dados porque está vacía" << endl;
        return l;
    } else if(m==n){
        return l;
    } else if(!pertenece(l, n) && !pertenece(l, m)){
        cout << "Ninguno de los elementos dados esta en la lista" << endl;
        return l;
    } else if(!pertenece(l, n)){
        cout << n << " no se encuentra entre los elementos de la lista" << endl;
        return l;
    } else if(!pertenece(l, m)){
        cout << m << " no se encuentra entre los elementos de la lista" << endl;
        return l;
    } else{
        lista aux1=l, aux2=l->sig, ant_nodo_n, ant_nodo_m, nodo_n, nodo_m, sig_nodo_n, sig_nodo_m;
        while(aux2!=NULL){
            if(aux2->dato==n){
                ant_nodo_n=aux1;
                nodo_n=aux2;
                sig_nodo_n=aux2->sig;
                aux1=aux2;
                aux2=aux2->sig;
            } else if(aux2->dato==m) {
                ant_nodo_m=aux1;
                nodo_m=aux2;
                sig_nodo_m=aux2->sig;
                aux1=aux2;
                aux2=aux2->sig;
            } else {
                aux1=aux2;
                aux2=aux2->sig;
            }
        }
        ant_nodo_n->sig=nodo_m;
        nodo_m->sig= sig_nodo_n;
        ant_nodo_m->sig=nodo_n;
        nodo_n->sig=sig_nodo_m;
    }
    return l;
}