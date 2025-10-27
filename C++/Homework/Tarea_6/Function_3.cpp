//============================================================================
// Name        : Function_3.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 6 - Funciones (Ejercicio [3])
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
  limpiarEntrada();
  return true;
}

// Invertir arreglo
void invertirArreglo(int numeros[], int longitud) {
  int inicio = 0;          // Öndice del primer elemento
  int fin = longitud - 1;  // Öndice del £ltimo elemento

  // Usamos la l¢gica del ejercico clasico cambio de 3 variables
  while (inicio < fin) {
    int temp = numeros[inicio];  // Guardamos el valor del inicio
    numeros[inicio] =
        numeros[fin];     // Intercambio el valor del final en el inicio
    numeros[fin] = temp;  // Intercambio el valor guardado en el final
    inicio++;             // Avanzamos un valor del ¡ndice
    fin--;                // Retrocedemos un valor del indice
  }
}

// Funcion Principal
int main() {
  cout << "\n======== EJERCICIO 3 - INVERTIR ARREGLO ========\n";

  const int LONGITUD = 10;
  int arreglo[LONGITUD];

  for (int i = 0; i < LONGITUD; i++) {
    int valores;
    cout << "Ingrese el valor #" << i + 1 << ": ";
    cin >> valores;

    while (!entradaValida()) {
      cout << "Ingrese el valor #" << i + 1 << ": ";
      cin >> valores;
    }
    arreglo[i] = valores;
  }
  // Imprimir arreglo norma;
  cout << "Arreglo normal: [";
  for (int i = 0; i < LONGITUD; i++) {
    cout << arreglo[i];
    if (i < LONGITUD - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";
  // Funcion arreglo invertido
  invertirArreglo(arreglo, LONGITUD);

  // Imprimir arreglo invertido
  cout << "\nArreglo invertido: [";
  for (int i = 0; i < LONGITUD; i++) {
    cout << arreglo[i];
    if (i < LONGITUD - 1) {
      cout << ", ";
    }
  }
  cout << "]\n";

  return 0;
}
