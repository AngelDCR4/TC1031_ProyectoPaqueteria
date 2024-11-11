//Ángel David Candelario Rolon
//A01712387

#ifndef DISTANCIAS_H
#define DISTANCIAS_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>

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

//CLASE PAQUETE
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

    //METODOS
    void ejemplos(vector<Paquete>& paquetes);
    void mostrar_paquetes(vector<Paquete>& paquetes);
    void agregar_paquete(vector<Paquete>& paquetes);
    vector<float> calcdist(vector<Paquete>& paquetes);
    void cargar_csv(vector<Paquete>& paquetes, const string& archivo_csv);
    void guardar_archivo(vector<Paquete>& paquetes);
};

//CONSTRUCTORES
Paquete::Paquete() : nomUsu(""), nomLug(""), x(0), y(0) {}
Paquete::Paquete(string usu, string lug, float cx, float cy) : nomUsu(usu), nomLug(lug), x(cx), y(cy) {}

//GETTERS
string Paquete::get_nombreUsuario() { return nomUsu; }
string Paquete::get_nombreLugar() { return nomLug; }
float Paquete::get_x() { return x; }
float Paquete::get_y() { return y; }

//LEER ARCHIVO CSV
void Paquete::cargar_csv(vector<Paquete>& paquetes, const string& archivo_csv) {
    ifstream archivo(archivo_csv.c_str());
    string linea;
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << archivo_csv << endl;
        return;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nomUsu, nomLug, sx, sy;
        float x, y;

        getline(ss, nomUsu, ',');
        getline(ss, nomLug, ',');
        getline(ss, sx, ',');
        getline(ss, sy, ',');

        x = stof(sx);
        y = stof(sy);

        paquetes.push_back(Paquete(nomUsu, nomLug, x, y));
    }
    archivo.close();
}

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
void Paquete::ejemplos(vector<Paquete>& paquetes) {
    cargar_csv(paquetes, "datos_paquetes.csv");
}

//GUARDAR EN ARCHIVO
void Paquete::guardar_archivo(vector<Paquete>& paquetes) {
    ofstream archivo("paquetes_uhc.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < paquetes.size(); i++) {
            archivo << "Paquete " << i + 1 << " -> "
                    << paquetes[i].get_nombreUsuario() << ", "
                    << paquetes[i].get_nombreLugar() << ", "
                    << fixed << setprecision(2) << paquetes[i].get_x() << ", "
                    << fixed << setprecision(2) << paquetes[i].get_y() << endl;
        }
        archivo.close();
        cout << "La informacion de los paquetes se guardo en 'paquetes_uhc.txt'.\n";
    } else {
        cerr << "No se pudo abrir el archivo para guardar.\n";
    }
}

#endif
