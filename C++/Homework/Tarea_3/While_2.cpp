//============================================================================
// Name        : While_2.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 3 - While (Ejercicio [2])
//============================================================================

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// EJERCICIO 2
// Soluci¢n para n£meros enteros
void lengthInt() {
  int numero, longitud = 0;

  cout << "Ingrese un n£mero entero: ";
  cin >> numero;

  // Convertir n£mero negativo a positivo
  if (numero < 0) numero = -numero;

  // Si el n£mero es 0, su longitud es 1
  if (numero == 0) {
    longitud = 1;
  } else {
    while (numero > 0) {
      numero = numero / 10;
      longitud++;
    }
  }
  cout << "La longitud del n£mero es: " << longitud << " d¡gito(s)." << endl;
}

// Soluci¢n para n£meros enteros
void lengthDec() {
  string entrada;
  int longitud = 0;
  size_t i = 0;  // dato entero sin signo

  cout << "Ingrese un n£mero: ";
  cin >> entrada;

  while (i < entrada.length()) {
    if (isdigit(
            entrada[i])) {  // verificar si un car cter es un d¡gito num‚rico
      longitud++;           // cuenta solo los d¡gitos
    }
    i++;
  }

  cout << "La longitud del n£mero es: " << longitud << " d¡gito(s)." << endl;
}

// Funci¢n Principal
int main() {
  cout << endl;
  cout << "********** Ejercicio 2 - Longitud [While] **********" << endl;

  cout << endl;
  cout << "##### Soluci¢n para n£meros enteros #####" << endl;
  lengthInt();

  cout << endl;
  cout << "##### Soluci¢n para n£meros decimales #####" << endl;
  lengthDec();

  return 0;
}
