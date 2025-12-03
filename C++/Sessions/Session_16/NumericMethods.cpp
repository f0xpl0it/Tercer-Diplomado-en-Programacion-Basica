//============================================================================
// Name        : NumericMethodsModular.cpp
// Author      : Michael Paucar
// Version     : v.3 (modular con 1D, 2D y 3D)
//============================================================================

// Referencia:
// Numerical Recipes in C++: The Art of Scientific Computing (2nd Edition),
// Press, Teukolsky, Vetterling, Flannery, Cambridge University Press (2002).

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define EPS 3.0e-11
const int NMAX =
    100;  // Aproximaci¢n inicial de las ra¡ces no es buena para n peque¤o

// ======================================================================
// Gauss-Legendre
// ======================================================================
void gauleg(double x1, double x2, double x[], double w[], const int n) {
  int m = (n + 1) / 2;
  double xm = 0.5 * (x2 + x1);
  double xl = 0.5 * (x2 - x1);

  double xt[NMAX], wt[NMAX];

  for (int i = 1; i <= m; i++) {
    double z = cos(M_PI * (i - 0.25) / (n + 0.5));
    double z1, p1, p2, p3, pp;

    do {
      p1 = 1.0;
      p2 = 0.0;

      for (int j = 1; j <= n; j++) {
        p3 = p2;
        p2 = p1;
        p1 = ((2.0 * j - 1.0) * z * p2 - (j - 1.0) * p3) /
             j;  // Usa una recurrencia que no es estable
      }

      pp = n * (z * p1 - p2) / (z * z - 1.0);
      z1 = z;
      z = z1 - p1 / pp;

    } while (fabs(z - z1) > EPS);

    xt[i - 1] = xm - xl * z;
    xt[n - i] = xm + xl * z;

    wt[i - 1] = 2.0 * xl / ((1.0 - z * z) * pp * pp);
    wt[n - i] = wt[i - 1];
  }

  for (int i = 0; i < n; i++) {
    x[i] = xt[i];
    w[i] = wt[i];
  }
}

// ======================================================================
// Integral 1 Dimensi¢n
// ======================================================================
double integrate1D(double (*f)(double), double a, double b, int n) {
  double x[NMAX], w[NMAX];

  gauleg(a, b, x, w, n);

  double sum = 0.0;
  for (int i = 0; i < n; i++) sum += w[i] * f(x[i]);

  return sum;
}

// ======================================================================
// Integral 2 Dimensiones
// ======================================================================
double integrate2D(double (*f)(double, double), double ax, double bx, double ay,
                   double by, int nx, int ny) {
  double x[NMAX], wx[NMAX];
  double y[NMAX], wy[NMAX];

  gauleg(ax, bx, x, wx, nx);
  gauleg(ay, by, y, wy, ny);

  double sum = 0.0;

  for (int j = 0; j < ny; j++)
    for (int i = 0; i < nx; i++) sum += wx[i] * wy[j] * f(x[i], y[j]);

  return sum;
}

// ======================================================================
// Integral 3 Dimensiones
// ======================================================================
double integrate3D(double (*f)(double, double, double), double ax, double bx,
                   double ay, double by, double az, double bz, int nx, int ny,
                   int nz) {
  double x[NMAX], wx[NMAX];
  double y[NMAX], wy[NMAX];
  double z[NMAX], wz[NMAX];

  gauleg(ax, bx, x, wx, nx);
  gauleg(ay, by, y, wy, ny);
  gauleg(az, bz, z, wz, nz);

  double sum = 0.0;

  for (int k = 0; k < nz; k++)
    for (int j = 0; j < ny; j++)
      for (int i = 0; i < nx; i++)
        sum += wx[i] * wy[j] * wz[k] * f(x[i], y[j], z[k]);

  return sum;
}

// ======================================================================
// Funciones a intergrar
// ======================================================================
double f1D1(double x) { return exp(-x * x); }
double f1D2(double x) { return 1.0 / (1.0 + x * x); }

double f2D1(double x, double y) { return x * pow(y, 2); }
double f2D2(double x, double y) { return exp(-2.0 * x * y) * sin(x); }

double f3D1(double x, double y, double z) {
  return exp(-(x * x + y * y + z * z));
}
double f3D2(double x, double y, double z) {
  return exp(-(x * x + y * y + z * z));
}

// ======================================================================
// Funcion Principal
// ======================================================================
int main() {
  cout << setprecision(10);

  const int n = 30;  // 100 funciona pero es MUY pesado en 3D

  // Integrales 1 Dimension
  cout << "\n===== INTEGRALES 1D =====\n";
  double I1 = integrate1D(f1D1, 0.0, 100.0, n);
  cout << "Integral #1 = " << I1 << endl;

  double I2 = integrate1D(f1D2, 0.0, 10.0, n);
  cout << "Integral #2 = " << I2 << endl;

  // Integral 2 Dimensiones
  cout << "\n===== INTEGRALES 2D =====\n";
  double I3 = integrate2D(f2D1, 0, 1, 0, 2, n, n);
  cout << "Integral #3 = " << I3 << endl;

  double I4 = integrate2D(f2D2, 0.0, 1.0, 0.0, 2.0, n, n);
  cout << "Integral #4 = " << I4 << endl;

  // Integral 3 Dimensiones
  cout << "\n===== INTEGRALES 3D =====\n";
  double I5 = integrate3D(f3D1, 0.0, 5.0, 0.0, 5.0, 0.0, 5.0, n, n, n);
  cout << "Integral #5 = " << I5 << endl;

  double I6 = integrate3D(f3D2, 0.0, 5.0, 0.0, 5.0, 0.0, 5.0, n, n, n);
  cout << "Integral #6 = " << I6 << endl;

  return 0;
}
