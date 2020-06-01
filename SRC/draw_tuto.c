/*
** EPITECH PROJECT, 2019
** draw_tuto
** File description:
** draw_tuto
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void color_exit2(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->posi_mouse.x > my_sprite->s_exit2.posi.x &&
        window->posi_mouse.x < my_sprite->s_exit2.posi.x + 138 &&
        window->posi_mouse.y > my_sprite->s_exit2.posi.y &&
        window->posi_mouse.y < my_sprite->s_exit2.posi.y + 53)
        my_sprite->s_exit2.rect.top = 53;
    else
        my_sprite->s_exit2.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_exit2.s, my_sprite->s_exit2.rect);
}

void click_bottom_exit2(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_exit2.posi.x &&
            window->posi_mouse.x < my_sprite->s_exit2.posi.x + 138
            && window->posi_mouse.y > my_sprite->s_exit2.posi.y &&
            window->posi_mouse.y < my_sprite->s_exit2.posi.y + 53)
            window->scene = 0;
        }
}

void create_rules_exit(draw_sprite_t *my_sprite)
{
    my_sprite->s_rules.posi = (sfVector2f) {150, 250};
    my_sprite->t_rules.t = sfTexture_createFromFile("File/Rules.png", NULL);
    my_sprite->s_rules.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_rules.s, my_sprite->t_rules.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_rules.s, my_sprite->s_rules.posi);
    my_sprite->s_exit2.posi = (sfVector2f) {800, 500};
    my_sprite->t_exit2.t = sfTexture_createFromFile("File/Exit.png", NULL);
    my_sprite->s_exit2.rect = (sfIntRect) {0, 0, 138, 53};
    my_sprite->s_exit2.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_exit2.s, my_sprite->t_exit2.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_exit2.s, my_sprite->s_exit2.rect);
    sfSprite_setPosition(my_sprite->s_exit2.s, my_sprite->s_exit2.posi);
}

void draw_tuto(setup_t *window, draw_sprite_t *my_sprite)
{
    window->posi_mouse = sfMouse_getPositionRenderWindow(window->window);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_home.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_rules.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_exit2.s, NULL);
    color_exit2(window, my_sprite);
    click_bottom_exit2(window, my_sprite);
}