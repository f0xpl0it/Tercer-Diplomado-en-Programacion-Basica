//============================================================================
// Name        : Switch_3.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Uso de Switch (Ejercicio [3])
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

// EJERCICIO 3
// Figuras calculadora b sica

void calculadora() {
  float sum, sus, mul, div, pot, raiz, a, b;
  int option;

  // Solicitar al usuario ingrese una opci¢n
  cout << "[1] Suma" << endl;
  cout << "[2] Resta" << endl;
  cout << "[3] Multiplicaci¢n" << endl;
  cout << "[4] Divisi¢n" << endl;
  cout << "[5] Potencia" << endl;
  cout << "[6] Ra¡z Cuadrada" << endl;
  cout << "\t >> Seleccione una opci¢n: ";
  cin >> option;

  // Ingresar a los casos
  switch (option) {
    // Suma
    case 1:
      cout << endl;
      cout << "**** SUMA ****" << endl;

      // Solicitar al usuario ingresar los datos
      cout << "Ingresar primer n£mero: ";
      cin >> a;
      cout << "Ingresar segundo n£mero: ";
      cin >> b;

      // C lculos
      sum = a + b;

      // Imprimir salida
      cout << a << " + " << b << " = " << sum << endl;
      break;

      // Resta
    case 2:
      cout << endl;
      cout << "**** RESTA ****" << endl;

      // Solicitar al usuario ingresar los datos
      cout << "Ingresar primer n£mero: ";
      cin >> a;
      cout << "Ingresar segundo n£mero: ";
      cin >> b;

      // C lculos
      sus = a - b;

      // Imprimir salida
      cout << a << " - " << b << " = " << sus << endl;
      break;

      // Multiplicacion
    case 3:
      cout << endl;
      cout << "**** MULTIPLICACIàN ****" << endl;

      // Solicitar al usuario ingresar los datos
      cout << "Ingresar primer n£mero: ";
      cin >> a;
      cout << "Ingresar segundo n£mero: ";
      cin >> b;

      // C lculos
      mul = a * b;

      // Imprimir salida
      cout << a << " x " << b << " = " << mul << endl;
      break;

      // Divisi¢n
    case 4:
      cout << endl;
      cout << "**** DIVISIàN ****" << endl;

      // Solicitar al usuario ingresar los datos
      cout << "Ingresar primer n£mero: ";
      cin >> a;
      cout << "Ingresar segundo n£mero: ";
      cin >> b;

      // C lculos y validaci¢n
      if (b == 0) {
        cout << "[LA DIVISIàN POR 0 ES INDETERMINADA]" << endl;
      } else {
        // C lculos
        div = a / b;

        // Imprimir salida
        cout << a << " ö " << b << " = " << div << endl;
      }
      break;

      // Potencia
    case 5:
      cout << endl;
      cout << "**** POTENCIA ****" << endl;

      // Solicitar al usuario ingresar los datos
      cout << "Ingresar la base: ";
      cin >> a;
      cout << "Ingresar el exponente: ";
      cin >> b;

      // C lculos
      pot = pow(a, b);

      // Imprimir salida
      cout << a << " ^ " << b << " = " << pot << endl;
      break;

      // Ra¡z cuadrada
    case 6:
      cout << endl;
      cout << "**** RAÖZ CUADRADA ****" << endl;

      // Solicitar al usuario ingresar los datos
      cout << "Ingresar un n£mero: ";
      cin >> a;

      // Validaci¢n
      if (a < 0) {
        cout << "[NO DEFINIDA EN LOS REALES]" << endl;
      } else {
        // C lculos
        raiz = sqrt(a);

        // Imprimir salida
        cout << "sqrt(" << a << ") = " << raiz << endl;
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

  cout << "Ejercicio 3 - Calculadora b sica" << endl;
  calculadora();

  return 0;
}
