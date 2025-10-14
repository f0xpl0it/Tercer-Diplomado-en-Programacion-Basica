//============================================================================
// Name        : For.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/10/14
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

// Programa Serie del 0 al 10
void serie() {
  int i;

  cout << "Bucle 0 al 10\n";
  for (i = 0; i <= 10; ++i) {
    cout << i << endl;
  }
}

// Buble Serie del 10 al 1
void serieInvertida() {
  int i;

  cout << "Bucle 10 al 0\n";
  for (i = 10; i >= 0; --i) {
    cout << i << endl;
  }
}

// Programa Serie del 0 al 20
void seriePar() {
  int i;

  cout << "Bucle con apres del 0 al 20\n";
  for (i = 0; i <= 20; i += 2) {
    cout << i << endl;
  }
}

// Programa bucle con potencias de 3 del 1 al 100
void potencia() {
  cout << "\nBucle con potencias de 3 del 1 al 10\n" << endl;
  for (int i = 1; i <= 100; i *= 3) {
    cout << i << endl;
  }
}

// BUCLE QUE NO SE EJECUTA
void serieError() {
  for (int i = 10; i <= 0; --i) {
    cout << i << endl;
  }
}

// Programa para crear serie de n£mero de forma ascendente
void rangoNumero() {
  int n1, n2;

  cout << "Introduce el primer n£mero: ";
  cin >> n1;
  cout << "Introduce el segundo n£mero: ";
  cin >> n2;

  if (n1 <= n2) {
    for (int i = n1; i <= n2; ++i) {
      cout << i << endl;
    }
  } else {
    for (int i = n2; i <= n1; i++) {
      cout << i << endl;
    }
  }
}

// Programa que calcula la media de una serie de n£meros
void mediaNumero() {
  int num;

  cout << "Introduce el n£mero de valores: ";
  cin >> num;

  double acumulador = 0;
  for (int i = 0; i < num; ++i) {
    double valor;
    cout << "Introduce n£mero: ";
    cin >> valor;
    acumulador = acumulador + valor;
  }
  double media = acumulador / num;
  cout << "\nLa media de los n£meros es: " << media << endl;
}

int main() {
  cout << "\n===== EJEMPLO 1 =====\n";
  serie();

  cout << "\n===== EJEMPLO 2 =====\n";
  seriePar();

  cout << "\n===== EJEMPLO 3 =====\n";
  potencia();

  cout << "\n===== EJEMPLO 4 =====\n";
  serieError();
  cout << "int i = 10; i <= 0; --i\n";
  cout << "i > 0 por tanto i <= 0 NUNCA SE CUMPLE!!!\n";
  cout << "\nLA SERIE NO IMPRIME NADA!!\n";
  /*
   * Inicializaci¢n: i = 10
   * Condici¢n: i <= 0 ? falsa desde el principio
   * Actualizaci¢n: --i (se decrementar¡a si la condici¢n fuera verdadera)
   * La condici¢n 10 <= 0 es falsa, por lo tanto, el for se salta
   * completamente y no imprime nada.*/

  cout << "\n===== EJEMPLO 5 =====\n";
  serieInvertida();  // Ejemplo anterior corregido

  cout << "\n===== EJEMPLO 6 =====\n";
  rangoNumero();

  cout << "\n===== EJEMPLO 7 =====\n";
  mediaNumero();

  return 0;
}
