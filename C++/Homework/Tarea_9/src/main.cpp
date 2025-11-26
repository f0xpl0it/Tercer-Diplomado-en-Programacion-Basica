//============================================================================
// Name        : main.cpp
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : main file for dragon game
//============================================================================

// Colores ANSI
#define RESET "\033[0m"
#define ROJO "\033[31m"
#define VERDE "\033[32m"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

#include "animacion.h"
#include "dragon.h"
#include "fases.h"
#include "input.h"
#include "tablero.h"
using namespace std;

//----------------------------------------
// Funci¢n Principal
//----------------------------------------

int main() {
  srand(time(NULL));

  // Constantes
  const int POSICION_TESORO = 15;
  int opc = 0;

  do {
    mostrarTitulo();

    cout << "[1] Jugar\n";
    cout << "[2] Salir\n";
    cout << "   \t>> Selecciona una opcion: ";
    cin >> opc;

    if (!entradaValida() && (opc < 1 || opc > 2)) {
      cout << "   \t>> Selecciona una opcion: ";
      cin >> opc;
    }

    if (opc == 1) {
      // Limpiar el buffer
      limpiarEntrada();

      // Variables (Reiniciamos cada partida)
      int posicionJugador = 0;
      int dreamDragon = 30;
      bool cofreAbierto = false;

      mostrarTitulo1();

      //----------------------------------------
      // FASE 1
      //----------------------------------------
      fase1(posicionJugador, dreamDragon, POSICION_TESORO);
      if (dragonDespierto(dreamDragon)) {
        cout << ROJO << "\nFALLASTE EL DRAGON DESPERTO!!\n\n" << RESET;
        return 0;
      }

      mostrarTitulo2();

      //----------------------------------------
      // FASE 2
      //----------------------------------------
      fase2(posicionJugador, cofreAbierto, dreamDragon);
      if (dragonDespierto(dreamDragon)) {
        cout << ROJO << "\nFALLASTE EL DRAGON DESPERTO!!\n\n" << RESET;
        return 0;
      }

      mostrarTitulo3();

      //----------------------------------------
      // FASE 3
      //----------------------------------------
      fase3(posicionJugador, dreamDragon, cofreAbierto);

      if (dragonDespierto(dreamDragon)) {
        cout << ROJO << "\nFALLASTE EL DRAGON DESPERTO!!\n" << RESET;
        mostrarDragonDespierto();

      } else {
        cout << VERDE
             << "\nMISION COMPLETA, EL DRAGON DUERME Y TIENES EL TESORO!!\n"
             << RESET;
        mostrarDragonDormido();
      }

    } else if (opc == 2) {
      limpiarEntrada();
      cout << "\nSaliendo del programa...\n";
      cin.get();

    } else {
      cout << ROJO << "\nFuera de rango!!\n" << RESET;
    }

  } while (opc != 2);

  return 0;
}
