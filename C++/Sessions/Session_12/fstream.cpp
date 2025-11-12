//============================================================================
// Name        : fstream.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/11/07
//============================================================================

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

//----------------------------------------
// Funci¢n para escribir  un archivo
//----------------------------------------
void crearArchivo() {
  ofstream archivo("notas.txt");
  cout << "Hola Mundo!" << endl;
  cout << 123 << endl;
  cout << 456 << endl;

  cout << "Archivo creado correctamente.\n";
  archivo.close();
}

//----------------------------------------
// Funci¢n para escribir  un archivo
//----------------------------------------
void crearArchivo2() {
  ofstream archivo("notas2.txt");
  int numeros[3] = {100, 200, 300};

  for (int i = 0; i < 3; i++) {
    archivo << numeros[i] << endl;
  }

  cout << "Archivo creado correctamente.\n";
  archivo.close();
}

//----------------------------------------
// Funci¢n para escribir  un archivo
//----------------------------------------
void crearArchivo3() {
  ofstream archivo("notas3.txt");
  int numeros[3] = {100, 200, 300};

  for (int i = 0; i < 3; i++) {
    archivo << numeros[i] << " " << pow(numeros[i], 2) << endl;
  }

  cout << "Archivo creado correctamente.\n";
  archivo.close();
}

int main() {
  cout << "\n===== EJEMPLO 1 =====\n";
  crearArchivo();

  cout << "\n===== EJEMPLO 2 =====\n";
  crearArchivo2();

  cout << "\n===== EJEMPLO 3 =====\n";
  crearArchivo3();

  return 0;
}
