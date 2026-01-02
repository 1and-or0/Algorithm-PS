#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

#define rock 1
#define paper 2
#define scissors 3

#define Lose 7
#define Win 9
#define Draw 5

#define end_game  -1
#define running  1

// 데이터 초기화
void My_Init(int * num_F, int * num_W, int * num_D)
{
	*num_F = 0;
	*num_W = 0;
	*num_D = 0;
	srand(time(NULL));
}

// 1 ~ 3 무작위 숫자를 반환
int Get_PC_hand()
{
	return rand() % 3 + 1;
}

// USER의 선택 (가위, 바위, 보 中) 
int Get_USER_hand()
{
	int user_hand;
	printf("종료: -1, rock(바위): 1, paper(보): 2, scissors(가위): 3\n");
	printf("선택: ");
	scanf_s("%d", &user_hand);
	while (user_hand != 1 && user_hand != 2 && user_hand != 3 && user_hand != -1)
	{
		printf("잘못된 범위의 입력입니다!\n");
		printf("종료: -1, rock(바위): 1, paper(보): 2, scissors(가위): 3\n");
		printf("선택: ");
		scanf_s("%d", &user_hand);
	}
	return user_hand;
}

// 승, 패, 무승부 확인
int My_Check(int user, int pc)
{
	if (rock == user && scissors == pc)
	{
		return Win;
	}

	if (scissors == user && paper == pc)
	{
		return Win;
	}

	if (paper == user && rock == pc)
	{
		return Win;
	}

	if (user == pc)
	{
		return Draw;
	}

	return Lose;
}

// 전적 출력, 승률 계산, 출력
void Show_W_rate(int num_L, int num_W, int num_D)
{
	float w_rate = (float)num_W / (num_L + num_W) * 100;
	//w_rate  += (float)num_W % (num_L + num_W);

	printf("승률: %.2f%%\n", w_rate);
	printf("무승부: %d 번\n", num_D);
	printf("승: %d 번, 패: %d 번\n", num_W, num_L);
	for (int i = 10; i>-1; --i)
	{
		printf("프로그램이 %d초 뒤에 종료됩니다.\n", i);
		Sleep(1000);
	}
}

int main()
{
	int user;
	int pc;
	
	int outcome;

	int num_D;
	int num_L;
	int num_W;

	My_Init(&num_L, &num_W, &num_D);

	int progress = running;

	while (progress)
	{
		pc = Get_PC_hand();
		user = Get_USER_hand();


		if (end_game == user)
		{
			break;
		}

		outcome = My_Check(user, pc);
		if (Win == outcome)
		{
			++num_W;
			printf("You Win! You: %d, Pc: %d\n", user, pc);
		}
		else if (Draw == outcome)
		{
			++num_D;
			printf("Draw! You: %d, Pc: %d\n", user, pc);
		}
		else
		{
			++num_L;
			printf("You Lose! You: %d, Pc: %d\n", user, pc);
		}

	}

	Show_W_rate(num_L, num_W, num_D);

	return 0;
}