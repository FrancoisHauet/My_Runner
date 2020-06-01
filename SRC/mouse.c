/*
** EPITECH PROJECT, 2019
** mouse
** File description:
** mouse
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void color_bottom(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->posi_mouse.x > my_sprite->s_start.posi.x &&
        window->posi_mouse.x < my_sprite->s_start.posi.x + 197
        && window->posi_mouse.y > my_sprite->s_start.posi.y &&
        window->posi_mouse.y < my_sprite->s_start.posi.y + 53)
        my_sprite->s_start.rect.top = 53;
    else
        my_sprite->s_start.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_start.s, my_sprite->s_start.rect);
    if (window->posi_mouse.x > my_sprite->s_exit.posi.x &&
        window->posi_mouse.x < my_sprite->s_exit.posi.x + 138 &&
        window->posi_mouse.y > my_sprite->s_exit.posi.y &&
        window->posi_mouse.y < my_sprite->s_exit.posi.y + 53)
        my_sprite->s_exit.rect.top = 53;
    else
        my_sprite->s_exit.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_exit.s, my_sprite->s_exit.rect);
}

void color_tuto(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->posi_mouse.x > my_sprite->s_tuto.posi.x &&
        window->posi_mouse.x < my_sprite->s_tuto.posi.x + 296
        && window->posi_mouse.y > my_sprite->s_tuto.posi.y &&
        window->posi_mouse.y < my_sprite->s_tuto.posi.y + 53)
        my_sprite->s_tuto.rect.top = 53;
    else
        my_sprite->s_tuto.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_tuto.s, my_sprite->s_tuto.rect);
}

void click_tuto(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_tuto.posi.x &&
        window->posi_mouse.x < my_sprite->s_tuto.posi.x + 296 &&
        window->posi_mouse.y > my_sprite->s_tuto.posi.y &&
        window->posi_mouse.y < my_sprite->s_tuto.posi.y + 53) {
            window->scene = 1;
        }
    }
}

void click_bottom_exit(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_exit.posi.x &&
            window->posi_mouse.x < my_sprite->s_exit.posi.x + 138
            && window->posi_mouse.y > my_sprite->s_exit.posi.y &&
            window->posi_mouse.y < my_sprite->s_exit.posi.y + 53)
            sfRenderWindow_close(window->window);
        }
}

void click_bottom_start(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_start.posi.x &&
        window->posi_mouse.x < my_sprite->s_start.posi.x + 197 &&
        window->posi_mouse.y > my_sprite->s_start.posi.y &&
        window->posi_mouse.y < my_sprite->s_start.posi.y + 53) {
            window->scene = 2;
        }
    }
}