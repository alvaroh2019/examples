/*
 * Aplicación básica de gestión de notas realizada en C++, como método de 
 * aprendizaje de este lenguaje de programación.
 * 
 * Licencia empleada: Creative Commons Reconocimiento-CompartirIgual 
 * 
 * Fecha de desarrollo: Enero de 2017.
 */

#include <vector>
#include <string>


using namespace std;

struct note {
    string title;
    string body;
};

int loadDatabase(vector<note> * notes);
int removeNote(vector<note> * notes, int index);
note readNote(vector<note> * notes, int index);
int addNote(vector<note> * notes, string title, string noteBody);
vector<string> list(vector<note> * notes);
