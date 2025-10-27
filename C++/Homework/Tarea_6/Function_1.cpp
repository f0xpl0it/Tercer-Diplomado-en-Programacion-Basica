//============================================================================
// Name        : Function_1.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 6 - Funciones (Ejercicio [1])
//============================================================================

#include <String>
#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 1

#include <iostream>
#include <limits>
using namespace std;

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
  return true;
}

// Funci¢n para invertir un n£mero entero while e integer
int revertirNumero(int numero) {
  int numeroInvertido = 0;

  while (numero != 0) {
    int digito = numero % 10;  // Obtiene el £ltimo d¡gito
    numeroInvertido =
        numeroInvertido * 10 + digito;  // Lo agrega al n£mero invertido
    numero /= 10;                       // Elimina el £ltimo d¡gito del original
  }

  return numeroInvertido;
}

// Funci¢n para invertir n£mero con for y string (Segunda forma)
void revertirNumero2() {
  string numero;
  cout << "Ingrese un n£mero: ";
  cin >> numero;

  // Invertir la cadena (n£mero como string)
  string numeroInvertido = "";
  for (int i = numero.length() - 1; i >= 0; i--) {
    numeroInvertido += numero[i];  // Concatenamos los caracteres
  }
  cout << "\t>> N£mero ingresado: " << numero << endl;
  cout << "\t>> N£mero revertido: " << numeroInvertido << endl;
}

// Funci¢n principal
int main() {
  cout << "\n======== EJERCICIO 1 - REVERTIR NéMERO (WHILE-INT)========\n";

  int numero;
  cout << "Ingrese un n£mero: ";
  cin >> numero;

  // Validar la entrada
  while (!entradaValida()) {
    cout << "\nIngrese un n£mero entero: ";
    cin >> numero;
  }

  int resultado = revertirNumero(numero);
  cout << "\t>> N£mero ingresado: " << numero << endl;
  cout << "\t>> N£mero invertido: " << resultado << endl;

  cout << "\n======== EJERCICIO 1 - REVERTIR NéMERO (FOR-STRING) ========\n";
  revertirNumero2();

  return 0;
}