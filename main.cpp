//Ángel David Candelario Rolon
//A01712387

#include <iostream>
#include <vector>
#include <iomanip>
#include "Paquete.h"

using namespace std;

int main() {
    Paquete ejemplo;
    vector<Paquete> paquetes;
    ejemplo.ejemplos(paquetes);  // Cargar los paquetes desde el archivo CSV

    Sorts<float> sorts;
    Arbol arbol;

    bool continuar = true;

    while (continuar) {
        cout << "\n --> Paqueteria UHC <-- \n";
        cout << "1 -> Ver pedidos actuales\n";
        cout << "2 -> Agregar pedidos\n";
        cout << "3 -> Ver distancias mas cortas (Merge Sort)\n";
        cout << "4 -> Ver distancias ordenadas segun el ABB (In-order)\n";
        cout << "5 -> Guardar pedidos en archivo\n";
        cout << "6 -> Salir\n";
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
                cout << "Paquete " << i + 1 << " - " << paquetes[i].get_nombreLugar() << " -> "
                << fixed << setprecision(2) << distancias[i] << endl;
            }
            cout << "\n";
        
        } else if (opcion == 4) {

            vector<float> distancias = ejemplo.calcdist(paquetes);
            arbol.construir_arbol(distancias);
            cout << "\nCreando arbol binario de busqueda...\n";
            cout << "Ordenando distancias en recorrido in-order...\n";
            cout << "Distancias desplegadas de menor a mayor:\n";
            arbol.imprimir_inorder();
        
        } else if (opcion == 5) {

            ejemplo.guardar_en_archivo(paquetes);
        
        } else if (opcion == 6) {

            continuar = false;
            cout << "Saliendo del sistema...\n";

        } else {

            cout << "Opcion invalida, intente de nuevo.\n";
        }
    }

    return 0;
}
