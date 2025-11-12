//============================================================================
// Name        : fstream2.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 7 - Manipulacion de Datos ((Ejercicio[2])
//============================================================================

#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

//========================================
// EJERCICIO 2 - PROMEDIO NOTAS [IFSTREAM]
//========================================

//----------------------------------------
// Funciones validacion de entrada
//----------------------------------------
void limpiarEntrada() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool entradaValida() {
  if (cin.fail()) {
    cout << "\033[31m\nSolo se permiten n£meros!!\033[0m\n";
    limpiarEntrada();
    return false;
  }
  return true;
}

//----------------------------------------
// Funci¢n para leer un archivo
//----------------------------------------
void abrirArchivo(vector<float>& notas) {
  ifstream archivo("notas.txt");  // Usar la ruta relativa

  // Verificar si el archivo se abre correctamente
  if (!archivo.is_open()) {
    cout << "No se pudo abrir el archivo.\n";
    return;
  }

  float nota;

  cout << "\n****** NOTAS DEL ESTUDIANTE ******\n";
  while (archivo >> nota) {
    notas.push_back(nota);  // Almacenar cada nota en el vector
  }

  archivo.close();
}

//----------------------------------------
// Funci¢n para calcular el promedio
//----------------------------------------
void calcularPromedio(const vector<float>& notas) {
  if (notas.empty()) {
    cout << "No se encontraron notas v lidas.\n";
    return;
  }

  float suma = 0;
  for (float nota : notas) {
    suma += nota;
  }

  float promedio = suma / notas.size();

  cout.precision(4);
  cout << "El promedio de notas es: " << promedio << endl;
}

//----------------------------------------
// Funci¢n para desviaci¢n est ndar
//----------------------------------------
void calcularDesviacionEstandar(const vector<float>& notas) {
  if (notas.empty()) {
    cout << "No se encontraron notas v lidas.\n";
    return;
  }

  float suma = 0, sumaCuadrados = 0;
  for (float nota : notas) {
    suma += nota;
    sumaCuadrados += nota * nota;
  }

  float promedio = suma / notas.size();
  float varianza = (sumaCuadrados / notas.size()) - (pow(promedio, 2));
  float desviacionEstandar = sqrt(varianza);

  cout.precision(4);
  cout << "La desviaci¢n est ndar de las notas es: " << desviacionEstandar
       << endl;
}

//----------------------------------------
// Funci¢n Principal
//----------------------------------------
int main() {
  vector<float> notas;
  abrirArchivo(notas);

  int opcion;

  do {
    cout << "\n======  SISTEMA ESTUDIANTIL ======\n";
    cout << "[1] Reportar el promedio \n";
    cout << "[2] Reportar la desviaci¢n est ndar\n";
    cout << "[3] Salir\n";
    cout << "\t>> Seleccione una opci¢n: ";
    cin >> opcion;

    if (!entradaValida()) continue;

    switch (opcion) {
      case 1:
        cout << "\n****** PROMEDIO NOTAS ******\n";
        calcularPromedio(notas);
        cout << endl;
        break;

      case 2:
        cout << "\n****** DESVIACIàN ESTµNDAR ******\n";
        calcularDesviacionEstandar(notas);
        cout << endl;
        break;

      case 3:
        cout << "\nFin del programa...\n";
        break;

      default:
        cout << "\033[31m\nFuera de rango!!\033[0m\n";
        break;
    }

  } while (opcion != 3);

  return 0;
}
