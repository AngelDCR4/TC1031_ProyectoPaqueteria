//Ángel David Candelario Rolon
//A01712387

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "Paquete.h"

using namespace std;

//FUNCION DESPLIEGUE DE PEDIDOS
void mostrar_paquetes(vector<Paquete>& paquetes){
  cout << "Lista de pedidos:\n";
  cout << "FORMATO -> Paquete n -> Usuario, Destino, coordenada X, coordenada Y\n";
  for(int i = 0; i < paquetes.size(); i++){
    cout << "Paquete " << i + 1 << " -> " << paquetes[i].get_nombreUsuario() << ", " <<
         paquetes[i].get_nombreLugar() << ", " << fixed << setprecision(2) << paquetes[i].get_x()
         << ", " << fixed << setprecision(2) << paquetes[i].get_y() << endl;
  }
}

//FUNCION AGREGAR NUEVO PEDIDO
void agregar_paquete(vector<Paquete>& paquetes){
  string nomUsu;
  string nomLug;
  float x;
  float y;

  cout << "Ingrese el nombre del usuario: ";
  cin >> nomUsu;
  cout << "Ingrese el nombre del lugar: ";
  cin >> nomLug;
  cout << "Ingrese la coordenada x: ";
  cin >> x;
  cout << "Ingrese la coordenada y: ";
  cin >> y;

  Paquete nuevoPaquete(nomUsu, nomLug, x, y);
  paquetes.push_back(nuevoPaquete);
  cout << "Paquete agregado correctamente :D\n\n";
}

//CALCULAR DISTANCIAS Y GUARDAR EN VECTOR
vector<float>calcdist(vector<Paquete>& paquetes){
  vector<float>distancias;
  for(int i = 0; i < paquetes.size(); i++){
      float x = paquetes[i].get_x();
      float y = paquetes[i].get_y();
      float distancia = sqrt(pow(x,2) + pow(y,2));
      distancias.push_back(distancia);
  }
  return distancias;
}

//ALGORITMO DE ORDENAMIENTO - SELECTION SORT
void selectionsort(vector<float>& vec){
  int n = vec.size();

  for(int i = 0; i < n - 1; i++){
    int min = i;
    for(int j = i + 1; j < n; j++){
      if(vec[j] < vec[min]){
        min = j;
      }
    }
    swap(vec[i], vec[min]);
  }
}

//MENU
int main() {
  Paquete ejemplo;
  vector<Paquete> paquetes = ejemplo.ejemplos();


  bool continuar = true;

  while(continuar){
    cout << "\n --> Paqueteria UHC <-- \n";
    cout << "1 -> Ver pedidos actuales\n";
    cout << "2 -> Agregar pedidos\n";
    cout << "3 -> Ver distancias mas cortas\n";
    cout << "4 -> Salir\n";
    cout << "Seleccione una opcion: ";

    int opcion;
    cin >> opcion;

    if(opcion == 1){
      mostrar_paquetes(paquetes);
    }else if(opcion == 2){
      agregar_paquete(paquetes);
    }else if(opcion == 3){
      vector<float> distancias = calcdist(paquetes);
      selectionsort(distancias);
      cout << "Distancias ordenadas:\n";
      for(int i = 0; i < distancias.size(); i++){
        cout << fixed << setprecision(2) << distancias[i] << " -> ";}
      cout << "\n";
    }else if(opcion == 4){
      continuar = false;
      cout << "Saliendo del sistema...";
    }else{
      cout << "Opcion invalida intente de nuevo\n";
    }
  }

}
