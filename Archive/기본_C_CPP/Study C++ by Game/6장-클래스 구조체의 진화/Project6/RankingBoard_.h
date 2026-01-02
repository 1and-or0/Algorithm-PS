#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#define NUM_MVP 5

struct PlayInfo {
	char name[200];
	int nMove;
	double tElapsed;
};

class RankingBoard {
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;

	void init()
	{
		PlayInfo noname = { "C++좋아요python편해요.", 1000, 1000.0 };
		for (int i = 0; i < nMVP; ++i)
		{
			MVP[i] = noname;
		}
	}
public:
	void load(const char* fname)
	{
		FILE* fp = fopen(fname, "r");
		if (fp == NULL)
		{
			init();
		}
		else
		{
			for (int i = 0; i < nMVP; ++i)
			{
				fscanf(fp, " %d %s %lf\n", &MVP[i].nMove, &MVP[i].name, &MVP[i].tElapsed);
			}
			fclose(fp);
		}
	}

	void store(const char* fname)
	{
		FILE* fp = fopen(fname, "w");
		if (fp == NULL)
			return;

		//fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		for (int i = 0; i < nMVP; ++i)
		{
			fprintf(fp, " %4d %-16s %-5.2f\n", MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
		}

		fclose(fp);
	}

	void print()
	{
		for (int i = 0; i < nMVP; ++i)
		{
			printf(" [%2d위] %4d %-16s %5.2f\n", i + 1, MVP[i].nMove,
				MVP[i].name, MVP[i].tElapsed);
		}
	}

	int add(int nMove, double tElap)
	{
		if (nMove < MVP[nMVP - 1].nMove)
		{
			int pos = nMVP - 1;
			for (; pos > 0; --pos)
			{
				if (nMove >= MVP[pos - 1].nMove)
				{
					break;
				}
				MVP[pos] = MVP[pos - 1];
			}
			MVP[pos].nMove = nMove;
			MVP[pos].tElapsed = tElap;
			printf("%d위 입니다. 이름을 입력하세요: ", pos + 1);
			scanf("%s", &MVP[pos].name);
			return pos + 1;
		}
		return 0;
	}
};
