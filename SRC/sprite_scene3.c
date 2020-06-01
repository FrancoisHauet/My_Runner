/*
** EPITECH PROJECT, 2019
** sprite_scene3
** File description:
** sprite_scene3
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

void create_dino(draw_sprite_t *my_sprite)
{
    my_sprite->s_dino.posi = (sfVector2f) {50, 750};
    my_sprite->t_dino.t = sfTexture_createFromFile("File/Mouv.png", NULL);
    my_sprite->s_dino.rect = (sfIntRect) {0, 0, 65, 134};
    my_sprite->s_dino.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_dino.s, my_sprite->t_dino.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_dino.s, my_sprite->s_dino.posi);
}

void create_duck(draw_sprite_t *my_sprite)
{
    my_sprite->s_duck.posi = (sfVector2f) {0, 250};
    my_sprite->t_duck.t = sfTexture_createFromFile("File/Sprite.png", NULL);
    my_sprite->s_duck.rect = (sfIntRect) {0, 0, 60, 50};
    my_sprite->s_duck.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_duck.s, my_sprite->t_duck.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_duck.s, my_sprite->s_duck.posi);
    my_sprite->s_cloud.posi = (sfVector2f) {2000, 100};
    my_sprite->t_cloud.t = sfTexture_createFromFile("File/Nuage.png", NULL);
    my_sprite->s_cloud.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_cloud.s, my_sprite->t_cloud.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_cloud.s, my_sprite->s_cloud.posi);
    my_sprite->s_grou.posi = (sfVector2f) {0, 755};
    my_sprite->t_grou.t = sfTexture_createFromFile("File/Back2.png", NULL);
    my_sprite->s_grou.rect = (sfIntRect) {0, 0, 1913, 200};
    my_sprite->s_grou.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_grou.s, my_sprite->t_grou.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_grou.s, my_sprite->s_grou.posi);
}

void create_bush(draw_sprite_t *my_sprite)
{
    my_sprite->s_score.posi = (sfVector2f) {736, 50};
    my_sprite->t_score.t = sfTexture_createFromFile("File/Score.png", NULL);
    my_sprite->s_score.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_score.s, my_sprite->t_score.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_score.s, my_sprite->s_score.posi);
    my_sprite->s_par.posi = (sfVector2f) {0, 400};
    my_sprite->t_par.t = sfTexture_createFromFile("File/test1.png", NULL);
    my_sprite->s_par.rect = (sfIntRect) {0, 0, 1913, 380};
    my_sprite->s_par.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_par.s, my_sprite->t_par.t, sfTrue);
    sfSprite_setPosition(my_sprite->s_par.s, my_sprite->s_par.posi);
}

void create_background_game(draw_sprite_t *my_sprite)
{
    my_sprite->t_whi.t = sfTexture_createFromFile("File/White.jpg", NULL);
    my_sprite->s_whi.s = sfSprite_create();
    sfSprite_setTexture(my_sprite->s_whi.s, my_sprite->t_whi.t, sfTrue);
}

void clock2(draw_sprite_t *my_sprite)
{
    my_sprite->clock2.time = sfClock_getElapsedTime(my_sprite->clock2.clock);
    my_sprite->seconds2 = my_sprite->clock2.time.microseconds / 1000000.0;
    if (my_sprite->seconds2 > 0.15) {
        mouv_down(&my_sprite->s_par.rect, 380, 3040);
        sfClock_restart(my_sprite->clock2.clock);
    }
}