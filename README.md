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
>Seleccionar opción 4 (Hacer arbol e imprimir inorder)
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

#### Implementación  del Arbol Binario
El implementar un arbol binario implica tener:

Mejor caso -> O(log n) se esta considerando que el arbol esta balanceado, es decir el arbol tiene una cantidad de hijos similar de cada lado

Caso promedio -> O(log n) se sigue considerando que el arbol esta balanceado 

Peor caso -> O(n) aquí se esta considerando que el arbol esta desbalanceado, es decir no todos los nodos tienen hijos y la forma en que se insertan los nodos de una manera irregular

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Elegí el merge Sort porque el algoritmo me permite ordenar las distancias de los paquetes debido a su alta eficiencia con la gran cantidad de datos que se pueden llegar a presentar a lo largo del desarrollo del proyecto. Su complejidad similar de O(n log n) en todos los casos se adecua a la situación que se esta manejando en mi proyecto y no a lo que se adecua a mi perpectiva. 

De igual manera elegí implementar el Arbol binario para almacenar y organizar las distancias calculadas de los paquetes debido a que me permite insertar, buscar y ordenar los datos que se presenten. El caso promedio O(log n) me beneficia en tener las distancias ordenandas y visualizarlas en un recorrido inorder

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructras correctos.

Implemente mecanismos para consultar los datos de los paquetes, utilice el algoritmo de Merge Sort para ordenarlas los datos de la manera más eficiente de acuerdo a la cantidad de datos que se pueden llegar a presentar. Ademas la implementación del Árbol binario consulta la información almacenada y me ayuda a consultar la información teniendo un recorrido inorder permitiendo visualizar la información de menor a mayor. Estos mecanismos me ayudana a consultar la información de manera eficiente y ordenada.
