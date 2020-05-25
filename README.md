# TET_hpc_p4

UNIVERSIDAD EAFIT
INGENIERÍA DE SISTEMAS
STO0263 TÓPICOS ESPECIALES EN TELEMÁTICA, 2020-1
GRUPOS 031 Y 032

PROYECTO 4 – HPC

template de propuesta proyecto 4

Consensus and profile
jlherrerac@eafit.edu.co
jscardonag@eafit.edu.co
https://github.com/SymphonycM/TET_hpc_p4
https://drive.google.com/drive/folders/1fPnGNXCHQuAwJbQuef1IljKWcZdHSfWS?usp=sharing

<0.ideas preliminares de proyecto4>

Problema

El procesamiento de cadenas de ADN hace parte del intenso día a día de la investigación científica en las áreas de medicina y biología, por eso es importante que la velocidad en la que los algoritmos utilizados para procesarlas exitosamente.
Uno de estos procesos que se hacen sobre éstas es encontrar una Matriz de Perfil y una Cadena de Consenso a partir de determinadas cadenas.

Con el fin de lograr reducir significativamente estos tiempos, se debe crear un algoritmo de alto rendimiento que haga uso de paralelización para resolver este proceso exitosamente en el menor tiempo posible

Enunciado

Dada una colección de como máximo 10 cadenas de ADN de igual longitud (como máximo 1 kbp) en formato FASTA, se debe devolver una cadena de consenso y una matriz de perfil para la colección. (Si existen varias posibles cadenas de consenso, puede devolver cualquiera de ellas).

Base teórica

Una matriz es una tabla rectangular de valores dividida en filas y columnas. Una matriz m × n tiene m filas y n columnas. Dada una matriz A, escribimos Ai, j para indicar el valor encontrado en la intersección de la fila i y la columna j.

Digamos que tenemos una colección de cadenas de ADN, todas con la misma longitud n. Su matriz de perfil es una matriz P 4 × n en la cual P1, j representa el número de veces que 'A' ocurre en la posición j de una de las cadenas, P2, j representa el número de veces que C ocurre en la posición j , y así sucesivamente.

Una cadena de consenso c es una cadena de longitud n formada a partir de nuestra colección tomando el símbolo más común en cada posición; el símbolo j de c corresponde, por lo tanto, al símbolo que tiene el valor máximo en la columna j-ésima de la matriz de perfil. Por supuesto, puede haber más de un símbolo más común, lo que lleva a múltiples posibles cadenas de consenso.

Objetivo y alcance

El principal objetivo de este reto es reducir significativamente el tiempo del proceso sobre las cadenas de ADN en el que se busca una matriz perfil y una cadena de consenso a partir de determinadas cadenas.
Esto con el fin de apoyar la investigación científica en las áreas de medicina y biología

Requerimientos técnicos

Se requiere un procesador con el kit de instrucciones y la capacidad de computación que le permitan ejecutar algoritmos de alto rendimiento de forma paralela 

Plan de trabajo

Diseño de la solución - Entre el 24 y el 30 de Mayo de 2020
Implementación y testing de la solución - Entre el 5 y 6 de Junio de 2020

Referencias

Éste problema fue seleccionado de:
http://rosalind.info/problems/cons/

Código de Honor:

Cada uno de los autores, debe declarar explícitamente que el trabajo es original y cuál fue su aporte en el desarrollo del proyecto4, o si es copiado de algún sitio en internet (porque hay muchas implementaciones de este problema) deberá referenciar o citar el sitio de donde tomó el trabajo y declarar entonces cuál fue su aporte con esta copia en el proyecto4. 

Esta declaración debe ser colocada en README.md del github del proyecto4 por cada autor.

REFERENCIAS DE INSPIRACIÓN:


https://www.worldcommunitygrid.org/discover.action
https://setiathome.berkeley.edu/
http://luna.inf.um.es
http://rosalind.info/problems/locations/

