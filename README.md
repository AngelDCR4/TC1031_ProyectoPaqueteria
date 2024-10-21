# Proyecto: Paqueteria UHC
El proyecto consiste en un sistema de una empresa de paqueteria. El sistema es capaz de visualizar los pedidos que esten registrados en el sistema, agregar nuevos pedidos y organizar las distancias de menor a mayor para tener una ruta adecuada de la entrega de los paquetes

## Avance 1
El proyecto puede desplegar un menu en el que el administrador del sistema pueda seleccionar algunas de las opciones presentadas:
1 - Ver pedidos actuales
Se desplegara en la terminal todos los pedidos mostrando su nombre, destino, coordenadas xy

2 - Agregar pedidos
Se solicitara al administrador ingresar el nombre del usuario que solicita la entrega del paquete, el lugar de destino y las coordenadas xy dentro del mapa

3 - Ver distancias mas cortas
Los paquetes que esten en el sistema continen coordenadas, se calcularan sus distancias y seran organizadas de menor a mayor para tener a la mano la mejor ruta posible para la entrega de los paquetes

4 - Salir
Salir del sistema y finalizar el programa

## Avance 2
En esta etapa del proyecto se desarrollarón mejoras importantes en la estructura del programa y ademas se implementarón nuevas funciones para optimizar el manejo de los daots y la organización del código:

1 - Estructuración de programa: se simplifico el main.cpp separando los metodos principales (como agregar paquetes y calcular distancias) y pasandolos al archivo Paquete.h mejorando la legibilidad y entendimiento del código.

2 - Implementación del Algoritmo Merge Sort: se sustituyo el algoritmo de ordenamiento selection sort por Merge sort para tener un mejor manejo del volumen de datos. La complejidad de Merge Sort es de O(n log n) lo que hace se ajusta más al ordenamiento de las distancias de cada paquete. 

3 - Implementación del Árbol binario: se implemento el árbol binario para almacenar y organizar las distancias calculadas, ademas se desarrollo un recorrido inorder permitiendo visualizaar las distancias en un order de menor a mayor.

4 - Actualización del menú: se actualizo el menu para incluir una nueva opción que permite generar e imprimir el árbol binario con las distancias ordenadas de menor a mayor, ademas se especifica el uso del metedo de ordenamiento Merge Sort

## Ejemplo de uso

>PASO 1: Visualizar lista de pedidos
>
>Seleccionar opción 1
>
>PASO 2: Agregar pedidos con el siguiente formato:
>
>Ingresar -> Roberto
>
>Ingresar -> Chihuahua
>
>Ingresar -> 56
>
>Ingresar -> 87
>
>PASO 3: Visualizar lista de pedidos actualizados
>
>Seleccionar opcion 3 (Ver distancias mas cortas (Merge Sort))
>
>Visualizar distancias ordenadas de menor a mayor
>
>Seleccionar opción 4 (Hacer arbol e imprimir in-order)
>
>Visualizar arbol ordenado de menor a mayor
>
>PASO 5: Salir del sistema

### Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal

`cd "DIRECCION DE CARPETA EN DONDE SE ENCUETRA EL main.cpp"` 

Posteriormente ejecuta el siguiente comando en la terminal:

`g++ main.cpp` 

### Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./a.exe` 

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

#### Implementación del Merge Sort
Implemente el algoritmo de Merge Sort en lugar de Selection Sort, aunque el proyecto no contenga una gran cantidad de datos el proyecto necesita de un algoritmo capaz de manejar una gran cantidad de datos manejando mejor el tiempo de ordenamiento y se tiene que:

Mejor caso -> O(n log n) esto se debe a que el algortimo siempre realiza el mismo número de divisiones y comparaciones sin importar la cantidad inicia de datos

Caso promedio -> O(n log n) esto se debe a que independientemente de como esten los datos, el algoritmo continua dividiendo el arreglo o vector en mitades hasta que se tenga un solo dato

Peor caso -> O(n log n) incluso si la cantidad de datos estan desordenados el algoritmo sigue haciendo la misma operación, dividir el arreglo en mitades y luego combinar

La razón de que el algoritmo de Merge Sort mantenga la misma complejidad en todos los casos es porque se sigue la misma estructura recursiva de dividir el arreglo en mitades y combinar las mitades ordenadas sin importar la cantidad de datos

Implementación del Selection Sort: Implemente el algoritmo de Selection Sort en la función "selectionsort(vector<float>& vec)". Este algoritmo tiene una complejidad de O(n^2), ya que en cada iteración del bucle se recorre la lista para encontrar el valor mínimo a intercambiar, lo que involucra dos bucles distintos pero enlazados.

Arbol Binario
### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Seleccione este algoritmo de ordenamient Select Sort debido a que el volumen de datos es bajo. El Selection Sort es adecuado para listas pequeñas o cuando se prefiere la simplicidad en el código. Elegi implementar el algoritmo de Selection Sort para ordenar las distancias de los paquetes respecto al origen (0,0) lo cual es apropiado en este contexto. El Selection Sort es fácil de entender y de implementar, por lo que resulta adecuado para casos donde no se esperan grandes volúmenes de datos.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.



