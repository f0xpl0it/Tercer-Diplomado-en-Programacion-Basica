//============================================================================
// Name        : Function_4.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 6 - Funciones (Ejercicio [4])
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 4

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

// Funci¢n para llenar el arreglo
void llenarArreglo(int arreglo[], int longitud) {
  for (int i = 0; i < longitud; i++) {
    cout << "Ingrese el valor #" << i + 1 << ": ";
    cin >> arreglo[i];

    while (!entradaValida()) {
      cout << "Ingrese el valor #" << i + 1 << ": ";
      cin >> arreglo[i];
    }
  }
}

// FUnci¢n para imprimir el arreglo
void mostrarArreglo(int arreglo[], int longitud, string nombre) {
  cout << nombre << ": [";
  for (int i = 0; i < longitud; i++) {
    cout << arreglo[i];
    if (i < longitud - 1) cout << ", ";
  }
  cout << "]\n";
}

// Funci¢n para el producto escalar
int productoEscalar(int vector1[], int vector2[], int longitud) {
  int resultado = 0;
  for (int i = 0; i < longitud; i++) {
    resultado += vector1[i] * vector2[i];
  }
  return resultado;
}

// Funcion Principal
int main() {
  cout << "\n======== EJERCICIO 4 - PRODUCTO ESCALAR ========\n";
  const int LONGITUD = 4;
  int vector1[LONGITUD];
  int vector2[LONGITUD];

  cout << "\n***** VECTOR #1 *****\n";
  llenarArreglo(vector1, LONGITUD);

  cout << "\n***** VECTOR #2 *****\n";
  llenarArreglo(vector2, LONGITUD);

  cout << endl;
  mostrarArreglo(vector1, LONGITUD, "Vector 1");
  mostrarArreglo(vector2, LONGITUD, "Vector 2");

  int resultado = productoEscalar(vector1, vector2, LONGITUD);
  cout << "\n>> Producto punto: " << resultado << endl;

  return 0;
}
