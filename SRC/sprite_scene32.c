/*
** EPITECH PROJECT, 2019
** sprite_scene3.2
** File description:
** sprite_scene3.2
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void cactus4(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->cactus == 4) {
        my_sprite->s_cact4.posi.x -= window->speed + 5;
        sfSprite_setPosition(my_sprite->s_cact4.s, my_sprite->s_cact4.posi);
        if (my_sprite->s_cact4.posi.x <= -250) {
            my_sprite->s_cact4.posi.x = 1900;
            window->score += 4;
            window->cactus = rand() % 4 + 1;
        }
        sfRenderWindow_drawSprite(window->window, my_sprite->s_cact4.s, NULL);
        if (my_sprite->s_dino.posi.x >= my_sprite->s_cact4.posi.x &
        my_sprite->s_dino.posi.x <= my_sprite->s_cact4.posi.x + 252 &&
        my_sprite->s_dino.posi.y >= my_sprite->s_cact4.posi.y &&
        my_sprite->s_dino.posi.y <= my_sprite->s_cact4.posi.y + 148)
            window->scene = 5;
    }
}

void cactus3(setup_t *window, draw_sprite_t *my_sprite)
{
    if (window->cactus == 3) {
        my_sprite->s_cact3.posi.x -= window->speed + 5;
        sfSprite_setPosition(my_sprite->s_cact3.s, my_sprite->s_cact3.posi);
        if (my_sprite->s_cact3.posi.x <= -150) {
            my_sprite->s_cact3.posi.x = 1900;
            window->score += 3;
            window->cactus = rand() % 4 + 1;
        }
        sfRenderWindow_drawSprite(window->window, my_sprite->s_cact3.s, NULL);
        if (my_sprite->s_dino.posi.x >= my_sprite->s_cact3.posi.x &&
        my_sprite->s_dino.posi.x <= my_sprite->s_cact3.posi.x + 148 &&
        my_sprite->s_dino.posi.y >= my_sprite->s_cact3.posi.y &&
        my_sprite->s_dino.posi.y <= my_sprite->s_cact3.posi.y + 148)
            window->scene = 5;
    }
}

void create_text(draw_sprite_t *my_sprite)
{
    my_sprite->text.font = sfFont_createFromFile("File/Pixel.ttf");
    my_sprite->text.text = sfText_create();
    sfText_setFont(my_sprite->text.text, my_sprite->text.font);
    sfText_setCharacterSize(my_sprite->text.text, 100);
}

void create_cactus(draw_sprite_t *my_sprite)
{
    my_sprite->s_cact1.posi = (sfVector2f) {1900, 750};
    my_sprite->t_cact1.t = sfTexture_createFromFile("File/cactus1.png", NULL);
    my_sprite->s_cact1.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_cact1.s, my_sprite->t_cact1.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_cact1.s, my_sprite->s_cact1.posi);
    my_sprite->s_cact2.posi = (sfVector2f) {1900, 750};
    my_sprite->t_cact2.t = sfTexture_createFromFile("File/cactus2.png", NULL);
    my_sprite->s_cact2.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_cact2.s, my_sprite->t_cact2.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_cact2.s, my_sprite->s_cact2.posi);
    my_sprite->s_cact3.posi = (sfVector2f) {1900, 750};
    my_sprite->t_cact3.t = sfTexture_createFromFile("File/cactus3.png", NULL);
    my_sprite->s_cact3.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_cact3.s, my_sprite->t_cact3.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_cact3.s, my_sprite->s_cact3.posi);
    my_sprite->s_cact4.posi = (sfVector2f) {1900, 750};
    my_sprite->t_cact4.t = sfTexture_createFromFile("File/cactus4.png", NULL);
    my_sprite->s_cact4.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_cact4.s, my_sprite->t_cact4.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_cact4.s, my_sprite->s_cact4.posi);
}

void create_sound(draw_sprite_t *sound)
{
    sound->sound.buffer = sfSoundBuffer_createFromFile("File/Jump.ogg");
    sound->sound.sound = sfSound_create();
    sfSound_setBuffer(sound->sound.sound, sound->sound.buffer);
}