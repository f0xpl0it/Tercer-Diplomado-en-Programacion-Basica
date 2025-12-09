//============================================================================
// Name : rectangulo.cpp
// Author : Michael Paucar
// Version : v.1
// Description : 2025/12/09 - Programa que implementa la clase Rectangulo
//============================================================================

#include "rectangulo.h"  // Incluye el archivo de cabecera de la clase Rectangulo

#include <iostream>

using namespace std;

// Constructor sin parametros: inicializa el rectangulo con ancho y alto en 1
Rectangulo::Rectangulo() {
  ancho = 1;  // Valor por defecto para ancho
  alto = 1;   // Valor por defecto para alto
}

// Aqu¡ usamos el operador :: para indicar que estos m‚todos pertenecen a la
// clase Rectangulo

// Constructor con parametros: inicializa el rectangulo con los valores dados
// para ancho y alto
Rectangulo::Rectangulo(double a, double b) {
  ancho = a;  // Inicializa ancho con el valor de 'a'
  alto = b;   // Inicializa alto con el valor de 'b'
}

// Metodo para calcular el area del rectangulo: area = ancho * alto
double Rectangulo::area() { return ancho * alto; }

// Metodo para calcular el perimetro del rectangulo: perimetro = 2 * (ancho +
// alto)
double Rectangulo::perimetro() { return 2 * ancho + 2 * alto; }

// Metodo para imprimir las dimensiones del rectangulo
// Muestra el rectangulo en formato: "Rectangulo ancho x alto"
void Rectangulo::imprimir() {
  cout << "Rectangulo " << ancho << " x " << alto << endl;
}
