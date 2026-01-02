#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 두 수를 입력받음
void Input_Data(int * a, int * b)
{
	printf("두 수(a, b) 입력: ");
	scanf_s("%d %d", a, b);
}

// 두 수의 사칙연산을 계산함
void Cal_Data(int a, int b, int * c, int * d, int * e, int * f)
{
	*c = a + b;
	*d = a - b;
	*e = a * b;
	*f = a / b;
}

// 사칙 연산 결과를 출력함
void Print_Data(int a, int b, int c, int d, int e, int f)
{
	printf("%d + %d = %d\n", a, b, c);
	printf("%d - %d = %d\n", a, b, d);
	printf("%d * %d = %d\n", a, b, e);
	printf("%d / %d = %d\n", a, b, f);
}




// 각 과목에 임의의 점수를 저장함
void Get_grade(int kor[10], int eng[10], int math[10])
{
	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		kor[i] = rand() % 101;
		eng[i] = rand() % 101;
		math[i] = rand() % 101;
	}
}

// 총점과, 평균을 구함
void Total_Avr(int total[10], float avr[10], int kor[10], int eng[10], int math[10])
{
	for (int i = 0; i < 10; ++i)
	{
		total[i] = kor[i] + eng[i] + math[i];
		avr[i] = total[i] / 3.0f;
	}
}

// 1등한 학생의 번호를 구함
void find_num_1(int * max, int total[10])
{
	*max = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (total[*max] < total[i])
		{
			*max = i;
		}
	}

}

// 1등한 학생의 성적을 출력함
void Print_Grade(int max_index, int kor[10], int eng[10], int math[10], int total[10])
{
	printf("학생 번호: %d, <성적> 국어: %d, 영어: %d, 수학: %d, 총점: %d", max_index, kor[max_index],
			eng[max_index], math[max_index], total[max_index]);
}



// 배열에 중복되지 않게 임의의 숫자를 저장한다
void Get_Nums(int data[6], int len)
{
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
	{
		data[i] = (rand() % 46) + 1;
		for (int j = 0; j < i; ++j)
		{
			if (data[i] == data[j])
			{
				--i;
				break;
			}
		}
	}
}

// 배열을 출력한다
void Show_nums(int data[6], int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d\t", data[i]);
	}
	printf("\n");
}

int main()
{

	//int a;
	//int b;

	//int c;
	//int d;
	//int e;
	//int f;

	//Input_Data(&a, &b);

	//Cal_Data(a, b, &c, &d, &e, &f);

	//Print_Data(a, b, c, d, e, f);


	//-----------------------


	int max_index;
	
	int kor[10];
	int eng[10];
	int math[10];

	int total[10];
	float avr[10];


	Get_grade(kor, eng, math);

	Total_Avr(total, avr, kor, eng, math);

	find_num_1(&max_index, total);

	Print_Grade(max_index, kor, eng, math, total);


	printf("\n");
	// -----------------------


	int data[6];

	int len_data = sizeof(data) / sizeof(int);

	Get_Nums(data, len_data);

	Show_nums(data, len_data);

	return 0;
}