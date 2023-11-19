/**
 * Dados dos conjuntos sobrecargar el operator- para obtener un nuevo conjunto que sea la diferencia del 
 * primero menos el segundo.
 * 
 * 
 * Resolución propia: dado que set almacena datos en conjuntos de forma ordenada de menor a mayor y
 * sin elementos repetidos... La resta de un conjunto menos el otro sería aproximadamente quitarle
 * los elementos que sean iguales.
 * 
 * No obstante proporcionaré también la otra forma de ver el problema, y es restar los valores que sean
 * iguales.
*/

#include <iostream>
#include <set>
using namespace std;

set<int> operator-(set<int> &s1, const set<int> &s2){
    
    set<int> output;
    set<int>::const_iterator it1, it2;

    it1 = s1.begin();
    

    for (it2 = s2.begin(); it2 != s2.end(); ++it2){
        if (*it1 != *it2){
            output.insert(*it1);
        }
        ++it1;
    }
    
    return output;
}

/*set<int> RestaValores(const set<int> &s1, const set<int> &s2){

    set<int>::iterator it1, it2;
    
    it1 = s1.cbegin();

    for (it2 = s2.cbegin(); it2 != s2.cend(); ++it2){
        if (*it1 == *it2){
        *(it1) -= *(it2);
        }
    }
}*/

int main(){

    set<int> s1 = {1,2,4,5,7};
    set<int> s2 = {1,2,3,10};
    set<int> resultado;

    resultado = s1 - s2;

    for (auto it = resultado.begin(); it != resultado.end(); ++it){
        cout << *(it) << " ";
    }
    cout << endl;


}
