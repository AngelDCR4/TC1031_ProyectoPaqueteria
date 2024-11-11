//Ángel David Candelario Rolon
//A01712387

#include <iostream>
#include <vector>
#include <iomanip>
#include "Paquete.h"

using namespace std;

//CLASE MAIN
int main() {
    Paquete ejemplo;
    vector<Paquete> paquetes;
    ejemplo.ejemplos(paquetes);
    Sorts<float> sorts;
    Arbol arbol;

    bool continuar = true;

    //MENU
    while (continuar) {
        cout << "\n --> Paqueteria UHC <-- \n";
        cout << "1 -> Ver pedidos actuales\n";
        cout << "2 -> Agregar pedidos\n";
        cout << "3 -> Ver distancias mas cortas (Merge Sort)\n";
        cout << "4 -> Ver distancias ordenadas segun el ABB (In-order)\n";
        cout << "5 -> Guardar pedidos en archivo (Generar txt)\n";
        cout << "6 -> Salir\n";
        cout << "Seleccione una opcion: ";

        int opcion;
        cin >> opcion;

        //DESPLEGAR INFORMACIÓN DE PAQUETES
        //NIVEL DE COMPLEJIDAD -> O(n)
        if (opcion == 1) {
            ejemplo.mostrar_paquetes(paquetes);
        
        //AGREGAR PAQUETE AL VECTOR Y AL ARBOL
        //NIVEL DE COMPLEJIDAD -> O(n)
        } else if (opcion == 2) {

            ejemplo.agregar_paquete(paquetes);
            vector<float> distancias = ejemplo.calcdist(paquetes);
            arbol.construir_arbol(distancias);
        
        //CALCULAR DISTANCIAS Y AGREGAR AL VECTOR
        //NIVEL DE COMPLEJIDAD -> O(n log n)
        } else if (opcion == 3) {

            vector<float> distancias = ejemplo.calcdist(paquetes);
            sorts.ordenaMerge(distancias);
            cout << "Distancias ordenadas (Merge Sort):\n";
            for (int i = 0; i < distancias.size(); i++) {
                cout << "Paquete " << i + 1 << " - " << paquetes[i].get_nombreLugar() << " -> "
                << fixed << setprecision(2) << distancias[i] << endl;
            }
            cout << "\n";
        
        //CREAR ARBOL Y DESPLEGAR DISTANCIAS
        //NIVEL DE COMPLEJIDAD -> O(n log n)
        } else if (opcion == 4) {

            vector<float> distancias = ejemplo.calcdist(paquetes);
            arbol.construir_arbol(distancias);
            cout << "\nCreando arbol binario de busqueda...\n";
            cout << "Ordenando distancias en recorrido in-order...\n";
            cout << "Distancias desplegadas de menor a mayor:\n";
            arbol.imprimir_inorder();
        
        //ESCRIBIR ARCHIVO TXT
        //NIVEL DE COMPLEJIDAD -> O(n) 
        } else if (opcion == 5) {

            ejemplo.guardar_archivo(paquetes);
        
        //SALIR DEL PROGRAMA 
        } else if (opcion == 6) {

            continuar = false;
            cout << "Saliendo del sistema...\n";

        //OPCION INVALIDA
        } else {

            cout << "Opcion invalida, intente de nuevo.\n";
        }
    }

    return 0;
}
