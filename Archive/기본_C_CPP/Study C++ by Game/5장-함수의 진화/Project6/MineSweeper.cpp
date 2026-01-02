#include "MineSweeper.h"

#define DIM 9

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };

static int MineMapLabel[DIM][DIM]; // 0 ~ 8, 9(= Bomb)
static int MineMapMask[DIM][DIM]; // Hide, Open, Flag

static int nx = DIM, ny = DIM;
static int nBomb = DIM;

// 여러 가지 작은 함수들
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }

inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; } // isValid 검사 후 폭탄이 있으면 true, 없으면 false 반환
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; } // isValid 검사 후 비어있으면 true, 아니면 false 반환

static void dig(int x, int y)
{
	if (isValid(x, y) && mask(x, y) != Open)
	{
		mask(x, y) = Open;
		if (label(x, y) == 0)
		{
			dig(x - 1, y - 1);
			dig(x - 1, y);
			dig(x - 1, y + 1);
			dig(x, y + 1);
			dig(x, y - 1);
			dig(x + 1, y - 1);
			dig(x + 1, y);
			dig(x + 1, y + 1);
		}
	}
}

static void mark(int x, int y)
{
	if (isValid(x, y) && mask(x, y) == Hide)
	{
		mask(x, y) = Flag;
	}
}

static int getBombCount()
{
	int count = 0;
	for (int y = 0; y < ny; ++ y)
	{
		for (int x = 0; x < nx; ++x)
		{
			if (mask(x, y) == Flag)
			{
				++count;
			}
		}
	}
	return count;
}

static void print()
{
	system("cls");
	printf(" 발견: %2d, 전체: %2d\n", getBombCount(), nBomb);
	printf("   ①②③④⑤⑥⑦⑧⑨\n");

	for (int y = 0; y < ny; ++y)
	{
		printf("%2c ", 'A' + y);
		for (int x = 0; x < nx; ++x)
		{
			if (mask(x, y) == Hide) // 파지 않은 곳
				printf("■");
			else if (mask(x, y) == Flag) // 지뢰 예상 자리(깃발 꽂은 곳)
				printf("¤");
			else // 판(dig) 자리
			{
				if (isBomb(x, y)) // (MapLabel) 9: 폭발   
					printf("※");
				else if (isEmpty(x, y)) // (MapLabel) 0: 빈칸 표시
					printf("  ");
				else
					printf("%2d", label(x, y)); // (MapLabel) 1 ~ 8: 숫자 표시
			}
		}
		printf("\n");
	}
}

// 인접한 지뢰의 수 계산 함수
static int countNbrBombs(int x, int y)
{
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; ++yy)
	{
		for (int xx = x - 1; xx <= x + 1; ++xx)
		{
			if (isValid(xx, yy) && label(xx, yy) == Bomb)
			{
				++count;
			}
		}
	}
	return count;
}

static void init(int total = 9)
{
	srand((unsigned int)time(NULL));
	
	// 지뢰 맵, 마스크 맵 초기화
	for (int y = 0; y < ny; ++y)
	{
		for (int x = 0; x < nx; ++x)
		{
			mask(x, y) = Hide;
			label(x, y) = 0;
		}
	}

	nBomb = total;
	// 지뢰 매설
	for (int i = 0; i < nBomb; ++i)
	{
		int x, y;
		do {
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y) != Empty);
		label(x, y) = Bomb;
	}

	// 인접한 지뢰의 수 계산
	for (int y = 0; y < ny; ++y)
	{
		for (int x = 0; x < nx; ++x)
		{
			if (label(x, y) == Empty)
				label(x, y) = countNbrBombs(x, y);
		}
	}
}

// 키보드 좌표 입력 함수
static bool getPos(int& x, int& y)
{
	printf("\n지뢰(P) 행(A-I) 열(1-9)\n 입력 --> ");

	bool isBomb = false;
	y = toupper(_getch()) - 'A';    // 'a' -> 'A'   'A' --> 0

	// 깃발 꽂기 위해 P가 눌린 경우
	if (y == 'P' - 'A') 
	{
		isBomb = true;
		y = toupper(_getche()) - 'A';    // 'a' -> 'A'   'A' --> 0
	}

	x = _getch() - '1';    // '1' --> 1
	return isBomb;
}

// 게임 종료 검사 함수
static int checkDone()
{
	int count = 0;
	for (int y = 0; y < ny; ++y)
	{
		for (int x = 0; x < nx; ++x)
		{
			if (mask(x, y) != Open)
				++count;
			else if (isBomb(x, y))
				return -1;
		}
	}
	return (count == nBomb) ? 1 : 0;
}

// 지뢰 찾기 주 함수
void playMineSweeper(int total)
{
	int x, y, status;

	init(total); // 지뢰 맵과 마스크 초기화
	
	do {
		print();

		bool isBomb = getPos(x, y); // 위치 입력
		if (isBomb) // 깃발 위치이면 ==> mark() 호출
			mark(x, y); 
		else  // 아니면 ==> dig() 호출
			dig(x, y);
		status = checkDone(); // 게임 종료 상황 검사
	} while (status == 0);
	print();
	if (status < 0)
	{
		printf("\n실패: 지뢰 폭발!!!\n");
	}
	else
	{
		printf("\n성공: 탐색 성공!!!\n\n");
	}
}