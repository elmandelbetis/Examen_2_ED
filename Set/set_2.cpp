#include <iostream>
#include <set>
using namespace std;

int main(){
    
    set<int> miconj;
    
    for (int i=0; i<5; i++){
        miconj.insert(i);
    }
    cout << miconj.size() << endl;

    for (auto it = miconj.begin(); it != miconj.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    if (!miconj.empty()){
        pair<set<int>::iterator, set<int>::iterator> ret = miconj.equal_range(5);
        if (*(ret.first) == 5){
            miconj.erase(*(ret.first)); //borra la parejita del rango entre 5 y su inmediatamente mayor
            miconj.erase(*(ret.second));
        }else{
            miconj.erase(miconj.find(1)); // si no, borra la posicion donde haya un 1, si es q lo hay
        }
    }

    for (auto it = miconj.begin(); it != miconj.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

}