#include <iostream>

class Actor
{
	int height;
protected:
	int money;
public:
	int age;

	Actor(int h = 180, int m = 100, int a = 20) : height(h), money(m), age(a) {	}

protected:
	void print()
	{
		printf("height: %d, money: %d, age: %d\n", height, money, age);
	}
};

// Teacher : 상속 지정자 Actor // public, protected, private 바꿔가며 디버깅 해보면 알 수 있다
class Teacher : public Actor
{
	int careerYear;
public:
	
	void getOlder()
	{
		age += 1;
		printf("age: %d\n", age);
	}

	void raise(int plusM)
	{
		money += plusM;
		print();
	}

	void when(int year = 0)
	{
		careerYear = year;
	}
};

int main()
{
	Actor actor1;
	Teacher teacher1;
	Teacher teacher2;
	teacher2.age = 31;


	//actor1.print();
	//teacher1.print();

	teacher1.getOlder();
	//teacher1.print();
	
	teacher1.raise(200);
	teacher2.raise(-10);

	return 0;
}