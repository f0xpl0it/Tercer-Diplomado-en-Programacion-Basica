//============================================================================
// Name        : dragon.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Functions file for dragon game
//============================================================================

// Colores ANSI
#define RESET "\033[0m"
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AMARILLO "\033[33m"
#define AZUL "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

#include "dragon.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

#include "animacion.h"
#include "tablero.h"

using namespace std;

//----------------------------------------
// LANZAR EL DADO
//----------------------------------------
int lanzarDado(int caras) {
  int resultado = rand() % caras + 1;
  cout << "\nValor del dado: #" << resultado << endl;
  mostrarDado(resultado);
  return resultado;
}

//----------------------------------------
// AVANCE DEL JUGADOR
//----------------------------------------
int avanzarJugador(int posicionActual) {
  int dado = lanzarDado(6);
  posicionActual += dado;
  cout << AZUL << "[EXPLORADOR] --> Avanza " << dado << " posiciones.\n"
       << RESET;
  return posicionActual;
}

//----------------------------------------
// RUIDO PARA DRAGON
//----------------------------------------
int lanzarRuido(int& dreamDragon) {
  int dado = lanzarDado(6);
  dreamDragon -= dado;
  if (dreamDragon > 20)
    cout << AMARILLO << "[DRAGON] --> Ruido: " << dado
         << " --> Profundamente dormido Zzz..." << RESET << endl;
  else if (dreamDragon > 10)
    cout << AMARILLO << "[DRAGON] --> Ruido: " << dado
         << " --> Se mueve un poco..." << RESET << endl;
  else if (dreamDragon > 0)
    cout << AMARILLO << "[DRAGON] --> Ruido: " << dado
         << " --> Est  despertando!" << RESET << endl;
  else
    cout << ROJO << "[DRAGON] --> Ruido: " << dado << " --> DESPERTà!!!"
         << RESET << endl;
  return dado;
}
//----------------------------------------
// RETROCEDER DEL JUGADOR
//----------------------------------------
int retrocederJugador(int& posicionActual) {
  int dado = lanzarDado(6);
  posicionActual -= dado;
  cout << AZUL << "[EXPLORADOR] --> Retrocede " << dado << " posiciones.\n"
       << RESET;
  return posicionActual;
}

//----------------------------------------
// PAR E IMPAR PARA COFRE
//----------------------------------------
bool abrirCofre() {
  int dado = lanzarDado(6);
  cout << AZUL << "[COFRE] --> Llave: " << dado << RESET << endl;
  return (dado % 2 != 0);
}

//----------------------------------------
// JUEGO FALLIDO
//----------------------------------------
bool dragonDespierto(int dreamDragon) {
  // El drag¢n est  despierto si su sue¤o es 0 o menos
  return dreamDragon <= 0;
}

//----------------------------------------
// JUEGO EXITOSO
//----------------------------------------
bool jugadorEscapo(int posicionJugador) {
  // El jugador ha escapado si su posici¢n es 0 o menos
  return posicionJugador <= 0;
}

//----------------------------------------
// ESTADO DEL JUGADOR Y DRAGON
//----------------------------------------
void mostrarEstado(int posicionJugador, int dreamDragon, bool cofreAbierto) {
  cout << MAGENTA
       << "\n========================= ESTADO ==========================\n"
       << RESET;
  cout << AZUL << "Posicion del jugador: " << posicionJugador << RESET << endl;
  cout << AMARILLO << "Sue¤o del drag¢n: " << dreamDragon << RESET << endl;
  cout << VERDE << "Cofre abierto: " << (cofreAbierto ? "S¡" : "No") << RESET
       << endl;

  cout << endl;
  mostrarCueva(posicionJugador);
  mostrarBarraDragon(dreamDragon);
  cout << MAGENTA
       << "===========================================================\n\n"
       << RESET;
}
