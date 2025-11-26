//============================================================================
// Name        : fases.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : stages functions for dragon game
//============================================================================

// Colores ANSI
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define VERDE "\033[32m"
#define AZUL "\033[34m"

#include "fases.h"

#include <iostream>

#include "animacion.h"
#include "dragon.h"
#include "input.h"
#include "tablero.h"
using namespace std;

//----------------------------------------
// Fase 1: Acercamiento al tesoro
//----------------------------------------
void fase1(int& posicionJugador, int& dreamDragon, const int POSICION_TESORO) {
  while (posicionJugador < POSICION_TESORO && !dragonDespierto(dreamDragon)) {
    cout << "   \n* Presiona [ENTER] para avanzar...";
    cin.get();

    posicionJugador = avanzarJugador(posicionJugador);
    lanzarRuido(dreamDragon);

    mostrarEstado(posicionJugador, dreamDragon, false);
  }
}

//----------------------------------------
// Fase 2: Abrir el cofre
//----------------------------------------
void fase2(int& posicionJugador, bool& cofreAbierto, int& dreamDragon) {
  while (!cofreAbierto && !dragonDespierto(dreamDragon)) {
    cout << "\n* Presiona [ENTER] para intentar abrir el cofre...";
    cin.get();

    cofreAbierto = abrirCofre();

    if (!cofreAbierto) {
      cout << MAGENTA << "Llave incorrecta... \n" << RESET;
      // mostrarCofreCerrado();
      lanzarRuido(dreamDragon);
    } else {
      cout << VERDE << "El cofre se abri¢!!\n" << RESET;
      posicionJugador = 15;  // Reiniciamos en 15 para retroceder
      mostrarCofreAbierto();
    }

    mostrarEstado(posicionJugador, dreamDragon, cofreAbierto);
  }
}

//----------------------------------------
// Fase 3: Escape con el tesoro
//----------------------------------------
void fase3(int& posicionJugador, int& dreamDragon, bool cofreAbierto) {
  while (!jugadorEscapo(posicionJugador) && !dragonDespierto(dreamDragon)) {
    cout << "\n* Presiona [ENTER]para retroceder...";
    cin.get();

    retrocederJugador(posicionJugador);

    lanzarRuido(dreamDragon);

    mostrarEstado(posicionJugador, dreamDragon, cofreAbierto);
  }
}
