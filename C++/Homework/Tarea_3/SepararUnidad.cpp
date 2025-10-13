//============================================================================
// Name        : SepararUnidad.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description :
//============================================================================

#include <iostream>
using namespace std;

int main() {
  int numero;
  cout << "Ingrese un n£mero entero (m ximo 4 d¡gitos): ";
  cin >> numero;

  // Convertir a positivo si es negativo
  if (numero < 0) {
    numero = -numero;
  }

  int unidad = numero % 10;
  int decena = (numero / 10) % 10;
  int centena = (numero / 100) % 10;
  int mil = (numero / 1000) % 10;

  cout << "Mil:     " << mil << endl;
  cout << "Centena: " << centena << endl;
  cout << "Decena:  " << decena << endl;
  cout << "Unidad:  " << unidad << endl;

  return 0;
}
