/**
 * Escribe un programa que tome una lista de palabras y agrupe las palabras que sean anagramas entre sí. 
 * Dos palabras son anagramas si tienen las mismas letras, independientemente del orden en el que 
 * aparezcan. Utiliza un map<string, vector<string>> donde la clave sea una versión ordenada 
 * alfabéticamente de la palabra y el valor sea un vector que contenga las palabras que son anagramas 
 * entre sí.
*/

#include <iostream>
#include <map>
#include <set>
#include <list>
using namespace std;

int main(){
    
    map<string, set<string>> anagr;
    list<string> lista_palabras;
    string palabra;

    cout << "Introduzca una lista de palabras (ingrese '0' para terminar):\n";
    do {
        cin >> palabra;
        if (palabra != "0") {
            lista_palabras.push_back(palabra);
        }
    } while(palabra != "0");

    for (auto it = lista_palabras.begin(); it != lista_palabras.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;


}