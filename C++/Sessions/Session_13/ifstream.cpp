//============================================================================
// Name        : ifstream.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/11/11
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

//----------------------------------------
// Funci¢n para leer un archivo
//----------------------------------------
void abrirArchivo() {
  ifstream archivo("../datos_ejemplo.txt");  // Usar la ruta relativa

  // Verificar si el archivo se abre correctamente
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo.\n";
    return;  // Salir de la funci¢n si no se puede abrir el archivo
  }

  int numeros1;
  while (archivo >> numeros1) {
    cout << numeros1 << endl;
  }

  archivo.close();
}

//----------------------------------------
// Funci¢n para leer un archivo
//----------------------------------------
void abrirArchivo2() {
  ifstream archivo("../datos_ejemplo2.txt");

  // Verificar si el archivo se abre correctamente
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo.\n";
    return;  // Salir de la funci¢n si no se puede abrir el archivo
  }

  int numeros1, numeros2;
  while (archivo >> numeros1 >> numeros2) {
    cout << numeros1 << " " << numeros2 << endl;
  }

  archivo.close();
}

//----------------------------------------
// Funci¢n para leer un archivo
//----------------------------------------
void abrirArchivo3() {
  ifstream archivo("../datos_ejemplo.txt");

  // Verificar si el archivo se abre correctamente
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo.\n";
    return;  // Salir de la funci¢n si no se puede abrir el archivo
  }

  // Crear un vector del archivo y alamcenarlosen el vector
  vector<int> numeros;

  int indice;

  while (archivo >> indice) {
    numeros.push_back(indice);
  }
  // Cerrar el archivo
  archivo.close();

  // Mostrar los datos en la slaida estandar
  cout << "Los datos leidos del archivo son: ";
  for (int dato : numeros) {
    cout << dato << " ";
  }
  cout << endl;
}

//----------------------------------------
// Funci¢n Principal
//----------------------------------------
int main() {
  cout << "\n===== EJEMPLO 1 =====\n";
  abrirArchivo();

  cout << "\n===== EJEMPLO 2 =====\n";
  abrirArchivo2();

  cout << "\n===== EJEMPLO 3 =====\n";
  abrirArchivo3();
  return 0;
}
