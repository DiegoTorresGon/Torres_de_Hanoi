/*****************************************************************//**
 * \file   main.cpp
 * \brief  Archivo principal del proyecto.
 * 
 * \author Equipo Rocket
 * \date   29/04/2021
 *********************************************************************/

#include <iostream>
#include <allegro5/allegro5.h>

#include "Utileria.h"

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

#define _FPS 30.0 /*< Cantidad de cuadros por segundo que se actualiza la pantalla */


int main() {

	//Inicializar componentes principal de Allegro.
	initialize_al_component(al_init(), "Allegro");

	//Inicializar teclado.
	initialize_al_component(al_install_keyboard(), "teclado");

	//Inicializar cola de eventos.
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	initialize_al_component(queue, "cola de eventos");

	//Inicializar temporizador.
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / _FPS);
	initialize_al_component(timer, "temporizador");

	//Crear pantalla.
	ALLEGRO_DISPLAY* disp = al_create_display(_WINDOW_WIDTH, _WINDOW_HEIGTH);
	initialize_al_component(disp, "pantalla");
	
	//Mover pantalla a posici�n inicial.
	al_set_window_position(disp, _WINDOW_POS_X, _WINDOW_POS_Y);

	//Pedir el registro eventos relevantes en la cola de eventos.
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	//Pasar control a funci�n menu hasta que el usuario quiera salir.
	//Menu();

	//Liberar variables de Allegro
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);

	return 0;
}
