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
#include <algorithm>
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

    cout << "\n\n"; 

    cout << "La lista generada es la siguiente:\n";
    for (auto it = lista_palabras.begin(); it != lista_palabras.end(); ++it){
        cout << *it << " ";
    }
    cout << "\n\n";

    for (const auto palabra : lista_palabras){
        string palabra_ordenada = palabra;
        sort(palabra_ordenada.begin(), palabra_ordenada.end());

        if (palabra_ordenada.size() != 1)
            anagr[palabra_ordenada].emplace(palabra);
    }

    for (auto it = anagr.begin(); it != anagr.end(); ++it){
        cout << it->first << ":";
        for (const auto i : it->second){
            cout << i << " ";
        }
        if (it->second.size() == 1){
                cout << " ----> No existen anagramas";
        }else{
            cout << " ----> Existen " << it->second.size() << " anagramas";
        }
        cout << endl;
    }
    cout << endl;


    

}