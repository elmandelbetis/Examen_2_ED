#include <iostream>
#include <set>
using namespace std;

void Imprimir(set<int> &miconj){
    for (auto it = miconj.begin(); it != miconj.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    set<int> miconj;
    set<int>::iterator init, fin;

    for(int i = 1; i <= 10; i++){
        miconj.insert(i*10);
    }

    Imprimir(miconj);

    init = miconj.lower_bound(22);
    fin = miconj.upper_bound(60);

    cout << *init << " " << *fin << endl;



}