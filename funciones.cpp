#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "arbol.h"
#include "funciones.h"


using namespace std;

//----------------------------------Ordenamiento de caracteres----------------------------------//

int cantidadCaracteres(string nom){
	int tam=nom.size();
	return tam;
}

string pasarNuevo(string nom){
	string letras="abcdefghijklmnñopqrstuvwxyzABRCEFGHIJKLMNÑOPQRSTUVWXYZÁÉÍÓÚáéíóú";
	int salida=0;
	string aux;
	for(int i=0; i<nom.size(); i++){
		for(int j=0; j<letras.size(); j++){
			if(nom[i]==letras[j]){
				salida=1;
			}
		}
		if(salida==1){
			aux.append(nom.substr(i,1));
		}
		salida=0;
	}
	return aux;
}

//----------------------------------Lectura de archivo y creacion de arbol----------------------------------//

void lecturaArchivo(Nodo *&arb){
	string nom;
	string copia;
	string aux;

	ifstream lectura;

	lectura.open("enunciado.txt",ios::out);

	if(lectura.is_open()){

		while(!lectura.eof()){
			lectura>>nom;
			copia=pasarNuevo(nom);
			if(cantidadCaracteres(copia)>4){
				if(busqueda(arb, copia) == false){
					insertarNodo(arb, copia, NULL);
				}
			}
		}

	}else{
		cout<<"No existe el archivo"<<endl;
	}
	lectura.close();

}
