#include <stdio.h>

int StudyArray()
{
    // 배열
    // int 자료형 10개의 요소가 만들어짐 
    // {}; 는 모든 요소를 0으로 초기화함을 의미
    int Array[10] = {};

    // 5번째 요소, 인덱스 4
    Array[4] = 22;

    //Array[10] = 10;
    printf("%d", Array[4]);
    //printf("%d", Array[10]);
    // 포인터

    return 0;
}


// 1 1 2 3 5 
int Fibonacci(int number)
{

    if (number == 1 || number == 2)
    {
        return 1;
    }

    int n1 = 1;
    int n2 = 1;
    int an = 0;

    for (int i = 0; i < number - 2; ++i)
    {
        an = n1 + n2;
        n2 = n1;
        n1 = an;
    }

    return an;
}

// 그냥 재귀함수 말고 꼬리재귀를 이용해야 한다(?)
int Fibonacci_re(int number)
{
    if (number >= 1)
    {
        if (number == 1 or number == 2)
        {
            return 1;
        }

        return Fibonacci_re(number - 2) + Fibonacci_re(number - 1);
    }
    else
    {
        return 0;
    }
}


int main()
{

    StudyArray();


    /*int fibo_4 = Fibonacci_re(4);
    printf("Fibonacci_re(4): %d\n", fibo_4);
    */
    /*int user_input = 0;
    printf("user_input: ");*/
    /*
    scanf_s("%d", &user_input);
    printf("user_input: %d\n", user_input);
    printf("Fibonacci_re(%d): %d\n", user_input, Fibonacci_re(user_input));*/


    /*int fibo_5 = Fibonacci(5);
    printf("Fibonacci(5): %d\n", fibo_5);

    int fibo_3 = Fibonacci(3);
    printf("Fibonacci(3): %d\n", fibo_3);

    int fibo_ = Fibonacci(60);
    printf("%d\n", Fibonacci(60));

    int fibo_re = Fibonacci_re(3);
    printf("%d\n", fibo_re);*/

    /*printf("user_input: ");
    scanf_s("%d", &user_input);
    printf("Fibonacci(%d): %d\n", user_input, Fibonacci(user_input));*/



    return 0;
}