//============================================================================
// Name        : AutobusInt.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 3 - While (Ejercicio [1])
//============================================================================

#include <iostream>
using namespace std;
int total = 8;

// Asigna asiento de ventana (retorna el nuevo valor)
int ventana(int asientosVentana) {
  if (asientosVentana < 4) {
    asientosVentana++;
    total--;
    cout << "Asiento de ventana asignado. (" << asientosVentana << "/4)\n";
    cout << "Asientos diponibles (" << total << "/8) \n";
  } else {
    cout << "Ya no hay asientos de ventana.\n";
  }
  return asientosVentana;
}

// Asigna asiento de pasillo (retorna el nuevo valor)
int pasillo(int asientosPasillo) {
  if (asientosPasillo < 4) {
    asientosPasillo++;
    total--;
    cout << "Asiento de pasillo asignado. (" << asientosPasillo << "/4)\n";
    cout << "Asientos diponibles (" << total << "/8) \n";
  } else {
    cout << "Ya no hay asientos de pasillo.\n";
  }
  return asientosPasillo;
}

int main() {
  int asientosVentana = 0, asientosPasillo = 0;
  int opcion;

  while (asientosVentana < 4 || asientosPasillo < 4) {
    cout << endl;
    cout << "[1] Ventana " << endl;
    cout << "[2] Pasillo " << endl;
    cout << "\tSeleccione una opci¢n: ";
    cin >> opcion;

    if (opcion == 1) {
      asientosVentana = ventana(asientosVentana);  // actualiza el valor
    } else if (opcion == 2) {
      asientosPasillo = pasillo(asientosPasillo);  // actualiza el valor
    } else {
      cout << "Opci¢n no v lida.\n";
    }
  }

  cout << "Todos los asientos han sido ocupados.\n";
  return 0;
}
