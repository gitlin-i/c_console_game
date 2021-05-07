#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "battle_sys.h"
enum draw_point
{
	enemy_x = 70,
	enemy_y = 7,
	player_x = 0,
	player_y = 7,
	ground_x = 0,
	ground_y = 16,
	sun_x = 33,
	sun_y = 11,
	player_status_x = 0,
	player_status_y = 17,
	enemy_status_x = 74,
	enemy_status_y = 17,
	cut_effect_x = 25,
	cut_effect_y = 7,
	attack_x = 25,
	attack_y = 7,
	result_print_x =33,
	result_print_y =20
};

void basic(int x, int y);
void draw_ground(int x, int y);
void draw_sun(int x, int y);
void draw_player(int x, int y);
void draw_player2(int x, int y);
void ani_player_action(int x, int y);
void draw_enemy(int x, int y);
void draw_enemy2(int x, int y);
void ani_enemy_action(int x, int y);
void ani_enemy_hurt(int x, int y);
void ani_player_hurt(int x, int y);
void ani_cut_effect(int x, int y);
void ani_move_attack(int x, int y);
void draw_dust(int x, int y);
void erase_pic(int x, int y, int size_x, int size_y);
void draw_cactus(int x, int y);
void draw_attack(int x, int y);
void draw_status(int a, int b,int x, int y);
void draw_cut_effect(int x, int y);
void draw_background();