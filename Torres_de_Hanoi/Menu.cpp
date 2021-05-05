/*********************************************************************
 * \file   Menu.cpp
 * \brief  Implementaciones de Menu.h
 * 
 * \author Equipo Rocket
 * \date   3/05/2021
 *********************************************************************/

#include "Menu.h"

void Menu(ALLEGRO_EVENT_QUEUE* queue) {
	//Esta funci�n se tiene que encargar de mostrar un men�
	//y de tomar acci�n cuando el usuario de una entrada.

    //Inicializar tipo de letra.
    ALLEGRO_FONT* font = al_create_builtin_font();
    
    initialize_al_component(font, "font");

    initialize_al_component(al_init_primitives_addon(), "primitives");

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));


            al_draw_text(font, al_map_rgb(255, 255, 255), _WINDOW_WIDTH/2,0, 0, "its a tiny cow");

            al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 3 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 4 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.5));
            al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 5 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 6 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.5));
            al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 7 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 8 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.5));

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
}
