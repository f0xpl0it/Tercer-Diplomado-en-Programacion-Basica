//============================================================================
// Name        : Array_4.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 5 - Arreglos (Ejercicio [4])
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
  limpiarEntrada();  // Siempre limpiar el buffer
  return true;
}

// Funci¢n para ingresar una matriz
void ingresarMatriz(int matriz[3][3], string nombre) {
  cout << "\nIngresar valores para la " << nombre << ":\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "Ingrese el valor posici¢n [" << i + 1 << "][" << j + 1 << "]: ";
      cin >> matriz[i][j];

      while (!entradaValida()) {
        cout << "Reingrese el valor posici¢n [" << i + 1 << "][" << j + 1
             << "]: ";
        cin >> matriz[i][j];
      }
    }
  }
}

// Mostrar matriz
void mostrarMatriz(int matriz[3][3], string nombre = "") {
  cout << "\n" << nombre << ":\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
}

// Dividir y validar el lemento no sea cero
void dividirMatriz(int matriz[3][3], int divisor) {
  if (divisor == 0) {
    cout << "\nError: No se puede dividir entre cero.\n";
    return;
  }

  cout << "\nMatriz dividida por " << divisor << ":\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      float resultado = (float)matriz[i][j] / divisor;
      cout << resultado << " ";
    }
    cout << endl;
  }
}

// Extraemos el indice
void extraerIndice() {
  int matriz[3][3];

  ingresarMatriz(matriz, "Matriz 3x3");
  mostrarMatriz(matriz, "Matriz Ingresada");

  int fila, columna;

  cout << "\n>> Seleccione una posici¢n [fila][columna] (1 a 3): ";
  cout << "\nFila: ";
  cin >> fila;

  while (!entradaValida() || fila < 1 || fila > 3) {
    cout << "Fila inv lida. Ingrese un n£mero entre 1 y 3: ";
    cin >> fila;
  }

  cout << "Columna: ";
  cin >> columna;

  while (!entradaValida() || columna < 1 || columna > 3) {
    cout << "Columna inv lida. Ingrese un n£mero entre 1 y 3: ";
    cin >> columna;
  }

  // Convertimos a ¡ndice (de 0 a 2)
  int valor = matriz[fila - 1][columna - 1];

  cout << "\nEl valor en la posici¢n [" << fila << "][" << columna
       << "] es: " << valor << endl;
  dividirMatriz(matriz, valor);
}

// Funci¢n Principal
int main() {
  cout << "\n======== EJERCICIO 4 - MATRIZ 3x3 ========\n";

  extraerIndice();
  return 0;
}
