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

#include <stdexcept>

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

float Elipse(float a, float b, float p, float q, float x);

#endif
