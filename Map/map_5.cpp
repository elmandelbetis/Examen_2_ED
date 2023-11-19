/**
 * Desarrolla un programa que simule la gestión de un inventario de productos en una tienda. 
 * Utiliza un map<string, int> donde las claves sean los nombres de los productos y los valores 
 * sean las cantidades disponibles. Implementa funciones para agregar nuevos productos, actualizar
 * inventarios, vender productos (disminuir la cantidad disponible) y mostrar el inventario actualizado.
*/

#include <iostream>
#include <map>
using namespace std;

void MostrarInventario(map<string, int> &mapa){

    cout << "Estado actual del inventario de la tienda:\n";
    for (auto it : mapa){
        cout << it.first << ": " << it.second << endl;
    }

    cout << endl;
}

void AgregarProducto(map<string,int> &mapa){
    string producto;
    int cantidad_añadida;

    //Añadir producto a mapa, incrementar nº productos
    //Comprobar que si hay 0, se use at() para añadir 1
    //Y que si no es 0 sino otro, se añada igual
    
    cout << "Introduzca producto a añadir: (pulse '0' para terminar)\n";
    do{
        cin >> producto;
    }while(producto == "0");

    cout << "Introduzca la cantidad de producto a añadir al inventario: ";
    cin >> cantidad_añadida;
    
    if(mapa.find(producto) != mapa.end())
        mapa[producto] += cantidad_añadida;
    else   
        mapa[producto] = cantidad_añadida;

    MostrarInventario(mapa);

}

void VenderProducto(map<string,int> &mapa){
    string producto;
    int cantidad_vendida;

    cout << "Introduzca producto a vender: (pulse '0' para terminar)";
    do{
        cin >> producto;
        if (mapa.find(producto) == mapa.end())
            cout << "Introduzca un producto válido\n";

    }while(producto == "0" || mapa.find(producto) == mapa.end());

    cout << "Introduzca la cantidad de producto a vender: ";
    cin >> cantidad_vendida;
    
    mapa[producto] -= cantidad_vendida;
    int it = mapa[producto];
    
    if (it <= 0){
        cout << "Sólo se han podido vender " << (cantidad_vendida - abs(it)) << " productos\n";
        mapa.erase(producto);
    }

    MostrarInventario(mapa);


}

int main(){
    map<string,int> inventario;

//Añadimos 6 productos y vendemos parte (total o parcial) de 3 de ellos
    AgregarProducto(inventario);
    AgregarProducto(inventario);
    AgregarProducto(inventario);
    AgregarProducto(inventario);
    AgregarProducto(inventario);
    AgregarProducto(inventario);

    VenderProducto(inventario);
    VenderProducto(inventario);
    VenderProducto(inventario);

}