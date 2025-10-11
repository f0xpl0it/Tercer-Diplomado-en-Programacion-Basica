//============================================================================
// Name        : areaCirculo.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/09/23
//============================================================================

#include <iostream>
using namespace std;

// Programa para calcular el  reaa de un c¡rculo
int main() {
  // Declaraci¢n de variables
  double radio;
  double area;
  double pi = 3.141592;

  // Ingreso de datos
  cout << "Ingrese el radio: ";
  cin >> radio;

  // C lculo del  rea del c¡rculo
  area = pi * radio * radio;

  // Impresion en consola
  cout << "El  rea es: " << area << endl;

  return 0;
}
