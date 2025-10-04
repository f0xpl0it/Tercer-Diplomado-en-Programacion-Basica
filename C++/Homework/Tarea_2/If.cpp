//============================================================================
// Name        : If.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 2 - Uso de if-elseif-else
//============================================================================

#include <iostream>
using namespace std;

// EJERCICIO 1
//  Clasificacion de calificaciones

void clasificarNotas() {
  int rating;

  // Solicitar al usuario la calificaci¢n
  cout << "Ingrese la calificaci¢n: ";
  cin >> rating;

  // Verificar la calificaci¢n rango [90-100]
  if (rating >= 90 && rating <= 100) {
    cout << "Excelente" << endl;
    // Verificar la calificaci¢n rango [70-89]
  } else if (rating >= 70 && rating <= 89) {
    cout << "Notable" << endl;
    // Verificar la calificaci¢n rango [60-69]
  } else if (rating >= 60 && rating <= 69) {
    cout << "Suficiente" << endl;
    // Verificar la calificaci¢n rango [0-59)
  } else if (rating >= 0 && rating < 60) {
    cout << "Insuficiente" << endl;
  } else {
    // Verificar la calificaci¢n fuera de rango (negativos y mayores a 100)
    cout << "Calificaci¢n fuera de rango!!" << endl;
  }
  cout << endl;
}

//  EJERCICIO 2
//  A¤o Biciesto
//  Si un a¤o es divisible por 400, es bisiesto.
//  Si no es divisible por 400, pero s¡ por 100, no es bisiesto.
//  Si no es divisible por 100, pero s¡ por 4, es bisiesto.
//  Si no cumple con ninguna de las condiciones anteriores, no es bisiesto.

void leapYear() {
  int year;

  // Solicitar al usuario el a¤o
  cout << "Ingrese un a¤o: ";
  cin >> year;

  // Verificar si el a¤o es bisiesto
  if (year % 400 == 0) {
    // Si es divisible por 400, es bisiesto
    cout << year << " es un a¤o bisiesto." << endl;
  } else if (year % 100 == 0) {
    // Si es divisible por 100 pero no por 400, no es bisiesto
    cout << year << " no es un a¤o bisiesto." << endl;
  } else if (year % 4 == 0) {
    // Si es divisible por 4 pero no por 100, es bisiesto
    cout << year << " es un a¤o bisiesto." << endl;
  } else {
    // Si no es divisible ni por 4, 100, ni 400, no es bisiesto
    cout << year << " no es un a¤o bisiesto." << endl;
  }
  cout << endl;
}

// EJERCICIO 3
// Numero mayo de tres

void contarValor() {
  int a, b, c, aux = 0;  // Para contar los n£meros mayores que 3

  // Ingreso de n£meros por el usuario
  cout << "Ingrese un n£mero [1]: ";
  cin >> a;
  cout << "Ingrese un n£mero [2]: ";
  cin >> b;
  cout << "Ingrese un n£mero [3]: ";
  cin >> c;

  // Contamos cu ntos n£meros son mayores que 3
  if (a > 3) {
    aux++;
  }
  if (b > 3) {
    aux++;
  }
  if (c > 3) {
    aux++;
  }

  // Imprimir cu ntos n£meros son mayores que 3
  cout << "Se ingres¢ " << aux << " n£meros mayores que 3." << endl;
}

int main() {
  cout << "****** Uso de if-elseif-else ******" << endl;
  cout << endl;

  cout << "Ejercicio 1 - Calificaciones" << endl;
  clasificarNotas();

  cout << "Ejercicio 2 - A¤o biciesto" << endl;
  leapYear();

  cout << "Ejercicio 3 - N£mero mayor a tres" << endl;
  contarValor();

  return 0;
}
