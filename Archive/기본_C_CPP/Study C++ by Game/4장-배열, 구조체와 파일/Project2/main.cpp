#include <cstdio>
#include <cstring>


void main()
{
	//int A[4][3] = { {1, 2, 3}, {4, 5, 6,}, {7, 8, 9}, {10, 11, 12} };
	//char msg[12] = { 'g', 'a', 'm', 'e' , ' ', 'o' , 'v', 'e', 'r' };
	//char s[12] = "game over";
	//s[10] = '!';

	//printf("%s\n", msg);
	//printf("%s\n", s);
	
	char s1[] = "game", s2[20], s3[20];

	strcpy_s(s2, "over");
	sprintf_s(s3, "s1: %s, s2:%s !", s1, s2);

	printf("strlen(%s) = %d\n", s1, strlen(s1));
	printf("strlen(%s) = %d\n", s2, strlen(s2));
	printf("strlen(%s) = %d\n", s3, strlen(s3));
	
	printf("strcmp(%s, %s) = %d\n", s1, s2, strcmp(s1, s2));
	printf("strcmp(%s, \"game\") = %d\n", s1, strcmp(s1, "game"));

	
	return;
}