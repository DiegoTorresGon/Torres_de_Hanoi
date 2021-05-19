﻿/*****************************************************************//**
 * \file   Instrucciones.cpp
 * \brief  Implementaciones de Instrucciones.h
 * 
 * \author Equipo Rocket
 * \date   3/05/2021
 *********************************************************************/

#include "Instrucciones.h"

enum {
    _REGRESAR = 0,
    _ORIGEN
};

void Instrucciones(ALLEGRO_EVENT_QUEUE* queue) {
    //Esta función se tiene que encargar de mostrar las instrucciones del juego


    ALLEGRO_FONT* font_title = al_load_font("ROBOTECH_GP.ttf", 48, 0);
    ALLEGRO_FONT* font = al_load_font("ROBOTECH_GP.ttf", 36, 0);
    ALLEGRO_FONT* font_paragraph = al_load_font("ROBOTECH_GP.ttf", 24, 0);

    initialize_al_component(font, "font");
    initialize_al_component(font_title, "font titulo");
    initialize_al_component(font_paragraph, "font parrafo");

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    int button_place = _REGRESAR;

    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // nada por ahora.
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            
            if (event.keyboard.keycode == ALLEGRO_KEY_UP || event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                button_place = (button_place - 1) % 2;
                if (button_place < 0)
                    button_place = _ORIGEN;
            }

            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                button_place = (button_place + 1) % 2;

            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true;

            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE || event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                switch (button_place)
                    case _REGRESAR:
                        done = true;
            }

            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            InstruccionesDisplay(font_title, font, font_paragraph);

            MoverSeleccion_Instrucciones(button_place);

            al_flip_display();

            redraw = false;
        }
    }

    //Destruir fuentes creadas
    al_destroy_font(font);
    al_destroy_font(font_title);
}

void InstruccionesDisplay(ALLEGRO_FONT* title, ALLEGRO_FONT* text, ALLEGRO_FONT* paragraph) {

    //Pantalla
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Titulo
    al_draw_text(title, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 2, _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "INSTRUCCIONES");
    //Cuerpo
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 2.5 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "DescripciOn: Las Torres de HanOi es un rompecabezas o juego matemAtico inventado en 1883");

   
    //Boton Regresar
    al_draw_filled_rectangle(_WINDOW_WIDTH / 5, 7 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 5, 8 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.3));
    al_draw_text(text, al_map_rgb(255, 255, 255), 1.5* _WINDOW_WIDTH / 5, 7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "REGRESAR");
    //Boton Origen
    al_draw_filled_rectangle(3*_WINDOW_WIDTH / 5, 7 * _WINDOW_HEIGTH / 9, 4 * _WINDOW_WIDTH / 5, 8 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.5));
    al_draw_text(text, al_map_rgb(255, 255, 255), 3.5 * _WINDOW_WIDTH / 5, 7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "ORIGEN");

}

void MoverSeleccion_Instrucciones(int Button) {

    switch (Button)
    {
    case _REGRESAR:
        al_draw_filled_rectangle(_WINDOW_WIDTH / 5, 7 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 5, 8 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0.5, 0.5, 0.5, 0.5));
        break;
    case _ORIGEN:
        al_draw_filled_rectangle(3 * _WINDOW_WIDTH / 5, 7 * _WINDOW_HEIGTH / 9, 4 * _WINDOW_WIDTH / 5, 8 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0.5, 0.5, 0.5, 0.5));
        break;
    }

}
