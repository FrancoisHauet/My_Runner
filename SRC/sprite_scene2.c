/*
** EPITECH PROJECT, 2019
** sprite_scene2
** File description:
** sprite_scene2
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void click_easy(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_easy.posi.x &&
        window->posi_mouse.x < my_sprite->s_easy.posi.x + 177 &&
        window->posi_mouse.y > my_sprite->s_easy.posi.y &&
        window->posi_mouse.y < my_sprite->s_easy.posi.y + 66) {
            window->speed = 10;
            window->speed_cac = -10;
            window->scene = 3;
        }
    }
}

void click_nor(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_nor.posi.x &&
            window->posi_mouse.x < my_sprite->s_nor.posi.x + 268 &&
            window->posi_mouse.y > my_sprite->s_nor.posi.y &&
            window->posi_mouse.y < my_sprite->s_nor.posi.y + 53) {
            window->speed = 15;
            window->speed_cac = -15;
            window->scene = 3;
            }
        }
}

void click_hard(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_hard.posi.x &&
        window->posi_mouse.x < my_sprite->s_hard.posi.x + 177 &&
        window->posi_mouse.y > my_sprite->s_hard.posi.y &&
        window->posi_mouse.y < my_sprite->s_hard.posi.y + 53) {
            window->speed = 20;
            window->speed_cac = -15;
            window->scene = 3;
        }
    }
}

void input2(setup_t *window, draw_sprite_t *my_sprite)
{
    my_sprite->s_dino.posi.y -= 35;
    sfSprite_setPosition(my_sprite->s_dino.s, my_sprite->s_dino.posi);
    if (my_sprite->s_dino.posi.y <= 600)
        my_sprite->s_dino.posi.y = 600;
}