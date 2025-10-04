//============================================================================
// Name        : areaPer.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description :
//============================================================================

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

// Funci¢n para Tri ngilo Is¢celes
void isoceles() {
  float side, base, height, area, perimeter;

  // Ingreso de datos por el usuario
  cout << "Ingrese el lado igual: ";
  cin >> side;
  cout << "Ingrese la base: ";
  cin >> base;
  cout << "Ingrese la altura: ";
  cin >> height;

  // C lculos
  area = (base * height) / 2;
  perimeter = base + (2 * side);

  // Imprimir salida
  cout << "El per¡metro es: " << perimeter << " (m)" << endl;
  cout << "El  rea es: " << area << " (m^2)" << endl;
}

// Funci¢n para Tri ngulo Escaleno
void escaleno() {
  float side1, side2, side3, height, area, perimeter;

  // Ingreso de datos por el usuario
  cout << "Ingrese base: ";
  cin >> side1;
  cout << "Ingrese lado [2]: ";
  cin >> side2;
  cout << "Ingrese lado [3]: ";
  cin >> side3;
  cout << "Ingrese la altura: ";
  cin >> height;

  // C lculos
  area = (side1 * height) / 2;
  perimeter = side1 + side2 + side3;

  // Imprimir salida
  cout << "El per¡metro es: " << perimeter << " (m)" << endl;
  cout << "El  rea es: " << area << " (m^2)" << endl;
}

// Funci¢n para Tri ngulo Equil tero
void equilatero() {
  float side, area, perimeter;

  // Ingreso de datos por el usuario
  cout << "Ingrese el lado: ";
  cin >> side;

  // C lculos
  area = (sqrt(3) / 4) * side;
  perimeter = 3 * side;

  // Imprimir salida
  cout << "El per¡metro es: " << perimeter << " (m)" << endl;
  cout << "El  rea es: " << area << " (m^2)" << endl;
}

// NOTA: Se puede crear otra funci¢n con la FàRMULA DE HERON

// Funci¡n Principal
void figuraGeo() {
  double side, base, area, perimeter, pi = 3.14159;
  int option, option2;

  // Solicitar al usuario ingrese una opci¢n
  cout << "[1] Cuadrado" << endl;
  cout << "[2] C¡rculo" << endl;
  cout << "[3] Rect ngulo" << endl;
  cout << "[4] Tri ngulo" << endl;
  cout << "\t Seleccione una opci¢n: ";
  cin >> option;

  // Ingresasr a los casos
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
      // Solicitar al usuario seleccione un tipo de tri ngulo
      cout << endl;
      cout << "**** TRIµNGULOS ****" << endl;

      cout << "[1] Tri ngulo Equil tero: " << endl;
      cout << "[2] Tri ngulo Is¢celes: " << endl;
      cout << "[3] Tri ngulo Escaleno: " << endl;
      cout << "\t Seleccione un tipo de tri ngulo: ";
      cin >> option2;

      switch (option2) {
        case 1:
          cout << endl;
          cout << "TRIµNGULO EQUILµTERO" << endl;
          equilatero();
          break;
        case 2:
          cout << endl;
          cout << "TRIµNGULO ISàCELES" << endl;
          isoceles();
          break;

        case 3:
          cout << endl;
          cout << "TRIµNGULO ESCALENO" << endl;
          escaleno();
          break;

        default:
          cout << "ERROR!!" << endl;
          break;
      }
      break;

    default:
      cout << endl;
      cerr << "\033[31mOpci¢n Incorrecta!!\033[0m" << endl;
      break;
  }
  cout << endl;
}

int main() {
  cout << "****** Uso de Switch ******" << endl;
  cout << "****** µreas y Per¡metros ******" << endl;
  cout << endl;

  cout << "Ejercicio 2" << endl;
  figuraGeo();

  return 0;
}
