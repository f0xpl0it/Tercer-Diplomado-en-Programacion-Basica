//============================================================================
// Name        : Switch_1.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 2 - Uso de Switch (Ejercicio [1])
//============================================================================

#include <iostream>
using namespace std;

// Funci¢n para verificar si el a¤o es bisiesto
bool esBisiesto(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    return true;
  }
  return false;
}

// EJERCICIO 1
// Calendario
void calendar() {
  int year, month;

  // Solicitar el a¤o al usuario
  cout << "Ingrese un a¤o: ";
  cin >> year;

  // Solicitar el mes al usuario
  cout << "Ingrese un n£mero de mes (1-12): ";
  cin >> month;

  // Usar switch para mostrar los d¡as de cada mes
  switch (month) {
    case 1:
      cout << "Enero tiene 31 d¡as." << endl;
      break;
    case 3:
      cout << "Marzo tiene 31 d¡as." << endl;
      break;
    case 5:
      cout << "Mayo tiene 31 d¡as." << endl;

    case 7:
      cout << "Julio tiene 31 d¡as." << endl;
      break;
    case 8:
      cout << "Agosto tiene 31 d¡as." << endl;
      break;
    case 10:
    case 12:
      cout << "Diciembre tiene 31 d¡as." << endl;
      break;

    case 4:
      cout << "Abril tiene 30 d¡as." << endl;
      break;
    case 6:
      cout << "Junio tiene 30 d¡as." << endl;
      break;
    case 9:
      cout << "Septiembre tiene 30 d¡as." << endl;
      break;
    case 11:
      cout << "Noviembre tiene 30 d¡as." << endl;
      break;

    case 2:  // Febrero, debe verificar si el a¤o es bisiesto
      if (esBisiesto(year)) {
        cout << "Febrero tiene 29 d¡as (a¤o bisiesto)." << endl;
      } else {
        cout << "Febrero tiene 28 d¡as." << endl;
      }
      break;

    default:
      cout << endl;
      cout << "Opci¢n incorrecta!!" << endl;
      break;
  }
}

int main() {
  cout << "****** Uso de Switch ******" << endl;
  cout << endl;

  cout << "Ejercicio 1 - Generador de calendario" << endl;
  calendar();

  return 0;
}