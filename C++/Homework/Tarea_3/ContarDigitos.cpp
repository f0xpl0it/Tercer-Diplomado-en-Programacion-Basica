//============================================================================
// Name        : ContarDigitos.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Variante para contadar digitos con For
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void lengthNumber() {
  string entrada;
  int longitud = 0;

  cout << "Ingrese un n£mero (puede tener decimales): ";
  cin >> entrada;

  // Recorremos cada car cter de la cadena
  for (char c : entrada) {
    if (isdigit(c)) {
      longitud++;  // Contamos solo los d¡gitos (ignoramos punto y signo)
    }
  }

  cout << "La longitud del n£mero es: " << longitud << " d¡gito(s)." << endl;
}

int main() {
  cout << endl;
  cout << "********** Ejercicio 2 - Longitud [While/String] **********" << endl;

  lengthNumber();

  return 0;
}
