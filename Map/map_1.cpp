#include <iostream>
#include <map>
using namespace std;

int main(){

    map<string,int> mimapa;

    mimapa["Alvaro"] = 12;
    mimapa["Franco"] = 23;
    mimapa["Stalin"] = 25;
    mimapa["Juan de Dios"] = 24;
    mimapa["Bombardeen Teruel"] = 14;

    for (auto it = mimapa.begin(); it != mimapa.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }

    auto busca = mimapa.find("Franco");
    if (busca != mimapa.end()){
        cout << "Lo encontré\n";
    }else{
        cout << "No lo encontré\n";
    }

    auto busca_1 = mimapa.find("esferg");
    if (busca_1 != mimapa.end()){
        cout << "Lo encontré\n";
    }else{
        cout << "No lo encontré\n";
    }

    auto comp = mimapa.value_comp();
    string key_1 = "Alvaro";
    string key_2 = "Franco";

    if (comp(*(mimapa.find(key_1)), *(mimapa.find(key_2)))){
        cout << mimapa[key_1] << " es menor que " << mimapa[key_2] << endl;
    }else{
        cout << mimapa[key_1] << " es mayor que " << mimapa[key_2] << endl;
    }

    mimapa.insert(make_pair("Merequetengue",100));
    for (auto it = mimapa.begin(); it != mimapa.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }
}