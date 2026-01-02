#include <bits/stdc++.h>
using namespace std;
#define SIZE 8

class pos {
	int x, y;
public:
	pos(const int& xx = 0, const int& yy = 0) : x(xx), y(yy) { }

	bool operator==(const pos& a);
	
	void SetPos(const int& xx, const int& yy);
	void AddPos(const int& xx, const int& yy);
	void AddPos(const pos& a);
	bool InBorder();
	void ShowPos();
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	// 입력받기
	string king, stone; cin >> king >> stone;
	int n; cin >> n;
	
	vector<string> moves;
	for (int i = 0; i < n; i++)
	{
		string temp; cin >> temp;
		moves.push_back(temp);
	}

	// 이동 x: 행, y: 열 - board[x][y]로 씀
	string op[] = { "T", "RT", "R", "RB", "B", "LB", "L", "LT"};
	int dx[SIZE] = {   -1,   -1,   0,    1,   1,    1,   0,   -1 };
	int dy[SIZE] = {    0,    1,   1,    1,   0,   -1,  -1,   -1 };
	map<string, pos> delta;
	for (int i = 0; i < SIZE; i++)
	{
		delta.insert({ op[i], pos(dx[i], dy[i]) });
	}

	pos now_k;
	now_k.SetPos(('8' - king[1]), (king[0] - 'A'));
	pos now_s;
	now_s.SetPos(('8' - stone[1]), (stone[0] - 'A'));
	
	for (int j=0; j < moves.size(); ++j)
	{
		pos temp_k = now_k;
		pos temp_s = now_s;
		temp_k.AddPos(delta[moves[j]]);

		if (!temp_k.InBorder())
			continue;

		if (temp_s == temp_k)
		{
			temp_s.AddPos(delta[moves[j]]);
			if (!temp_s.InBorder())
				continue;
			else
			{
				now_s = temp_s;
			}
		}

		now_k = temp_k;
	}

	now_k.ShowPos();
	now_s.ShowPos();

	return 0;
}

bool pos::operator==(const pos& a)
{
	bool result;
	if (this->x == a.x && this->y == a.y)
		result = true;
	else
		result = false;
	return result;
}

void pos::ShowPos()
{
	char result[3] = { 0 };
	result[1] = (char) '8' - (this->x);
	result[0] = (char) 'A' + (this->y);

	cout << result << "\n";
}

void pos::AddPos(const pos& a)
{
	this->x += a.x;
	this->y += a.y;
}

void pos::SetPos(const int& xx, const int& yy)
{
	this->x = xx;
	this->y = yy;
}

void pos::AddPos(const int& xx, const int& yy)
{
	this->x += xx;
	this->y += yy;
}

bool pos::InBorder()
{
	bool result;
	if (this->x < 0 || this->y < 0)
		result = false;
	else if (this->x >= 8 || this->y >= 8)
		result = false;
	else
		result = true;
	return result;
}