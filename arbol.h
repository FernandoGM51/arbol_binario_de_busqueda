#ifndef _ARBOL_H_
#define _ARBOL_H_

using namespace std;

struct Nodo;

//.:DECLARACIÓN DE PRIMITIVAS:.

/**GETS**/

//PRE: Se necesita un puntero a un nodo por parametro
//POST: Retorna el valor que se encuentra dentro de la variable "palabra"
string getPalabra(Nodo* nodo);

//PRE: Se necesita un puntero a un nodo por parametro
//POST: Retorna un puntero al nodo derecho
Nodo* getNodoDerecha(Nodo* nodo);

//PRE: Se necesita un puntero a un nodo por parametro
//POST: Retorna un puntero al nodo izquierdo
Nodo* getNodoIzquierda(Nodo* nodo);

//PRE: Se necesita un puntero a un nodo por parametro
//POST: Retorna un puntero al nodo padre
Nodo* getNodoPadre(Nodo* nodo);

/**SETS**/

//PRE: Se necesita un puntero a un nodo y un string por parametro
//POST: Setea la variable "palabra" con el string ingresado por parametro
void setPalabra(Nodo* nodo, string nuevaPalabra);

//PRE: Se necesita un puntero a un nodo y un puntero a un nuevo nodo por parametro
//POST: Setea al nodo derecho con el nuevo nodo ingresado por parametro
void setDerecha(Nodo* nodo, Nodo* nuevoNodo);

//PRE: Se necesita un puntero a un nodo y un puntero a un nuevo nodo por parametro
//POST: Setea al nodo izquierdo con el nuevo nodo ingresado por parametro
void setIzquierda(Nodo* nodo, Nodo* nuevoNodo);

//PRE: Se necesita un puntero a un nodo y un puntero a un nuevo nodo por parametro
//POST: Setea al nodo padre con el nuevo nodo ingresado por parametro
void setPadre(Nodo* nodo, Nodo* nuevoNodo);

//PRE: Necesita un string y un puntero a Nodo padre por parametro
//POST: Retorna un puntero a nuevo_nodo(padre e hijos) con una palabra y lo guarda en memoria
Nodo *crearNodo(string pal, Nodo *padre);

//PRE: Se necesita un puntero a un nodo por parametro
//POST: Se destruye el nodo ingresado por parametro
void destruirNodo(Nodo *nuevo);

//PRE: Se necesita un puntero a un nodo por parametro
//POST: Se eliminan todos los nodos del arbol y se setea "vacia" la raiz para un futuro uso
void borrarArbol(Nodo *arb);

//PRE: Se necesita un puntero a un nodo por parametro
//POST: Busca al nodo hoja y lo elimina
void buscarEliminar(Nodo *sub_arb);

//.:DECLARACIÓN DE FUNCIONES:.

//PRE: Necesita un arbol pasado por puntero y por referencia, un string y un puntero a nodo padre
//POST: Si arbol es nulo, nuevo_nodo se asigna como raiz , si no, se compara el tamaño de la palabra
//y se asigna a la rama correspondiente, ordenado alfabeticamente (decreciente hacia izquiera y creciente hacia derecha)
void insertarNodo(Nodo *&arb, string pal, Nodo *padre);

//PRE: Necesita puntero a nodo arbol y un entero, por parametro
//POST: Muestra el contenido del arbol de manera esquematizada horizontalmente
void mostrarArbol(Nodo *arb, int cont);

//PRE: Se necesita puntero a nodo arbol por parametro
//POST: Se muestra el arbol de manera ordenada en forma de texto
void mostrarArbolNormal(Nodo *arb);

//PRE: Se necesita puntero a nodo arbol y un string, pasados por parametro
//POST: Se retorna TRUE cuando se encuentra la palabra pasada por parametro y FALSE cuando no se encuentra
bool busqueda(Nodo* arb, string pal);

//PRE: Se necesita puntero a nodo arbol y puntero a nodo nuevo por parametro
//POST: Se le asigna un nuevo nodo hijo al nodo padre
void reemplazar(Nodo *arb, Nodo *nuevo);



#endif /*_ARBOL_H_*/
