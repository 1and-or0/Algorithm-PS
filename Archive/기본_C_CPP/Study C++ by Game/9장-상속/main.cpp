#include <iostream>
#include <string.h>
using namespace std;

#define MAN 1
#define WOMAN 2

class Teacher
{
	int grade;
	short gender;
	int height = 175;

protected:
	string name;
	
public:
	int careerYear = 0;
	
	Teacher(string name = "Amily", short gender = WOMAN, int grade = 1) : name(name), grade(grade), gender(gender) {}

	void print()
	{
		cout << "name: " << this->name << endl;
		
		cout << "gender: " << ((this->gender == MAN)? "Man" : "Woman" )<< endl;
		
		cout << "grade: " << this->grade << endl;
	}
};

class InvitedLecturer : public Teacher
{
	string name1;
public:
	InvitedLecturer(string n = "Aron") { Teacher::name = n; }

	void print1()
	{
		cout <<"name: "<< this->name << endl;
		cout << "name1: "<< this->name1 << endl;
	}
};

template<typename T>
T findMaxValue(T a[], int len)
{
	T maxV = a[0];
	for (int i = 1; i < len; ++i)
	{
		if (maxV < a[i])
			maxV = a[i];
	}
	return maxV;
}



int main()
{
	int iArr[5] = { 1, 2, 4, 5, 3 };
	int iMax = findMaxValue(iArr, 5);

	float fArr[5] = { 1.4f, 2.4f, 4.8f, 4.1f, 3.7f };
	float fMax = findMaxValue(fArr, 5);

	char cArr[] = { "game over !" };
	char cMax = findMaxValue(cArr, strlen(cArr));

	//Teacher t1;
	//t1.print();
	//
	//Teacher t2("Hary", MAN, 3);
	//t2.print();

	//InvitedLecturer l1;
	//l1.print1();
	////l1.print1();

	return 0;
}