/*
** EPITECH PROJECT, 2019
** draw_win
** File description:
** draw_win
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void create_win(draw_sprite_t *my_sprite)
{
    my_sprite->s_win.posi = (sfVector2f) {100, 50};
    my_sprite->t_win.t = sfTexture_createFromFile("File/win.png", NULL);
    my_sprite->s_win.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_win.s, my_sprite->t_win.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_win.s, my_sprite->s_win.posi);
    my_sprite->s_cake.posi = (sfVector2f) {200, 475};
    my_sprite->t_cake.t = sfTexture_createFromFile("File/end.png", NULL);
    my_sprite->s_cake.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_cake.s, my_sprite->t_cake.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_cake.s, my_sprite->s_cake.posi);
}

void draw_win(setup_t *window, draw_sprite_t *my_sprite)
{
    window->posi_mouse = sfMouse_getPositionRenderWindow(window->window);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_home.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_win.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_exit3.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_retry.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_cake.s, NULL);
    color_retry(window, my_sprite);
    click_exit(window, my_sprite);
    click_retry(window, my_sprite);
    window->score = 0;
    window->cactus = 1;
    my_sprite->s_cact1.posi = (sfVector2f) {1900, 750};
    sfSprite_setPosition(my_sprite->s_cact1.s, my_sprite->s_cact1.posi);
    my_sprite->s_cact2.posi = (sfVector2f) {1900, 750};
    sfSprite_setPosition(my_sprite->s_cact2.s, my_sprite->s_cact2.posi);
    my_sprite->s_cact3.posi = (sfVector2f) {1900, 750};
    sfSprite_setPosition(my_sprite->s_cact3.s, my_sprite->s_cact3.posi);
    my_sprite->s_cact4.posi = (sfVector2f) {1900, 750};
    sfSprite_setPosition(my_sprite->s_cact4.s, my_sprite->s_cact4.posi);
}