/**
 * Dados dos set construir la función 
 *         bool soncomplementarios(const set<int> & s1,const set<int> &s2)
 * que determine si dos conjuntos son complementarios. Diremos que dos conjuntos son
 * complementarios si entre dos elementos del primer conjunto existe uno y solo uno en el
 * segundo
 * Ej
 *  s1={1,5,7} s2={2,6} --> devolveria true
 *  s1={1,5,7} s2={2,3,6}-->devolveria false ya que 2,3 son mas de un elemento entre 1 y 5.
 * Además de que 6 no se podría poner entre 2 valores de s1. 
 * Nota: puesto que para que sean complementarios, el segundo debe ser menor que el primero.
 * Si el segundo no es menor, luego al apuntar para comparar, sig apuntará a basura virtual.
*/

#include <iostream>
#include <set>
using namespace std;

bool soncomplementarios(const set<int> &s1, const set<int> &s2){
    if (s2.size() != s1.size() - 1)
        return false;
    
    set<int>::const_iterator it1, it2, sig, final;
    final = s1.cend(); 
    --final; // se reduce el valor de final porque, por algún motivo, final = s2.cend()
             // apunta al 2 en vez de al 6
    it1 = s1.begin();
    it2 = s2.begin();

    while(it1 != final){
        sig = it1;
        ++sig; //apuntamos al siguiente valor en s1
        
        if(!(*it1 <= *it2 && *it2 < *sig)){
            return false;
        }
        
        ++it1;
        ++it2;
    }

    return true;
}

int main(){
    set<int> s1 = {1,5,7}, s2 = {2,6}, s3 = {1,5,7}, s4 = {2,3,6};

    if(soncomplementarios(s1,s2))
        cout << "Son complementarios\n";
    else  
        cout << "No son complementarios\n";
    if(soncomplementarios(s3,s4))
        cout << "Son complementarios";
    else 
        cout << "No son complementarios\n";
}