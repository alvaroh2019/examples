
# Ejercicio de programación: gestor de notas
## Ejercicio
El objetivo es el de elaborar un gestor de notas en un lenguaje de programación imperativo y compilado (C o C++). Las funciones con las que deberá contar son:
* Inserción de notas: permitirá insertar una nota. Estas se diferenciarán de manera única por la posición que ocupan en la Estructura de Datos empleada (no utilizar conjuntos ni mapas no ordenados).
* Borrado de notas: Al igual que en el caso de la inserción, se deberá poder borrar las notas, proporcionando el identificador que ocupan en la Estructura de Datos.
* Listado de notas: se deberá permitir listar todas las notas almacenadas, mostrando, para cada una de ellas, el título y el contenido de la misma.
* Lectura de notas: Si se proporciona el número de nota (posición dentro de la Estructura de Datos) se deberá poder leer, el título y el cuerpo de la nota.

Para implementar este programa se podrá usar, o bien Programación Orientada a Objetos, o bien, programación procedimental. En este último caso, se deberá usar una estructura.

## Notas adicionales
* La aplicación será persistente y deberá almacenar la información en ficheros de tipo textual en la memoria secundaria.

## Sintaxis de compilación y ejecución

### Para Sistemas Operativos de tipo Linux

g++ main.cpp app.cpp

Generará un fichero de tipo a.out
	
A partir de ahí...

* ./a.out add titulo cuerpo, para añadir una nueva nota.
* ./a.out remove numeroNota, para borrar una nota.
* ./a.out list, para listar todas las notas.
* ./a.out read numeroNota, para leer una determinada nota.
