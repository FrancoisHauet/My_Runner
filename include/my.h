/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct set_sound
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} set_sound_t;

typedef struct set_text
{
    sfText *text;
    sfFont *font;
    sfVector2f posi_text;
} set_text_t;

typedef struct set_clock
{
    sfClock *clock;
    sfVector2f offset;
    sfTime time;
} set_clock_t;

typedef struct set_sprite
{
    sfSprite *s;
    sfVector2f posi;
    sfIntRect rect;
    sfIntRect s_rect;
} set_sprite_t;

typedef struct set_texture
{
    sfTexture *t;
} set_texture_t;

typedef struct set_music
{
    sfMusic *music;
} set_music_t;

typedef struct draw_sprite
{
    set_texture_t t_home;
    set_sprite_t s_home;
    set_sprite_t s_start;
    set_texture_t t_start;
    set_sprite_t s_exit;
    set_texture_t t_exit;
    set_sprite_t s_exit2;
    set_texture_t t_exit2;
    set_sprite_t s_exit3;
    set_texture_t t_exit3;
    set_sprite_t s_tuto;
    set_texture_t t_tuto;
    set_sprite_t s_runner;
    set_texture_t t_runner;
    set_sprite_t s_rules;
    set_texture_t t_rules;
    set_sprite_t s_easy;
    set_texture_t t_easy;
    set_sprite_t s_nor;
    set_texture_t t_nor;
    set_sprite_t s_hard;
    set_texture_t t_hard;
    set_sprite_t s_cho;
    set_texture_t t_cho;
    set_sprite_t s_bleu;
    set_texture_t t_bleu;
    set_sprite_t s_whi;
    set_texture_t t_whi;
    set_sprite_t s_tree;
    set_texture_t t_tree;
    set_sprite_t s_tree2;
    set_texture_t t_tree2;
    set_sprite_t s_bush;
    set_texture_t t_bush;
    set_sprite_t s_bush2;
    set_texture_t t_bush2;
    set_sprite_t s_duck;
    set_texture_t t_duck;
    set_sprite_t s_cloud;
    set_texture_t t_cloud;
    set_sprite_t s_dino;
    set_texture_t t_dino;
    set_sprite_t s_grou;
    set_texture_t t_grou;
    set_sprite_t s_score;
    set_texture_t t_score;
    set_sprite_t s_cact1;
    set_texture_t t_cact1;
    set_sprite_t s_cact2;
    set_texture_t t_cact2;
    set_sprite_t s_cact3;
    set_texture_t t_cact3;
    set_sprite_t s_cact4;
    set_texture_t t_cact4;
    set_sprite_t s_loose;
    set_texture_t t_loose;
    set_sprite_t s_win;
    set_texture_t t_win;
    set_sprite_t s_retry;
    set_texture_t t_retry;
    set_sprite_t s_end;
    set_texture_t t_end;
    set_sprite_t s_cake;
    set_texture_t t_cake;
    set_sprite_t s_par;
    set_texture_t t_par;
    set_text_t text;
    set_sound_t sound;
    set_music_t music_game;
    set_clock_t clock;
    set_clock_t clock2;
    int space;
    int frame;
    float seconds;
    float seconds2;
} draw_sprite_t;

typedef struct setup
{
    int score;
    int speed;
    int speed_cac;
    int scene;
    int cactus;
    int cactus2;
    char *buffer_score;
    char *buffer_life;
    int nb_window_y;
    int nb_window_x;
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    sfVector2i posi_mouse;
    sfVector2f posi_sprite;
    sfMouseButton button;
} setup_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str, int size);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_itoa(int nb);
void scene_one(setup_t window, draw_sprite_t my_sprite, int ac, char **av);
void draw(setup_t *window, draw_sprite_t *my_sprite);
void create_my_background(draw_sprite_t *my_sprite);
void create_my_windows(setup_t *window);
void check_event(setup_t *window);
void music_game(draw_sprite_t *music);
void draw_tuto(setup_t *window, draw_sprite_t *my_sprite);
void create_rules_exit(draw_sprite_t *my_sprite);
void click_bottom_exit2(setup_t *window, draw_sprite_t *my_sprite);
void color_exit2(setup_t *window, draw_sprite_t *my_sprite);
void create_my_sprite_start_exit(draw_sprite_t *my_sprite);
void create_my_sprite_tuto(draw_sprite_t *my_sprite);
void click_bottom_start(setup_t *window, draw_sprite_t *my_sprite);
void click_bottom_exit(setup_t *window, draw_sprite_t *my_sprite);
void click_tuto(setup_t *window, draw_sprite_t *my_sprite);
void color_tuto(setup_t *window, draw_sprite_t *my_sprite);
void color_bottom(setup_t *window, draw_sprite_t *my_sprite);
void destroy(setup_t *window, draw_sprite_t *my_sprite);
void input(setup_t *window, draw_sprite_t *my_sprite);
void input2(setup_t *window, draw_sprite_t *my_sprite);
void create_dino(draw_sprite_t *my_sprite);
void create_duck(draw_sprite_t *my_sprite);
void create_bush(draw_sprite_t *my_sprite);
void create_background_game(draw_sprite_t *my_sprite);
void create_choose(draw_sprite_t *my_sprite);
void create_difficulty(draw_sprite_t *my_sprite);
void draw_game(setup_t *window, draw_sprite_t *my_sprite);
void draw_difficulty(setup_t *window, draw_sprite_t *my_sprite);
void click_hard(setup_t *window, draw_sprite_t *my_sprite);
void click_nor(setup_t *window, draw_sprite_t *my_sprite);
void click_easy(setup_t *window, draw_sprite_t *my_sprite);
void create_cactus(draw_sprite_t *my_sprite);
void create_sound(draw_sprite_t *sound);
void create_win(draw_sprite_t *my_sprite);
void draw_win(setup_t *window, draw_sprite_t *my_sprite);
void create_loose(draw_sprite_t *my_sprite);
void draw_loose(setup_t *window, draw_sprite_t *my_sprite);
void click_retry(setup_t *window, draw_sprite_t *my_sprite);
void click_exit(setup_t *window, draw_sprite_t *my_sprite);
void color_retry(setup_t *window, draw_sprite_t *my_sprite);
void create_text(draw_sprite_t *my_sprite);
void cactus3(setup_t *window, draw_sprite_t *my_sprite);
void cactus4(setup_t *window, draw_sprite_t *my_sprite);
void cloud(setup_t *window, draw_sprite_t *my_sprite);
void score(setup_t *window, draw_sprite_t *my_sprite);
void cactus(setup_t *window, draw_sprite_t *my_sprite);
void cactus2(setup_t *window, draw_sprite_t *my_sprite);