/*
** EPITECH PROJECT, 2019
** scene_one
** File description:
** scene_one
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void scene(setup_t *window, draw_sprite_t *my_sprite, int ac, char **av)
{
    window->scene = 0;
    window->speed = 0;
    window->score = 0;
    window->cactus = 1;
    my_sprite->space = 1;

    my_sprite->clock.clock = sfClock_create();
    my_sprite->clock2.clock = sfClock_create();
    sfMusic_play(my_sprite->music_game.music);
    my_sprite->frame = 60;
    sfRenderWindow_setFramerateLimit(window->window, my_sprite->frame);
}

void choose(setup_t *window, draw_sprite_t *my_sprite)
{
    switch (window->scene) {
        case 5:
            draw_loose(window, my_sprite);
            break;
        case 4:
            draw_win(window, my_sprite);
            break;
        case 3:
            draw_game(window, my_sprite);
            break;
        case 2:
            draw_difficulty(window, my_sprite);
            break;
        case 1:
            draw_tuto(window, my_sprite);
            break;
        case 0:
            draw(window, my_sprite);
            break;
    }
}

void scene_one(setup_t window, draw_sprite_t my_sprite, int ac, char **av)
{
    scene(&window, &my_sprite, ac, av);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_clear(window.window, sfBlack);
        check_event(&window);
        choose(&window, &my_sprite);
        sfRenderWindow_display(window.window);
    }
    destroy(&window, &my_sprite);
}