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
  cout << "Ingrese la temperatura [�C]: ";
  cin >> temp;

  // C�lculos
  fharenheit = (temp * 9 / 5) + 32;
  kelvin = temp + 273.15;
  rankine = kelvin * 9 / 5;

  // Imprimir salida
  cout << temp << "�C --> " << fharenheit << "�F" << endl;
  cout << temp << "�C --> " << kelvin << "K" << endl;
  cout << temp << "�C --> " << rankine << "�R" << endl;
}

// Conversor Fharenheit
void fharenheit() {
  float temp, celcius, kelvin, rankine;

  // Solicitar al usuario ingrese un valor
  cout << "Ingrese la temperatura [�F]: ";
  cin >> temp;

  // C�lculos
  celcius = (temp - 32) * 5 / 9;
  kelvin = celcius + 273.15;
  rankine = kelvin * 9 / 5;

  // Imprimir salida
  cout << temp << "�F --> " << celcius << "�C" << endl;
  cout << temp << "�F --> " << kelvin << "K" << endl;
  cout << temp << "�F --> " << rankine << "�R" << endl;
}

// Conversor Kelvin
void kelvin() {
  float temp, celcius, fharenheit, rankine;

  // Solicitar al usuario ingrese un valor
  cout << "Ingrese la temperatura [K]: ";
  cin >> temp;

  // C�lculos
  celcius = temp - 273.15;
  fharenheit = (celcius * 9 / 5) + 32;
  rankine = temp * 9 / 5;

  // Imprimir salida
  cout << temp << "K --> " << celcius << "�C" << endl;
  cout << temp << "K --> " << fharenheit << "�F" << endl;
  cout << temp << "K --> " << rankine << "�R" << endl;
}

// Conversor Rankine
void rankine() {
  float temp, celcius, fharenheit, kelvin;

  cout << "Ingrese la temperatura [�R]: ";
  cin >> temp;

  // C�lculos
  celcius = (temp - 491.67) * 5 / 9;
  fharenheit = temp - 459.67;
  kelvin = temp * 5 / 9;

  // Imprimir salida
  cout << temp << "�R --> " << celcius << "�C" << endl;
  cout << temp << "�R --> " << fharenheit << "�F" << endl;
  cout << temp << "�R --> " << kelvin << "K" << endl;
}

// Funci�n principal
void conversor() {
  int option;

  // Solicitar al usuario ingrese una opci�n
  cout << "[1] Convertir �C a �F, K, �R" << endl;
  cout << "[2] Convertir �F a �C, K, �R" << endl;
  cout << "[3] Convertir K a �C, �F, �R" << endl;
  cout << "[4] Convertir �R a �C, �F, K" << endl;
  cout << "\t >> Seleccione una opci�n: ";
  cin >> option;

  // Ingresar a los casos
  switch (option) {
    // Celcius
    case 1:
      cout << endl;
      cout << "**** CELCIUS ****" << endl;

      // LLamada de funci�n
      celcius();
      break;

      // Fharenheit
    case 2:
      cout << endl;
      cout << "**** FHARENHEIT ****" << endl;

      // LLamada de funci�n
      fharenheit();
      break;

      // Kelvin
    case 3:
      cout << endl;
      cout << "**** KELVIN ****" << endl;

      // LLamada de funci�n
      kelvin();

      break;

      // Rankine
    case 4:
      cout << endl;
      cout << "**** RANKINE ****" << endl;

      // LLamada de funci�n
      rankine();

      break;

    default:
      cout << endl;
      cout << "Opci�n incorrecta!!" << endl;
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
