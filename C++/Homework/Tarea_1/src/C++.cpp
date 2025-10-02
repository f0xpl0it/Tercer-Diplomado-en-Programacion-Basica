//============================================================================
// Name        : C++.cpp
// Author      : Michael Paucar
// Version     :
// Copyright   : Your copyright notice
// Description : Tarea 1
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

// Ejercicio 1: Conversor de Temperaturas
void conversorTemperatura(){
	// Variables
	float degree, fharenheit, kelvin;

	// Output - Input
	cout << "Ingrese temperatura en grados Celcius: ";
	cin >> degree;

	// Conversiones
	fharenheit = (degree*9/5)+32;
	kelvin = degree +273.5;

	// Imprimir
	cout << degree << "°C --> " << fharenheit << "°F" << endl;
	cout << degree << "°C --> " << kelvin << "K" << endl;
	cout << endl;
}

// Ejercicio 2: Promedio Estudiantes
void promedioEstudiante(){
	// Variables
	float nota1, nota2, nota3, prom;

	// Output - Input
	cout << "Ingrese Nota 1: ";
	cin >> nota1;
	cout << "Ingrese Nota 2: ";
	cin >> nota2;
	cout << "Ingrese Nota 3: ";
	cin >> nota3;

	// C[alculos
	prom = (nota1 + nota2 + nota3)/3;

	// Imprimir
	cout << "El estudiante tiene un promdeio de: " << prom << endl;
	cout << endl;
}
// Ejercicio 3: Conversión múltiple de unidades
void conversionUnidad(){
	// Variables
	float distancia, km, cm, mm;

	// Input - Output
	cout << "Ingrese la distancia en metros (m): ";
	cin >> distancia;

	// Conversiones
	km = distancia / 1000;
	cm = distancia * 100;
	mm = distancia * 1000;

	// Imprimir
	cout << distancia << " (m) --> " << km << " (Km)" << endl;
	cout << distancia << " (m) --> " << cm << " (cm)" << endl;
	cout << distancia << " (m) --> " << mm << " (mm)" << endl;
	cout << endl;
}

// Ejercicio 4: Ecuación cuadrática (fórmula general)
void formulaGeneral(){
	//Variables
	float a, b, c, delta, x1, x2;

	// Input - Output
	cout << "Ingrese el coeficiente de (a): ";
	cin >> a;
	cout << "Ingrese el coeficiente de (b): ";
	cin >> b;
	cout << "Ingrese el coeficiente de (c): ";
	cin >> c;

	// Discriminante
	delta = b*b - 4*a*c;

	// Soluciones
	x1 = (-b + sqrt(delta))/(2*a);
	x2 = (-b + sqrt(delta))/(2*a);

	// Imprimir
	cout << "Discriminante = " << delta << endl;
	cout << "Soluciones: " << endl;
	cout << "\t x1 = " << x1 << endl;
	cout << "\t x2 = " << x2 << endl;
	cout << endl;
}


int main (int argc, char *argv[]) {

	cout << "Ejercicio 1" << endl;
	conversorTemperatura();

	cout << "Ejercicio 2" << endl;
	promedioEstudiante();

	cout << "Ejercicios 3" << endl;
	conversionUnidad();

	cout << "Ejercicio 4" << endl;
	formulaGeneral();

	return 0;
}

