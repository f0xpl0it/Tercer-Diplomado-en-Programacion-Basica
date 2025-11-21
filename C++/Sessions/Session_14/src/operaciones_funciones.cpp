//============================================================================
// Name        : operaciones_funciones.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description :
//============================================================================

//----------------------------------------
// PROGRAMA FUNCIONES
//----------------------------------------

#include "operaciones_funciones.h"

#include <cmath>
#include <iostream>
using namespace std;

//----------------------------------------
// Funci¢n Sumar
//----------------------------------------
int sumar(int a, int b) { return a + b; }

//----------------------------------------
// Funci¢n Restar
//----------------------------------------
int restar(int a, int b) { return a - b; }

//----------------------------------------
// Funci¢n Multiplicar
//----------------------------------------
int multiplicar(int a, int b) { return a * b; }

//----------------------------------------
// Funci¢n Dividir
//----------------------------------------
float dividir(float a, float b) {
  if (b != 0) {
    return a / b;
  } else {
    cout << "Error: Division por cero." << endl;
    return NAN;  // Retorna Not-A-Number si hay divisi¢n por cero
  }
}