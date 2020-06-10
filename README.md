# UNIVERSIDAD EAFIT

## Ingeniería de Sistemas
## ST0263 - Tópicos Especiales en Telemática

## Proyecto #4 - HPC

### Transcribing DNA into RNA

### Consensus and profile
#### Autores
- Jorge Luis Herrera Chamat - jlherrerac@eafit.edu.co 
- Jhoan Stiven Cardona Galeano -jscardonag@eafit.edu.co 

### 1. Enlace al Google Drive

[Carpeta en Google Drive con la propuesta del proyecto 4](https://drive.google.com/drive/folders/1fPnGNXCHQuAwJbQuef1IljKWcZdHSfWS?usp=sharing)

### 2. Enlace al video
[Videosustentación](https://web.microsoftstream.com/video/ef8be5e5-dad7-4b0d-936c-27caf7ffbf71)

### 2. Descripción del problema
El procesamiento de cadenas de ADN hace parte del intenso día a día de la investigación científica en las áreas de medicina y biología, por esto, es muy importante contar con una alta eficiencia en el tiempo que los algoritmos se toman para procesar exitosamente estas tareas.

Uno de los procesos que se realizan en estas cadenas de ADN es la transformación de grandes cadenas de ADN en cadenas de ácido Ribonucléico.

Con el fin de lograr reducir significativamente estos tiempos, se debe crear un algoritmo de alto rendimiento que haga uso de la paralelización, con el fin de resolver este proceso de una forma exitosa en el menor tiempo posible.

### 3. Dataset
Para la ejecución de este proyecto es necesario contar con un dataset lo suficientemente grande para notar una diferencia notable entre los tiempos de ejecución de la solución en paralelo y la solución en serial.

Para esto hemos desarrollado un sencillo programa en Python 3, el cual se encarga de tomar un número digitado por el usuario como argumento al programa para generar un dataset de un solo string, el cual contará con una longitud de n carácteres, en donde n es el valor ingresado por el usuario com argumento.
```
python generator.py <tamaño del string de ADN>
```
> [En dónde 'tamaño del string de ADN' es un valor entero que ingresa el usuario como argumento al programa a ejecutar.]

Este dataset generado consiste en un string de n carácteres, en dónde estos carácteres son los valores correspondientes a una cadena de ADN (A = Adenina, C = Citosina, G = Guanina, T = Timina) generados aleatoriamente por el programa [generator.py](https://github.com/SymphonycM/TET_hpc_p4/blob/master/generator.py).

> [El algoritmo solo genera carácteres correspondientes a la cadena de ADN, 'A', 'C', 'G', 'T']

### 4. Algoritmo Secuencial
#### 4.1 Descripción del algoritmo
El algoritmo desarrollado lee los datos de un fichero de texto `dataset.txt` y procede a guardar en una variable la longitud del String de ADN que se leyó del fichero.

Con este dato se ejecuta un ciclo for que se encarga de recorrer el String de ADN, verificando que la letra en la posición actual sea igual a la 'T', en cuyo caso se procede a sobreescribir el string en la posición actual, cambiando la 'T' por una 'U'.

Finalmente el algoritmo imprime la nueva cadena, que ya no es de ADN, sino de ARN.

#### 4.2 Pseudocódigo
```
double t0 = getTime()
file dataset
int length = 0
string line = ""

while (dataset >> line){
    length = line.length()
}

print (length)
array t[length]

for (int k = 0, k < length, k + 1){
    if(t[k] = 'T'){
        t[k] = 'U'
    }
}

for (int j = 0, j < length, j + 1){
    print (t[j])
}

double t1 = getTime()
print (Time: t1 - t0)
```
#### 4.3 Guía de Compilación
Para compilar nuestra solución del algoritmo en serial necesitamos correr el siguiente compilar en la carpeta que contiene la solución en serial 'SNA/serial'.

`mpiicpc Serial_SNA.cc`



#### 4.4 Guía de Ejecución
Para ejecutar nuestra solución del algoritmo en serial dentro del clúster de Colfax (El clúster del curso de Fundamentals of Parallelism on Intel Architecture) ejecutamos la siguiente linea de código dentro de la carpeta.
`echo 'cd SNA/serial; ./a.out dataset.txt' | qsub`

En el clúster ya se encuentran ejecutados los comandos y la salida se encuentra en el archivo STDIN, esta salida se puede observar con el comando:
`cat STDIN.o118960`

#### 4.5 Resultados
Resultados al correr el algoritmo con un dataset, el cual contiene una cadena de ADN de longitud 1000000 carácteres.
![Ejecución en serial](https://i.imgur.com/FvLiTdn.jpg)


### 5. Algoritmo Paralelo (OpenMP/MPI)
#### 5.1 Descripción del algoritmo
En el algoritmo en paralelo hicimos uso de MPI, como fue planeado en el proceso PCAM y dividimos el string de entrada en 4 partes, cada proceso ejecuta un cuarto de los datos de entrada y transcribe esa parte de AND a ARN. 
Dentro de cada proceso, el engranaje principal es un loop for que recorre la cadena, ese loop fue paralelizado con openmp.
Al final de la ejecución de cada proceso, juntamos todos los datos dentro del proceso identificado con rank=0 por medio de una función MPI_Gather, teniendo todos los datos en este proceso, se imprimen en consola y se cierra la instanciación de MPI

![Algoritmo paralelo](https://i.imgur.com/np7FRsL.png)

#### 5.2 Guía de Compilación
Para compilar nuestra solución del algoritmo en paralelo estamos ejecutando el siguiente comando en la carpeta que contiene la solución en paralelo 'solucion_Paralela'.
`mpiicpc Parallel_SNA.cc -o parallel -qopenmp`
#### 5.3 Guía de Ejecución
Para ejecutar nuestra solución del algoritmo en paralelo dentro del clúster de Colfax (El clúster del curso de Fundamentals of Parallelism on Intel Architecture) ejecutamos la siguiente linea de código.
`make queue`

En el clúster ya se encuentran ejecutados los comandos y la salida se encuentra en el archivo STDIN, esta salida se puede observar con el comando:
`cat STDIN.o118967`

#### 5.4 Resultados
Resultados al correr el algoritmo con un dataset, el cual contiene una cadena de ADN de longitud 1000000 carácteres.
![Ejecución en paralelo](https://i.imgur.com/00cNjb1.jpg)


### 6. Análisis
Como se puede apreciar en los numerales **4.5** y **5.4**, los resultados obtenidos con ambas soluciones son los siguientes:

- **Solución serial:** 0.198786 segundos.
- **Solución en paralelo:** 0.0421316 segundos.

#### 6.1 Speed Up de la aplicación
El cálculo del Speed Up de la aplicación se realiza dividiendo el tiempo de la ejecución del algoritmo serial sobre el tiempo de la ejecución del algoritmo en paralelo, así:

> ts/tp = SpeedUp
> 0.198786s/0.0421316s = 4.7182162

Vale la pena aclarar en este proyecto que no hicimos uso de la ejecución alojando el programa y su memoria en el apartado de memoria de banda ancha del procesador Xeon Phi. En ese caso, se puede obtener un speed up de casi el dobre, teniendo un promedio de ejecución de cada proceso en paralelo de 0.0019... segundos.
Para ejecutar el códio paralelizado en este modo, es suficiente con cambiar el comando de ejecución
`make queue`
Por el comando
`echo 'cd SNA/parallel; numactl --membind 1 mpirun -host localhost ./parallel dataset2.txt' | qsub -l nodes=4:flat`

Ejecutando el código de esta forma, observamos la seguiente salida:
![](https://i.imgur.com/8zdBEkv.jpg)

### Referencias

- http://rosalind.info/problems/cons/
- https://www.worldcommunitygrid.org/discover.action - https://setiathome.berkeley.edu/
- http://luna.inf.um.es
- http://rosalind.info/problems/locations/

