/*****************************************************************//**
 * \file   Menu.h
 * \brief  Responsable del men� principal de la aplicaci�n.
 * 
 * \author Equipo Rocket
 * \date   3/05/2021
 *********************************************************************/
#pragma once
#ifndef _MENU_H
#define _MENU_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Utileria.h"

/**
 * \brief Funci�n que se encarga de mostrar el men� principal
 * 
 * \param queue Cola de eventos principal.
 * \return void
 */
void Menu(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* display);

/**
 * \brief Muesta el titulo y los botones en pantalla
 *
 * \param 
 * \return void
 */
void MenuDisplay(ALLEGRO_FONT* title, ALLEGRO_FONT* text);

void MoveSelection(int Button);





#endif 
