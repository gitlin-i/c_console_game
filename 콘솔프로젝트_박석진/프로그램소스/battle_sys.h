#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <stdlib.h>
#include <winuser.h>
#pragma comment(lib,"winmm.lib")

enum input
{
	up = 72,//H
	down = 80,//P
	left = 75,//K
	right = 77,//M 
	enter = 13,
	space = 32,
	game_start = 1,
	game_info = 2,
	easy = 1,
	normal = 2,
	hard = 3,
	attack = 90
};
typedef struct _enemy {
	int HP;
	int load_bullet; //최대 장전 가능한 총알 수
	int loaded_bullet; // 현재 장전된 총알 수
	int effective_time; //유효 판정 시간
}enemy;
typedef struct _player {
	int HP;
	int power; 
	int possible_attack; // 방어 성공으로 획득한 공격 수 
}player;
typedef struct _judge
{
	clock_t shoot_time;
	clock_t player_action_time;
	int succes;
	int attack_sucess;
	
}judge;
enemy enemy_level(int x);
player player_set(int x);
void gotoxy(int x, int y);
double random_second(double i, double j);
int sec_to_milli(double sec);
void cut_call();
void cut(judge * judgment);
void reload_call(int milli_sec);
void reload(enemy * a);
void shoot_call(int milli_sec);
void shoot(judge * judgment , enemy * outlaw);
void judgment_init(judge * judgment);
void judgment_success(judge * judgment,player * warrior);
void attack_f(enemy * outlaw, player * warrior);
void screen_init();
int controller();
int game_controller();
void battle(int n);
void result_print(enemy * outlaw, player * warrior);
void game_explain();
void title_draw();
int menu_draw();
int select_level();