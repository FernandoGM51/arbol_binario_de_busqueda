#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "arbol.h"
#include "funciones.h"

using namespace std;

struct Nodo{
	string palabra;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

Nodo *crearNodo(string pal, Nodo *padre){
	Nodo *nuevo_nodo= new Nodo();

	setPalabra(nuevo_nodo, pal);
	setDerecha(nuevo_nodo, NULL);
	setIzquierda(nuevo_nodo, NULL);
	setPadre(nuevo_nodo, padre);

	return nuevo_nodo;
}

void insertarNodo(Nodo *&arb, string pal, Nodo *padre){

	if(arb == NULL){
		Nodo *nuevo_nodo=crearNodo(pal, padre);
		arb = nuevo_nodo;
	}else{
		string raiz = getPalabra(arb);

		if(pal.compare(raiz)==-1){
			insertarNodo(arb->izq, pal, arb);
		}else{
			insertarNodo(arb->der, pal, arb);
		}
	}
}

void mostrarArbol(Nodo *arb, int cont){

	if(arb == NULL){
		return;
	}else{
		mostrarArbol(getNodoDerecha(arb), cont+1);
		for(int i=0; i<cont; i++){
			cout<<"   ";
		}
		cout<<getPalabra(arb)<<endl;
		mostrarArbol(getNodoIzquierda(arb), cont+1);
	}
}

bool busqueda(Nodo* arb, string pal){
    //El primer if y el primer else es lo que se va a terminar haciendo. No va a cortar hasta que entre en alguno de los returnos
    //
	if(arb == NULL){
		return false;
	}else if (getPalabra(arb).compare(pal) == 0) {
		return true;           //esa palabra ya estaba ingresada en el arbol.
	}else if (pal.compare(getPalabra(arb)) == -1) {
		return busqueda(getNodoIzquierda(arb), pal);
	}else{
		return busqueda(getNodoDerecha(arb), pal);
	}
}

void mostrarArbolNormal(Nodo *arb){
	if ((arb == NULL) || (getPalabra(arb).size() <= 1 )) {
		return;
	}else{
		mostrarArbolNormal(getNodoIzquierda(arb));
		cout<<getPalabra(arb)<<" - ";
		mostrarArbolNormal(getNodoDerecha(arb));
	}
}

void reemplazar(Nodo *arb, Nodo *nuevo){
	if (getNodoPadre(arb)) {
		if (getNodoIzquierda(arb->padre) != NULL) {
			if (getPalabra(arb).compare(arb->padre->izq->palabra) == 0) {
				setIzquierda(arb->padre, nuevo);
			}
		}
		if (getNodoDerecha(arb->padre) != NULL) {
			if (getPalabra(arb).compare(arb->padre->der->palabra) == 0) {
				setDerecha(arb->padre, nuevo);
			}
		}

	}
	if(nuevo){
		setPadre(nuevo, getNodoPadre(arb));
	}
}

void destruirNodo(Nodo *nuevo){
	setIzquierda(nuevo, NULL);
	setDerecha(nuevo, NULL);
	delete nuevo;

}

void buscarEliminar(Nodo *sub_arb){
	if (getNodoIzquierda(sub_arb)) {
		sub_arb = getNodoIzquierda(sub_arb);
		buscarEliminar(sub_arb);
	}else if (getNodoDerecha(sub_arb)) {
		sub_arb = getNodoDerecha(sub_arb);
		buscarEliminar(sub_arb);
	}else{
		reemplazar(sub_arb, NULL);
		destruirNodo(sub_arb);
	}
}

void borrarArbol(Nodo *arb){

	if(arb == NULL){
		return;
	}else if (getNodoDerecha(arb)) {
		buscarEliminar(arb);
		borrarArbol(arb);
	}else if (getNodoIzquierda(arb)) {
		buscarEliminar(arb);
		borrarArbol(arb);
	}else{
		destruirNodo(arb);
		cout<<"\n\n\t.:ARBOL BORRADO:."<<endl;
	}

}


string getPalabra(Nodo* nodo) {
    return nodo->palabra;
}

Nodo* getNodoDerecha(Nodo* nodo) {
    return nodo->der;
}

Nodo* getNodoIzquierda(Nodo* nodo) {
    return nodo->izq;
}
Nodo* getNodoPadre(Nodo* nodo) {
    return nodo->padre;
}

void setPalabra(Nodo* nodo, string nuevaPalabra) {
    nodo->palabra = nuevaPalabra;
}

void setDerecha(Nodo* nodo, Nodo* nuevoNodo) {
    nodo->der = nuevoNodo;
}

void setIzquierda(Nodo* nodo, Nodo* nuevoNodo) {
    nodo->izq = nuevoNodo;
}

void setPadre(Nodo* nodo, Nodo* nuevoNodo) {
    nodo->padre = nuevoNodo;
}
