//============================================================================
// Name        : AutobusRef.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 3 - While (Ejercicio [1])
//============================================================================

#include <iostream>
using namespace std;

// Asigna asiento de ventana (por referencia)
void ventana(int &asientosVentana) {
  if (asientosVentana < 4) {
    asientosVentana++;
    cout << "Asiento de ventana asignado. (" << asientosVentana << "/4)\n";
  } else {
    cout << "Ya no hay asientos de ventana.\n";
  }
}

// Asigna asiento de pasillo (por referencia)
void pasillo(int &asientosPasillo) {
  if (asientosPasillo < 4) {
    asientosPasillo++;
    cout << "Asiento de pasillo asignado. (" << asientosPasillo << "/4)\n";
  } else {
    cout << "Ya no hay asientos de pasillo.\n";
  }
}

int main() {
  int asientosVentana = 0;
  int asientosPasillo = 0;
  int opcion;

  while (asientosVentana < 4 || asientosPasillo < 4) {
    cout << endl;
    cout << "[1] Ventana " << endl;
    cout << "[2] Pasillo " << endl;
    cout << "\tSeleccione una opci¢n: ";
    cin >> opcion;

    if (opcion == 1) {
      ventana(asientosVentana);
    } else if (opcion == 2) {
      pasillo(asientosPasillo);
    } else {
      cout << "Opci¢n no v lida.\n";
    }
  }

  cout << "Todos los asientos han sido ocupados.\n";
  return 0;
}
