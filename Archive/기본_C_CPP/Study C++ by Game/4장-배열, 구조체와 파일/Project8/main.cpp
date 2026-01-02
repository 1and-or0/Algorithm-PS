 #define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stdio.h>
#include <cstdlib>


void fprintArray(int a[], int len, FILE* fp = stdout)
{
	for (int i = 0; i < len; ++i)
	{
		fprintf(fp, "%d ", a[i]);
	}
	fprintf(fp, "\n");
}

int main()
{
	FILE* fp;
	int a[10], b[10];

	for (int i = 0; i < 10; ++i)
	{
		a[i] = rand();
	}

	printf(" 원본 데이터: ");
	fprintArray(a, 10);
	

	fp = fopen("아스키파일.txt", "w"); // 자료형: FILE * , 파일의 포인터를 반환, 파일 열기 실패시 NULL 반환, 
	if (fp != NULL)
	{
		fprintArray(a, 10, fp);
		fclose(fp);
	}

	fp = fopen("아스키파일.txt", "r");
	if (fp != NULL)
	{
		for (int i = 0; i < 10; ++i)
		{
			fscanf_s(fp, "%d", &(b[i]));
		}
		printf("아스키 파일: ");
		fprintArray(b, 10);
		fclose(fp);
	}

	return 0;
}