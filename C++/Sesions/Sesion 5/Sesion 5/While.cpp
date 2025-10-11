//============================================================================
// Name        : While.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/10/07
//============================================================================

#include <iostream>
using namespace std;

// Programa para validar un n£mero positivo
void numeroPositivo() {
  int numero;
  cout << "Ingrese un n£mero positivo: ";
  cin >> numero;

  while (numero <= 0) {
    cout << "N£mero no v lido. Ingrese un n£mero positivo: ";
    cin >> numero;
  }
  cout << "N£mero v lido ingresado: " << numero << endl;
}

// Programa crea rango de nn£meros postivos [1 2 3 4 ...]
void contadorNumeros() {
  int limite, contador = 1;

  // Solicitar al usuario que ingrese un n£mero positivo
  cout << "Ingrese un numero positivo: ";
  cin >> limite;

  // VCerificar si el n£mero es positivo
  while (limite <= 0) {
    cout << "N£mero no v lido. Ingrese un n£mero positivo: ";
    cin >> limite;
  }

  // Imprimir los n£meros desde  1 hast n ingresados
  while (contador <= limite) {
    cout << contador << " ";
    contador++;
  }
  cout << endl;
}

// Programa para validar el ingreso de n£meros del [1 - 100]
void validarNumero() {
  int numero;

  cout << "Ingrese un numero entre 1 y 100: ";
  cin >> numero;

  while (numero < 1 || numero > 100) {
    cout << "N£mero invalido. Por favor, ingrese un n£mero entre 1 y 100: ";
    cin >> numero;
  }
  cout << "N£mero v lido ingresado: " << numero << endl;
}

// Llamado de funciones de ejemplos
int main() {
  cout << endl;
  cout << "****** EJEMPLO 1 ******" << endl;
  numeroPositivo();

  cout << endl;
  cout << "****** EJEMPLO 2 ******" << endl;
  contadorNumeros();

  cout << endl;
  cout << "****** EJEMPLO 3 ******" << endl;
  validarNumero();
  return 0;
}
