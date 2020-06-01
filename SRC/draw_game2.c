/*
** EPITECH PROJECT, 2019
** draw_game2
** File description:
** draw_game2
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void cactus2(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->cactus == 2) {
        my_sprite->s_cact2.posi.x -= window->speed + 5;
        sfSprite_setPosition(my_sprite->s_cact2.s, my_sprite->s_cact2.posi);
        if (my_sprite->s_cact2.posi.x <= -100) {
            my_sprite->s_cact2.posi.x = 1900;
            window->score += 2;
            window->cactus = rand() % 4 + 1;
        }
        sfRenderWindow_drawSprite(window->window, my_sprite->s_cact2.s, NULL);
        if (my_sprite->s_dino.posi.x >= my_sprite->s_cact2.posi.x &&
        my_sprite->s_dino.posi.x <= my_sprite->s_cact2.posi.x + 128 &&
        my_sprite->s_dino.posi.y >= my_sprite->s_cact2.posi.y &&
        my_sprite->s_dino.posi.y <= my_sprite->s_cact2.posi.y + 148)
            window->scene = 5;
    }
}

void cactus(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->cactus == 1) {
        my_sprite->s_cact1.posi.x -= window->speed + 5;
        sfSprite_setPosition(my_sprite->s_cact1.s, my_sprite->s_cact1.posi);
        if (my_sprite->s_cact1.posi.x <= -50) {
            my_sprite->s_cact1.posi.x = 1900;
            window->score += 1;
            window->cactus = rand() % 4 + 1;
        }
        sfRenderWindow_drawSprite(window->window, my_sprite->s_cact1.s, NULL);
        if (my_sprite->s_dino.posi.x >= my_sprite->s_cact1.posi.x &&
        my_sprite->s_dino.posi.x <= my_sprite->s_cact1.posi.x + 70 &&
        my_sprite->s_dino.posi.y >= my_sprite->s_cact1.posi.y &&
        my_sprite->s_dino.posi.y <= my_sprite->s_cact1.posi.y + 148)
            window->scene = 5;
    }
    cactus2(window, my_sprite);
    cactus3(window, my_sprite);
    cactus4(window, my_sprite);
}

void cloud(setup_t *window, draw_sprite_t *my_sprite)
{
    sfSprite_setPosition(my_sprite->s_cloud.s, my_sprite->s_cloud.posi);
    if (my_sprite->s_cloud.posi.x <= -200) {
        my_sprite->s_cloud.posi.x = 2000;
        my_sprite->s_cloud.posi.y = rand() % 300 + 50;
    }
}

void score(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->score > 100)
        window->scene = 4;
}

void input(setup_t *window, draw_sprite_t *my_sprite)
{
    static int sound = 0;
    static int pressed = 0;

    if (sfKeyboard_isKeyPressed(sfKeySpace) && pressed < 100) {
        if (sound == 0) {
            sfSound_play(my_sprite->sound.sound);
            sound = 1;
        }
        pressed += 5;
        input2(window, my_sprite);
    }
    else {
        if (!sfKeyboard_isKeyPressed(sfKeySpace)) {
            sound = 0;
            pressed = 0;
        }
        my_sprite->s_dino.posi.y += 35;
        sfSprite_setPosition(my_sprite->s_dino.s, my_sprite->s_dino.posi);
        if (my_sprite->s_dino.posi.y >= 750)
            my_sprite->s_dino.posi.y = 750;
    }
}