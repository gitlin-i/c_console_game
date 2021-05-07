#include "graphic.h"



void basic(int x,int y)
{//24*9
	gotoxy(x, y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
	printf("                       ");
	gotoxy(x, ++y);
}
void erase_pic(int x, int y, int size_x,int size_y)
{
	int a = x;
	int b = y;
	for (int i = 0; i < size_y; i++)
	{
		gotoxy(a, b);
		for (int j = 0; j<size_x; j++)
		{
			
			printf(" ");
			a++;
		}
		a = x;
		b++;
	}
}
void draw_ground(int x,int y)
{
	gotoxy(x, y);
	for (int i = 0; i < 95; i++)
	{
		printf("=");
	}
}
void draw_sun(int x,int y)
{
	gotoxy(x,y);
	printf("     |   |    |   |");
	gotoxy(x, ++y);
	printf(" |    |  |    |  |    |");
	gotoxy(x, ++y);
	printf("   |    @@@@@@@@    |");
	gotoxy(x, ++y);
	printf("    | @@@@@@@@@@@@ |");
	gotoxy(x, ++y);
	printf(" |   @@@@@@@@@@@@@@  |");
	gotoxy(x, ++y);
	//printf("   | @@@@@@@@@@@@@@|");
	//gotoxy(x, ++y);

}
void draw_player(int x, int y)
{
	gotoxy(x, y);
	printf("       ##              ");
	gotoxy(x, ++y);
	printf("      #  #             ");
	gotoxy(x, ++y);
	printf("       ##              ");
	gotoxy(x, ++y);
	printf("      # #              ");
	gotoxy(x, ++y);
	printf("     ####-|ㅡㅡㅡㅡㅡㅡ");
	gotoxy(x, ++y);
	printf("     /# #              ");
	gotoxy(x, ++y);
	printf("   / #  #              ");
	gotoxy(x, ++y);
	printf(" /  #####              ");
	gotoxy(x, ++y);
	printf("     ## ##             ");
	gotoxy(x, ++y);
}
void draw_player2(int x, int y)
{
	gotoxy(x, y);
	printf("       ##         /    ");
	gotoxy(x, ++y);
	printf("      #  #     /     ) ");
	gotoxy(x, ++y);
	printf("       ##    /      )  ");
	gotoxy(x, ++y);
	printf("      # #  +      )    ");
	gotoxy(x, ++y);
	printf("     ####/             ");
	gotoxy(x, ++y);
	printf("     /# #              ");
	gotoxy(x, ++y);
	printf("   / #  #              ");
	gotoxy(x, ++y);
	printf(" /  #####              ");
	gotoxy(x, ++y);
	printf("     ## ##             ");
	gotoxy(x, ++y);
}
void ani_player_action(int x, int y)
{
	draw_player(x, y);
	Sleep(100);
	draw_player2(x, y);
	Sleep(200);
	draw_player(x, y);
}
void draw_enemy(int x, int y)
{
	gotoxy(x, y);
	printf("                   @@@ ");
	gotoxy(x, ++y);
	printf("                  @@@@@");
	gotoxy(x, ++y);
	printf("                   @ @ ");
	gotoxy(x, ++y);
	printf("                   @@@ ");
	gotoxy(x, ++y);
	printf("           @@@@@  @@@@@");
	gotoxy(x, ++y);
	printf("               @@@@   @");
	gotoxy(x, ++y);
	printf("                  @@@@@");
	gotoxy(x, ++y);
	printf("                  @@ @@");
	gotoxy(x, ++y);
	printf("                 @@  @@");
	gotoxy(x, ++y);
}
void draw_enemy2(int x, int y)
{
	gotoxy(x, y);
	printf("                   @@@ ");
	gotoxy(x, ++y);
	printf("                  @@@@@");
	gotoxy(x, ++y);
	printf("      \\            @ @ ");
	gotoxy(x, ++y);
	printf("        \\          @@@ ");
	gotoxy(x, ++y);
	printf(" <==       @@@@@  @@@@@");
	gotoxy(x, ++y);
	printf("        \\      @@@@   @");
	gotoxy(x, ++y);
	printf("      \\           @@@@@");
	gotoxy(x, ++y);
	printf("                  @@ @@");
	gotoxy(x, ++y);
	printf("                 @@  @@");
	gotoxy(x, ++y);
}
void ani_enemy_action(int x, int y)
{
	draw_enemy2(x, y);
	Sleep(200);
	draw_enemy(x, y);
}
void ani_enemy_hurt(int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		draw_enemy(x, y);
		Sleep(100);
		basic(x, y);
		Sleep(100);
		draw_enemy(x, y);
	}
	
}
void ani_player_hurt(int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		draw_player(x, y);
		Sleep(100);
		basic(x, y);
		Sleep(100);
		draw_player(x, y);
	}

}
void ani_cut_effect(int x, int y)
{
	draw_cut_effect(x, y);
	Sleep(200);
	erase_pic(x, y, 19, 8);
	draw_sun(sun_x, sun_y);
}
void ani_move_attack(int x, int y)
{
	int a = x;
	int b = y;
	while (a < 75)
	{
		draw_attack(a, b);
		Sleep(100);
		erase_pic(a, b, 14, 7);
		a += 10;
		draw_background();
	}
	ani_enemy_hurt(enemy_x,enemy_y);
}
void draw_dust(int x, int y)
{
	gotoxy(x, y);
	printf("   ..  \".\'\'.  \"..\'  .. ");
	gotoxy(x, ++y);
	printf("    \'   \" .  . \'  \"    ");
	gotoxy(x, ++y);
	printf("   \" ..  \"   .    \'    ");
	gotoxy(x, ++y);
	printf("       ...  \'  .   ..  ");
	gotoxy(x, ++y);
	printf("     \"  \'  .. \"  .\' ...");
	gotoxy(x, ++y);
	
}

void draw_cactus(int x, int y)
{
	gotoxy(x, y);
	printf("  _----_");
	gotoxy(x, ++y);
	printf(" -l   = l=");
	gotoxy(x, ++y);
	printf(" =l =   l-");
	gotoxy(x, ++y);
	printf(" =l   = l- ");
	gotoxy(x, ++y);
	printf(" -l  =  l=");
	gotoxy(x, ++y);
	printf("  l    =l");
	gotoxy(x, ++y);
}

void draw_status(int a,int b,int x, int y)
{
	gotoxy(x, y);
	printf("HP : %d     ", a);
	gotoxy(x, y + 1);
	printf("공격 가능 횟수 : %d", b);
}
void draw_cut_effect(int x,int y)
{//19*8?
	gotoxy(x, y);
	printf(">>        /  .  .");
	gotoxy(x, ++y);
	printf(" >>    \'  . /");
	gotoxy(x, ++y);
	printf("  >>    \" #  . \" ");
	gotoxy(x, ++y);
	printf("   >>       \"  .");
	gotoxy(x, ++y);
	printf("   >>       #   \' ");
	gotoxy(x, ++y);
	printf("  >>  \'  .  \\   | ");
	gotoxy(x, ++y);
	printf(" >>       \'   . | ");
	gotoxy(x, ++y);
	printf(">>            \\  ");
	gotoxy(x, ++y);

}
void draw_attack(int x, int y)
{
//14*7
	gotoxy(x, y);
	printf(">>   ");
	gotoxy(x, ++y);
	printf("  >>  ");
	gotoxy(x, ++y);
	printf("    >> ");
	gotoxy(x, ++y);
	printf("      >> ");
	gotoxy(x, ++y);
	printf("    >>  ");
	gotoxy(x, ++y);
	printf("  >> ");
	gotoxy(x, ++y);
	printf(">>");
	
	
}
void draw_background()
{//95,32//기준점
	draw_ground(ground_x, ground_y);
	draw_sun(sun_x, sun_y);
	draw_player(player_x, player_y);
	draw_enemy(enemy_x, enemy_y);
}
