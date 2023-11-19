#include <iostream>
#include <set>
#include <queue>
using namespace std;

set<int> UnionConjuntosCola(queue<set<int>> &C){
    set<int> output;
    
    while (!C.empty()){
        for (auto it = C.front().begin(); it != C.front().end(); ++it){
            output.insert(*it);
        }
        C.pop();
    }

    return output;
}

int main(){
    queue<set<int>> q1;

    set<int> s1 = {1,2,3,4};
    set<int> s2 = {2,5,6};
    set<int> s3 = {8,9,10};
    set<int> conj_resultado;

    q1.push(s1);
    q1.push(s2);
    q1.push(s3);

    conj_resultado = UnionConjuntosCola(q1);

    for (auto it = conj_resultado.begin(); it != conj_resultado.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}