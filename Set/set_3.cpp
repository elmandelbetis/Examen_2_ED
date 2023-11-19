#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> miconj;
    for (int i=1; i<=5; i++){
        miconj.insert(i*10);
    }

    for (auto it = miconj.begin(); it != miconj.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    auto it = miconj.find(20);
    miconj.erase(it);

    for (auto it = miconj.begin(); it != miconj.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    miconj.erase(miconj.find(40));
    for (it = miconj.begin(); it != miconj.end(); ++it){
        cout << *it << " ";
    }
    cout<<endl;
}