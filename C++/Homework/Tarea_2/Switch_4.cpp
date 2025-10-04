//============================================================================
// Name        : Switch_4.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Uso de Switch (Ejercicio [4])
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

// EJERCICIO 4
// Convertir temperatura

// Conversor Celsius
void celcius() {
  float temp, fharenheit, kelvin, rankine;

  // Solicitar al usuario ingrese un valor
  cout << "Ingrese la temperatura [øC]: ";
  cin >> temp;

  // C lculos
  fharenheit = (temp * 9 / 5) + 32;
  kelvin = temp + 273.15;
  rankine = kelvin * 9 / 5;

  // Imprimir salida
  cout << temp << "øC --> " << fharenheit << "øF" << endl;
  cout << temp << "øC --> " << kelvin << "K" << endl;
  cout << temp << "øC --> " << rankine << "øR" << endl;
}

// Conversor Fharenheit
void fharenheit() {
  float temp, celcius, kelvin, rankine;

  // Solicitar al usuario ingrese un valor
  cout << "Ingrese la temperatura [øF]: ";
  cin >> temp;

  // C lculos
  celcius = (temp - 32) * 5 / 9;
  kelvin = celcius + 273.15;
  rankine = kelvin * 9 / 5;

  // Imprimir salida
  cout << temp << "øF --> " << celcius << "øC" << endl;
  cout << temp << "øF --> " << kelvin << "K" << endl;
  cout << temp << "øF --> " << rankine << "øR" << endl;
}

// Conversor Kelvin
void kelvin() {
  float temp, celcius, fharenheit, rankine;

  // Solicitar al usuario ingrese un valor
  cout << "Ingrese la temperatura [K]: ";
  cin >> temp;

  // C lculos
  celcius = temp - 273.15;
  fharenheit = (celcius * 9 / 5) + 32;
  rankine = temp * 9 / 5;

  // Imprimir salida
  cout << temp << "K --> " << celcius << "øC" << endl;
  cout << temp << "K --> " << fharenheit << "øF" << endl;
  cout << temp << "K --> " << rankine << "øR" << endl;
}

// Conversor Rankine
void rankine() {
  float temp, celcius, fharenheit, kelvin;

  cout << "Ingrese la temperatura [øR]: ";
  cin >> temp;

  // C lculos
  celcius = (temp - 491.67) * 5 / 9;
  fharenheit = temp - 459.67;
  kelvin = temp * 5 / 9;

  // Imprimir salida
  cout << temp << "øR --> " << celcius << "øC" << endl;
  cout << temp << "øR --> " << fharenheit << "øF" << endl;
  cout << temp << "øR --> " << kelvin << "K" << endl;
}

// Funci¢n principal
void conversor() {
  int option;

  // Solicitar al usuario ingrese una opci¢n
  cout << "[1] Convertir øC a øF, K, øR" << endl;
  cout << "[2] Convertir øF a øC, K, øR" << endl;
  cout << "[3] Convertir K a øC, øF, øR" << endl;
  cout << "[4] Convertir øR a øC, øF, K" << endl;
  cout << "\t >> Seleccione una opci¢n: ";
  cin >> option;

  // Ingresar a los casos
  switch (option) {
    // Celcius
    case 1:
      cout << endl;
      cout << "**** CELCIUS ****" << endl;

      // LLamada de funci¢n
      celcius();
      break;

      // Fharenheit
    case 2:
      cout << endl;
      cout << "**** FHARENHEIT ****" << endl;

      // LLamada de funci¢n
      fharenheit();
      break;

      // Kelvin
    case 3:
      cout << endl;
      cout << "**** KELVIN ****" << endl;

      // LLamada de funci¢n
      kelvin();

      break;

      // Rankine
    case 4:
      cout << endl;
      cout << "**** RANKINE ****" << endl;

      // LLamada de funci¢n
      rankine();

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

  cout << "Ejercicio 4 - Convertir temperatura" << endl;
  conversor();

  return 0;
}
