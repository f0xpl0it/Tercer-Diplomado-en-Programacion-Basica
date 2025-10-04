//============================================================================
// Name        : Switch_2.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 2 - Uso de Switch (Ejercicio [2])
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

// EJERCICIO 2
// Figuras Geometricas

void figuraGeo() {
  double side, base, area, perimeter, pi = 3.14159;
  int option;

  // Solicitar al usuario ingrese una opci¢n
  cout << "[1] Cuadrado" << endl;
  cout << "[2] C¡rculo" << endl;
  cout << "[3] Rect ngulo" << endl;
  cout << "[4] Tri ngulo" << endl;
  cout << "\t >> Seleccione una opci¢n: ";
  cin >> option;

  // Ingresar a los casos
  switch (option) {
    // Cuadrado
    case 1:
      // Solicitar al usuario ingrese el lado del cuadrado
      cout << endl;
      cout << "**** CUADRADO ****" << endl;
      cout << "Ingrese el lado: ";
      cin >> side;

      // C lculos
      area = pow(side, 2);
      perimeter = 4 * side;

      // Imprimir salida
      cout << "El per¡metro es: " << perimeter << " (m)" << endl;
      cout << "El  rea es: " << area << " (m^2)" << endl;
      break;

      // Rect ngulo
    case 2:
      // Solicitar al usuario ingrese la base y altura del rect ngulo
      cout << endl;
      cout << "**** RECTµNGULO ****" << endl;
      cout << "Ingrese la base: ";
      cin >> base;
      cout << "Ingrese la altura: ";
      cin >> side;

      // C lculos
      area = base * side;
      perimeter = (2 * base) + (2 * side);

      // Imprimir salida
      cout << "El per¡metro es: " << perimeter << " (m)" << endl;
      cout << "El  rea es: " << area << " (m^2)" << endl;
      break;

      // C¡rculo
    case 3:
      // Solicitar al usuario ingrese el radio del c¡rculo
      cout << endl;
      cout << "**** CÖRCULO ****" << endl;
      cout << "Ingrese el radio: ";
      cin >> side;

      // C lculos
      area = pi * pow(side, 2);
      perimeter = 2 * side * pi;

      // Imprimir salida
      cout << "El per¡metro es: " << perimeter << " (m)" << endl;
      cout << "El  rea es: " << area << " (m^2)" << endl;
      break;

      // Tri ngulo
    case 4:
      // Solicitar al usuario ingrese el lado del tri ngulo
      cout << "Ingrese el lado: ";
      cin >> side;

      // C lculos
      area = (sqrt(3) / 4) * side;
      perimeter = 3 * side;

      // Imprimir salida
      cout << "El per¡metro es: " << perimeter << " (m)" << endl;
      cout << "El  rea es: " << area << " (m^2)" << endl;
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

  cout << "Ejercicio 2 - Figuras geom‚tricas" << endl;
  figuraGeo();

  return 0;
}
