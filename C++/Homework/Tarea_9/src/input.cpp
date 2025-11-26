//============================================================================
// Name        : input.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : validation functions for dragon game
//============================================================================

#include "input.h"

#include <iostream>
#include <limits>
using namespace std;

// Colores ANSI
#define RESET "\033[0m"
#define ROJO "\033[31m"

//----------------------------------------
// Funciones validacion de entrada
//----------------------------------------
void limpiarEntrada() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool entradaValida() {
  if (cin.fail()) {
    cout << ROJO << "\nEntrada inv lida!!" << RESET << "\n";
    limpiarEntrada();
    return false;
  }
  return true;
}
