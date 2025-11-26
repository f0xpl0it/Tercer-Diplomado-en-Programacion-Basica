//============================================================================
// Name        : fases.h
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Header file for dragon game functions
//============================================================================

//----------------------------------------
// HEADERS
//----------------------------------------

#ifndef FASES_H
#define FASES_H

//----------------------------------------
// Funciones de las fases del juego fases.cpp
//----------------------------------------
void fase1(int& posicionJugador, int& dreamDragon, const int POSICION_TESORO);
void fase2(int& posicionJugador, bool& cofreAbierto, int& dreamDragon);
void fase3(int& posicionJugador, int& dreamDragon, bool cofreAbierto);

#endif