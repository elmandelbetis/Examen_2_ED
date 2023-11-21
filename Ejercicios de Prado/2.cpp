/*Dado un multimap con clave un string y con informaci�n asociada un entero obtener un mapa con clave el string e informaci�n asociada una lista con los enteros asociados al string. La funci�n ser�a:
map<string,list<int> > getMapa(const multimap<string,int> &multim)
Ej
Multim={<ahora,1>,<ahora,3>,<ahora,4>,<aunque,3>,<aunque,5>,<banco,2>,<banco,10>,<zanahoria,1>,<zanahoria,2>}
Map = {<ahora,{1,3,4}>,<aunque,{3,5}>,<banco,{2,10}>,<zanahoria,{1,2}>}*/

#include <iostream>
#include <map>
#include <list>
using namespace std;

map<string,list<int> > getMapa(const multimap<string,int> &multim){

    pair<multimap<string,int>::const_iterator, multimap<string,int>::const_iterator> rango;
    multimap<string,int>::const_iterator it = multim.cbegin();
    map<string,list<int> > output;

    while(it != multim.cend()){
        rango = multim.equal_range(it->first);
        list<int> lista;
        for (auto it2 = rango.first; it2 != rango.second; ++it2){
            lista.push_back(it2->second);
        }

        output.emplace(it->first, lista);
        it = rango.second;

    }

    return output;

}

int main(){
  multimap<string, int> mim({{"ahora",1},{"ahora",3},{"ahora",4},{"aunque",3},
                            {"aunque",5},{"banco",2},{"banco",10},
                            {"zanahoria",1},{"zanahoria",2}});
  map<string,list<int> > mimap=getMapa(mim);

  map<string,list<int> >::iterator it;
  for (it=mimap.begin(); it!=mimap.end();++it){
    cout<<"Clave: "<<it->first<<" "<< "Lista asoc. :";
    for (auto it_l = it->second.begin(); it_l!=it->second.end();++it_l)
        cout<<*it_l<<" ";
    cout<<endl;
   }
}
