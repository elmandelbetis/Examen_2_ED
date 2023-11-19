#include <iostream>
#include <set>
using namespace std;


// EJEMPLOS DE USO DEL SET

int main(){

    //Encontrar elementos en un conjunto usando count()
    set<int> conjunto;
    for (int i = 1; i < 5; i++)
        conjunto.insert(i*3);
    for (int i = 0; i <= 12; i++){

        if (conjunto.count(i) > 0){
            cout << i << " está en el conjunto" << endl;
        }else{
            cout << i << " no está en el conjunto" << endl;
        }
    }

    conjunto.clear();

    //Añadir elementos a un conjunto usando emplace()
    //Añadir elementos a un conjunto usando un iterator y emplace_hint() para 
    //insertarlo a partir de un punto determinado
    set<int> cs;
    cs.emplace(2);
    cs.emplace(12); 
    /*cs.emplace(1);
    cs.emplace(7);*/
    auto it = cs.emplace_hint(cs.begin(),1);
    it = cs.emplace_hint(it, 7);

    for (auto it = cs.begin(); it != cs.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    

}