//============================================================================
// Name        : For_3.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 4 - For (Ejercicio [3])
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 3 FACTORIAL

// Funci¢n para limpiar errores de entrada
void limpiarEntrada() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Funci¢n para verificar si la entrada fue v lida
bool entradaValida() {
  if (cin.fail()) {
    cout << "\033[31m\nSolo se permiten n£meros!!!\n\033[0m";
    limpiarEntrada();
    return false;
  }
  limpiarEntrada();  // Siempre limpiar el buffer
  return true;
}

// Funci¢n para calcular el factorial
void factorial() {
  int number;
  int resultado = 1;

  cout << "\n>> Ingrese un n£mero: ";
  cin >> number;

  if (!entradaValida()) return;

  if (number < 0) {
    cout << "\033[31mEl factorial no est  definido para n£meros "
            "negativos.\033[0m\n";
  } else if (number == 0) {
    cout << number << "! = " << 1 << endl;
  } else {
    cout << number << "! = ";

    for (int i = 1; i <= number; i++) {
      cout << i;
      if (i < number) {
        cout << " x ";
      }
      resultado *= i;
    }
    cout << " = " << resultado << endl;
  }
}

// Funci¢n Principal
int main() {
  int option;

  cout << endl;
  cout << "======== EJERCICIO 3 - FACTORIAL [for] ========";
  do {
    cout << "\n[1] Calcular Factorial\n";
    cout << "[2] Salir\n";
    cout << "\tIngrese una opci¢n: ";
    cin >> option;

    if (!entradaValida()) continue;

    if (option == 1) {
      factorial();

    } else if (option == 2) {
      cout << "\nFin del programa!!\n";
    } else {
      cout << "\n\033[31mOpci¢n incorrecta. Intente nuevamente.\033[0m\n";
    }
  } while (option != 2);

  return 0;
}
