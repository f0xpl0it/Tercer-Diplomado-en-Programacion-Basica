//============================================================================
// Name        : If.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/09/30
//============================================================================

#include <iostream>
using namespace std;

// Programa para asiganar la edad if..else
void asignarEdad() {
  int edad;

  cout << "1. Menor edad" << endl;
  cout << "2. Adulto" << endl;
  cout << "3. Adulto mayor" << endl;

  cout << "Seleccione la opci¢n corrrespondiente: ";
  cin >> edad;

  if (edad == 1) {
    cout << "Tu entrada cuesta $1.00" << endl;

  } else if (edad == 2) {
    cout << "Tu entrada cuesta $2.00" << endl;
  } else if (edad == 3) {
    cout << "Tu entrada cuesta $1.50" << endl;
  } else {
    cout << "Valor incorrecto" << endl;
  }
  cout << endl;
}

// Programa para verificar la edad if..else
void verificaEdad() {
  int edad;

  cout << "Ingrese la edad: ";
  cin >> edad;

  if (edad > 0 and edad < 13) {
    cout << "Tu entrada cuesta $1.00" << endl;
  } else if (edad >= 13 and edad < 60) {
    cout << "Tu entrada cuesta $2.00" << endl;
  } else if (edad >= 60) {
    cout << "Tu entrada cuesta $1.50" << endl;
  } else {
    cout << "Valor incorrecto" << endl;
  }
  cout << endl;
}

// Programa para validar las credenciales
void credencial() {
  string user, password;

  cout << "Ingrese el usuario: ";
  cin >> user;
  cout << "Ingrese la contrase¤a: ";
  cin >> password;

  if (user == "admin" and password == "1234")
    cout << "Usuario Correcto" << endl;
  else
    cout << "Unsuario Incorrecto" << endl;
}

int main() {
  cout << endl;
  cout << "****** EJEMPLO 1 ******" << endl;
  asignarEdad();

  cout << endl;
  cout << "****** EJEMPLO 2 ******" << endl;
  verificaEdad();

  cout << endl;
  cout << "****** EJEMPLO 3 ******" << endl;
  credencial();

  return 0;
}
