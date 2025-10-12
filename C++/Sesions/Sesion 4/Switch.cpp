//============================================================================
// Name        : Switch.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description :
//============================================================================

#include <iostream>
using namespace std;

// Programa para asiganar la edad switch
void menuEdad() {
  int edad;

  cout << "1. Menor edad" << endl;
  cout << "2. Adulto" << endl;
  cout << "3. Adulto mayor" << endl;

  cout << "Seleccione la opci¢n corrrespondiente: ";
  cin >> edad;

  switch (edad) {
    case 1:
      cout << "Tu entrada cuesta $1.00" << endl;

      break;
    case 2:
      cout << "Tu entrada cuesta $2.00" << endl;
      break;
    case 3:
      cout << "Tu entrada cuesta $1.50" << endl;

      break;
    default:
      cout << "Valor incorrecto" << endl;
      break;
  }
  cout << endl;
}

int main() {
    cout << endl;
  cout << "****** EJEMPLO 1 ******" << endl;
  menuEdad();

  return 0;
}
