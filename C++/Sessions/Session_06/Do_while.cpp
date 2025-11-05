//============================================================================
// Name        : Do_while.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/10/10
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

// Progrma que imprime n£meros del 1 al 100
void serie() {
  int contador = 1;

  // Blucle do-while imprime los n£meros del 1 al 5
  do {
    cout << contador << " ";
    // contador = contador + 1
    contador++;
  } while (contador <= 5);
  cout << endl;
}

// Programa que despliega un menu con do-while
void menuDo() {
  int opcion;

  do {
    cout << "Ingrese 1 para mostrar mensaje \n";
    cout << "Ingrese 2 para hacer algo mas \n";
    cout << "Ingrese 0 para salir \n  ";

    cout << "Ingrese una opci¢n a ejecutar:  \n";
    cin >> opcion;
  } while (opcion != 0);
}

// Programa que despliega un menu con while
void menuWhile() {
  int opcion = 1;

  while (opcion != 0) {
    cout << "Ingrese 1 para mostrar mensaje \n";
    cout << "Ingrese 2 para hacer algo mas \n";
    cout << "Ingrese 0 para salir \n  ";

    cout << "Ingrese una opci¢n a ejecutar:  \n";
    cin >> opcion;

    cout << "Ingrese una opci¢n a ejecutar:  \n";
    cin >> opcion;
  }
}

// Programa que despliega menu de un cajero
void cajero() {
  int opcion;

  do {
    cout << "1: Retirar dinero" << endl;
    cout << "2: Depositar dinero" << endl;
    cout << "0: Salir" << endl;

    cout << "Elige una opci¢n: ";
    cin >> opcion;

    if (opcion == 1) {
      cout << "Retirando dinero...";
    } else if (opcion == 2) {
      cout << "Depositando..." << endl;
    } else if (opcion == 3) {
      cout << "Opcion inv lida." << endl;
    } else {
      cout << "Saliendo del menu." << endl;
    }

  } while (opcion != 0);
}

int main() {
  cout << endl;
  cout << "****** EJEMPLO 1 ******" << endl;
  serie();

  cout << endl;
  cout << "****** EJEMPLO 2 ******" << endl;
  menuDo();

  cout << endl;
  cout << "****** EJEMPLO 3 ******" << endl;
  menuWhile();

  cout << endl;
  cout << "****** EJEMPLO 4 ******" << endl;
  cajero();
  return 0;
}
