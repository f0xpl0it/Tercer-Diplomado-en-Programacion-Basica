//============================================================================
// Name        : operaciones_main.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/11/21
//============================================================================

// g++ operaciones_main.cpp operaciones_funciones.cpp -o operaciones
// COMPILAR EL PROGRAMA DESDE CONSOLA

//----------------------------------------
// PROGRAMA PRINCIPAL
//----------------------------------------
#include <iostream>

#include "operaciones_funciones.h"
using namespace std;

//----------------------------------------
// Funci¢n Principal
//----------------------------------------
int main() {
  cout << "Suma: " << sumar(5, 3) << endl;
  cout << "Resta: " << restar(5, 3) << endl;
  cout << "Multiplicacion: " << multiplicar(5, 3) << endl;
  cout << "Division: " << dividir(5, 0) << endl;

  return 0;
}
