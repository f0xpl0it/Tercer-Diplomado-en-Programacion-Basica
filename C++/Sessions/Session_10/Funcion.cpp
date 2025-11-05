//============================================================================
// Name        : Funcion.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/10/24
//============================================================================

#include <iostream>
using namespace std;

// Funcion modificar n
int modificarn(int n) {
  n += 2;
  cout << "\nInterno: " << n << endl;
  return 0;
}

// Funcion modifica rn por referencia
void modificarreferencia(int& p) {
  p += 2;
  cout << "\nInterno: " << p << endl;
}

// Funcion para llenar arreglo
int duplicar(int arreglo[], int m) {
  cout << "\nArreglo Interno: ";
  for (int i = 0; i < m; i++) {
    ;
    arreglo[i] = 2 * arreglo[i];
    cout << arreglo[i] << " ";
  }
  cout << endl;
}

// Funci¢n Principal
int main() {
  // Paso por valor
  cout << "\n===== EJEMPLO 1 - PASO POR VALOR =====";
  int n = 1;

  modificarn(n);
  cout << "Original: " << n << endl;

  // Paso por referencia con &
  cout << "\n===== EJEMPLO 2 - PASO POR REFERENCIA =====";
  int p = 1;

  modificarreferencia(p);
  cout << "Original: " << p << endl;

  // Paso por referencia por default
  cout << "\n===== EJEMPLO 3 - ARREGLOS =====";
  int m = 3;
  int numeros[3] = {1, 2, 3};
  duplicar(numeros, m);
  cout << "Arreglo Original: ";

  for (int i = 0; i < m; i++) {
    cout << numeros[i] << " ";
  }
  cout << endl;

  return 0;
}
