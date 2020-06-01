/*
** EPITECH PROJECT, 2019
** draw_difficulty
** File description:
** draw_difficulty
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void color_easy_nor(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->posi_mouse.x > my_sprite->s_easy.posi.x &&
        window->posi_mouse.x < my_sprite->s_easy.posi.x + 177 &&
        window->posi_mouse.y > my_sprite->s_easy.posi.y &&
        window->posi_mouse.y < my_sprite->s_easy.posi.y + 66)
        my_sprite->s_easy.rect.top = 66;
    else
        my_sprite->s_easy.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_easy.s, my_sprite->s_easy.rect);
    if (window->posi_mouse.x > my_sprite->s_nor.posi.x &&
        window->posi_mouse.x < my_sprite->s_nor.posi.x + 268 &&
        window->posi_mouse.y > my_sprite->s_nor.posi.y &&
        window->posi_mouse.y < my_sprite->s_nor.posi.y + 53)
        my_sprite->s_nor.rect.top = 55;
    else
        my_sprite->s_nor.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_nor.s, my_sprite->s_nor.rect);
}

void color_hard(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->posi_mouse.x > my_sprite->s_hard.posi.x &&
        window->posi_mouse.x < my_sprite->s_hard.posi.x + 177
        && window->posi_mouse.y > my_sprite->s_hard.posi.y &&
        window->posi_mouse.y < my_sprite->s_hard.posi.y + 53)
        my_sprite->s_hard.rect.top = 53;
    else
        my_sprite->s_hard.rect.top = 0;
    sfSprite_setTextureRect(my_sprite->s_hard.s, my_sprite->s_hard.rect);
}

void create_difficulty(draw_sprite_t *my_sprite)
{
    my_sprite->s_easy.posi = (sfVector2f) {300, 500};
    my_sprite->t_easy.t = sfTexture_createFromFile("File/Easy.png", NULL);
    my_sprite->s_easy.rect = (sfIntRect) {0, 0, 177, 64};
    my_sprite->s_easy.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_easy.s, my_sprite->t_easy.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_easy.s, my_sprite->s_easy.rect);
    sfSprite_setPosition(my_sprite->s_easy.s, my_sprite->s_easy.posi);
    my_sprite->s_nor.posi = (sfVector2f) {550, 500};
    my_sprite->t_nor.t = sfTexture_createFromFile("File/Nor.png", NULL);
    my_sprite->s_nor.rect = (sfIntRect) {0, 0, 268, 53};
    my_sprite->s_nor.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_nor.s, my_sprite->t_nor.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_nor.s, my_sprite->s_nor.rect);
    sfSprite_setPosition(my_sprite->s_nor.s, my_sprite->s_nor.posi);
    my_sprite->s_hard.posi = (sfVector2f) {900, 500};
    my_sprite->t_hard.t = sfTexture_createFromFile("File/Hard.png", NULL);
    my_sprite->s_hard.rect = (sfIntRect) {0, 0, 177, 53};
    my_sprite->s_hard.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_hard.s, my_sprite->t_hard.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_hard.s, my_sprite->s_hard.rect);
    sfSprite_setPosition(my_sprite->s_hard.s, my_sprite->s_hard.posi);
}

void create_choose(draw_sprite_t *my_sprite)
{
    my_sprite->s_cho.posi = (sfVector2f) {150, 250};
    my_sprite->t_cho.t = sfTexture_createFromFile("File/Dif.png", NULL);
    my_sprite->s_cho.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_cho.s, my_sprite->t_cho.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_cho.s, my_sprite->s_cho.posi);
}

void draw_difficulty(setup_t *window, draw_sprite_t *my_sprite)
{
    window->posi_mouse = sfMouse_getPositionRenderWindow(window->window);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_home.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_cho.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_easy.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_nor.s, NULL);
    sfRenderWindow_drawSprite(window->window, my_sprite->s_hard.s, NULL);
    color_easy_nor(window, my_sprite);
    color_hard(window, my_sprite);
    click_easy(window, my_sprite);
    click_nor(window, my_sprite);
    click_hard(window, my_sprite);
}