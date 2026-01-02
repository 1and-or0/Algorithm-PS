#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "Cmp_.h"

int main()
{
	wchar_t str1[10] = L"abc";
	wchar_t str2[10] = L"abc";
	int y1 = Cmp_(str1, str2);
	int y1_ = Cmp_(L"abc", L"abc");

	wchar_t str3[10] = L"cbc";
	wchar_t str4[10] = L"abc";
	int y2 = Cmp_(str3, str4);
	int y2_ = Cmp_(L"cbc", L"abc");

	wchar_t str5[10] = L"abc";
	wchar_t str6[10] = L"cbc";
	int y3 = Cmp_(str5, str6);
	int y3_ = Cmp_(L"abc", L"cbc");

	wchar_t str7[10] = L"aba";
	wchar_t str8[10] = L"abc";
	int y4 = Cmp_(str7, str8);
	int y4_ = Cmp_(L"aba", L"abc");

	wchar_t str9[10] = L"abc";
	wchar_t str10[10] = L"aba";
	int y5 = Cmp_(str9, str10);
	int y5_ = Cmp_(L"abc", L"aba");

	wchar_t str11[10] = L"abca";
	wchar_t str12[10] = L"abc";
	int y6 = Cmp_(str11, str12);
	int y6_ = Cmp_(L"abca", L"abc");

	wchar_t str13[10] = L"abc";
	wchar_t str14[10] = L"abca";
	int y7 = Cmp_(str13, str14);
	int y7_ = Cmp_(L"abc", L"abca");

	wchar_t str15[10] = L"abc";
	wchar_t str16[10] = L"accd";
	int y8 = Cmp_(str15, str16);
	int y8_ = Cmp_(L"abc", L"accd");


	return 0;
}