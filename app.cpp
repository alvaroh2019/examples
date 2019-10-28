/*
 * Aplicación básica de gestión de notas realizada en C++, como método de 
 * aprendizaje de este lenguaje de programación.
 * 
 * Licencia empleada: Creative Commons Reconocimiento-CompartirIgual 
 * 
 * Fecha de desarrollo: Enero de 2017.
 */



#include <iostream>
#include <fstream>
#include "./headers.h"
#define database "db.txt"
#define limit '\n'

static int writeFile(vector<note> * notes);


/*
 * Función que lee de la base de datos (fichero) y crea la ED que da soporte a la
 * aplicación.
 * @args notes: vector de notas, sobre el que escribir el resultado
 */
int loadDatabase(vector<note> * notes) {
    ifstream file;
    file.open(database);
    if (!file.is_open()) {
        /*Base de datos no existe, ya se creará*/
        return 0;
    }
    string nota[2];
    int pos=0;
    char readChar;
    string str="";
    while (file.get(readChar)) {
        str+=readChar;
        if(readChar==limit){
            str.erase(str.end()-1);
            nota[pos]=str;
            str="";
            pos++; 
        }
        if (pos==2){
            pos=0;
            note nuevaNota;
            nuevaNota.title=nota[0];
            nuevaNota.body=nota[1];
            notes->push_back(nuevaNota);
        }
    }
    return 0;
}

/*
 Función que elimina una nota de la ED.
 * @return -1 si ha habido un error
 * @return 0 si ha habido éxito (incluye que haya habido una actualización
 * correcta en la Base de Datos.
 * 
 * @arg notes: el vector de notas.
 * @index, el número de índice de la nota a eliminar.
 */
int removeNote(vector<note> * notes, int index) {
    if(notes->size()<index | index<0){
        return -1;//No existe la nota
    }
    notes->erase(notes->begin()+index);
    return writeFile(notes);
}
/*
 Función que escribe en la Base de Datos.
 * @args notes: vector de notas
 * 
 * @nota es de tipo static, porque no debe ser accesible desde fuera de los
 * métodos de este fichero.
 */
static int writeFile(vector<note> * notes) {
    if(notes->size()==0){
        return 0;
    }
    ofstream file;
    
    file.open(database);
    if (!file.is_open()) {
        /*Hubo un error*/
        return -1;
    }
    note current;
    for (int i = 0; i < notes->size(); i++) {
        current = (*notes)[i];
        file << current.title << limit;
        file << current.body << limit;
    }
    file.close();
    return 0;
}

/*
 Función que añade una nota a la ED y devuelve -1 o 0 dependiendo de si ha
 * habido éxito en la actualización de la BBDD
 * 
 * @args notes vector de notas
 * @title título de la nueva nota.
 * @noteBody cuerpo de la nueva nota.
 * 
 * @return 0 en caso de éxito; -1 en caso contrario.
 */
int addNote(vector<note> * notes, string title, string noteBody) {
    note newNote;
    newNote.title=title;
    newNote.body=noteBody;
    notes->push_back(newNote);
    return writeFile(notes);
}

/*
 Función que devuelve un vector parametrizado con string.
 * @args notes, vector de notas
 * @return vector que incluye los strings de las notas almacenadas.
 */
vector<string> list(vector<note> * notes){
    vector<string> output;
    
    for(int i=0;i<notes->size();i++){
        output.push_back("Título:\n\t"+(*notes)[i].title+"\n"+
        "Cuerpo:\n\t"+(*notes)[i].body+"\n");
    }
    return output;
}


/*
 Función que devuelve una única nota.
 * 
 * @args notes, vector de notas.
 * @args index, número de nota a leer.
 * 
 * @return nota solicitada.
 */
note readNote(vector<note> * notes, int index){
    return (*notes)[index];
}
