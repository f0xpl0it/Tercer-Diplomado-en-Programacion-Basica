//============================================================================
// Name        : NumericMethodsModular.cpp
// Author      : Michael Paucar
// Version     : v.2 Modular
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Modualar implementation of Numerical Methods: 1D, 2D, 3D
// Integrals
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

// ------------------------------------------------------------
// Gauss-Legendre
// ------------------------------------------------------------
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

// ------------------------------------------------------------
// Integral 1D
// ------------------------------------------------------------
double integrate1D_f1(double a, double b, int n) {  // f1(x) = 1/(1+x^2)
  double x[NMAX], w[NMAX];
  gauleg(a, b, x, w, n);
  double sum = 0.0;
  for (int i = 0; i < n; i++) sum += w[i] * (1.0 / (1.0 + x[i] * x[i]));
  return sum;
}

double integrate1D_f2(double a, double b, int n) {  // f2(x) = exp(-x^2)
  double x[NMAX], w[NMAX];
  gauleg(a, b, x, w, n);
  double sum = 0.0;
  for (int i = 0; i < n; i++) sum += w[i] * exp(-x[i] * x[i]);
  return sum;
}

// ------------------------------------------------------------
// Integral 2D
// ------------------------------------------------------------
double integrate2D_f1(double ax, double bx, double ay, double by, int nx,
                      int ny) {  // f1(x,y) = exp(-x*y)*sin(x)
  double x[NMAX], wx[NMAX], y[NMAX], wy[NMAX];
  gauleg(ax, bx, x, wx, nx);
  gauleg(ay, by, y, wy, ny);
  double sum = 0.0;
  for (int j = 0; j < ny; j++)
    for (int i = 0; i < nx; i++)
      sum += wx[i] * wy[j] * exp(-x[i] * y[j]) * sin(x[i]);
  return sum;
}

double integrate2D_f2(double ax, double bx, double ay, double by, int nx,
                      int ny) {  // f2(x,y) = cos(x*y)
  double x[NMAX], wx[NMAX], y[NMAX], wy[NMAX];
  gauleg(ax, bx, x, wx, nx);
  gauleg(ay, by, y, wy, ny);
  double sum = 0.0;
  for (int j = 0; j < ny; j++)
    for (int i = 0; i < nx; i++) sum += wx[i] * wy[j] * cos(x[i] * y[j]);
  return sum;
}
// ------------------------------------------------------------
// Integral 3D
// ------------------------------------------------------------
double integrate3D_f1(double ax, double bx, double ay, double by, double az,
                      double bz, int nx, int ny,
                      int nz) {  // f1(x,y,z) = exp(-x*y*z)*sin(x+y+z)
  double x[NMAX], wx[NMAX], y[NMAX], wy[NMAX], z[NMAX], wz[NMAX];
  gauleg(ax, bx, x, wx, nx);
  gauleg(ay, by, y, wy, ny);
  gauleg(az, bz, z, wz, nz);
  double sum = 0.0;
  for (int k = 0; k < nz; k++)
    for (int j = 0; j < ny; j++)
      for (int i = 0; i < nx; i++)
        sum += wx[i] * wy[j] * wz[k] * exp(-x[i] * y[j] * z[k]) *
               sin(x[i] + y[j] + z[k]);
  return sum;
}

double integrate3D_f2(double ax, double bx, double ay, double by, double az,
                      double bz, int nx, int ny, int nz) {  // f2(x,y,z) = x*y*z
  double x[NMAX], wx[NMAX], y[NMAX], wy[NMAX], z[NMAX], wz[NMAX];
  gauleg(ax, bx, x, wx, nx);
  gauleg(ay, by, y, wy, ny);
  gauleg(az, bz, z, wz, nz);
  double sum = 0.0;
  for (int k = 0; k < nz; k++)
    for (int j = 0; j < ny; j++)
      for (int i = 0; i < nx; i++)
        sum += wx[i] * wy[j] * wz[k] * x[i] * y[j] * z[k];
  return sum;
}

// ------------------------------------------------------------
// Funcion Principal
// ------------------------------------------------------------
int main() {
  const int n = 100;  // N£mero de puntos de Gauss-Legendre, si es muy peque¤o
                      // la integral puede fluctuar

  // 1D
  cout << "\n===== INTEGRALES 1 DIMENSION =====\n";

  cout << "Integral f1: " << setprecision(12) << integrate1D_f1(0, 10, n)
       << endl;
  cout << "Integral f2: " << setprecision(12) << integrate1D_f2(0, 10, n)
       << endl;

  // 2D
  cout << "\n===== INTEGRALES 2 DIMENSIONES =====\n";

  cout << "Integral f1: " << setprecision(12)
       << integrate2D_f1(0, 10, 0, 10, n, n) << endl;
  cout << "Integral f2: " << setprecision(12)
       << integrate2D_f2(0, 10, 0, 10, n, n) << endl;

  // 3D
  cout << "\n===== INTEGRALES 3 DIMENSIONES =====\n";

  cout << "Integral f1: " << setprecision(12)
       << integrate3D_f1(0, 5, 0, 5, 0, 5, n, n, n) << endl;
  cout << "Integral f2: " << setprecision(12)
       << integrate3D_f2(0, 5, 0, 5, 0, 5, n, n, n) << endl;

  return 0;
}
