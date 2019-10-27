/*
 * Aplicación básica de gestión de notas realizada en C++, como método de 
 * aprendizaje de este lenguaje de programación.
 * 
 * Licencia empleada: Creative Commons Reconocimiento-CompartirIgual 
 * 
 * Fecha de desarrollo: Enero de 2017.
 */

#include <iostream>
#include <cstdlib>
#include "./headers.h"



int main(int argc, char** argv);
void showErrorMsg();
void checkResultCode(int resultCode);
void checkNumberOfArgs(int numArgumentos,int cuantosDeboTener);

/*
 * Procedimiento que muestra el mensaje de error como que hemos introducido mal
 * los argumentos.
 */
void showErrorMsg() {
    cout << "Error en el argumento introducido"<<endl;
    cout << "SINTAXIS DE EJECUCIÓN"<<endl;
    cout << "./a.out COMANDO [argumento1] [argumento2]"<<endl;
}

void checkResultCode(int resultCode){
    if (resultCode == -1) {
        cout << "Hubo un error en la operación. Por favor, inténtelo de nuevo" << endl;
    }
}

void checkNumberOfArgs(int argsNumber,int minimumNumber){
    if (argsNumber < minimumNumber) {
        showErrorMsg();
        exit(-1);
    }
    
}

/*
 Argumentos:
 * Los argumentos se almacenan en el puntero doble argv, que apunta a cadenas de
 * caracteres y podremos acceder a ellos como si fueran un array.
 * Importante el parámetro argc, que nos indica el número de argumentos que nos 
 * pasan.
 * 
 * Los argumentos son 0-indexados, esto es, el primer argumento está en la
 * posicion 0, que justo es el nombre del fichero que estamos ejecutando
 * por lo que en la mayoría de los casos nos interesará a partir del segundo
 * argumento (accediendo como un array, el 1º).
 * 
 * Esta estructura de ifs elses me sirve para comprobar en qué caso estoy:
 * Caso 1 (add): Quiero añadir una nota.
 * Caso 2 (list): Quiero listar notas.
 * Caso 2 (remove): Quiero borrar una nota.
 * Caso 3 (read): Quiero borrar una nota.
 * 
 * 
 * Modo de ejecución del programa:
 * ./a.out COMANDO argumento1 argumento2.
 * En los que:
 * 
 * COMANDO será:
 *  add, remove, list, read
 * argumento1 será
 *  Si caso de add, el título de la nota.
 *  Si caso remove, read, el número de nota que ocupa en el vector.
 * 
 * argumento2 será
 *  Si caso de add, el cuerpo de la nota. 
 */
int main(int argc, char** argv) {
    vector <note> notas;
    int resultCode = 0;
    
    resultCode=loadDatabase(&notas);
    checkResultCode(resultCode);
    checkNumberOfArgs(argc,2); /*tiene que haber dos argumentos mínimo 
    (nombre programa, comando)*/

    string command = argv[1];
    
    if (command == "add") {
        if (argc != 4) {
            showErrorMsg();
            return -1;
        }
        string noteTitle = argv[2];
        string noteBody = argv[3];
        resultCode = addNote(&notas, noteTitle, noteBody);
        cout << "Añadida nota " << notas.size() << endl;
        cout << "Ahora hay " << (notas.size() + 1) << " nota(s)" << endl;
    } else if (command == "list") {
li:
        vector <string> listOfNotes = list(&notas);
        for (int i = 0; i < listOfNotes.size(); i++) {
            cout << "Nota " << i << endl;
            cout << listOfNotes[i] << endl;
        }
    } else {
        int numberOfNote = atoi(argv[2]); //atoi convierte un string en int

        if (command == "remove") {
            resultCode = removeNote(&notas, numberOfNote);
            cout << "Eliminada nota " << numberOfNote << endl;
            cout << "Ahora quedan " << notas.size() << " nota(s)" << endl;

        } else if (command == "read") {
            cout << "Leyendo nota " << numberOfNote << endl;
            note notaToRead = readNote(&notas, numberOfNote);
        } else {
            showErrorMsg();
        }
    }
    checkResultCode(resultCode);
 
    return 0;
}
