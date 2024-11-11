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

## Avance 3
En esta etapa del proyecto se implementarón tres cambios fundamentales dentro del funcionamiento del programa:

1 - Eliminación de paquetes ejemplo: se elimino la sección de información predeterminada dentro código (los paquetes por default) con el proposito de la simplificación del código y de hacer más accesible la modificación a esta información.

2 - Implementación de lectura de archivo csv: Se implemento la función de lectura de un archivo de excel csv para la carga de datos. Se hizo uso de la información predeterminada (paquetes por default) para la creación de este excel. Esto con el proposito de tener mejor accesibilidad a esta información.

3 - Implementación de escritura de archivo txt: Se implemento la función de guardar y  escribir los datos en un archivo de texto. Esto con el proposito de tener una mejor consulta de la información guardada al momento de usar el programa. 

Otros cambios pequeños que se realizarón dentro de este avance son:

1 - La opción 3 de "Ver distancias mas cortas (Merge Sort)" ahora también despliega el número de paquete junto con su lugar de destino y la distancia correspondiente e imprime todos los paquetes con sus distancias de menor a mayor.

2 - La opción 4 de "Ver distancias ordenadas segun el ABB (In-order)" ahora despliega información del proceso que se esta realizando para poder imprimir las distancias de menor a mayor. Esto con el proposito de tener un mejor entendimiento de que se esta realizando para el usuario final.

3 -  Se considerarón todos los nivel de complejidad de todos las estructuras de datos y de los metodos u operaciones.

## Ejemplo de uso

>PASO 1: Consultar archivo csv
>
>Visualizar o agregar más información al archivo csv almacenado en la misma carpeta en donde esta el programa
>
>PASO 2: Ejecutar archivo .exe en cmd
>
>PASO 3: Visualizar lista de pedidos
>
>Seleccionar opción 1
>
>PASO 4: Agregar pedidos con el siguiente formato:
>
>Ingresar -> Roberto
>
>Ingresar -> Chihuahua
>
>Ingresar -> 56
>
>Ingresar -> 87
>
>PASO 5: Visualizar lista de pedidos actualizados
>
>Seleccionar opcion 3 (Ver distancias mas cortas (Merge Sort))
>
>Visualizar distancias ordenadas de menor a mayor
>
>PASO 6: Seleccionar opción 4 (Ver distancias ordenadas segun el ABB (In-order))
>
>Visualizar arbol ordenado de menor a mayor
>
>PASO 7: Seleccionar opción 5 (Guardar pedidos en archivo)
>
>Abrir archivo txt almacenado en la misma carpeta
>
>PASO 8: Salir del sistema

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

#### ESTRUCTURA DE DATOS Y COMPONETES

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

#### Vector de paquetes

El vector de paquetes se encarga de almacenar la información (Nombre, Destino, Coordenada X, Coordenada Y). Este vector me permite tener acceso a la información de cada paquete o elemento. Este vector es de suma importancia ya que permite tener una facilidad para recorrer y agregar información a este mismo. Se llega a usar desde la carga inicial de los datos, la visualización de los datos, el calculo y almacenamiento de las distancias, ordenamiento con el Merge Sort, construcción del ABB y en el guardado de la información en el archivo txt.

#### FUNCIONES

####  `insertar_nodo`:

Esta función inserta valores dentro del ABB siguiendo las reglas de ordenamiento de un árbol binario de búsqueda y su nivel de complejidad en el caso promedio es de O(log n) cuando se trata de un árbol balanceado y en el peor caso es de O(n) ya que tendra que recorrer todos los nodos cuando el árbol este desbalanceado.

####  `imprimir_inorder`

Esta función hace un recorrido in-order (izquierda -> raíz -> derecha) dentro del ABB y su nivel de complejidad es de O(n) ya que debe de recorrer todos los nodos del ABB.

####  `construir_arbol`

Esta función inicia el Árbol de Busqueda Binaria y agrega cada elemento al vector de distancias ordenadas según sus reglas. Para agregar requiere llamar al metodo agregar y esto implica que su nivel de complejidad es de O(n log n) en el caso promedio, es decir, cuando el árbol esta balanceado, sin embargo, en el peor de los casos cuando el arbol esta desbalanceado cada agregación desde este método implica un nivel de complejidad O(n^2).

####  `ejemplos`

Esta función carga los paquetes por default desde un archivo csv y los pasa al vector de paquetes. Su nivel de complejidad es de O(n) ya que solo recorre cada línea del archivo csv y agrega cada paquete al vector.

####  `mostrar_paquetes`

Esta función imprime todos los paquetes que se encuentran dentro del vector paquetes de manera legible. Su nivel de complejidad es de O(n) ya que imprime cada uno de los paquetes.

####  `agregar_paquete`

Esta función solicita información al usuario para la agregación de un nuevo paquete y lo añade al vector de paquetes. Su nivel de complejidad es de O(1) ya que solo agrega la información proporcionada al final del vector.

####  `calcdist`

Esta función permite calcular la distancia desde el punto de origen hasta lo acorde según las coordenadas XY, esto para cada uno de los paquetes del vector. Su nivel de complejidad es de O(n) ya que calcula la distancia acorde a la cantidad de paquetes almacenadas en el vector. 

####  `cargar_csv`

Esta función lee el archivo csv y toda la información de cada paquete los agrega al vector de paquetes. Su nivel de complejidad es de O(n) ya que lee cada linea o fila del archivo csv 

####  `guardar_archivo`

Esta función guarda y escribe toda la información del vector paquetes en un archivo txt. Su nivel de complejidad es de O(n) ya que escribe la información acorde a la cantidad de paquetes que almacena el vector.

#### COMPLEJIDAD FINAL

####  Opción 1: Ver Pedidos Actuales

Esta función llama a `mostrar_paquetes` que tiene un nivel de complejidad de O(n) debido a que imprime todos los paquetes del vector.

####  Opción 2: Agregar Pedidos

Esta función llama a `agregar_paquete` que tiene un nivel de complejidad de O(1) y a `calcdist` con un nivel de O(n). Para esta opción su nivel de complejidad que se le asigna es de O(n) ya que es la más dominante.

####  Opción 3: Ver Distancias Ordenadas (Merge Sort):

Esta función llama a `calcdist` y tiene un nivel de complejidad de O(n) para posteriormente aplicar Merge Sort que tiene un nivel O(n log n) y este mismo nivel de complejidad se le asigna a esta opción.

####  Opción 4: Ver Distancias Ordenadas Según el ABB (In-order):

Esta función llama a `construir_arbol` que tiene un nivel de complejidad de O(n log n) en los casos promedios y luego acude a `imprimir_inorder` que tiene un nivel de O(n). Es el nivel O(n log n) que se le asigna a esta opción.

####  Opción 5: Guardar Pedidos en Archivo:

Esta función llama a `guardar_archivo` que tiene un nivel de complejidad de O(n) ya que solo hace un recorrido del vector para escribirlo en el archivo txt. Es este mismo nivel el que se aplica a esta opción

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Elegí el merge Sort porque el algoritmo me permite ordenar las distancias de los paquetes debido a su alta eficiencia con la gran cantidad de datos que se pueden llegar a presentar a lo largo del desarrollo del proyecto. Su complejidad similar de O(n log n) en todos los casos se adecua a la situación que se esta manejando en mi proyecto y no a lo que se adecua a mi perpectiva. 

De igual manera elegí implementar el Arbol binario para almacenar y organizar las distancias calculadas de los paquetes debido a que me permite insertar, buscar y ordenar los datos que se presenten. El caso promedio O(log n) me beneficia en tener las distancias ordenandas y visualizarlas en un recorrido inorder

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructras correctos.

Implemente mecanismos para consultar los datos de los paquetes, utilice el algoritmo de Merge Sort para ordenarlas los datos de la manera más eficiente de acuerdo a la cantidad de datos que se pueden llegar a presentar. Ademas la implementación del Árbol binario consulta la información almacenada y me ayuda a consultar la información teniendo un recorrido inorder permitiendo visualizar la información de menor a mayor. Estos mecanismos me ayudana a consultar la información de manera eficiente y ordenada.

Implemente un mecanismo que permite hacer una lectura de un archivo csv. Esto con el proposito de cargar la información de cada paquete que este almacenada en el archivo. Esto me permite tener un mejor acceso y modificación a la información a cargar.

Implemente un mecanismo que me permite almacenar o escribir la información de mi vector paquete a un archivo de texto. Esto con el proposito de tener un mejor acceso y compresión de la información de cada paquete almacenado en el vector.
