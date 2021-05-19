/*****************************************************************//**
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
    //Esta funci�n se tiene que encargar de mostrar las instrucciones del juego

    //Inicializar texto.
    initialize_al_component(al_init_font_addon(), "font component");
    //Inicializar ttf (True Type Font)
    initialize_al_component(al_init_ttf_addon(), "ttf font componenent");

    ALLEGRO_FONT* font_title = al_load_font("ROBOTECH_GP.ttf", 48, 0);
    ALLEGRO_FONT* font = al_load_font("ROBOTECH_GP.ttf", 36, 0);

    initialize_al_component(font, "font");
    initialize_al_component(font_title, "font titulo");
    initialize_al_component(al_init_primitives_addon(), "primitives");

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
            // Ya que solo hay 2 opciones
            if (event.keyboard.keycode == ALLEGRO_KEY_UP) {
                button_place = _ORIGEN;
            }

            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                button_place = _REGRESAR;

            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                done = true;

            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                switch (button_place)
                    case _REGRESAR:
                        done = true;
            }


            redraw = true;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            InstruccionesDisplay(font_title, font);

            MoverSeleccion_Instrucciones(button_place);

            al_flip_display();

            redraw = false;
        }
    }

    //Destruir fuentes creadas
    al_destroy_font(font);
    al_destroy_font(font_title);
}

void InstruccionesDisplay(ALLEGRO_FONT* title, ALLEGRO_FONT* text) {

    //Pantalla
    al_clear_to_color(al_map_rgb(2, 3, 1));
    //Titulo
    al_draw_text(title, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 2, _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "INSTRUCCIONES");
    //Boton Jugar
    al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 3 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 4 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.3));
    al_draw_text(text, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 2, 3 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "ORIGEN");
    //Boton Instrucciones
    al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 4.5 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 5.5 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.5));
    al_draw_text(text, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 2, 4.5 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "REGRESAR");
    //Boton Creditos
  /*  al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 6 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 7 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.5));
    al_draw_text(text, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 2, 6 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "CREDITOS");
    //Boton Salir
    al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 7.5 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 8.5 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0, 0, 0.5, 0.5));
    al_draw_text(text, al_map_rgb(255, 255, 255), _WINDOW_WIDTH / 2, 7.5 * _WINDOW_HEIGTH / 9, ALLEGRO_ALIGN_CENTER, "SALIR");
    */
    al_flip_display();
}

void MoverSeleccion_Instrucciones(int Button) {

    switch (Button)
    {
    case _REGRESAR:
        al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 3 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 4 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0.5, 0.5, 0.5, 0.5));
        break;
    case _ORIGEN:
        al_draw_filled_rectangle(_WINDOW_WIDTH / 3, 4.5 * _WINDOW_HEIGTH / 9, 2 * _WINDOW_WIDTH / 3, 5.5 * _WINDOW_HEIGTH / 9, al_map_rgba_f(0.5, 0.5, 0.5, 0.5));
        break;
    }

}
