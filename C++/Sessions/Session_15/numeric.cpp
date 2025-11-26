//============================================================================
// Name : numeric.cpp // Author : Michael Paucar
// Version : v.1
// Copyright : Copyright (c) 2025 Michael Paucar.
// Description : 2025/11/25 - Numeric Integral Types
//============================================================================

#include <cmath>
#include <iomanip>  // Gestiona el formato de entrada y salida (PRESICION)
#include <iostream>
using namespace std;

#define EPS 3.6e-11  // Tolerancia para la convergencia del m‚todo iterativo

const int NMAX =
    20;  // N£mero m ximo de puntos para la cuadratura de Gauss-Legendre

// Funci¢n que calcula los puntos y pesos de la cuadratura de Gauss-Legendre
void gaussLegendreQuadrature(double x1, double x2, double x[], double w[],
                             const int n) {
  int m = (n + 1) /
          2;  // Solo necesitamos calcular la mitad de los puntos por simetr¡a
  double xm = 0.5 * (x2 + x1);  // Punto medio del intervalo
  double xl = 0.5 * (x2 - x1);  // Semi-longitud del intervalo

  double xt[NMAX],
      wt[NMAX];  // Arreglos temporales para almacenar puntos (x) y pesos (w)

  // Bucle para calcular los puntos y pesos
  for (int i = 1; i <= m; i++) {
    // Aproximaci¢n inicial para la ra¡z del polinomio de Legendre
    double z = cos(M_PI * (i - 0.25) / (n + 0.5));
    double z1, p1, p2, p3, pp;

    // M‚todo de Newton-Raphson para refinar la ra¡z
    do {
      p1 = 1.0;  // P_0(x)
      p2 = 0.0;  // P_{-1}(x), auxiliar para la recurrencia

      // Recurrencia para calcular P_n(z) (polinomio de Legendre de grado n)
      for (int j = 1; j <= n; j++) {
        p3 = p2;
        p2 = p1;
        p1 = ((2.0 * j - 1.0) * z * p2 - (j - 1.0) * p3) / j;
      }

      // Derivada del polinomio de Legendre
      pp = n * (z * p1 - p2) / (z * z - 1.0);
      z1 = z;
      z = z1 - p1 / pp;  // Correcci¢n de Newton-Raphson
    } while (fabs(z - z1) > EPS);  // Repetir hasta convergencia

    // Convertir la ra¡z al intervalo [x1, x2] y guardar pesos
    xt[i - 1] = xm - xl * z;  // Punto sim‚trico izquierdo
    xt[n - i] = xm + xl * z;  // Punto sim‚trico derecho
    wt[i - 1] = 2.0 * xl / ((1.0 - z * z) * pp * pp);  // Peso izquierdo
    wt[n - i] = wt[i - 1];  // Peso derecho (simetr¡a)
  }

  // Copiar resultados a los arreglos de salida
  for (int i = 0; i < n; i++) {
    x[i] = xt[i];
    w[i] = wt[i];
  }
}

int main() {
  const int n = NMAX;
  double x[NMAX], w[NMAX];

  // Calcular puntos y pesos para el intervalo [0, 10]
  gaussLegendreQuadrature(0.0, 10.0, x, w, n);

  // Primera integral: ?_0^10 1/(1+x^2) dx
  cout << "\n===== INTEGRAL 1 =====\n";

  double integral1 = 0.0;
  for (int i = 0; i < n; i++) {
    integral1 += w[i] * (1.0 / (x[i] * x[i] + 1.0));
  }
  cout << "Integral 1: " << setprecision(10) << integral1 << endl;

  // Segunda integral: ?_0^10 e^(-x^2) dx
  cout << "\n===== INTEGRAL 2 =====\n";

  double integral2 = 0.0;
  for (int i = 0; i < n; i++) {
    integral2 += w[i] * exp(-x[i] * x[i]);
  }
  cout << "Integral 2: " << setprecision(10) << integral2 << endl;

  return 0;
}
