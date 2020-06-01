/*
** EPITECH PROJECT, 2019
** draw_game
** File description:
** draw_game
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void draw2(setup_t *window, draw_sprite_t *my_sprite)
{
    sfRenderWindow_drawSprite(window->window, my_sprite->s_whi.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_cloud.s, NULL);
    sfSprite_setTextureRect(my_sprite->s_duck.s, my_sprite->s_duck.rect);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_duck.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_grou.s, NULL);
    sfSprite_setTextureRect(my_sprite->s_grou.s, my_sprite->s_grou.rect);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_dino.s, NULL);
    sfSprite_setTextureRect(my_sprite->s_dino.s, my_sprite->s_dino.rect);
    sfText_setString(my_sprite->text.text, my_itoa(window->score));
    sfText_setPosition(my_sprite->text.text, (sfVector2f) {1125, 40});
    sfRenderWindow_drawSprite(window->window, my_sprite->s_score.s, NULL);
    sfText_setColor(my_sprite->text.text, sfBlack);
    sfRenderWindow_drawText(window->window, my_sprite->text.text, NULL);
}

void mouv_rect(sfIntRect *rect, int offset, int max_value)
{
    (*rect).left = (*rect).left + offset;
    if ((*rect).left >= max_value)
        (*rect).left = 0;
}

void mouv_down(sfIntRect *rect, int offset, int max_value)
{
    (*rect).top = (*rect).top + offset;
    if ((*rect).top >= max_value)
        (*rect).top = 0;
}

void duck(setup_t *window, draw_sprite_t *my_sprite)
{
    sfSprite_setPosition(my_sprite->s_duck.s, my_sprite->s_duck.posi);
    if (my_sprite->s_duck.posi.x >= 1913) {
        my_sprite->s_duck.posi.x = -60;
        my_sprite->s_duck.posi.y = rand() % 500 + 50;
    }
}

void draw_game(setup_t *window, draw_sprite_t *my_sprite)
{
    window->posi_mouse = sfMouse_getPosition(window->window);
    window->posi_sprite = sfSprite_getPosition(my_sprite->s_duck.s);
    my_sprite->clock.time = sfClock_getElapsedTime(my_sprite->clock.clock);
    my_sprite->seconds = my_sprite->clock.time.microseconds / 1000000.0;
    if (my_sprite->seconds > 0.10) {
        mouv_rect(&my_sprite->s_duck.rect, 60, 180);
        mouv_down(&my_sprite->s_grou.rect, 200, 800);
        mouv_rect(&my_sprite->s_dino.rect, 65, 130);
        sfClock_restart(my_sprite->clock.clock);
    }
    clock2(my_sprite);
    input(window, my_sprite);
    my_sprite->s_duck.posi.x += window->speed + 3;
    my_sprite->s_cloud.posi.x -= window->speed + 2;
    duck(window, my_sprite);
    cloud(window, my_sprite);
    score(window, my_sprite);
    draw2(window, my_sprite);
    cactus(window, my_sprite);
}