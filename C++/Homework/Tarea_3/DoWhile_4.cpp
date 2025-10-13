//============================================================================
// Name        : DoWhile_4.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 3 - While (Ejercicio [4])
//============================================================================

#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <iostream>
#include <limits>
using namespace std;

// EJERCICIO 4
// Funci¢n para limpiar errores de entrada
void limpiarEntrada() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Funci¢n para verificar si la entrada fue v lida
bool entradaValida() {
  if (cin.fail()) {
    cout << "\033[31m Solo se permiten n£meros. \n\033[0m";
    limpiarEntrada();
    return false;
  }
  limpiarEntrada();  // Siempre limpiar el buffer
  return true;
}

// Funci¢n para generar el n£mero heredada de C
int generarAleatorio(int min, int max) {
  srand(time(NULL));                              // Semilla basada en tiempo
  int number = (rand() % (max - min + 1)) + min;  // Aleatorio entre min y max
  return number;
}

// Funci¢n para adivinar le n£mero
void adivinarNum() {
  int number, aux = 0;
  int random = generarAleatorio(1, 50);

  cout << "\n##### Adivinar un n£mero entre 1 y 50. ­Adivina cu l es! #####\n";

  do {
    aux++;
    cout << "\nIngrese un n£mero: ";
    cin >> number;

    if (!entradaValida()) continue;

    if (number > random) {
      aux++;
      cout << "Es menor que " << number << "\n";
    } else if (number < random) {
      aux++;
      cout << "Es mayor que " << number << "\n";
    } else {
      cout << "\n>> Adivinaste el n£mero, a los " << aux << " intento(s)!!\n";
    }

  } while (random != number);
}

// Funci¢n Principal
int main() {
  int option;

  cout << endl;
  cout << "********** Ejercicio 4 - N£mero Aleatorio [Do..While] **********"
       << endl;
  do {
    cout << "\n[1] Adivinar un n£mero\n";
    cout << "[2] Salir\n";
    cout << "\t Ingrese una opci¢n: ";
    cin >> option;

    if (!entradaValida()) continue;  // Validar entradas

    if (option != 1 && option != 2) {
      cout << "\033[31m Opci¢n inv lida!! \033[0m\n";
    } else if (option == 2) {
      cout << "Fin del Programa.\n";
    } else {
      adivinarNum();
    }
  } while (option != 2);
  return 0;
}
