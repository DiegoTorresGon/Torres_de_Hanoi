/*****************************************************************//**
 * \file   Utileria.h
 * \brief  Funciones de utileria para todo el proyecto.
 * 
 * \author Equipo Rocket
 * \date   3/05/2021
 *********************************************************************/
#pragma once
#ifndef _UTILERIA_H
#define _UTILERIA_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdexcept>

/** Colores usados para imprimir los discos y para los textos.
 */
enum {
	VERY_PALE_YELLOW=0,
	PALE_YELLOW,
	PALE_YELLOW_RED,
	YELLOW_RED,
	MAXIMUM_YELLOW_RED,
	ORANGE,
	BRORANGE,
	BRONZE,
	METALIC_BRONZE,
	INDIGO,
	HANBLUE,
	UNITED_NATIONS_BLUE
};

 /*< Medidas en px de la pantalla. */
enum {
	_WINDOW_HEIGTH = 684, /*< Altura de la pantalla del programa en pixeles. */
	_WINDOW_WIDTH = 1216 /*< Ancho de la pantalla del programa en pixeles. */
};

/*< Posicion inicial de la pantalla (px desde la esquina superior izquierda) en x y en y. */
enum {
	_WINDOW_POS_X = 0, /*< Posici�n inicial de la pantalla en x en px, iniciando del margen izuqierdo. */
	_WINDOW_POS_Y = 0 /*< Posici�n inicial de la pantalla en y en px, iniciando del margen superior. */
};

#define _FPS 30.0f /*< Cantidad de cuadros por segundo que se actualiza la pantalla */

 /**
  * \brief Si flag tiene un valor falso, tira un excepci�n de tipo std::runtime_error.
  * \details La excepci�n tiene el mensaje "No se pudo inicializar comp_name.".
  *
  * \param flag Si es verdaro se tira la excepci�n.
  *				Se usa con alguna funci�n que regresa verdadero si se pudo inicializar el componente
  *				y falso si no lo pudo hacer.
  * \param comp_namme Nombre de lo que se est� inicializando. Se incluye en el mensaje de excepci�n.
  * \return void
  */
void initialize_al_component(bool flag, const char* comp_name);

/**
 * \brief 
 * \details 
 *
 * \param 
 * \param
 * \param
 * \param
 * \param
 * 
 * \return 
 */
float Elipse(float a, float b, float p, float q, float x);

/**
 * \brief Asigna el mapa RGB al color recibido
 * 
 * \param nombre_color Nombre del color de que se requiere el mapa
 * \return al_map_rgb() El mapa de color correspondiente
 */
ALLEGRO_COLOR ColorMap(int nombre_color);

/**
 * \brief Dibuja un bot�n en pantalla 
 * 
 * \param x1 Posici�n x donde comienza el rect�ngulo
 * \param y1 Posici�n y donde comienza el rect�ngulo
 * \param x2 Posici�n x donde termina el rect�ngulo
 * \param y2 Posici�n y donde termina el rect�ngulo
 * \param button_color Color del bot�n
 * \param text Fuente del texto a escribir sobre el bot�n
 * \param string Texto que se escribe sobre el bot�n
 * \param text_color Color del texto que se escribe
 *
 * \return void
 */
void DrawButton(float x1, float y1, float x2, float y2, ALLEGRO_COLOR button_color, 
	ALLEGRO_FONT* text, const char string[], ALLEGRO_COLOR text_color);

#endif
