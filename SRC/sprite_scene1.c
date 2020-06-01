/*
** EPITECH PROJECT, 2019
** Sprite_scene1
** File description:
** Sprite_scene1
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void create_my_sprite_start_exit(draw_sprite_t *my_sprite)
{
    my_sprite->s_start.posi = (sfVector2f) {300, 400};
    my_sprite->t_start.t = sfTexture_createFromFile("File/Start.png", NULL);
    my_sprite->s_start.rect = (sfIntRect) {0, 0, 197, 53};
    my_sprite->s_start.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_start.s, my_sprite->t_start.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_start.s, my_sprite->s_start.rect);
    sfSprite_setPosition(my_sprite->s_start.s, my_sprite->s_start.posi);
    my_sprite->s_exit.posi = (sfVector2f) {900, 400};
    my_sprite->t_exit.t = sfTexture_createFromFile("File/Exit.png", NULL);
    my_sprite->s_exit.rect = (sfIntRect) {0, 0, 138, 53};
    my_sprite->s_exit.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_exit.s, my_sprite->t_exit.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_exit.s, my_sprite->s_exit.rect);
    sfSprite_setPosition(my_sprite->s_exit.s, my_sprite->s_exit.posi);
    my_sprite->s_runner.posi = (sfVector2f) {350, 50};
    my_sprite->t_runner.t = sfTexture_createFromFile("File/runner.png", NULL);
    my_sprite->s_runner.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_runner.s, my_sprite->t_runner.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_runner.s, my_sprite->s_runner.posi);
}

void create_my_sprite_tuto(draw_sprite_t *my_sprite)
{
    my_sprite->s_tuto.posi = (sfVector2f) {550, 400};
    my_sprite->t_tuto.t = sfTexture_createFromFile("File/Tuto.png", NULL);
    my_sprite->s_tuto.rect = (sfIntRect) {0, 0, 296, 53};
    my_sprite->s_tuto.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_tuto.s, my_sprite->t_tuto.t, sfTrue);
    sfSprite_setTextureRect(my_sprite->s_tuto.s, my_sprite->s_tuto.rect);
    sfSprite_setPosition(my_sprite->s_tuto.s, my_sprite->s_tuto.posi);
    my_sprite->t_home.t = sfTexture_createFromFile("File/Back.png", NULL);
    my_sprite->s_home.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_home.s, my_sprite->t_home.t, sfTrue);
}

void music_game(draw_sprite_t *music)
{
    music->music_game.music = sfMusic_createFromFile("File/Game_music.ogg");
}