# PCAM

![PCAM](https://i.imgur.com/glQUD0v.png)

## 0. Problema
El procesamiento de cadenas de ADN hace parte del intenso día a día de la investigación científica en las áreas de medicina y biología, por esto, es muy importante contar con una alta eficiencia en el tiempo que los algoritmos se toman para procesar exitosamente estas tareas.

Uno de los procesos que se realizan en estas cadenas de ADN es la transformación de grandes cadenas de ADN en cadenas de ácido Ribonucléico.

Con el fin de lograr reducir significativamente estos tiempos, se debe crear un algoritmo de alto rendimiento que haga uso de la paralelización, con el fin de resolver este proceso de una forma exitosa en el menor tiempo posible.

## 1. Particionamiento
- **T1:** Esta tarea se encarga de ejecutar los primeros n/4 datos de entrada. En caso de este proyecto, procesa 250.000 caracteres de la cadena ADN de entrada

- **T2:** Esta tarea se encarga de ejecutar los segundos n/4 datos de entrada. Al encontrarse en el segundo proceso, transcribe desde el caracter 250.001 al caracter 500.000

- **T3:** Esta tarea se encarga de ejecutar los terceros n/4 datos de entrada. Aquí se resuelve el problema entre los caracteres 500.001 y 750.000

- **T4:** Esta tarea se encarga de ejecutar los cuartos n/4 datos de entrada. Esta última tarea procesa los caracteres finales de la cadena, al ser una entrada de 1.000.000 de caracteres, ejecuta también un total de 250.000 caracteres

- **T5:** Al final de la transcripción, se recoje el resultado total, es decir, el millón de caracteres transcritos y se imprime por consola

Dentro de cada una de estas tareas vamos a hacer uso del multithreading gracias a la biblioteca de OpenMP, lo que nos va a permitir partir cada una de estas tareas, en tareas más pequeñas, en donde cada una de ellas va a ser ejecutada por un hilo diferente para ahorrarnos tiempo al momento de procesar la información de las cadenas de ADN.

Éstas tareas son débilmente acopladas ya que ningún caracter de la cadena depende de los demás y se pueden separar fácilmente por las direcciones en memoria. Por esto, son tareas candidatas a ser ejecutadas en diferentes procesos con MPI.

## 2. Comunicación
El resultado de todo el proceso de transcripción será guardado en un solo conjunto de datos, por esto, el proceso encargado de entregar el resultado de la transcripción debe conocer las cadenas de salida de los demás procesos. Para cumplir este requisito, todos los procesos diferentes al 0 le enviarán a éste sus resultados de transcripción y él se encargará de entregar el resultado total de una forma ordenada por consola.

## 3. Aglomeración
En las dos primeras etapas del proceso de diseño, particionamos los datos para ser procesados en un set de tareas, además, introducimos un sistema de comunicación el cual se encarga de recolectar todos los datos necesarios para el procesamiento de las cadenas de ADN hacia las cadenas de ácido Ribunocléico.

El algoritmo diseñado hasta el momento sigue siendo muy abstracto ya que no está especializado para la ejecución eficiente en ningún computador con paralelismo. Es por esto que vamos a combinar/aglomerar los diferentes hilos que se encuentran ejecutando en cada uno de los procesos, con el fin de que todos los hilos procesen los misms datos (cada uno de ellos será el encargado de ejecutar paralelamente diferentes datos para evitar condiciones de carrera o concurso), para así de esta manera reducir el número de comunicaciones que se realizan entre las diferentes tareas, logrando que las únicas comunicaciones sea las que se realizan entre cada uno de los procesos en base a los resultados en conjunto de la ejecución de sus hilos.

## 4. Mapeo
Estas tareas serán ejecutadas en un procesador intel Xeon Phi al que se tendrá acceso mediante el clúster de Colfax. En este procesador se hará uso de MPI para crear 4 procesos de ejecución que se identificarán con su correspondiente rank entre 1 y 4. 
Cada proceso tomará una tarea entre T1 y T4, es decir, cada proceso se encargará de transcribir n/4 datos.
Al momento de transcribir sus n/4 datos va a hacer uso de una serie de hilos que le permita transcribir estos datos de forma paralela para reducir el tiempo de procesamiento, obteniendo al final el resultado de todos los hilos en conjunto de forma ordenada.

Finalmente, luego de realizar la transcripción de cada uno de los procesos y de su comunicación, el proceso identificado con el rank 0 se encargará de recoger los datos de los demás procesos e imprimirlos en la consola.

## Referencias

- http://mtovar.cs.buap.mx/doc/ProgConc/ProgramacionParalela.pdf
- https://www.mcs.anl.gov/~itf/dbpp/text/node15.html
