//============================================================================
// Name : objetos_1.cpp
// Author : Michael Paucar
// Version : v.1
// Description : 2025/12/09
//============================================================================

#include <iostream>
using namespace std;

// ===============================================
// Clase OperacionAritmetica
// Representa una operacion con dos numeros (a y b)
// y permite realizar operaciones basicas usando metodos.
// ===============================================
class OperacionAritmetica {
 private:
  // Atributos privados: solo la clase puede acceder a ellos
  double a;
  double b;

 public:
  // -----------------------------------------------
  // Constructor por defecto: inicializa a y b en 0.
  // Se usa cuando no se pasan parametros al crear el objeto.
  // Ejemplo: OperacionAritmetica op;
  // -----------------------------------------------
  OperacionAritmetica() {
    a = 0;
    b = 0;
  }

  // -----------------------------------------------
  // Constructor con parametros: permite crear un objeto
  // con valores especificos para 'a' y 'b'.
  // Ejemplo: OperacionAritmetica op(5, 10);
  // -----------------------------------------------
  OperacionAritmetica(double x, double y) {
    a = x;
    b = y;
  }

  // -----------------------------------------------
  // Metodos de operaciones aritmeticas basicas.
  // Cada metodo usa los valores 'a' y 'b' almacenados
  // en el objeto para devolver el resultado.
  // -----------------------------------------------

  // Suma los valores a + b
  double sumar() { return a + b; }

  // Resta los valores a - b
  double restar() { return a - b; }

  // Multiplica los valores a * b
  double multiplicar() { return a * b; }

  // Divide los valores a / b
  // Incluye una validacion para evitar dividir entre 0
  double dividir() {
    if (b == 0) {  // Evita division entre cero
      cout << "Error: division entre cero." << endl;
      return 0;  // Retorna 0 como valor por defecto
    }
    return a / b;
  }

  // -----------------------------------------------
  // Metodo para imprimir los valores actuales de a y b
  // Util para verificar que datos contiene el objeto.
  // -----------------------------------------------
  void imprimir() { cout << "a = " << a << ", b = " << b << endl; }
};

// ===============================================
// Programa principal (main)
// Aqui se crean objetos de la clase y se usan.
// ===============================================
int main() {
  // op1 usa el constructor por defecto -> a = 0, b = 0
  OperacionAritmetica op1;

  // op2 usa el constructor con parametros -> a = 2, b = 3
  OperacionAritmetica op2(2, 3);

  // Otro objeto con valores diferentes
  OperacionAritmetica op3(3, 7);

  cout << "Valores de op1: " << endl;
  op1.imprimir();  // Muestra los valores de op1

  cout << "Valores de op2: " << endl;
  op2.imprimir();  // Muestra los valores de op2

  // Se muestran resultados de operaciones usando op2
  cout << "Operaciones con op2:" << endl;
  cout << "Suma: " << op2.sumar() << endl;
  cout << "Resta: " << op2.restar() << endl;
  cout << "Multiplicacion: " << op2.multiplicar() << endl;
  cout << "Division: " << op2.dividir() << endl;

  return 0;  // Fin del programa
}
