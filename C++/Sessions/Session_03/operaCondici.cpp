//============================================================================
// Name        : operaCondici.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/09/26
//============================================================================

#include <iostream>
using namespace std;

// Programa para b sico para comprobar mayoria de edad
void mayorEdad() {
  // Asigar variable
  int edad;

  // Imprimir mensaje para ingresar datos
  cout << "Ingresa tu edad: ";

  // Lectura de la edad
  cin >> edad;

  // Comparaci¢n de edad
  if (edad >= 18) {
    // Mensaje si es mayor de edad
    cout << "Eres mayor de edad";
  }
  cout << endl;
}

// Programa para b sico para comprobar edad y altura
void requisito() {
  // Asigar variable
  int edad;
  float altura;

  // Imprimir mensaje para ingresar datos
  cout << "Ingresa tu edad: ";
  cin >> edad;  // Lectura de entradas

  // Imprimir mensaje para ingresar datos
  cout << "Ingresa tu estatura: ";
  cin >> altura;  // Lectura de entradas

  // Comparaci¢n de edad
  if (edad >= 18 || edad <= 65 && altura >= 1.50) {
    // Mensaje si es mayor de edad
    cout << "Eres un adulto, tienes " << edad << " a¤os y mides " << altura;
  }
  cout << endl;
}

int main() {
  cout << endl;
  cout << "****** EJEMPLO 1 ******" << endl;
  mayorEdad();

  cout << endl;
  cout << "****** EJEMPLO 2 ******" << endl;
  requisito();

  return 0;
}
