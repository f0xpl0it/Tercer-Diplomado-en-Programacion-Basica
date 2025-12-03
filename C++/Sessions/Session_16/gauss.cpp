#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Rutina de integraci¢n num‚rica usando cuadraturas de Gauss-Legendre.
// Extra¡da de Numerical Recipes in C++, secci¢n 4.5 Gaussian Quadratures.
//
// Referencia:
// Numerical Recipes in C++: The Art of Scientific Computing (2nd Edition),
// Press, Teukolsky, Vetterling, Flannery, Cambridge University Press (2002).

#define EPS 3.0e-11    // Tolerancia para el criterio de convergencia en Newton
const int NMAX = 100;  // M ximo n£mero de nodos permitidos

// ============================================================================
// ga u l e g
// ---------------------------------------------------------------------------
// Esta funci¢n calcula:
//
//  x[i]  -> los nodos (abscisas) de Gauss-Legendre
//  w[i]  -> los pesos de Gauss-Legendre
//
// en el intervalo [x1, x2] usando N puntos.
//
// Los nodos y pesos se obtienen resolviendo las ra¡ces del polinomio
// de Legendre P_n(x), y calculando sus pesos correspondientes:
//
//   w_i = 2 / [ (1 - x_i^2) (P_n'(x_i))^2 ]
//
// El algoritmo es:
//  1. Calcular aproximaci¢n inicial de la ra¡z i-‚sima.
//  2. Refinarla con Newton-Raphson usando P_n(x) y su derivada P_n'(x).
//  3. Explorar solo la mitad de los nodos gracias a la simetr¡a.
// ============================================================================
void gauleg(double x1, double x2, double x[], double w[], const int n) {
  // N£mero de nodos £nicos a calcular (por simetr¡a)
  int m = (n + 1) / 2;

  // Transformaci¢n lineal del intervalo [-1,1] a [x1,x2]
  double xm = 0.5 * (x2 + x1);  // Punto medio
  double xl = 0.5 * (x2 - x1);  // Semilongitud del intervalo

  // Arreglos temporales para almacenar antes de copiar
  double xt[NMAX], wt[NMAX];

  // Recorremos la mitad de las ra¡ces del polinomio de Legendre P_n
  for (int i = 1; i <= m; i++) {
    // Aproximaci¢n inicial para la ra¡z i usando f¢rmula de Chebyshev
    double z = cos(M_PI * (i - 0.25) / (n + 0.5));
    double z1, p1, p2, p3, pp;

    // --------------------------
    // MTODO DE NEWTON-RAPHSON
    // --------------------------
    do {
      // Inicializamos los polinomios de Legendre
      p1 = 1.0;  // P_0(x)
      p2 = 0.0;  // P_{-1}(x) ficticio para la recurrencia

      // Recurrencia para construir P_j(x) hasta P_n(x)
      for (int j = 1; j <= n; j++) {
        p3 = p2;
        p2 = p1;
        // F¢rmula de recurrencia para P_j(x)
        p1 = ((2.0 * j - 1.0) * z * p2 - (j - 1.0) * p3) / j;
      }

      // Derivada del polinomio de Legendre P_n'(x)
      pp = n * (z * p1 - p2) / (z * z - 1.0);

      // Guardamos el valor anterior para verificar convergencia
      z1 = z;

      // Iteraci¢n de Newton:  z = z - f(z)/f'(z)
      z = z1 - p1 / pp;

    } while (fabs(z - z1) > EPS);

    // --------------------------
    // TRANSFORMACIàN AL INTERVALO [x1, x2]
    // --------------------------
    xt[i - 1] = xm - xl * z;  // Ra¡z izquierda
    xt[n - i] = xm + xl * z;  // Ra¡z derecha (sim‚trica)

    // C lculo del peso asociado a esta ra¡z
    wt[i - 1] = 2.0 * xl / ((1.0 - z * z) * pp * pp);
    wt[n - i] = wt[i - 1];  // Simetr¡a de pesos
  }

  // Copiamos los valores calculados a los arreglos de salida
  for (int i = 0; i < n; i++) {
    x[i] = xt[i];
    w[i] = wt[i];
  }
}

// ============================================================================
// PROGRAMA PRINCIPAL
// ---------------------------------------------------------------------------
// Realiza una integraci¢n doble:
//
//   ?_0^100 ?_0^100  exp(-2xy) sin(x)  dx dy
//
// usando NMAX x NMAX puntos de Gauss-Legendre.
// ============================================================================
int main() {
  const int n = NMAX;  // N£mero total de nodos en cada dimensi¢n

  double x[n], wx[n];  // Nodos y pesos en X
  double y[n], wy[n];  // Nodos y pesos en Y

  // Obtenemos las abscisas y pesos para X y Y
  // gauleg(a, b, nodos, pesos, cantidad_de_nodos)
  gauleg(0.0, 100.0, x, wx, n);
  gauleg(0.0, 100.0, y, wy, n);

  double integracion = 0.0;

  // -----------------------------
  // DOBLE SUMATORIA DE GAUSS-LEGENDRE
  // -----------------------------
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      // f(x, y) = exp(-2xy) sin(x)
      // cada t‚rmino se multiplica por wx[j] * wy[i]
      integracion += wx[j] * wy[i] * exp(-2.0 * x[j] * y[i]) * sin(x[j]);
    }
  }

  cout << "La integracion es: " << setprecision(10) << integracion << endl;

  return 0;
}
