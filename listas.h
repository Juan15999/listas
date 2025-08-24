typedef struct nodo_lista* lista;
lista crear();
//Agrega n al principio de la lista.
lista cons(lista l, int n);
//Agrega n al final de la lista. (Snoc al reves es cons jsjsj). 
lista snoc(lista l, int n);
//Devuelve true si la lista está vacía.
bool vacia(lista l);
//Devuelve true si n está en la lista.
bool pertenece(lista l, int n);
//Quita n de la lista l.
lista quitar(lista l, int n);
//retorna la cantidad de elementos en la lista.
int contar(lista l);
//Borra la lista y libera la memoria.
lista destruir(lista l);
//Retorna el primer elemento de la lista l. Pre: lista no vacía.
int head(lista l);
//Retorna una lista sin el primer elemento.
lista tail(lista l);
//Cuenta sin acceder a la estructura interna de los datos y de forma recursiva.
int contar_2(lista l);
//Es tipo pertenece pero recursiva y sin estructura interna.
bool pertenece_2(lista l, int n);
//Es snoc pero recursivo y sin estructura interna.
lista snoc_2(lista l, int n);
//Borrar recursiva Juan´s version
lista destruir_lista(lista l);
//Borra la lista y libera la memoria.
lista destruir(lista l);
//Imprime en orden los contenidos de una lista l
void imprimir_lista(lista l);
//Devuelve a l con elementos random, tantos como cantidadElementos
lista llenar(lista l,int cantidadElementos);
//Imprime uno si uno no.
void imprimir_gracioso(lista l);
//imprime solo pares.
void imprimir_solo_pares(lista l);
//Imprime la lista al revés.
void imprimir_reves(lista l);
//Elimina repetidos de la lista.
lista eliminar_repetidos(lista l);