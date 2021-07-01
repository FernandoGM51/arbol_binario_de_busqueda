#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "arbol.h"
#include "funciones.h"

using namespace std;


int main(){

    Nodo *arbol=NULL;
    int entero = 0;

    setlocale(LC_CTYPE, "Spanish");

    lecturaArchivo(arbol);
    cout<<"\t.:MOSTRAMOS EL ARBOL BINARIO ESTRUCTURADO:.\n"<<endl;
    mostrarArbol(arbol, entero);
    cout<<"\n\t.:MOSTRAMOS LAS PALABRAS ORDENADAS ALFABETICAMENTE:.\n"<<endl;
    mostrarArbolNormal(arbol);
    borrarArbol(arbol);

    return 0;
}

