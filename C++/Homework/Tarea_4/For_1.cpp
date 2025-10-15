//============================================================================
// Name        : For_1.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 4 - For (Ejercicio [1])
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 1

// Funci¢n para limpiar errores de entrada
void limpiarEntrada() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Funci¢n para verificar si la entrada fue v lida
bool entradaValida() {
  if (cin.fail()) {
    cout << "\033[31m\nSolo se permiten n£meros!!!\n\033[0m";
    limpiarEntrada();
    return false;
  }
  limpiarEntrada();  // Siempre limpiar el buffer
  return true;
}

// Funci¢n para calcular el promedio de alumnos
void notaEstudiante() {
  int students, grade;
  double score, average = 0;

  cout << "Ingrese el n£mero de estudiantes: ";
  cin >> students;

  if (!entradaValida() || students <= 0) return;  // manejo de errores

  cout << "Ingrese el n£mero de notas a evaluar: ";
  cin >> grade;

  if (!entradaValida() || grade <= 0) return;  // manejo de errores

  // Generamos M de estudiantes y N notas para calcular el promedio
  for (int i = 1; i <= students; i++) {
    double sum = 0;

    cout << "\n###### Estudiante [" << i << "] ######\n";
    cout << endl;

    for (int j = 1; j <= grade; j++) {
      cout << "Ingrese nota [" << j << "]: ";
      cin >> score;

      if (!entradaValida() || score < 0) {
        cout << "\033[31mNota inv lida. Intente nuevamente.\033[0m\n";
        j--;  // Repetir esta nota
        continue;
      }
      sum += score;
    }
    cout.precision(4);  // n£mero de cifras
    average = sum / grade;
    cout << "\n>> ESTUDIANTE (#" << i << ") \n>> PROMEDIO: (" << average
         << ")\n";
  }
}

// Funci¢n Principal
int main() {
  cout << endl;
  cout << "======== EJERCICIO 1 - PROMEDIO [for] ========" << endl;
  notaEstudiante();
  cout << "\nFin del Porgrama.\n";
  return 0;
}
