//============================================================================
// Name        : fstream1.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Tarea 7 - Manipulacion de Datos ((Ejercicio[1])
//============================================================================

#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

//========================================
// EJERCICIO 1 -  INGRESO NOTAS [ofstream]
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
// Funci¢n para crear el vector con notas
//----------------------------------------
void crearVector(vector<float>& v) {
  int longitud;

  cout << "Ingrese el n£mero de notas: ";
  cin >> longitud;
  while (!entradaValida() || longitud <= 0) {
    cout << "Ingrese nuevamente el n£mero de notas (> 0): ";
    cin >> longitud;
  }

  v.resize(longitud);  // Guardar longitud nueva del vector

  for (int i = 0; i < longitud; i++) {
    cout << "Ingrese nota #" << (i + 1) << ": ";
    cin >> v[i];
    while (!entradaValida()) {
      cout << "Ingrese nuevamente la nota #" << (i + 1) << ": ";
      cin >> v[i];
    }
  }

  // Mostrar el vector
  cout << "\nReporte creado: [ ";
  for (float num : v) cout << num << " ";
  cout << "]\n";
}

//----------------------------------------
// Funci¢n para sustituir un elemento
//----------------------------------------
void sustituirElemento(vector<float>& v) {
  if (v.empty()) {
    cout << "\033[31m\nEl vector est  vac¡o.\033[0m\n";
    return;
  }

  int pos;
  float nuevoValor;

  cout << "Ingrese la posici¢n de la nota a sustituir (1 - " << v.size()
       << "): ";
  cin >> pos;
  while (!entradaValida() || pos < 1 || pos > (int)v.size()) {
    cout << "Posici¢n inv lida. Ingrese nuevamente: ";
    cin >> pos;
  }

  cout << "Ingrese el nuevo valor: ";
  cin >> nuevoValor;
  while (!entradaValida()) {
    cout << "Ingrese nuevamente el nuevo valor: ";
    cin >> nuevoValor;
  }

  v[pos - 1] = nuevoValor;
  cout << "Nota sustituida correctamente.\n";

  // Mostrar vector
  cout << "Reporte actual: [ ";
  for (float num : v) cout << num << " ";
  cout << "]\n";
}

//----------------------------------------
// Funci¢n para crear archivo
//----------------------------------------
void crearArchivo(vector<float>& v) {
  ofstream archivo("notas.txt");
  for (float nota : v) {
    archivo << nota << endl;
  }

  cout << "Archivo creado correctamente.\n";
  archivo.close();
}

//----------------------------------------
// Funci¢n Principal
//----------------------------------------
int main() {
  vector<float> notas;
  crearVector(notas);
  int opcion;

  do {
    cout << "\n======  SISTEMA ESTUDIANTIL ======\n";
    cout << "[1] Ingresar notas\n";
    cout << "[2] Corregir nota\n";
    cout << "[3] Generar Reporte\n";
    cout << "[4] Salir\n";
    cout << "\t>> Seleccione una opci¢n: ";
    cin >> opcion;

    if (!entradaValida()) continue;

    switch (opcion) {
      case 1:
        cout << "\n****** INGRESAR NOTAS DEL ESTUDIANTE ******\n";
        crearVector(notas);
        cout << endl;
        break;

      case 2:
        cout << "\n****** CORREGIR NOTA DEL ESTUDIANTE ******\n";
        sustituirElemento(notas);
        cout << endl;
        break;

      case 3:
        cout << "\n****** GENERAR REPORTE ******\n";
        crearArchivo(notas);
        cout << endl;
        break;

      case 4:
        cout << "\nFin del programa...\n";
        break;

      default:
        cout << "\033[31m\nFuera de rango!!\033[0m\n";
        break;
    }

  } while (opcion != 4);

  return 0;
}
