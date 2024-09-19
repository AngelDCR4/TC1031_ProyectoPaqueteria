# Proyecto: Paqueteria UHC
El proyecto consiste en un sistema de una empresa de paqueteria. El sistema es capaz de visualizar los pedidos que esten registrados en el sistema, agregar nuevos pedidos y organizar las distancias de menor a mayor para tener una ruta adecuada de la entrega de los paquetes

## Comportamiento del Programa
El proyecto puede desplegar un menu en el que el administrador del sistema pueda seleccionar algunas de las opciones presentadas:
1 - Ver pedidos actuales
Se desplegara en la terminal todos los pedidos mostrando su nombre, destino, coordenadas xy

2 - Agregar pedidos
Se solicitara al administrador ingresar el nombre del usuario que solicita la entrega del paquete, el lugar de destino y las coordenadas xy dentro del mapa

3 - Ver distancias mas cortas
Los paquetes que esten en el sistema continen coordenadas, se calcularan sus distancias y seran organizadas de menor a mayor para tener a la mano la mejor ruta posible para la entrega de los paquetes

4 - Salir
Salir del sistema y finalizar el programa

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
>Ingresar -> Roberto
>
>Ingresar -> 56
>
>Ingresar -> 87
>
>PASO 3: Visualizar lista de pedidos actualizados
>
>PASO 4: Seleccionar opcion 3
>
>Visualizar distancias ordenadas
>
>PASO 5: Salir del sistema

### Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal

`cd "DIRECCION DE CARPETA EN DONDE SE ENCUETRA EL main.cpp"` 

Posteriormente ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance.exe` 

### Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance.exe` 

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Implementación del Selection Sort: Implemente el algoritmo de Selection Sort en la función "selectionsort(vector<float>& vec)". Este algoritmo tiene una complejidad de O(n^2), ya que en cada iteración del bucle se recorre la lista para encontrar el valor mínimo a intercambiar, lo que involucra dos bucles distintos pero enlazados.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Seleccione este algoritmo de ordenamient Select Sort debido a que el volumen de datos es bajo. El Selection Sort es adecuado para listas pequeñas o cuando se prefiere la simplicidad en el código. Elegi implementar el algoritmo de Selection Sort para ordenar las distancias de los paquetes respecto al origen (0,0) lo cual es apropiado en este contexto. El Selection Sort es fácil de entender y de implementar, por lo que resulta adecuado para casos donde no se esperan grandes volúmenes de datos.
