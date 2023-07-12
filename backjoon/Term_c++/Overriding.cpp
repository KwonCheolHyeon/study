#include <stdio.h>

class Parent
{
public:
    void outA(int a)
    {
        printf("%d\n", a);
    }
};



class Child : public Parent
{
public:
    void outA(int a)
    {
        printf("%d\n", a + a);
    }
};


void main()
{
    Child a;
    Parent b;
    a.outA(10);
    b.outA(10);
}

//예상 a.outA(10) 은 20 b.out은 10 
// 
//정답