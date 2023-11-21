/*Dado un multiset de enteros obtener un mapa con clave el entero en el multiset y con informaci�n asociada el n�mero de veces que aparece. La funci�n ser�a:
map<int,int> getFrecuencia(const multiset<int> &ms)
Ej
Ms={1,1,1,1,3,3,3,2,2,6,6,6} -----> equal_range
Map={<1,4>,<3,3>,<2,2>,<6,3>}
*/

#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int,int> getFrecuencia(const multiset<int> &ms){
    /**
     * Crear mapa que almacene un nº y el nº de veces que se repite en el multiset
     * Para eso, podemos crear un par de iteradores donde se almacene el equal_range de un elemento en el
     * iterador. El primer elemento por ejemplo puede ser un 1, y el segundo el 3 pues es el inmediatamente mayor
     * 
     * */ 
    
    map<int,int> output; //mapa con valores de salida
    typedef multiset<int>::const_iterator it_MS; //acortamos términos creando un alias
    
    pair<it_MS,it_MS> contenedor_rangos; //par de iteradores que almacenan los dos iteradores devueltos por equal_range
    it_MS it = ms.cbegin();

    while(it != ms.cend()){
        
        int contador = 0;
        contenedor_rangos = ms.equal_range(*it);
        for (auto it2 = contenedor_rangos.first; it2 != contenedor_rangos.second; ++it2){
            contador++;
        }
        output.emplace(*it, contador);
        it = contenedor_rangos.second;  //con esto nos aseguramos de que a la siguiente, 
                                        //it se sitúe sobre el valor grande y posterior

    } 

    return output;
}


int main(){

    map<int,int> frecuenciasNumericas;
    multiset<int> Ms = {1,1,1,1,3,3,3,2,2,6,6,6};

    frecuenciasNumericas = getFrecuencia(Ms);

    cout << "Map: {";
    for (auto it = frecuenciasNumericas.begin(); it != frecuenciasNumericas.end(); ++it){
        cout << "<" << it->first << ", " << it->second << "> ";
    }
    cout << endl;
}