//============================================================================
// Name        : Array.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/10/17
//============================================================================

#include <iostream>
using namespace std;

// Lista de n£meros
void arregloNumero() {
  // Creamos un arreglo
  int myNumbers[5] = {10, 20, 30, 40, 50};  // Definir arreglo Tama¤o 5

  cout << "*** Arreglo de longitud 5 ***\n";

  // Asignamos n£meros al arreglo
  for (int num : myNumbers) {
    cout << num << "\n";
  }
  cout << endl;
}

// Sumar arreglos
void sumArreglo() {
  int numero[3] = {1, 2, 3};
  int numero2[3] = {4, 5, 6};
  int suma[3];

  cout << "*** Suma de arreglos unidimensionales ***\n";

  for (int i = 0; i < 3; i++) {
    suma[i] = numero[i] + numero2[i];
    cout << suma[i];
  }
  cout << endl;
}

// Matriz Cuadrada
void matriz() {
  int matriz[2][2] = {{1, 2}, {3, 4}};  // Matriz 2x2
  cout << "*** Matriz Cuadrada ***\n";

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;  // Salto de l¡nea despu‚s de cada fila
  }
}

// Suma de matrices cuadradas
void sumamatriz() {
  int matriz[2][2] = {{1, 2}, {3, 4}};   // Definir matriz 2x2
  int matriz2[2][2] = {{8, 9}, {7, 9}};  // Definir matriz 2x2
  cout << "*** Suma de matriz cuadrada ***\n";

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << matriz[i][j] + matriz2[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Resta de matrices cuadradas
void resmatriz() {
  int matriz[2][2] = {{1, 2}, {3, 4}};   // Definir matriz 2x2
  int matriz2[2][2] = {{8, 9}, {7, 9}};  // Definir matriz 2x2
  cout << "*** Resta de matriz cuadrada ***\n";

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << matriz[i][j] - matriz2[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Matriz nxn
void matrizIrregular() {
  int matriz[2][3] = {{1, 2, 6}, {3, 6, -1}};
  cout << "*** Matriz 2x3 ***\n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Matriz nxn
void matrizImpar() {
  int matriz[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  cout << "*** Matriz 3x2 ***\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Funci¢n Principal
int main() {
  cout << "\n===== EJEMPLO 1 =====\n";
  arregloNumero();

  cout << "\n===== EJEMPLO 2 =====\n";
  sumArreglo();

  cout << "\n===== EJEMPLO 3 =====\n";
  matriz();

  cout << "\n===== EJEMPLO 4 =====\n";
  sumamatriz();

  cout << "\n===== EJEMPLO 5 =====\n";
  resmatriz();

  cout << "\n===== EJEMPLO 6 =====\n";
  matrizIrregular();

  cout << "\n===== EJEMPLO 7=====\n";
  matrizImpar();

  return 0;
}
