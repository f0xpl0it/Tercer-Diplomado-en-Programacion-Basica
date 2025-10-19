//============================================================================
// Name        : Array_Punteros.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 5 - Arreglos (Ejercicio [2])
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 2

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

// Funci¢n para encontrar n£meros pares
void arregloPar() {
  int n;
  cout << "\nIngrese la longitud del arreglo: ";
  cin >> n;

  while (!entradaValida() || n <= 0) {
    cout << "\nReingrese la longitud del arreglo: ";
    cin >> n;
  }

  int* numeros = new int[n];  // Crear el arreglo

  for (int i = 0; i < n; i++) {
    cout << "Ingrese el valor [" << i + 1 << "]: ";
    cin >> numeros[i];

    while (!entradaValida()) {
      cout << "Reingrese el valor [" << i + 1 << "]: ";
      cin >> numeros[i];
    }
  }

  int aux = 0;

  cout << "\nARREGLO -> [ ";
  for (int i = 0; i < n; i++) {
    cout << numeros[i] << " ";

    if (numeros[i] % 2 == 0) aux++;
  }
  cout << "]\n";
  cout << "\n>> El arreglo tiene " << aux << " n£meros pares." << endl;

  delete[] numeros;  // Liberar memoria
}

// Funci¢n Principal
int main() {
  cout << "\n======== EJERCICIO 2 - NéMEROS PARES ========\n";
  arregloPar();
  return 0;
}
