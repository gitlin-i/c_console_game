#include "battle_sys.h"
#include "graphic.h"

enemy enemy_level(int x)
{
	switch (x)
	{
		case 1:
		{
			enemy a = { 1,1,0 ,800};
			return a;
		}
		
		case 2:
		{
			enemy a = { 5,3,0 ,400};
			return a;
		}
		case 3:
		{
			enemy a = { 10,5,0 ,100};
			return a;
		}
	}
}
player player_set(int x)
{
	player a = { 1,x ,0};
	return a;
}
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
double random_second(double i,double j)
{//i초부터 j초까지 랜덤 반환 단위는 초//더블형 ij에 드는 정수를 반환
	//seed 초기화 함수를 밖에서 선언해야 함. 이 함수 내부에서 선언하면 함수를 호출하는 seed 시간 값이 일정해짐.
	while (1)
	{
		double sec = rand() % 10;
		double milli_sec = (double)(rand() % 1000) / 1000;
		if (sec + milli_sec >= i && sec + milli_sec <= j)
			return sec + milli_sec;
	}
}
int sec_to_milli(double sec)
{
	return (int)(sec * 1000);
}

void cut_call()
{
	PlaySound(TEXT("cut.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void cut(judge * judgment)
{
	ani_player_action(player_x, player_y);
	judgment->player_action_time = clock();
	judgment->succes = 1;
}
void reload_call(int milli_sec)
{
	Sleep(milli_sec);
	PlaySound(TEXT("reload.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void reload(enemy * outlaw)
{
	if (outlaw->loaded_bullet == 0)
	{
		for (int i = rand() % outlaw->load_bullet +1 ; i > 0; i--)// 범위내 랜덤 장전.
		{
			reload_call(sec_to_milli(random_second(1, 7)));
			outlaw->loaded_bullet += 1;
			draw_status(outlaw->HP, outlaw->loaded_bullet, enemy_status_x, enemy_status_y);
		}
	}
}
void shoot_call(int milli_sec)
{
	Sleep(milli_sec);
	PlaySound(TEXT("shoot.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void shoot(judge * judgment,enemy * outlaw)
{
	if (outlaw->loaded_bullet > 0) 
	{
		shoot_call(sec_to_milli(random_second(0.5, 1.5)));
		ani_enemy_action(enemy_x, enemy_y);
		outlaw->loaded_bullet--;
		judgment->shoot_time = clock();
		draw_status(outlaw->HP, outlaw->loaded_bullet, enemy_status_x, enemy_status_y);
	}
	
}
void attack_call()
{
	PlaySound(TEXT("attack.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void attack_f(enemy * outlaw ,player * warrior)
{
	while (warrior->possible_attack > 0 && outlaw->loaded_bullet == 0)
	{
		attack_call();
		ani_player_action(player_x, player_y);
		ani_move_attack(attack_x, attack_y);
		outlaw->HP -= 1;
		warrior->possible_attack -= 1;
		draw_status(warrior->HP, warrior->possible_attack,player_status_x, player_status_y);
		draw_status(outlaw->HP, outlaw->loaded_bullet, enemy_status_x, enemy_status_y);
		if (outlaw->HP == 0) break;
	}
}
void judgment_init(judge * judgment)
{
	judgment->player_action_time = 0;
	judgment->shoot_time = 0;
	judgment->succes = 0;
	judgment->attack_sucess = 0;
}
void judgment_success(judge * judgment,player * warrior)
{
	cut_call();
	ani_cut_effect(cut_effect_x, cut_effect_y);
	if (rand() % 2 == 0)
	{
		warrior->possible_attack += 1;
		draw_status(warrior->HP, warrior->possible_attack, player_status_x, player_status_y);

	}
	judgment_init(&judgment);
}
int select_level()
{
	
	const int x_s = 40, y_s = 11;
	int x = x_s;
	int y = y_s;
	system("cls");
	gotoxy(40, 10);
	printf("난 이 도 선 택");
	gotoxy(x,y);
	printf("  > 쉬움");
	gotoxy(x, ++y);
	printf("    보통");
	gotoxy(x, ++y);
	printf("    어려움");
	y = 11;
	gotoxy(x, y);
	while (1)
	{
		int select = controller();
		switch (select)
		{
		case up:
			if (y > y_s)
			{
				gotoxy(x, y);
				printf("    ");
				gotoxy(x, --y);
				printf("  > ");
			}
			break;
		case down:
			if (y < y_s + 3)
			{
				gotoxy(x, y);
				printf("    ");
				gotoxy(x, ++y);
				printf("  > ");
			}
			break;
		case enter:
			if (y == 11)
			{
				return easy;
			}
			else if (y == 12)
			{
				return normal;
			}
			else if (y == 13)
			{
				return hard;
			}
		}
	}

}

void screen_init()
{
	system("mode con cols=95 lines=32 | title game");
	HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO consolecursor;
	consolecursor.bVisible = 0;
	consolecursor.dwSize = 1;
	SetConsoleCursorInfo(consolehandle, &consolecursor);
	system("cls");
}
int controller()
{
	char temp;
	if (_kbhit())
	{
		temp = _getch();
		if (temp == -32)// char형에 224가 입력된 경우
		{
			temp = _getch();
			switch (temp)
			{
			case left:
				return left;
			case right:
				return right;
			case up:
				return up;
			case down:
				return down;
			}
		}
		else if (temp == 'w' || temp == 'W')
		{
			return up;
		}
		else if (temp == 's' || temp == 'S')
		{
			return down;
		}
		else if (temp == 'a' || temp == 'A')
		{
			return left;
		}
		else if (temp == 'd' || temp == 'D')
		{
			return right;
		}
		else if (temp == enter)
		{
			return enter;
		}
		else if (temp == space)
		{
			return space;
		}
		else if (temp == 'z' || temp == 'Z')
		{
			return attack;
		}
		return (int)temp;
	}
}
int game_controller()//항
{
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		return space;
	}
	if (GetAsyncKeyState(VK_CONTROL) & 0x8000)
	{
		return attack;
	}
	
	if (GetAsyncKeyState('W') & 0x8000)
	{
		return up;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		return up;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		return left;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		return left;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		return down;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		return down;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		return right;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		return right;
	}
	if ((GetAsyncKeyState(VK_RETURN) & 0x8000))
	{
		return enter;
	}
	
}


void battle(int n)//전투 시스템
{
	system("cls");
	enemy outlaw= enemy_level(n);
	player warrior = player_set(1);
	judge judgment;
	judgment_init(&judgment);
	draw_background();
	draw_status(warrior.HP, warrior.possible_attack, player_status_x, player_status_y);
	draw_status(outlaw.HP, outlaw.loaded_bullet, enemy_status_x, enemy_status_y);
	int value = 0;
	clock_t lastTime = 0;

	while (outlaw.HP > 0 && warrior.HP > 0)
	{
		attack_f(&outlaw, &warrior);
		if (outlaw.HP == 0) break;
		reload(&outlaw);
		shoot(&judgment, &outlaw);
		
		lastTime = clock();
		while ((lastTime - judgment.shoot_time) < outlaw.effective_time) {
			value = game_controller();
			if (value == space) {
  				cut(&judgment);
				judgment_success(&judgment, &warrior);
			}
			lastTime = clock();
		}
		if (!judgment.succes) {
			ani_player_hurt(player_x, player_y);
			warrior.HP--;
			draw_status(warrior.HP, warrior.possible_attack, player_status_x, player_status_y);
		}
		judgment_init(&judgment);
	}
	result_print(&outlaw, &warrior);
		return;
}
void result_print(enemy * outlaw, player * warrior)
{
	gotoxy(result_print_x, result_print_y);
	printf("%s가 승리하였습니다.", (outlaw->HP > warrior->HP) ? "무법자" : "플레이어");
	gotoxy(result_print_x-5, result_print_y+2);
	printf("Enter를 누르면 메뉴화면으로 돌아갑니다.");
	while (1)
	{
		if (controller() == enter) return;
	}
	
}
void game_explain()
{
	system("cls");
	printf("\n\n\n\n");
	printf("                                   [ 조 작 법 ]\n");//                                       ");
	printf("\n");//                                                                                              ");
	printf("                        Space bar : 방어\n");//                                                     ");
	printf("\n");//                                                                                              ");
	printf("                        무법자가 당신을 노립니다. 사격음에 빠르게 반응하세요.\n");//                                ");
	printf("                        방어에 성공하면 일정 확률로 공격을 합니다.\n");//                                              ");
	printf("                        등장하는 적을 물리치세요.\n");//                                                     ");
	printf("                        난이도에 따라 무법자의 체력,최대 공격 수, 판정이 바뀝니다.\n");
	printf("\n");//                                                                                              ");
	printf("\n");//                                                                                              ");
	while (1)
	{
		if (controller() == enter) return;
	}
}
void title_draw()
{
	system("cls");
	printf("\n\n\n\n");
	printf("       ####                ###### #                                                          \n");
	printf("      #    #                  #   #      ##           #              # #     ##              \n");
	printf("     #                #       #   # #  ##  ##         #              # #   ##  ##    #       \n");
	printf("     #       #   #  #####     #   ## # ######         #####  #   #   # #   ######  #####     \n");
	printf("      #    # #   #    #       #   #  # #              #    # #   #   # #   #         #       \n");
	printf("       ####   ### #   ###     #   #  #  ####          #####   ### #  # #    #####    ###     \n");
	printf("=============================================================================================\n");
}

int menu_draw()
{
	const int x_s = 40;
	const int y_s = 11;//기준점
	int x = x_s;
	int y = y_s;
	gotoxy(x, y);
	printf("  > 게임시작");//y11
	gotoxy(x, ++y);
	printf("    게임방법");//y12
	gotoxy(x, ++y);
	printf("    종료");//y13
	y = 11;
	gotoxy(x, y);
	while (1)
	{
		int select = controller();
		
		switch (select)
		{
		case up:
			if (y > y_s)
			{
				gotoxy(x, y);
				printf("    ");
				gotoxy(x, --y);
				printf("  > ");
			}
			break;
		case down:
			if (y < y_s + 2)
			{
				gotoxy(x, y);
				printf("    ");
				gotoxy(x, ++y);
				printf("  > ");
			}
			break;
		case enter:
			if (y == 13)
				exit(0);
			else if (y == 11)
			{
				return game_start;
			}
			else if (y == 12)
			{
				return game_info;
			}
		}
	}

}
