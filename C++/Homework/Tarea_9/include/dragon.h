//============================================================================
// Name        : dragon.h
// Author      : Michael Paucar
// Version     : v.1
// Copyright   : Copyright (c) 2025 Michael Paucar.
// Description : Header file for dragon game functions
//============================================================================

//----------------------------------------
// HEADERS
//----------------------------------------

#ifndef DRAGON_H
#define DRAGON_H

//----------------------------------------
// Funciones del juego dragon.cpp
//----------------------------------------
int avanzarJugador(int posicionActual);
int retrocederJugador(int& posicionActual);
int lanzarRuido(int& dreamDragon);
bool abrirCofre();
void mostrarEstado(int posicionJugador, int suenoDragon, bool cofreAbierto);
bool dragonDespierto(int dreamDragon);
bool jugadorEscapo(int posicionJugador);
int lanzarDado(int caras = 6);

#endif