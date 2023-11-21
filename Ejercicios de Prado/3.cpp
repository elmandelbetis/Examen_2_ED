/**Dado un conjunto de palabras obtener un mapa donde la clave sea la palabra del set y la informaci�n 
 * asociada el n�mero de vocales que tiene la palabra. La funci�n ser�a la siguiente
 * map<string,int> getNumVocales(const set<string>&s)
 * Ej
 * S={ aguila, alondra, buho,buitre canario, gavilan, gaviota, halcon}
 * M={<aguila,4>,<alondra,3>,<buho;2>,<buitre;3>,<canario,4>,<gavilan,3>,<gaviota,4>,<halcon,2>}*/

// Nota: string se comporta como vector de char

#include <iostream>
#include <set>
#include <map>
using namespace std;

int CuentaVocales(const string &s){

    set<char> vocales = {'a','e','i','o','u'};
    int contador = 0;

    for (int i = 0; i < s.size(); i++){
        if (vocales.find(s[i]) != vocales.end())
            contador++;

    }

    return contador;

}

map<string,int> getNumVocales(const set<string> &s){
    map<string,int> output;
    set<string>::const_iterator it;

    for (it = s.cbegin(); it != s.cend(); ++it){
        int num_vocales = CuentaVocales(*it);
        output.insert(make_pair(*it,num_vocales));
    }

    return output;

}

int main(){
    
    set<string> S = { "aguila", "alondra", "buho", "buitre", "canario", "gavilan", "gaviota", "halcon"};
    map<string,int> vocales_x_palabra;

    vocales_x_palabra = getNumVocales(S);

    cout << "Número de vocales por cada palabra del conjunto:\n";
    for (auto it = vocales_x_palabra.begin(); it != vocales_x_palabra.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }
    
}
