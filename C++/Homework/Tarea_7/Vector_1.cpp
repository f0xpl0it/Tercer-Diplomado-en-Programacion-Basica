//============================================================================
// Name        : Vector_1.cpp
// Author      : Michael Paucar
// Version     : v.3
// Description : Tarea 7 - Vectores ((Ejercicio[1])
//============================================================================

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

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
// Funci¢n para crear el vector
//----------------------------------------
void crearVector(vector<int>& v) {
  int longitud;

  cout << "Ingrese la longitud del vector: ";
  cin >> longitud;
  while (!entradaValida() || longitud <= 0) {
    cout << "Ingrese nuevamente la longitud del vector (> 0): ";
    cin >> longitud;
  }

  v.resize(longitud);  // Guardar longitud nueva del vector

  for (int i = 0; i < longitud; i++) {
    cout << "Ingrese el valor #" << (i + 1) << ": ";
    cin >> v[i];
    while (!entradaValida()) {
      cout << "Ingrese nuevamente el valor #" << (i + 1) << ": ";
      cin >> v[i];
    }
  }

  // Mostrar el vector
  cout << "\nVector creado: < ";
  for (int num : v) cout << num << " ";
  cout << ">\n";
}

//----------------------------------------
// Funci¢n para eliminar un elemento
//----------------------------------------
void eliminarElemento(vector<int>& v) {
  if (v.empty()) {
    cout << "\033[31m\nEl vector est  vac¡o.\033[0m\n";
    return;
  }

  int pos;
  cout << "Ingrese la posici¢n a eliminar (1 - " << v.size() << "): ";
  cin >> pos;
  while (!entradaValida() || pos < 1 || pos > (int)v.size()) {
    cout << "Posici¢n inv lida. Ingrese nuevamente: ";
    cin >> pos;
  }

  v.erase(v.begin() + pos - 1);
  cout << "Elemento eliminado correctamente.\n";

  // Mostrar vector
  cout << "Vector actual: < ";
  for (int num : v) cout << num << " ";
  cout << ">\n";
}

//----------------------------------------
// Funci¢n para sustituir un elemento
//----------------------------------------
void sustituirElemento(vector<int>& v) {
  if (v.empty()) {
    cout << "\033[31m\nEl vector est  vac¡o.\033[0m\n";
    return;
  }

  int pos, nuevoValor;
  cout << "Ingrese la posici¢n a sustituir (1 - " << v.size() << "): ";
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
  cout << "Elemento sustituido correctamente.\n";

  // Mostrar vector
  cout << "Vector actual: < ";
  for (int num : v) cout << num << " ";
  cout << ">\n";
}

//----------------------------------------
// Funci¢n para agregar un elemento
//----------------------------------------
void agregarElemento(vector<int>& v) {
  int valor;
  cout << "Ingrese el nuevo valor a agregar: ";
  cin >> valor;
  while (!entradaValida()) {
    cout << "Ingrese nuevamente el valor: ";
    cin >> valor;
  }

  v.push_back(valor);
  cout << "Elemento agregado correctamente.\n";

  // Mostrar vector
  cout << "Vector actual: < ";
  for (int num : v) cout << num << " ";
  cout << ">\n";
}

//----------------------------------------
// Funci¢n para separar pares e impares
//----------------------------------------
void paresImpares(const vector<int>& v) {
  if (v.empty()) {
    cout << "\033[31m\nEl vector est  vac¡o.\033[0m\n";
    return;
  }

  vector<int> pares, impares;

  for (int num : v) {
    if (num % 2 == 0)
      pares.push_back(num);
    else
      impares.push_back(num);
  }

  cout << "\nVector de pares: < ";
  for (int num : pares) cout << num << " ";
  cout << ">\n";

  cout << "Vector de impares: < ";
  for (int num : impares) cout << num << " ";
  cout << ">\n";
}

//----------------------------------------
// Funci¢n Principal
//----------------------------------------
int main() {
  vector<int> miVector;
  crearVector(miVector);

  int opcion;

  do {
    cout << "\n======  MODIFICAR ELEMENTOS ======\n";
    cout << "[1] Eliminar un n£mero\n";
    cout << "[2] Sustituir un n£mero\n";
    cout << "[3] Agregar un n£mero\n";
    cout << "[4] Separar pares e impares\n";
    cout << "[5] Salir\n";
    cout << "\t>> Seleccione una opci¢n: ";
    cin >> opcion;

    if (!entradaValida()) continue;

    switch (opcion) {
      case 1:
        cout << "\n****** ELIMINAR ELEMENTO ******\n";
        eliminarElemento(miVector);
        cout << endl;
        break;

      case 2:
        cout << "\n****** SUSTITUIR ELEMENTO ******\n";
        sustituirElemento(miVector);
        cout << endl;
        break;

      case 3:
        cout << "\n****** SUSTITUIR ELEMENTO ******\n";
        agregarElemento(miVector);
        cout << endl;
        break;

      case 4:
        cout << "\n****** PARES E IMPARES******\n";
        paresImpares(miVector);
        cout << endl;
        break;

      case 5:
        cout << "\nFin del programa...\n";
        break;

      default:
        cout << "\033[31m\nFuera de rango!!\033[0m\n";
        break;
    }

  } while (opcion != 5);

  return 0;
}
