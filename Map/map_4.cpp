/**
 * Crea un programa que mantenga un sistema de puntuación para jugadores en un juego. 
 * Utiliza un map<string, int> donde las claves sean los nombres de los jugadores y los 
 * valores sean sus puntuaciones. Implementa funciones para agregar puntuaciones a los 
 * jugadores, eliminar jugadores y mostrar la tabla de puntuaciones ordenada por puntaje.
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool comparador(pair<string,int> &a, pair<string,int> &b){
    return a.second < b.second;
}

void sort_values_and_print(map<string,int> & mapa){
    
    vector<pair<string,int>> V;

    for (auto &it : mapa){
        V.push_back(it);
    }

    sort(V.begin(), V.end(),comparador);

    for (auto &it : V){
        cout << it.first << ": " << it.second << endl;
    }
}

int main(){
    
    map<string, int> leaderboard;
    const int PL_LIMIT = 15;
    string jugador;
    int puntaje;
    
    cout << "Introduzca una lista de jugadores y sus puntuaciones:\n";
    for (int i = 1; i <= PL_LIMIT; i++){
        cout << "Datos " << i << ": ";
        cin >> jugador;
        cout << "Puntaje: ";
        cin >> puntaje;

        leaderboard[jugador] = puntaje;
        cout << endl;
    }

    cout << "Lista de jugadores ordenada:\n";
    sort_values_and_print(leaderboard);

}