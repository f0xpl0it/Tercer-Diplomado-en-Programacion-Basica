//============================================================================
// Name        : Vector_2.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 7 - Vectores (Ejercicio [2])
//============================================================================

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// EJERCICIO 2

//----------------------------------------
// Funciones validacion de entrada
//----------------------------------------
void limpiarEntrada() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool entradaValida() {
  if (cin.fail()) {
    cout << "\033[31m\nSolo se permiten n£meros!!!\n\033[0m";
    limpiarEntrada();
    return false;
  }
  return true;
}

//----------------------------------------
// Funci¢n para crear el vector
//----------------------------------------
void crearVector(vector<int>& v) {
  int longitud;

  cout << "Ingrese la longitud del vector: ";
  cin >> longitud;
  while (!entradaValida() || longitud <= 0) {
    cout << "Ingrese nuevamente la longitud del vector (> 0): ";
    cin >> longitud;
  }

  v.resize(longitud);  // Guardar longitud nueva del vector

  for (int i = 0; i < longitud; i++) {
    cout << "Ingrese el valor #" << (i + 1) << ": ";
    cin >> v[i];
    while (!entradaValida()) {
      cout << "Ingrese nuevamente el valor #" << (i + 1) << ": ";
      cin >> v[i];
    }
  }

  // Mostrar el vector
  cout << "\nVector creado: < ";
  for (int num : v) cout << num << " ";
  cout << ">\n";
}

//----------------------------------------
// Funci¢n para eliminar duplicados
//----------------------------------------
void eliminarDuplicados(vector<int>& v) {
  for (size_t i = 0; i < v.size(); i++) {
    for (size_t j = i + 1; j < v.size();) {
      if (v[i] == v[j]) {
        v.erase(v.begin() + j);  // elimina duplicado
      } else {
        j++;  // avanzamos al siguiente elemento
      }
    }
  }

  cout << "Vector actual: < ";
  for (int num : v) cout << num << " ";
  cout << ">\n";
}

//----------------------------------------
// Funci¢n Principal
//----------------------------------------
int main() {
  vector<int> dupliVector;
  crearVector(dupliVector);
  eliminarDuplicados(dupliVector);

  return 0;
}
