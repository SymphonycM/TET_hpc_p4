# TET_hpc_p4

# UNIVERSIDAD EAFIT

## INGENIERÍA DE SISTEMAS - ST0263 TÓPICOS ESPECIALES EN TELEMÁTICA

## PROYECTO 4 – HPC

### 1. Enlace al Google Drive

[Carpeta en Google Drive con la propuesta del proyecto 4](https://drive.google.com/drive/folders/1fPnGNXCHQuAwJbQuef1IljKWcZdHSfWS?usp=sharing)


### 2. Consensus and profile
#### 2.1 Autores
- Jorge Luis Herrera Chamat - jlherrerac@eafit.edu.co 
- Jhoan Stiven Cardona Galeano -jscardonag@eafit.edu.co

### 3. Algoritmo Secuencial
#### 3.1 Descripción del algoritmo
#### 3.2 Pseudocódigo
#### 3.3 Guía de Compilación
#### 3.4 Guía de Ejecución
#### 3.5 Resultados

### 4. Algoritmo Paralelo (OpenMP/MPI)
#### 4.1 Descripción del algoritmo
#### 4.2 Pseudocódigo
#### 4.3 Guía de Compilación
Para compilar nuestra solución del algoritmo en paralelo estamos ejecutando el siguiente comando en la carpeta que contiene la solución en paralelo 'solucion_Paralela'.
```
mpiicpc Pcons.cc -qopenmp
```
#### 4.4 Guía de Ejecución
Para ejecutar nuestra solución del algoritmo en paralelo dentro del clúster de Colfax (El clúster del curso de Fundamentals of Parallelism on Intel Architecture) ejecutamos la siguiente linea de código.
```
echo 'cd cons/parallel; mpirun -host localhost -np 2 numactl --membind 1 ./parallel' | qsub
```
#### 4.5 Resultados
