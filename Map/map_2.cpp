/**
 * Crea un programa que reciba una cadena de texto como entrada y cuente la frecuencia de cada palabra.
 * Utiliza un map<string, int> para almacenar las palabras como claves y sus conteos como valores.
*/

#include <iostream>
#include <set>
#include <sstream>
#include <map>
using namespace std;

int main(){

    string frase;

    cout << "Introduzca una cadena de texto: ";
    getline(cin, frase);

    istringstream cadena(frase);
    map<string, int> frecuencia_palabras;
    string palabra;

    while (cadena >> palabra)
        frecuencia_palabras[palabra]++;
    
    cout << endl << "Frecuencia de palabras:\n";
    for (auto it = frecuencia_palabras.begin(); it != frecuencia_palabras.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}