//============================================================================
// Name        : tablero.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Status of the game board for dragon game
//============================================================================

#include <cmath>
#include <iostream>
using namespace std;

//----------------------------------------
// Tablero de juego
//----------------------------------------
void mostrarCueva(int posicionJugador) {
  const int LONGITUD_CUEVA = 15;
  char cueva[LONGITUD_CUEVA];

  // Espacios como vac¡os
  for (int i = 0; i < LONGITUD_CUEVA; i++) cueva[i] = ' ';

  // Posiciones del jugador y tesoro
  if (posicionJugador < LONGITUD_CUEVA - 1)
    cueva[posicionJugador] = 'J';
  else
    cueva[LONGITUD_CUEVA - 1] = 'T';

  // Imprimir el arreglo
  cout << "Cueva: [";
  for (int i = 0; i < LONGITUD_CUEVA; i++) {
    cout << cueva[i];
    if (i != LONGITUD_CUEVA - 1) cout << "][";
  }
  cout << "]" << endl;
}

//----------------------------------------
// Barra de Estado del Dragon
//----------------------------------------
void mostrarBarraDragon(int dreamDragon) {
  const int MAX_DREAM = 30;

  cout << "Sue¤o del drag¢n: [";
  for (int i = 0; i < MAX_DREAM; i++) {
    if (i < dreamDragon)
      cout << "#";
    else
      cout << " ";
  }
  cout << "] (" << dreamDragon << "/" << MAX_DREAM << ")" << endl;
}
