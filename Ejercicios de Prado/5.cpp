/**
 * Dado un mapa con clave palabra en un documento e información asociada una lista de
 * pares número de página y línea en la página donde aparece la palabra, crear la función
 *      set<string> getPalabrasPagina(const mapa<string,list<pair<int,int> > > & m,int pag)
 * que obtenga un conjunto con todas las palabras que aparecen en una determinada página.
 * 
 * Ej
 * M={<Informática,{<1,20>,<3,10}>,<Robot,{<3,20>,<10,15>,<4,1>}> ,<Sistema,{<2,10>,<10,5>}>}
 * 
 * Si preguntamos por la pagina 3 obtendríamos
 * 
 *      S={Informática, Robot}
*/

#include <iostream>
#include <set>
#include <map>
#include <list>
using namespace std;

set<string> getPalabrasPagina(const map<string,list<pair<int,int> > > &m, int pag){

    map<string,list<pair<int,int> > >::const_iterator it_mapa;
    set<string> conj_salida;

    for (it_mapa = m.cbegin(); it_mapa != m.cend(); ++it_mapa){
        list<pair<int,int> >::const_iterator it_lista;
        for (it_lista = it_mapa->second.cbegin(); it_lista != it_mapa->second.cend(); ++it_lista){
            if(it_lista->first == pag){
                conj_salida.insert(it_mapa->first);
            }
        }
    }

    return conj_salida;
}


int main(){

    map<string,list<pair<int,int> > > mimap({{"Informática",{{1,20},{3,10}}},
                                            {"Robot",{{3,20},{10,15},{4,1}}} ,{"Sistema",{{2,10},{10,5}}}});
    set<string> miset= getPalabrasPagina(mimap,3);

    cout << "{";
    for (auto it = miset.begin(); it!=miset.end();++it)
        cout << *it << ", ";
    cout << "}\n";

}