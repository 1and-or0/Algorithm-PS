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

	printf("원본 데이터: ");
	fprintArray(a, 10);


	fp = fopen("이진파일.bin", "w");
	if (fp != NULL)
	{
		fwrite(a, sizeof(int), 10, fp);
		fclose(fp);
	}

	fp = fopen("이진파일.bin", "r");
	if (fp != NULL)
	{
		fread(b, sizeof(int), 10,     fp);
		printf("이진파일: ");
		fprintArray(b, 10);
		fclose(fp);
	}

	return 0;
}