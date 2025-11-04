//============================================================================
// Name        : Vectores.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : 2025/11/04
//============================================================================

#include <iostream>
#include <vector>  // Libreria para vector
using namespace std;

// Declarar vector por default
void vector1() {
  /* P
  alabra reservada "vector"
  tipo de dato> entre "<>"
  valor entre par‚ntesis "()"
  */
  int n = 3;
  vector<int> numeros(n);

  for (int i = 0; i < n; i++) {
    cout << numeros[i] << endl;  // Por default llena el vector con 0
  }
}

// Declarar vector inicializado en 1
void vector2() {
  int n = 3;
  vector<int> numeros(n, 1);

  for (int i = 0; i < n; i++) {
    cout << numeros[i] << endl;
  }
}

// Declarar vector inicializado en 5
void vector3() {
  int n = 3;
  vector<int> numeros(n, 5);

  for (int i = 0; i < n; i++) {
    cout << numeros[i] << endl;
  }
}

// Longitud del vector
void longitudVector() {
  int n = 3;
  vector<int> numeros(n, 5);

  cout << "Vector: < ";
  for (int i = 0; i < n; i++) {
    cout << numeros[i] << " ";
  }
  cout << ">\n";
  cout << "La longitud del vector es: " << numeros.size() << endl;
}

// Crear un vector reutilizable para las demas funciones
void mostrarVector(const vector<int>& v) {
  cout << "Vector actual: < ";
  for (int num : v) cout << num << " ";
  cout << ">" << endl;
}

// Agregar un elemento al final del vector
void agregarElemento(vector<int>& numeros, int valor) {
  numeros.push_back(valor);
  mostrarVector(numeros);
  cout << "Se agreg¢ el elemento " << valor << " al final" << endl;
}

// Eliminar el £ltimo elemento del vector
void eliminarElemento(vector<int>& numeros) {
  if (!numeros.empty()) {
    numeros.pop_back();
    cout << "Se elimin¢ el £ltimo elemento del vector" << endl;
  } else {
    cout << "El vector est  vac¡o, no hay nada que eliminar" << endl;
  }
  mostrarVector(numeros);
}

// Insertar elemento en posici¢n n
void insertarPosicion(vector<int>& numeros, size_t pos, int valor) {
  if (pos <= numeros.size()) {  // pos >= 0 && pos < numeros.size(); si
                                // declaramos como int
    numeros.insert(numeros.begin() + pos, valor);
    cout << "Se insert¢ el valor " << valor << " en la posici¢n " << pos
         << endl;
  } else {
    cout << "Posici¢n inv lida." << endl;
  }
  mostrarVector(numeros);
}

// Eliminar elemento en posici¢n n
void eliminarPosicion(vector<int>& numeros, size_t pos) {
  if (pos < numeros.size()) {  // pos >= 0 && pos < numeros.size(); si
                               // declaramos como int
    numeros.erase(numeros.begin() + pos);
    cout << "Se elimin¢ el elemento en la posici¢n " << pos << endl;
  } else {
    cout << "Posici¢n inv lida!!" << endl;
  }
  mostrarVector(numeros);
}

// Funci¢n Principal
int main() {
  cout << "\n===== EJEMPLO 1 - INICIALIZA VECTOR CON 0 =====\n";
  vector1();

  cout << "\n===== EJEMPLO 2 - INICIALIZA VECTOR CON 1 =====\n";
  vector2();

  cout << "\n===== EJEMPLO 3 - INICIALIZA VECTOR CON 5 =====\n";
  vector3();

  cout << "\n===== EJEMPLO 4 - LONGITUD DEL VECTOR =====\n";
  longitudVector();

  cout << "\n===== EJEMPLO - OPERACIONES CON VECTOR =====\n";

  // Crear vector base para los siguientes ejemplos
  vector<int> v = {5, 5, 5};
  cout << "Vector original: < ";
  for (size_t i = 0; i < v.size();
       i++) {  // size_t sirve sin signo, int = i tiene signo
    cout << v[i] << " ";
  }
  cout << ">" << endl;

  cout << "\n===== EJEMPLO 5 - AGREGA ELEMENTO AL FINAL=====\n";
  agregarElemento(v, 3);  // agrega un elemento al £ltimo del vector

  cout << "\n===== EJEMPLO 6 - ELIMINA ELEMENTO FINAL DEL VECTOR =====\n";
  eliminarElemento(v);  // elimina el £ltimo elemento del vector

  cout << "\n===== EJEMPLO 7 - INSERTAR ELEMENTO AL VECTOR =====\n";
  insertarPosicion(v, 1, 9);  // inserta elemento en [n] posici¢n

  cout << "\n===== EJEMPLO 8 - ELIMINAR ELEMENTO AL VECTOR =====\n";
  eliminarPosicion(v, 0);  // inserta elemento en [n] posici¢n

  return 0;
}
