//============================================================================
// Name        : Autobus.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 3 - While (Ejercicio [1])
//============================================================================

// EJERCICIO 1
// Autobus

#include <iostream>
using namespace std;

// Variables globales
const int MAX_VENTANA = 4;
const int MAX_PASILLO = 4;

int totalAsientos = 8;
int asientosVentana = 0;
int asientosPasillo = 0;

// Funci¢n para asignar asiento de ventana
void ventana() {
  if (asientosVentana < MAX_VENTANA) {
    asientosVentana++;
    totalAsientos--;
    cout << endl;
    cout << "Asientos diponibles (" << totalAsientos << "/8)" << endl;
    cout << "\tAsiento de ventana asignado. (" << asientosVentana
         << "/4 ocupados)" << endl;
  } else {
    cout << endl;
    cerr << "\033[31m No hay asientos disponibles!! \033[0m" << endl;
  }
}

// Funci¢n para asignar asiento de pasillo
void pasillo() {
  if (asientosPasillo < MAX_PASILLO) {
    asientosPasillo++;
    totalAsientos--;
    cout << endl;
    cout << "Asientos diponibles (" << totalAsientos << "/8)" << endl;
    cout << "Asiento de pasillo asignado. (" << asientosPasillo
         << "/4 ocupados)" << endl;
  } else {
    cout << endl;
    cerr << "\033[31m No hay asientos disponibles!! \033[0m" << endl;
  }
}

// Funcion Principal
int main() {
  string opcion;

  cout << endl;
  cout << "********** Ejercicio 1 - Autobus [While] **********" << endl;

  while (asientosVentana < MAX_VENTANA || asientosPasillo < MAX_PASILLO) {
    cout << endl;
    cout << "¨Qu‚ tipo de asiento desea? (ventana/pasillo): ";
    cin >> opcion;

    if (opcion == "ventana") {
      ventana();
    } else if (opcion == "pasillo") {
      pasillo();
    } else {
      cout << endl;
      cerr << "\033[31m Opci¢n inv lida. Intente con 'ventana' o 'pasillo'. "
              "\033[0m"
           << endl;
    }
  }
  cout << endl;
  cout << "Todos los asientos han sido ocupados." << endl;
  return 0;
}
