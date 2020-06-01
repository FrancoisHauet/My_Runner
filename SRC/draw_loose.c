/*
** EPITECH PROJECT, 2019
** draw_loose
** File description:
** draw_loose
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void color_retry(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->posi_mouse.x > my_sprite->s_retry.posi.x &&
        window->posi_mouse.x < my_sprite->s_retry.posi.x + 210 &&
        window->posi_mouse.y > my_sprite->s_retry.posi.y &&
        window->posi_mouse.y < my_sprite->s_retry.posi.y + 66)
        my_sprite->s_retry.rect.top = 66;
    else
        my_sprite->s_retry.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_retry.s, my_sprite->s_retry.rect);
    if (window->posi_mouse.x > my_sprite->s_exit3.posi.x &&
        window->posi_mouse.x < my_sprite->s_exit3.posi.x + 138 &&
        window->posi_mouse.y > my_sprite->s_exit3.posi.y &&
        window->posi_mouse.y < my_sprite->s_exit3.posi.y + 53)
        my_sprite->s_exit3.rect.top = 53;
    else
        my_sprite->s_exit3.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_exit3.s, my_sprite->s_exit3.rect);
}

void click_exit(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_exit3.posi.x &&
            window->posi_mouse.x < my_sprite->s_exit3.posi.x + 138
            && window->posi_mouse.y > my_sprite->s_exit3.posi.y &&
            window->posi_mouse.y < my_sprite->s_exit3.posi.y + 53)
            sfRenderWindow_close(window->window);
    }
}

void click_retry(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (window->posi_mouse.x > my_sprite->s_retry.posi.x &&
        window->posi_mouse.x < my_sprite->s_retry.posi.x + 210 &&
        window->posi_mouse.y > my_sprite->s_retry.posi.y &&
        window->posi_mouse.y < my_sprite->s_retry.posi.y + 64) {
            window->scene = 2;
        }
    }
}

void create_loose(draw_sprite_t *my_sprite)
{
    my_sprite->s_loose.posi = (sfVector2f) {150, 100};
    my_sprite->t_loose.t = sfTexture_createFromFile("File/loose.png", NULL);
    my_sprite->s_loose.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_loose.s, my_sprite->t_loose.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_loose.s, my_sprite->s_loose.posi);
    my_sprite->s_retry.posi = (sfVector2f) {300, 400};
    my_sprite->t_retry.t = sfTexture_createFromFile("File/Retry.png", NULL);
    my_sprite->s_retry.rect = (sfIntRect) {0, 0, 210, 66};
    my_sprite->s_retry.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_retry.s, my_sprite->t_retry.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_retry.s, my_sprite->s_retry.rect);
    sfSprite_setPosition(my_sprite->s_retry.s, my_sprite->s_retry.posi);
    my_sprite->s_exit3.posi = (sfVector2f) {600, 400};
    my_sprite->t_exit3.t = sfTexture_createFromFile("File/Exit.png", NULL);
    my_sprite->s_exit3.rect = (sfIntRect) {0, 0, 138, 53};
    my_sprite->s_exit3.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_exit3.s, my_sprite->t_exit3.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_exit3.s, my_sprite->s_exit3.rect);
    sfSprite_setPosition(my_sprite->s_exit3.s, my_sprite->s_exit3.posi);
}

void draw_loose(setup_t *window, draw_sprite_t *my_sprite)
{
    window->posi_mouse = sfMouse_getPositionRenderWindow(window->window);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_home.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_exit3.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_loose.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_retry.s, NULL);
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