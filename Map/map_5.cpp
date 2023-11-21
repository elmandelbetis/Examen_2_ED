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
    int cantidad_aniadida;

    //Añadir producto a mapa, incrementar nº productos
    //Comprobar que si hay 0, se use at() para añadir 1
    //Y que si no es 0 sino otro, se añada igual
    
    cout << "Introduzca producto a añadir: ";
    do{
        cin >> producto;
    }while(producto == "0");

    do{
        cout << "Introduzca la cantidad de producto a añadir al inventario: ";
        cin >> cantidad_aniadida;

        if(cantidad_aniadida <= 0)
            cout << "La cantidad a añadir debe ser un número entero positivo.\n";

    }while(cantidad_aniadida <= 0);
    
    if(mapa.find(producto) != mapa.end())
        mapa[producto] += cantidad_aniadida;
    else   
        mapa[producto] = cantidad_aniadida;

    MostrarInventario(mapa);

}

void VenderProducto(map<string,int> &mapa){
    string producto;
    int cantidad_vendida;

    cout << "Introduzca producto a vender: ";
    do{
        cin >> producto;
        if (mapa.find(producto) == mapa.end())
            cout << "Introduzca un producto válido\n";

    }while(producto == "0" || mapa.find(producto) == mapa.end());

    do{
        cout << "Introduzca la cantidad de producto a vender: ";
        cin >> cantidad_vendida;

        if(cantidad_vendida <= 0)
            cout << "La cantidad a vender debe ser un número entero positivo.\n";

    }while(cantidad_vendida <= 0);
    
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