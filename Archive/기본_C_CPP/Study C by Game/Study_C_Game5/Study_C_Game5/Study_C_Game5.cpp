#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

// 게임 초기화 함수
void Init_Game()
{
	srand(time(NULL));
	printf("Basball Game ver 0.1 by Jun\n");
}

// 0 ~ 9 中 중복 없이 임의의 숫자 3개 받아오기
int IsFind(int com[3], int index)
{
	int re = 0;
	
	for (int i = 0; i < index; ++i)
	{
		if (com[i] == com[index])
		{
			return 1;
		}
	}

	return re;
}

// 0 ~ 9 中 중복 없이 임의의 숫자 3개 받아오기
void Make_Com_Data(int com[3])
{
	for (int i = 0; i < 3; ++i)
	{
		com[i] = rand() % 10;
		if (1 == IsFind(com, i))
		{
			--i;
		}
	}
}

// player 로부터 숫자 3개 받아오기
void Input_Player(int p[3])
{
	printf("0 ~ 9 까지 중복 없이 숫자 3개 입력: ");
	for (int i = 0; i < 3; ++i)
	{
		scanf_s("%d", &p[i]);
	}
}

// 스트라이크와 볼의 수를 계산하고 3 스트라이크면 10회 반복문을 빠져 나간다.
void Check_Score(int com[3], int p[3], int * s, int * b)
{
	int ts = 0;
	int tb = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (p[i] == com[j])
			{
				if (i == j)
				{
					++ts;
				}
				else
				{
					++tb;
				}

				break;
			}
		}
	}

	*s = ts;
	*b = tb;
}

// 3스트라이크면 승리 그렇지 않으면 패배
// 개임 재시작 할지 체크
int Check_Next_Game()
{
	int go;
	int re = 0;
	
	printf("end: -1, else: continue game ");
	scanf_s("%d", &go);

	if (-1 == go)
	{
		re = -1;
	}
	
	return re;
}

int main()
{
	int com[3];
	int p[3];

	int s;
	int b;
	
	Init_Game();

	while (1)
	{
		Make_Com_Data(com);
		for (int i = 0; i < 10; ++i)
		{
			b = 0;
			s = 0;

			Input_Player(p);
			Check_Score(com, p, &s, &b);
			
			if (3 == s)
			{
				break;
			}
			else
			{
				printf("strike: %d, ball: %d\n", s, b);
			}
			
			if (3 == s)
			{
				printf("3 STRIKE!! You Win !!... \n");
			}
			else
			{
				printf("You Lose.. \n");
				printf("com => %d %d %d \n", com[0], com[1], com[2]);
			}

			if (-1 == Check_Next_Game())
			{
				printf("Thank You! ... \n");
				
				for (int i=0; i<10; ++i)
				{
					printf("Game is finished... after %ds\n", 10-i);
					Sleep(1000);
				}
				break;
			}
		}
	}


	return 0;
}