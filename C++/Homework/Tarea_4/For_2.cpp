//============================================================================
// Name        : For_2.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 4 - For (Ejercicio [2])
//============================================================================

#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 2

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

// Funci¢n para calcular la Serie Fibonacci
void fibonacci() {
  int number, f0 = 0, f1 = 1, f2;

  cout << "\n>> Ingrese la cantidad de t‚rminos de la Serie Fibonacci: ";
  cin >> number;

  if (!entradaValida()) return;

  if (number <= 0) {
    cout << "\033[31m\nDebe ingresar un n£mero mayor que 0!!!\033[0m\n";
    return;
  }

  for (int i = 0; i <= number; i++) {
    f2 = f0 + f1;
    cout << f0 << " ";
    f0 = f1;
    f1 = f2;
  }
  cout << endl;
}

// Funci¢n Principal
int main() {
  int option;

  cout << endl;
  cout << "======== EJERCICIO 2 - FACTORIAL [for] ========";
  do {
    cout << "\n[1] Calcular Serie Fibonacci\n";
    cout << "[2] Salir\n";
    cout << "\tIngrese una opci¢n: ";
    cin >> option;

    if (!entradaValida()) continue;

    if (option == 1) {
      fibonacci();

    } else if (option == 2) {
      cout << "\nFin del programa!!\n";
    } else {
      cout << "\nOpci¢n Incorrecta. Intente nuevamente.\n";
    }
  } while (option != 2);

  return 0;
}
