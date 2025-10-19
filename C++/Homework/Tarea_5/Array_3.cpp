//============================================================================
// Name        : Array_3.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 5 - Arreglos (Ejercicio [3])
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 3

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

// Funci¢n para ingresar una matriz y devolverla por referencia
void ingresarMatriz(int matriz[2][2], string nombre) {
  cout << "\nIngresar valores para la " << nombre << ":\n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
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
void mostrarMatriz(int matriz[2][2], string nombre = "Matriz") {
  cout << "\n" << nombre << ":\n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
}

// Funci¢n para sumar dos matrices
void sumar() {
  int matriz1[2][2];
  int matriz2[2][2];
  int resultado[2][2];

  // Ingresar matrices
  ingresarMatriz(matriz1, "Matriz 1");
  ingresarMatriz(matriz2, "Matriz 2");

  // Calcular suma
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      resultado[i][j] = matriz1[i][j] + matriz2[i][j];
    }
  }

  // Mostrar matrices y resultado
  mostrarMatriz(matriz1, "Matriz 1");
  mostrarMatriz(matriz2, "Matriz 2");
  mostrarMatriz(resultado, "Suma de las matrices");
}

// Funci¢n para restar dos matrices
void restar() {
  int matriz1[2][2];
  int matriz2[2][2];
  int resultado[2][2];

  // Ingresar matrices
  ingresarMatriz(matriz1, "Matriz 1");
  ingresarMatriz(matriz2, "Matriz 2");

  // Calcular suma
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      resultado[i][j] = matriz1[i][j] - matriz2[i][j];
    }
  }

  // Mostrar matrices y resultado
  mostrarMatriz(matriz1, "Matriz 1");
  mostrarMatriz(matriz2, "Matriz 2");
  mostrarMatriz(resultado, "Resta de las matrices");
}

// Multiplicar matrices
void multiplicar() {
  int matriz1[2][2], matriz2[2][2], resultado[2][2] = {0};

  ingresarMatriz(matriz1, "Matriz 1");
  ingresarMatriz(matriz2, "Matriz 2");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      resultado[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        resultado[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }

  mostrarMatriz(matriz1, "Matriz 1");
  mostrarMatriz(matriz2, "Matriz 2");
  mostrarMatriz(resultado, "Multiplicaci¢n de las matrices");
}

// Menu principal
void mostrarMenu() {
  cout << "\n[1] Sumar Matrices";
  cout << "\n[2] Restar Matrices";
  cout << "\n[3] Multiplicar Matrices";
  cout << "\n[4] Salir\n";
  cout << "\tIngrese una opci¢n: ";
}

// Funci¢n Principal
int main() {
  int opcion;

  cout << "\n======== EJERCICIO 3 - CALCULADORA DE MATRICES ========\n";

  while (true) {
    mostrarMenu();
    cin >> opcion;

    if (!entradaValida()) continue;

    switch (opcion) {
      case 1:
        sumar();
        break;
      case 2:
        restar();
        break;
      case 3:
        multiplicar();
        break;
      case 4:
        cout << "\nSaliendo del programa...\n";
        return 0;
      default:
        cout << "\033[31m\nOpci¢n no v lida. Intente nuevamente.\n\033[0m";
    }
  }
}
