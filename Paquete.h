#ifndef DISTANCIAS_H
#define DISTANCIAS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CLASE PAQUETE
class Paquete{
    private:
        string nomUsu;  //ATRIBUTO NOMBRE USUARIO
        string nomLug;  //ATRIBUTO LUGAR DE ENTREGA
        float x;        //COORDENADA X
        float y;        //COORDENADA Y
    public:
        //CONSTRUCTOR DEFAULT
        Paquete():nomUsu(""), nomLug(""), x(0), y(0){};
        //CONSTRUCTOR
        Paquete(string usu, string lug, float cx, float cy):
        nomUsu(usu),nomLug(lug),x(cx),y(cy){};
        
        //GETTERS
        string get_nombreUsuario(){return nomUsu;}
        string get_nombreLugar(){return nomLug;}
        float get_x(){return x;}
        float get_y(){return y;}
        //SETTERS
        void set_nombreUsuario(string usu){nomUsu = usu;}
        void set_nombreLugar(string lug){nomLug = lug;}
        void set_x(float cx) {x = cx;}
        void set_y(float cy) {y = cy;}

        //VECTOR DE PAQUETES PREEDETERMINADOS
        vector<Paquete> ejemplos(){
            return{
                Paquete("Ricardo", "CDMX", 1.2, 3.4),
                Paquete("Maria", "Guadalajara", 2.5, 4.6),
                Paquete("Jacob", "Monterrey", 5.1, 7.8),
                Paquete("Omar", "Puebla", 8.3, 6.2),
                Paquete("Pedro", "Cancun", 4.4, 9.7),
                Paquete("Lol", "Merida", 6.8, 2.3),
                Paquete("Sofia", "Leon", 7.9, 5.5),
                Paquete("Diego", "Toluca", 1.0, 3.3),
                Paquete("Elena", "Queretaro", 2.7, 6.4),
                Paquete("Fernando", "Tijuana", 5.9, 7.2),
                Paquete("Valeria", "Hermosillo", 9.0, 2.8),
                Paquete("Luis", "Chihuahua", 3.6, 8.9),
                Paquete("Ana", "Saltillo", 4.8, 7.1),
                Paquete("Javier", "Veracruz", 6.2, 5.3),
                Paquete("Patricia", "Oaxaca", 7.5, 4.0),
                Paquete("Miguel", "Aguascalientes", 2.1, 3.9),
                Paquete("Gabriela", "Morelia", 8.7, 6.6),
                Paquete("Roberto", "Culiacan", 9.3, 2.4),
                Paquete("Daniela", "Zacatecas", 3.8, 9.5),
                Paquete("Ricardo", "La Paz", 5.2, 4.4),
                Paquete("Raul", "Villahermosa", 7.3, 8.2),
                Paquete("Andrea", "San Luis Potosi", 4.1, 1.6),
                Paquete("Paola", "Reynosa", 6.9, 7.0),
                Paquete("Arturo", "Tampico", 2.9, 5.8),
                Paquete("Monica", "Tuxtla Gutierrez", 3.4, 6.7),
                Paquete("Carlos", "Colima", 8.1, 9.9),
                Paquete("Carmen", "Mazatlan", 4.9, 1.2),
                Paquete("Jorge", "Durango", 5.4, 7.4),
                Paquete("Isabel", "Irapuato", 6.1, 3.7),
                Paquete("Armando", "Xalapa", 9.8, 4.5),
                Paquete("Claudia", "Acapulco", 7.4, 2.6),
                Paquete("Eduardo", "Mexicali", 3.1, 8.3),
                Paquete("Alicia", "Ensenada", 1.4, 9.6),
                Paquete("Guillermo", "Manzanillo", 6.5, 4.2),
                Paquete("Natalia", "Tepic", 2.8, 1.8),
                Paquete("Francisco", "Cuernavaca", 5.7, 3.2),
                Paquete("Lorena", "Matamoros", 7.8, 9.1),
                Paquete("Rafael", "Nogales", 9.4, 2.1),
                Paquete("Veronica", "Chetumal", 4.6, 8.5),
                Paquete("Ivan", "Apizaco", 3.2, 7.9),
                Paquete("Rosa", "Iguala", 6.4, 5.0),
                Paquete("Felipe", "Guaymas", 8.6, 2.9),
                Paquete("Nancy", "Puerto Vallarta", 1.7, 6.3),
                Paquete("Enrique", "Celaya", 9.7, 3.0),
                Paquete("Marcela", "Coatzacoalcos", 2.4, 9.2),
                Paquete("Tomas", "Fresnillo", 4.7, 1.3),
                Paquete("Luz", "Guanajuato", 7.0, 8.8),
                Paquete("Hector", "Orizaba", 5.5, 2.2),
                Paquete("Estela", "Huatulco", 3.0, 4.3)
            };
            }
};

#endif
