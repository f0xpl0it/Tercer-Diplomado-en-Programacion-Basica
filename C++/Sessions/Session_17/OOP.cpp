//============================================================================
// Name        : OOP.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/15/05 - Programa que implementa una clase Punto con OOP
//============================================================================

#include <iostream>
using namespace std;

class Punto {
 private:
  int x;  // Coordenada x del punto
  int y;  // Coordenada y del punto

 public:
  // Constructor sin parametros: inicializa el punto en (0, 0)
  Punto() {
    x = 0;
    y = 0;
  }

  // Constructor con parametros: inicializa el punto con las coordenadas dadas
  Punto(int x0, int y0) {
    x = x0;
    y = y0;
  }

  // Metodo para mover el punto: agrega dx a x y dy a y
  void mover(int dx, int dy) {
    x += dx;
    y += dy;
  }

  // Metodo para imprimir las coordenadas del punto en formato (x, y)
  void imprimir() { cout << "(" << x << ", " << y << ")" << endl; }
};

int main() {
  // Se crea el objeto p1 usando el constructor sin parametros (por defecto ->
  // (0, 0))
  Punto p1;

  // Se crea el objeto p2 usando el constructor con parametros (inicializado en
  // (3, 4))
  Punto p2(3, 4);

  // Se imprime el punto p1
  cout << "Punto p1: ";
  p1.imprimir();

  // Se imprime el punto p2
  cout << "Punto p2: ";
  p2.imprimir();

  // Se mueve el punto p1: 2 unidades en x y 3 unidades en y (nuevo punto (2,
  // 3))
  p1.mover(2, 3);
  cout << "p1 despues de moverlo: ";
  p1.imprimir();

  // Se mueve el punto p2: 1 unidad en x y 1 unidad en y (nuevo punto (4, 5))
  p2.mover(1, 1);
  cout << "p2 despues de moverlo: ";
  p2.imprimir();

  return 0;
}
