#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

using namespace std;

//PRE: Se necesita un string por parametro
//POST: Se retorna el "texto limpio", sin caracteres agregados
string pasarNuevo(string nom);

//PRE: Se necesita un string por parametro
//POST: Se retorna la cantidad de caracteres
int cantidadCaracteres(string nom);

//PRE: Requiere tener un archivo .txt en el directorio para su lectura y separar sus palabras
//POST: Carga el arbol con palabras de caracteres mayores a 4 digitos, sin repetir y ordenadas alfabeticamente
void lecturaArchivo(Nodo *&arb);


#endif /*_FUNCIONES_H_*/
