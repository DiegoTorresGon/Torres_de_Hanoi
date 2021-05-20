/*****************************************************************//**
 * \file   Creditos.h
 * \brief  Encargado de p�gina de creditos.
 * 
 * \author Equipo Rocket
 * \date   3/05/2021
 *********************************************************************/
#pragma once
#ifndef _CREDITOS_H
#define _CREDITOS_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Utileria.h"

 /**
  * \brief Funci�n que se encarga de mostrar los ccr�ditos
  *
  * \param queue Cola de eventos principal.
  * \return void
  */
void Creditos(ALLEGRO_EVENT_QUEUE* queue);

/**
 * \brief Muesta el texto de cr�ditos en pantalla
 *
 * \param title Fuente definida para el t�tulo
 * \param text Fuente definida para los botones
 * \param paragraph Fuente definida para el cuerpo
 * 
 * \return void
 */
void CreditosDisplay(ALLEGRO_FONT* title, ALLEGRO_FONT* text, ALLEGRO_FONT* paragraph);

#endif 
