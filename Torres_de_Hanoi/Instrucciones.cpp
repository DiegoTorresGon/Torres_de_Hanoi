﻿/*****************************************************************//**
 * \file   Instrucciones.cpp
 * \brief  Implementaciones de Instrucciones.h
 *
 * \author Equipo Rocket
 * \date   3/05/2021
 *********************************************************************/

#include "Instrucciones.h"

enum {
    _MENU = 0,
    _NEXT
};

void Instructions(ALLEGRO_EVENT_QUEUE* queue) {


    ALLEGRO_FONT* font_title = al_load_font("ROBOTECH_GP.ttf", 36, 0);
    ALLEGRO_FONT* font = al_load_font("ROBOTECH_GP.ttf", 36, 0);
    ALLEGRO_FONT* font_paragraph = al_load_font("HelveticaLTStdLight.ttf", 22, 0);

    initialize_al_component(font, "font");
    initialize_al_component(font_title, "font titulo");
    initialize_al_component(font_paragraph, "font parrafo");

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    int button_place = _MENU;

    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:

            if (event.keyboard.keycode == ALLEGRO_KEY_UP || event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                button_place = (button_place - 1) % 2;
                if (button_place < 0)
                    button_place = _MENU;
            }

            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN || event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                button_place = (button_place + 1) % 2;

            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true;

            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE || event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                switch (button_place) {
                    case _MENU:
                        done = true;
                        break;

                    case _NEXT:
                        Origin(queue);
                        break;
                    }
            }

            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            exit(0);
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            InstructionsDisplay(font_title, font, font_paragraph);

            MoveSelection_Instructions(button_place);

            al_flip_display();

            redraw = false;
        }
    }

    //Destruir fuentes creadas
    al_destroy_font(font);
    al_destroy_font(font_title);
    al_destroy_font(font_paragraph);
}

void InstructionsDisplay(ALLEGRO_FONT* title, ALLEGRO_FONT* text, ALLEGRO_FONT* paragraph) {

    //Pantalla
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Titulo Instrucciones
    al_draw_text(title, ColorMap(INDIGO), _WINDOW_WIDTH / 2, 0.5 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "Description");
    //Cuerpo instrucciones
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 1.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "The Towers of Hanoi is a puzzle or mathematical game invented in 1883 by the french mathematician");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 1.7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "Edouard Lucas. This game consists of a number of perforated discs of increasing radius that");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 2.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "are stacked by inserting themselves into one of the three posts fixed to a board");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 2.7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "The objective of the game is to move the stack of discs to another of the posts. ");

    //Titulo Reglas
    al_draw_text(title, ColorMap(INDIGO), _WINDOW_WIDTH / 2, 3.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "Rules");
    //Cuerpo reglas
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 3.9 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "1. You cannot place a larger disk on top of a smaller disk.");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 4.4 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "2. You win the game when you get to insert all the disks stacked from highest to lowest");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 4.9 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "in the far right post. ");

    //Titulo Controles
    al_draw_text(title, ColorMap(INDIGO), _WINDOW_WIDTH / 2, 5.4 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "Controls");
    //Cuerpo controles
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 6.1 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "Use SPACE or ENTER to select the disc.");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 6.6 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "Use the arrow keys for moving the disc or navigate in the game.");

       //Boton Regresar
    DrawButton(_WINDOW_WIDTH / 5, 7.5 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 5,
        8.5 * _WINDOW_HEIGTH / 9, ColorMap(METALIC_BRONZE), text, "REGRESAR", al_map_rgb(255, 255, 255));
    //Boton Origen
    DrawButton(3 * _WINDOW_WIDTH / 5, 7.5 * _WINDOW_HEIGTH / 9, 4 * _WINDOW_WIDTH / 5,
        8.5 * _WINDOW_HEIGTH / 9, ColorMap(METALIC_BRONZE), text, "ORIGEN", al_map_rgb(255, 255, 255));
}

void MoveSelection_Instructions(int Button) {

    switch (Button)
    {
        case _MENU:
            al_draw_filled_rectangle(_WINDOW_WIDTH / 5, 7.5 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 5, 8.5 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0.3, 0.3, 0.3, 0.3));
            break;
        case _NEXT:
            al_draw_filled_rectangle(3 * _WINDOW_WIDTH / 5, 7.5 * _WINDOW_HEIGTH / 9, 4 * _WINDOW_WIDTH / 5, 8.5 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0.3, 0.3, 0.3, 0.3));
            break;
    }
}


// Inicia la pantalla que muestra el origen del juego, muestra el botón para volver a 
// instrucciones o para ir a la solución del acertijo
void Origin(ALLEGRO_EVENT_QUEUE* queue) {

    ALLEGRO_FONT* font_title = al_load_font("ROBOTECH_GP.ttf", 36, 0);
    ALLEGRO_FONT* font = al_load_font("ROBOTECH_GP.ttf", 36, 0);
    ALLEGRO_FONT* font_paragraph = al_load_font("HelveticaLTStdLight.ttf", 22, 0);

    initialize_al_component(font, "font");
    initialize_al_component(font_title, "font titulo");
    initialize_al_component(font_paragraph, "font parrafo");

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;


    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            redraw = true;
            break; 

        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) done = true;                

            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE || event.keyboard.keycode == ALLEGRO_KEY_ENTER) done = true;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            exit(0);
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            OriginDisplay(font_title, font, font_paragraph);

            al_flip_display();

            redraw = false;
        }
    }
    //Destruir fuentes creadas
    al_destroy_font(font);
    al_destroy_font(font_title);
    al_destroy_font(font_paragraph);

}

void OriginDisplay(ALLEGRO_FONT* title, ALLEGRO_FONT* text, ALLEGRO_FONT* paragraph) {

    //Pantalla
    al_clear_to_color(al_map_rgb(0, 0, 0));
    //Titulo Origen
    al_draw_text(title, ColorMap(INDIGO), _WINDOW_WIDTH / 2, 0.5 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "Origin of the Tower of Hanoi");
    //Cuerpo Origen
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 1.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "According to legend, the three posts refer to three diamond spiers of a cubit in height");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 1.7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "and the thickness of the body of a bee, lying on a bronze base under the dome of the great");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 2.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "temple of Benares. ");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 2.7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "On one of these stakes, God, at the beginning of the centuries, placed sixty-four discs");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 3.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "of pure gold. Day and night the priests take turns moving the discs, without deviating");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 3.7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "from the fixed and immutable rules imposed by Brahma.");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 4.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "Each priest should not move more than one disc at a time, and only should place a disc on");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 4.7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "a free stake, or on a larger disc.");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 5.2 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "When the priests move the entire column of discs to the third tower, the tower and the ");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 5.7 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "Brahmans will turn to dust and it will be the end of the world.");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 6.4 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "If the priests were able to perform one movement every second, what would be the time ");
    al_draw_text(paragraph, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 9, 6.9 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_LEFT,
        "needed to move the column and, therefore, when would the world end??");

    //BOTON REGRESAR
    DrawButton(_WINDOW_WIDTH / 5, 7.5 * _WINDOW_HEIGTH / 9, 4 * _WINDOW_WIDTH / 5,
        8.5 * _WINDOW_HEIGTH / 9, ColorMap(METALIC_BRONZE),
        text, "Press ESC, SPACE or ENTER to go back.", al_map_rgb(255, 255, 255));

 }


