//Ángel David Candelario Rolon
//A01712387

#include <iostream>
#include <vector>
#include <iomanip>
#include "Paquete.h"

using namespace std;

int main() {
    Paquete ejemplo;
    vector<Paquete> paquetes = ejemplo.ejemplos();
    Sorts<float> sorts;
    Arbol arbol;

    bool continuar = true;

    while (continuar) {
        cout << "\n --> Paqueteria UHC <-- \n";
        cout << "1 -> Ver pedidos actuales\n";
        cout << "2 -> Agregar pedidos\n";
        cout << "3 -> Ver distancias mas cortas (Merge Sort)\n";
        cout << "4 -> Hacer arbol e imprimir in-order\n";
        cout << "5 -> Salir\n";
        cout << "Seleccione una opcion: ";

        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            ejemplo.mostrar_paquetes(paquetes);
        
        } else if (opcion == 2) {

            ejemplo.agregar_paquete(paquetes);
            vector<float> distancias = ejemplo.calcdist(paquetes);
            arbol.construir_arbol(distancias);
        
        } else if (opcion == 3) {

            vector<float> distancias = ejemplo.calcdist(paquetes);
            sorts.ordenaMerge(distancias);
            cout << "Distancias ordenadas (Merge Sort):\n";
            for (int i = 0; i < distancias.size(); i++) {
                cout << fixed << setprecision(2) << distancias[i] << " -> "; //REDONDEAR A DOS DECIMALES
            }
            cout << "\n";
        
        } else if (opcion == 4) {

            vector<float> distancias = ejemplo.calcdist(paquetes);
            arbol.construir_arbol(distancias);
            cout << "Arbol in-order:\n";
            arbol.imprimir_inorder();
        
        } else if (opcion == 5) {

            continuar = false;
            cout << "Saliendo del sistema...\n";

        } else {

            cout << "Opcion invalida, intente de nuevo.\n";
        }
    }

    return 0;
}
