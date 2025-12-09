//============================================================================
// Name : objetos_4.cpp
// Author : Michael Paucar
// Version : v.1
// Description : 2025/12/09 - Programa que usa la clase Rectangulo
//============================================================================

#include <iostream>

#include "rectangulo.h"  // Se incluye el archivo de cabecera (header) de la clase Rectangulo
using namespace std;

int main() {
  // Se crea un objeto r1 de la clase Rectangulo con el constructor por defecto
  // El constructor por defecto inicializa el rectangulo con 1 de largo y 1 de
  // ancho
  Rectangulo r1;  // usa valores por defecto (1,1)

  // Se crea un objeto r2 de la clase Rectangulo con el constructor que toma dos
  // parametros Este rectangulo tiene largo 2 y ancho 6
  Rectangulo r2(2, 6);  // usa el constructor con parametros

  // Se imprime la informacion de r1
  r1.imprimir();
  // Se calcula e imprime el  rea de r1
  cout << "Area r1 = " << r1.area() << endl;
  // Se calcula e imprime el per¡metro de r1
  cout << "Perimetro r1 = " << r1.perimetro() << endl;

  cout << endl;  // L¡nea en blanco para separar las impresiones

  // Se imprime la informaci¢n de r2
  r2.imprimir();
  // Se calcula e imprime el  rea de r2
  cout << "Area r2 = " << r2.area() << endl;
  // Se calcula e imprime el per¡metro de r2
  cout << "Perimetro r2 = " << r2.perimetro() << endl;

  return 0;  // Fin del programa
}
