#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>

using namespace std;

class Hangman 
{
	string progress[64];  // 행맨 진행 상태 출력 글림
	string problem;   // 문제 단어
	string answer;  // 현재 진행 중인 단어

	string guessed; // 전체 알파벳의 현재까지 예측 상황
	int nTries;   // 현재까지 틀린 횟수
	const int maxTries = 7; // 최대 허용 시도 횟수 제한

	void load(const char* fileName = "HangmanProgress.txt")
	{
		ifstream fs(fileName);
		if (fs)
		{
			getline(fs, progress[0]);  // 첫 번째 행은 주석 가져오기 from 파일(.txt)
			for (int i = 0; i < 64; ++i)
			{
				getline(fs, progress[i]);
			}
		}
	}

	void print()
	{
		system("cls");
		cout << " <Hangman Game>\n";

		for (int i = 0; i < 8; ++i)
		{
			cout << '\t' << progress[nTries * 8 + i] << endl;
		}
		cout << "\n\t" << answer;
		cout << "\n\n" << guessed;
	}

	int countMatched(char ch)
	{
		int nMatched = 0;
		for (int pos = -1; ; )
		{
			pos = problem.find(ch, pos + 1);
			if (pos < 0)
			{
				break;
			}
			answer[pos] = ch;  // 현재 단어를 갱신 (맞힌 문자 열기)
			++nMatched;
		}
		return nMatched;
	}

	void guess()
	{
		char ch = _getch();
		if (ch >= 'a' && ch <= 'z')
		{
			int pos = guessed.find(ch);
			if (pos < 0)
			{
				guessed[ch - 'a'] = ch;
				if (countMatched(ch) == 0)
				{
					++nTries;
				}
			}
		}
	}

public:
	void play(string prob)
	{
		load();
		problem = prob;
		answer = string(problem.length(), '-');
		guessed = string(26, '.');
		nTries = 0;
		while (nTries < maxTries && answer != problem)
		{
			print();
			guess();
		}
		print();
		cout << "\n\t" << ((nTries == maxTries) ? "실패" : "정답") << endl;
	}
};