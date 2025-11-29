//============================================================================
// Name : numeric.cpp
// Author : Michael Paucar
// Version : v.2 (modular version)
// Description : 2025/11/25 - Gaussian Quadrature (Gauss-Legendre)
//============================================================================

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Tolerancia para la convergencia del m‚todo de Newton-Raphson
#define EPS 3.6e-11

// N£mero m ximo de puntos para la cuadratura de Gauss-Legendre
const int NMAX = 20;

// ------------------------------------------------------------
// Calcula el polinomio de Legendre P_n(x) y su derivada P'_n(x)
// usando relaciones de recurrencia
// ------------------------------------------------------------
void legendrePolynomialAndDerivative(double x, int n, double& Pn, double& dPn) {
  double p0 = 1.0;  // P0(x)
  double p1 = x;    // P1(x)

  // Casos base
  if (n == 0) {
    Pn = p0;
    dPn = 0.0;
    return;
  }
  if (n == 1) {
    Pn = p1;
    dPn = 1.0;
    return;
  }

  // Recurrencia para n >= 2
  double p2;
  for (int k = 2; k <= n; k++) {
    p2 = ((2.0 * k - 1.0) * x * p1 - (k - 1.0) * p0) / k;
    p0 = p1;
    p1 = p2;
  }

  Pn = p1;

  // Derivada del polinomio de Legendre
  dPn = n * (x * p1 - p0) / (x * x - 1.0);
}

// ------------------------------------------------------------
// Calcula los nodos y pesos de Gauss-Legendre en el intervalo [a, b]
// usando iteraci¢n de Newton-Raphson para encontrar ra¡ces de P_n(x)
// ------------------------------------------------------------
void gaussLegendreNodesWeights(double a, double b, double x[], double w[],
                               int n) {
  int m = (n + 1) /
          2;  // Solo necesitamos calcular la mitad de los nodos por simetr¡a
  double xm = 0.5 * (a + b);  // Punto medio del intervalo
  double xl = 0.5 * (b - a);  // Semi-longitud del intervalo

  for (int i = 0; i < m; i++) {
    // Aproximaci¢n inicial de la ra¡z
    double z = cos(M_PI * (i + 0.75) / (n + 0.5));
    double Pn, dPn, z1;

    // Iteraci¢n de Newton-Raphson
    do {
      legendrePolynomialAndDerivative(z, n, Pn, dPn);
      z1 = z;
      z = z1 - Pn / dPn;  // Correcci¢n de Newton-Raphson
    } while (fabs(z - z1) > EPS);  // Repetir hasta convergencia

    // Transformar la ra¡z desde [-1,1] al intervalo [a,b]
    x[i] = xm - xl * z;          // Nodo sim‚trico izquierdo
    x[n - 1 - i] = xm + xl * z;  // Nodo sim‚trico derecho

    // Calcular el peso correspondiente
    double w_val = 2.0 * xl / ((1.0 - z * z) * dPn * dPn);
    w[i] = w_val;
    w[n - 1 - i] = w_val;  // Simetr¡a de los pesos
  }
}

// ------------------------------------------------------------
// Funci¢n gen‚rica para integrar usando cuadratura Gauss-Legendre
// ------------------------------------------------------------
double integrateGaussLegendre(double (*f)(double), double a, double b, int n) {
  double x[NMAX], w[NMAX];

  // Obtener nodos y pesos
  gaussLegendreNodesWeights(a, b, x, w, n);

  double sum = 0.0;

  // Sumar la contribuci¢n de cada nodo
  for (int i = 0; i < n; i++) sum += w[i] * f(x[i]);

  return sum;
}

// ------------------------------------------------------------
// Funciones de prueba a integrar
// ------------------------------------------------------------
double f1(double x) { return 1.0 / (1.0 + x * x); }
double f2(double x) { return exp(-x * x); }

// ------------------------------------------------------------
// Programa principal
// ------------------------------------------------------------
int main() {
  const int n = 20;  // N£mero de puntos de Gauss-Legendre

  // Integral 1
  cout << "\n===== INTEGRAL 1 =====\n";
  double I1 = integrateGaussLegendre(f1, 0.0, 10.0, n);
  cout << "Integral 1: " << setprecision(12) << I1 << endl;

  // Integral 2
  cout << "\n===== INTEGRAL 2 =====\n";
  double I2 = integrateGaussLegendre(f2, 0.0, 10.0, n);
  cout << "Integral 2: " << setprecision(12) << I2 << endl;

  return 0;
}
