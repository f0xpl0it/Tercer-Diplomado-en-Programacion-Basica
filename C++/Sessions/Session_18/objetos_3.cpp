//============================================================================
// Name : objetos_3.cpp
// Author : Michael Paucar
// Version : v.1
// Description : 2025/12/09
//============================================================================

#include <iostream>
using namespace std;
// Programa que usa clases para registrar informacion de un estudiante

class Estudiante {
 private:
  string nombre;        // Nombre del estudiante
  double calificacion;  // Calificacion del estudiante

 public:
  // Constructor con parametros: inicializa el nombre y la calificacion
  Estudiante(string n, double c) {
    nombre = n;
    calificacion = c;
  }

  // Metodo que verifica si el estudiante ha aprobado (calificacion >= 6.0)
  bool aprobado() { return calificacion >= 6.0; }

  // Metodo para imprimir la informacion del estudiante
  // Imprime el nombre, la calificacion y si esta aprobado o reprobado
  void imprimir() {
    cout << nombre << " - " << calificacion;

    // Si el estudiante esta aprobado, imprime "(Aprobado)", de lo contrario
    // "(Reprobado)"
    if (aprobado())
      cout << " (Aprobado)";
    else
      cout << " (Reprobado)";

    cout << endl;
  }
};

int main() {
  // Se crean tres objetos de tipo Estudiante con diferentes nombres y
  // calificaciones
  Estudiante e1("Ana", 8.5);
  Estudiante e2("Luis", 5.0);
  Estudiante e3("Maria", 9.3);

  // Se imprime la informacion de cada estudiante
  e1.imprimir();
  e2.imprimir();
  e3.imprimir();

  return 0;  // Fin del programa
}
