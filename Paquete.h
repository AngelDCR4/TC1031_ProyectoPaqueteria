//Ángel David Candelario Rolon
//A01712387

#ifndef DISTANCIAS_H
#define DISTANCIAS_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

//NODOS
class Nodo {
public:
    float valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(float v) : valor(v), izquierda(NULL), derecha(NULL) {}
};

//ARBOL BINARIO
class Arbol {
private:
    Nodo* raiz;

    //INSERTAR NODO
    Nodo* insertar_nodo(Nodo* nodo, float valor) {
        if (nodo == NULL) {
            return new Nodo(valor);
        }
        if (valor < nodo->valor) {
            nodo->izquierda = insertar_nodo(nodo->izquierda, valor);
        } else {
            nodo->derecha = insertar_nodo(nodo->derecha, valor);
        }
        return nodo;
    }

    //INORDER
    void imprimir_inorder(Nodo* nodo) const {
        if (nodo != NULL) {
            imprimir_inorder(nodo->izquierda);
            cout << fixed << setprecision(2) << nodo->valor << " -> ";
            imprimir_inorder(nodo->derecha);
        }
    }

public:
    Arbol() : raiz(NULL) {}

    //INSERTAR
    void agregar(float valor) {
        raiz = insertar_nodo(raiz, valor);
    }

    //IMPRIMIR INORDER
    void imprimir_inorder() const {
        imprimir_inorder(raiz);
        cout << "\n";
    }

    //CONSTRUIR ARBOL
    void construir_arbol(const vector<float>& distancias) {
        raiz = NULL;  //REINICIAR
        for (int i = 0; i < distancias.size(); i++) {
            agregar(distancias[i]); //AGREGAR CADA ELEMENTO AL ARBOL
        }
    }
};


template <class T>
class Sorts {
public:
    void ordenaMerge(vector<T>& v);
private:
    void mergeSplit(vector<T>& A, vector<T>& B, int low, int high);
    void mergeArray(vector<T>& A, vector<T>& B, int low, int mid, int high);
};

//MERGE ARRAY
template <class T>
void Sorts<T>::mergeArray(vector<T>& A, vector<T>& B, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= high) {
        B[k++] = A[j++];
    }

    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

//MERGE SPLIT
template <class T>
void Sorts<T>::mergeSplit(vector<T>& A, vector<T>& B, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSplit(A, B, low, mid);
        mergeSplit(A, B, mid + 1, high);
        mergeArray(A, B, low, mid, high);
    }
}

//MERGE SORT
template <class T>
void Sorts<T>::ordenaMerge(vector<T>& v) {
    int size = v.size();
    vector<T> temp(size);
    mergeSplit(v, temp, 0, size - 1);
}

//CALSE PAQUETE
class Paquete {
private:
    string nomUsu;
    string nomLug;
    float x; //COORDENADA X
    float y; //COORDENADA Y

public:
    //CONSTRUCTORES
    Paquete();
    Paquete(string usu, string lug, float cx, float cy);

    //GETTERS
    string get_nombreUsuario();
    string get_nombreLugar();
    float get_x();
    float get_y();

    //SETTERS
    vector<Paquete> ejemplos();
    void mostrar_paquetes(vector<Paquete>& paquetes);
    void agregar_paquete(vector<Paquete>& paquetes);
    vector<float> calcdist(vector<Paquete>& paquetes);
};

//CONSTRUCTORES
Paquete::Paquete() : nomUsu(""), nomLug(""), x(0), y(0) {}
Paquete::Paquete(string usu, string lug, float cx, float cy) : nomUsu(usu), nomLug(lug), x(cx), y(cy) {}

//GETTERS
string Paquete::get_nombreUsuario() { return nomUsu; }
string Paquete::get_nombreLugar() { return nomLug; }
float Paquete::get_x() { return x; }
float Paquete::get_y() { return y; }

//VER PEDIDOS ACTUALES
void Paquete::mostrar_paquetes(vector<Paquete>& paquetes) {
    cout << "Lista de pedidos:\n";
    for (int i = 0; i < paquetes.size(); i++) {
        cout << "Paquete " << i + 1 << " -> " << paquetes[i].get_nombreUsuario() << ", "
             << paquetes[i].get_nombreLugar() << ", " << fixed << setprecision(2)
             << paquetes[i].get_x() << ", " << fixed << setprecision(2) << paquetes[i].get_y() << endl;
    }
}

//AGREGAR PAQUETE
void Paquete::agregar_paquete(vector<Paquete>& paquetes) {
    string nomUsu, nomLug;
    float x, y;

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
    cout << "Paquete agregado correctamente :D\n";
}

//CALCULAR DISTANCIAS
vector<float> Paquete::calcdist(vector<Paquete>& paquetes) {
    vector<float> distancias;
    for (int i = 0; i < paquetes.size(); i++) {
        float distancia = sqrt(pow(paquetes[i].get_x(), 2) + pow(paquetes[i].get_y(), 2));
        distancias.push_back(distancia); //GUARDAR DISTANCIAS
    }
    return distancias;
}

//PAQUETES POR DEFAULT
vector<Paquete> Paquete::ejemplos() {
    vector<Paquete> paquetes;
    paquetes.push_back(Paquete("Ricardo", "CDMX", 1.2, 3.4));
    paquetes.push_back(Paquete("Maria", "Guadalajara", 2.5, 4.6));
    paquetes.push_back(Paquete("Jacob", "Monterrey", 5.1, 7.8));
    paquetes.push_back(Paquete("Omar", "Puebla", 8.3, 6.2));
    paquetes.push_back(Paquete("Pedro", "Cancun", 4.4, 9.7));
    paquetes.push_back(Paquete("Lol", "Merida", 6.8, 2.3));
    paquetes.push_back(Paquete("Sofia", "Leon", 7.9, 5.5));
    paquetes.push_back(Paquete("Diego", "Toluca", 1.0, 3.3));
    paquetes.push_back(Paquete("Elena", "Queretaro", 2.7, 6.4));
    paquetes.push_back(Paquete("Fernando", "Tijuana", 5.9, 7.2));
    paquetes.push_back(Paquete("Valeria", "Hermosillo", 9.0, 2.8));
    paquetes.push_back(Paquete("Luis", "Chihuahua", 3.6, 8.9));
    paquetes.push_back(Paquete("Ana", "Saltillo", 4.8, 7.1));
    paquetes.push_back(Paquete("Javier", "Veracruz", 6.2, 5.3));
    paquetes.push_back(Paquete("Patricia", "Oaxaca", 7.5, 4.0));
    paquetes.push_back(Paquete("Miguel", "Aguascalientes", 2.1, 3.9));
    paquetes.push_back(Paquete("Gabriela", "Morelia", 8.7, 6.6));
    paquetes.push_back(Paquete("Roberto", "Culiacan", 9.3, 2.4));
    paquetes.push_back(Paquete("Daniela", "Zacatecas", 3.8, 9.5));
    paquetes.push_back(Paquete("Ricardo", "La Paz", 5.2, 4.4));
    paquetes.push_back(Paquete("Raul", "Villahermosa", 7.3, 8.2));
    paquetes.push_back(Paquete("Andrea", "San Luis Potosi", 4.1, 1.6));
    paquetes.push_back(Paquete("Paola", "Reynosa", 6.9, 7.0));
    paquetes.push_back(Paquete("Arturo", "Tampico", 2.9, 5.8));
    paquetes.push_back(Paquete("Monica", "Tuxtla Gutierrez", 3.4, 6.7));
    paquetes.push_back(Paquete("Carlos", "Colima", 8.1, 9.9));
    paquetes.push_back(Paquete("Carmen", "Mazatlan", 4.9, 1.2));
    paquetes.push_back(Paquete("Jorge", "Durango", 5.4, 7.4));
    paquetes.push_back(Paquete("Isabel", "Irapuato", 6.1, 3.7));
    paquetes.push_back(Paquete("Armando", "Xalapa", 9.8, 4.5));
    paquetes.push_back(Paquete("Claudia", "Acapulco", 7.4, 2.6));
    paquetes.push_back(Paquete("Eduardo", "Mexicali", 3.1, 8.3));
    paquetes.push_back(Paquete("Alicia", "Ensenada", 1.4, 9.6));
    paquetes.push_back(Paquete("Guillermo", "Manzanillo", 6.5, 4.2));
    paquetes.push_back(Paquete("Natalia", "Tepic", 2.8, 1.8));
    paquetes.push_back(Paquete("Francisco", "Cuernavaca", 5.7, 3.2));
    paquetes.push_back(Paquete("Lorena", "Matamoros", 7.8, 9.1));
    paquetes.push_back(Paquete("Rafael", "Nogales", 9.4, 2.1));
    paquetes.push_back(Paquete("Veronica", "Chetumal", 4.6, 8.5));
    paquetes.push_back(Paquete("Ivan", "Apizaco", 3.2, 7.9));
    paquetes.push_back(Paquete("Rosa", "Iguala", 6.4, 5.0));
    paquetes.push_back(Paquete("Felipe", "Guaymas", 8.6, 2.9));
    paquetes.push_back(Paquete("Nancy", "Puerto Vallarta", 1.7, 6.3));
    paquetes.push_back(Paquete("Enrique", "Celaya", 9.7, 3.0));
    paquetes.push_back(Paquete("Marcela", "Coatzacoalcos", 2.4, 9.2));
    paquetes.push_back(Paquete("Tomas", "Fresnillo", 4.7, 1.3));
    paquetes.push_back(Paquete("Luz", "Guanajuato", 7.0, 8.8));
    paquetes.push_back(Paquete("Hector", "Orizaba", 5.5, 2.2));
    paquetes.push_back(Paquete("Estela", "Huatulco", 3.0, 4.3));

    return paquetes;
}

#endif

