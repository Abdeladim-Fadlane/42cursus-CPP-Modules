#include<iostream>

using namespace std;
class A
{
    int a;
    public:
};

class B : virtual public A{public:int b;};
class C : public A {public:int c;};

class D : public B,public C{
    
    public:
        int d;
        D()
        {
            a = 10;
        }
};



int main()
{
    D d1;
}