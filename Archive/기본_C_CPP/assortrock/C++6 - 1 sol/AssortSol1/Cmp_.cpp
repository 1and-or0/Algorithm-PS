#include <stdlib.h>
#include "Cmp_.h"

unsigned int len(const wchar_t* str_)
{
	int i = 0;

	while (str_[i] != '\0')
	{
		++i;
	}

	return i;
}

int Cmp_(const wchar_t* str1, const wchar_t* str2)
{
	unsigned int len_str1 = len(str1);
	unsigned int len_str2 = len(str2);
	
	int i = 0;
	//int result = 0;  두 문자열의 길이가 같은 경우
	if (len_str1 == len_str2)
	{
		// str1[i] != str2[i]
		for (int j = 0; j < len_str1; ++j)
		{
			if (str1[i] > str2[i])
			{
				//result = 1;
				return 1;
			}
			else if (str1[i] < str2[i])
			{
				//result = -1;
				return -1;
			}
			++i;
		}
		return 0;
		
	}
	else if (len_str1 > len_str2)  // str1의 길이가 더 긴 경우
	{
		for (int j = 0; j < len_str1; ++j)
		{
			if (str1[i] > str2[i])
			{
				return 1;
			}
			else if (str1[i] < str2[i])
			{
				return -1;
			}
			++i;
		}
		return 1;
	}
	else if (len_str1 < len_str2) // str2의 길이가 더 긴 경우
	{
		for (int j = 0; j < len_str2; ++j)
		{
			if (str1[i] > str2[i])
			{
				//result = 1;
				return 1;
			}
			else if (str1[i] < str2[i])
			{
				//result = -1;
				return -1;
			}
			++i;
		}
		return -1;
	}
}


int Cmp_sol(const wchar_t* str1, const wchar_t* str2)
{
	unsigned int len_str1 = len(str1);
	unsigned int len_str2 = len(str2);

	int iLoop = len_str1;
	int iReturn = 0;
	
	if (len_str1 < len_str2)
	{
		iLoop = len_str1;
		iReturn = -1;
	}
	else if (len_str2 < len_str1)
	{
		iLoop = len_str2;
		iReturn = 1;
	}


	for (int i = 0; i < iLoop; ++i)
	{
		if (str1[i] < str2[i])
		{
			return -1;
		}
		else if (str1[i] > str2[i])
		{
			return 1;
		}
	}

	return iReturn;
}