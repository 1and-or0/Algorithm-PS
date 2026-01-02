#include "MonsterWorld.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);
	Monster m1("¸ó½ºÅÍ", "¡Ø", rand() % w, rand() % h);

	game.add(m1);

	// string name[6] = { "µµ±úºñ", "¡×", "´Á´ë", "§Ñ", "¿©¿ì", "£À" };
	Monster m2("µµ±úºñ", "¡×", rand() % w, rand() % h);
	Monster m3("´Á´ë", "§Ñ", rand() % w, rand() % h);
	Monster m4("¿©¿ì", "£À", rand() % w, rand() % h);
	game.add(m2);
	game.add(m3);
	game.add(m4);
	// game.add(Monster("µµ±úºñ", "¡×", rand() % w, rand() % h));
	// game.add(Monster("´Á´ë", "§Ñ", rand() % w, rand() % h));
	// game.add(Monster("¿©¿ì", "£À", rand() % w, rand() % h));



	game.play(500, 10);
	printf("----------°ÔÀÓ Á¾·á----------\n");

	return 0;
}