#include "battle_sys.h"
#include "graphic.h"

int main()
{
	int n;
	srand(time(NULL));
	screen_init();
	ShowCursor(0);
	while (1)
	{
		title_draw();
		n = menu_draw();
		if (n == game_info)
		{
			game_explain();
		}
		else if (n == game_start)
		{
			n = select_level();
			battle(n);
		}
		
	}

	return 0;
}