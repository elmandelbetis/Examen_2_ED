#include <iostream>
#include <queue>
#include<set>
#include <algorithm>
using namespace std;

// Unión de conjuntos usando sobrecarga del operador +

set<int> operator+(const set<int> &s1, const set<int> &s2){
    set<int> output = s1; // Copiamos s1 a output
    
    for (auto it1 = s2.begin(); it1 != s2.end(); ++it1){
        if (output.find(*it1) == output.end()){
            output.insert(*it1);
        }
    }
    
    return output;
}

// Intersección entre 2 conjuntos pasados por parámetros
set<int> Interseccion(const set<int> &s1, const set<int> &s2){
    set<int> output;
    set<int>::const_iterator it1,it2;

    it1 = s1.cbegin();
    
    for (it2 = s2.cbegin(); it2 != s2.cend(); ++it2){
        if (*it1 != *it2){
            output.insert(*it1);
            output.insert(*it2);
        }
    }

    return output;
}

// Unión entre dos conjuntos usando una cola
set<int> UnionEnCola (const set<int> &s1, const set<int> &s2, queue<set<int>> &C){
    set<int> output;

    C.push(s1);
    C.push(s2);
    
    while(!C.empty()){
        set<int> aux = C.front();
        C.pop();
        output = output + aux;
    }

    return output;
}

void Imprimir_set(const set<int> &s){
    for(auto it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){

    set<int> s1 = {1,2,3,4,5};
    set<int> s2 = {5,6};
    set<int>resultado;
    queue<set<int>> cola;

    resultado = operator+(s1,s2);
    Imprimir_set(resultado);
    
    resultado = UnionEnCola(s1, s2, cola);
    Imprimir_set(resultado);

    resultado = Interseccion(s1,s2);
    Imprimir_set(resultado);



    

}
