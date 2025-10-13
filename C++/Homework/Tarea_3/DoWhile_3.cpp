//============================================================================
// Name        : DoWhile_3.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 3 - While (Ejercicio [3])
//============================================================================

#include <iostream>
#include <limits>  // para limpiar el buffer de entrada
#include <string>
using namespace std;

// EJERCICIO 3
// Variables globales m¡nimas
double saldo = 1000.0;

// Funci¢n para validar contrase¤a
bool credenciales() {
  string passwordCorrecta = "1234";
  string passwordIngresada;
  int intentos = 0;

  while (intentos < 3) {
    cout << "Ingrese su contrase¤a: ";
    cin >> passwordIngresada;

    if (passwordIngresada == passwordCorrecta) {
      cout << "Acceso concedido.\n";
      return true;
    } else {
      intentos++;
      cout << "\nContrase¤a incorrecta. Intento " << intentos << " de 3.\n";
    }
  }

  cout << "\033[31m Cuenta bloqueada. Demasiados intentos.\n \033[0m";
  return false;
}

// Funci¢n para validar n£mero
void limpiarEntrada() {
  cin.clear();  // Limpia error
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n');  // Descarta entrada inv lida
}

// Funci¢n para consultar saldo
void consultarSaldo() { cout << "\n>> Su saldo actual es: $" << saldo << endl; }

// Funci¢n para depositar dinero
void depositarDinero() {
  double deposito;
  cout << "Ingrese la cantidad a depositar: $";
  cin >> deposito;

  if (cin.fail()) {
    limpiarEntrada();
    cout << "Solo se aceptan n£meros." << endl;
    return;
  }

  if (deposito > 0) {
    saldo += deposito;
    cout << "\n>> Dep¢sito exitoso. Nuevo saldo: $" << saldo << endl;
  } else {
    cout << "\n>> Monto inv lido. Debe ser mayor a 0." << endl;
  }
}

// Funci¢n para retirar dinero
void retirarDinero() {
  double retiro;
  cout << "\nIngrese la cantidad a retirar: $";
  cin >> retiro;

  if (cin.fail()) {
    limpiarEntrada();
    cout << "Solo se aceptan n£meros." << endl;
    return;
  }

  if (retiro > 0 && retiro <= saldo) {
    saldo -= retiro;
    cout << ">> Retiro exitoso. Nuevo saldo: $" << saldo << endl;
  } else {
    cout << ">> Retiro inv lido. Fondos insuficientes o cantidad no v lida."
         << endl;
  }
}

// Men£ principal
void menuBancario() {
  int opcion;

  do {
    cout << "\n##### MENé BANCO #####\n";
    cout << "[1] Consultar saldo\n";
    cout << "[2] Depositar dinero\n";
    cout << "[3] Retirar dinero\n";
    cout << "[4] Salir\n";
    cout << "\tSeleccione una opci¢n: ";
    cin >> opcion;

    if (cin.fail()) {
      limpiarEntrada();
      cout << "\033[31m Solo se aceptan n£meros!!! \033[0m" << endl;
      continue;
    }

    switch (opcion) {
      case 1:
        consultarSaldo();
        break;
      case 2:
        depositarDinero();
        break;
      case 3:
        retirarDinero();
        break;
      case 4:
        cout << "Gracias por usar el sistema bancario.\n";
        break;
      default:
        cout << "\033[31m  Opci¢n no v lida. Intente de nuevo!!!\n \033[0m";
    }
  } while (opcion != 4);
}

// Funci¢n principal
int main() {
  cout << endl;
  cout << "********** Ejercicio 3 - Banca Virutal [Do..While] **********"
       << endl;

  if (credenciales()) {
    menuBancario();
  }

  return 0;
}