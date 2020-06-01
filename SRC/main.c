/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void create_my_windows(setup_t *window)
{
    window->nb_window_y = 970;
    window->nb_window_x = 1913;
    window->mode.height = window->nb_window_y;
    window->mode.width = window->nb_window_x;
    window->mode.bitsPerPixel = 64;
    window->window = sfRenderWindow_create(window->mode,
    "My_Runner", sfDefaultStyle, NULL);
}

void check_event(setup_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (window->event.type == sfEvtClosed)
            sfRenderWindow_close(window->window);
    }
}

void draw(setup_t *window, draw_sprite_t *my_sprite)
{
    window->posi_mouse = sfMouse_getPositionRenderWindow(window->window);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_home.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_runner.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_start.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_exit.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_tuto.s, NULL);
    color_bottom(window, my_sprite);
    color_tuto(window, my_sprite);
    click_bottom_exit(window, my_sprite);
    click_bottom_start(window, my_sprite);
    click_tuto(window, my_sprite);
}

void destroy(setup_t *window, draw_sprite_t *my_sprite)
{
    sfWindow_destroy(window->window);
    sfMusic_destroy(my_sprite->music_game.music);
    sfSound_destroy(my_sprite->sound.sound);
    sfSoundBuffer_destroy(my_sprite->sound.buffer);
}

int main(int ac, char **av)
{
    setup_t window;
    draw_sprite_t my_sprite;
    create_my_windows(&window);
    create_background_game(&my_sprite);
    create_text(&my_sprite);
    create_loose(&my_sprite);
    create_win(&my_sprite);
    create_sound(&my_sprite);
    create_bush(&my_sprite);
    create_duck(&my_sprite);
    create_dino(&my_sprite);
    create_cactus(&my_sprite);
    create_my_sprite_start_exit(&my_sprite);
    create_my_sprite_tuto(&my_sprite);
    create_rules_exit(&my_sprite);
    create_difficulty(&my_sprite);
    create_choose(&my_sprite);
    music_game(&my_sprite);
    scene_one(window, my_sprite, ac, av);
    return 0;
}