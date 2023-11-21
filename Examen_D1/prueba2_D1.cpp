#include <iostream>
#include <list>
#include <set>
#include <algorithm>


using namespace std;



template<typename T>
ostream& operator<<(ostream &os, const set<T> &l);
template<typename T>
ostream& operator<<(ostream &os, const list<T> &l);
void test_mas_conectado(const list< set<int> > &LS, int expected);



int mas_conectado(const list< set<int> > &LS) {
    
    int max_conexiones = 0;
    int conj_max_conexiones = 0;
    int indice = 0;

    for (const auto conjunto: LS){
        int conexiones = 0;

        for (const auto otro_conjunto : LS){
            if (conjunto != otro_conjunto){
                set<int> interseccion;
                std::set_intersection(conjunto.begin(), conjunto.end(),
                        otro_conjunto.begin(), otro_conjunto.end(),
                        inserter(interseccion, interseccion.begin()));
                
                if (!interseccion.empty())
                    conexiones++;
            }

        }

        if(conexiones > max_conexiones){
            max_conexiones = conexiones;
            conj_max_conexiones = indice;
        }

        indice++;
    }

    return conj_max_conexiones;



}



int main() {

    /* Cada línea es un test diferente */
    list< set<int> > inputs[] = { 
        { {0}, {1}, {2}, {0,1,2} },
        { {0,1,2}, {0}, {1}, {2} },
        { {0,6,9}, {5,6,9}, {5}, {1}, {5,9}, {5}, {1,5,7} }
    };

    /* Resultados esperados */
    int results[] = {
        3,
        0,
        1
    };
  
    int num_tests = sizeof(results) / sizeof(int);
  
    for(int i=0; i<num_tests; i++) {
        cout << "Test " << i << endl;
        test_mas_conectado(inputs[i], results[i]);
    }
  
    return 0; 
}







template<typename T>
ostream& operator<<(ostream &os, const set<T> &l) {
    os << '{';
    for(auto it=l.begin(); it != l.end(); ++it) {
        if(it != l.begin())
            os << ", ";
        os << *it;
    }
    os << '}';
    return os;
}


template<typename T>
ostream& operator<<(ostream &os, const list<T> &l) {
    os << '[';
    for(auto it=l.begin(); it != l.end(); ++it) {
        if(it != l.begin())
            os << ", ";
        os << *it;
    }
    os << ']';
    return os;
}


void test_mas_conectado(const list< set<int> > &LS, int expected) {
    int generated = mas_conectado(LS);
    cout << LS << " -> " << generated << endl;
    if(generated == expected) {
        cout << "Test passed" << endl;
    } else {
        cout << "Test failed (" << generated << " != " << expected << ")" << endl;
    }
    cout << endl;
}
