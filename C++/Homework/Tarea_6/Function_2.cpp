//============================================================================
// Name        : Function_2.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 6 - Funciones (Ejercicio [2])
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
  limpiarEntrada();
  return true;
}

// Sumar elementos dle arreglo
int sumarArreglo(int numeros[], int longitud) {
  int suma = 0;
  for (int i = 0; i < longitud; i++) {
    suma += numeros[i];
  }
  return suma;
}

// Funcion Principal
int main() {
  cout << "\n======== EJERCICIO 2 - SUMA ARREGLO ========\n";
  const int LONGITUD = 5;
  int numeros[LONGITUD];

  for (int i = 0; i < LONGITUD; i++) {
    int valores;
    cout << "Ingrese el valor #" << i + 1 << ": ";
    cin >> valores;

    while (!entradaValida()) {
      cout << "Ingrese el valor #" << i + 1 << ": ";
      cin >> valores;
    }
    numeros[i] = valores;
  }

  int suma = sumarArreglo(numeros, LONGITUD);
  cout << ">> La suma de los elementos del arreglo es: " << suma << endl;

  return 0;
}
