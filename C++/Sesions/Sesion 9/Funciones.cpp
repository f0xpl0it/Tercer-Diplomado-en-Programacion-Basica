//============================================================================
// Name        : Funciones.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/10/21
//============================================================================

#include <iostream>
using namespace std;

// Funci�n para sumar dos n�meros con par�metros
int suma(int n1, int n2) {  // par�metros
  int n3;                   // Declaramos las variables de entorno
  n3 = n1 + n2;
  return n3;  // Retornamos el valor de la funci�n int
}

int ejemplo(int n) {
  n += 1;
  cout << n << endl;
  return 0;
}

// Funci�n void sin par�metros
void mensaje() { cout << "Hola Mundo!" << endl; }

// Funci�n Principal
int main() {
  cout << "\n===== EJEMPLO 1 FUNCI�N INT =====\n";
  int a, b, c;

  a = 1;
  b = 3;

  c = suma(a, b);
  cout << c << endl;

  cout << "\n===== EJEMPLO 2 FUNCI�N VOID =====\n";
  mensaje();

  cout << "\n===== EJEMPLO 3 FUNCI�N POR PAR�METROS =====\n";
  int n = 2;
  ejemplo(n);         // n par�metro por referencia
  cout << n << endl;  // n variable local

  return 0;
}
