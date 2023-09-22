using namespace std;
#include<iostream>
class A
{
    public:
        A(){cout<<"A constarcor\n";};
        ~A(){cout<<"A desstarcor\n";};
        void print(){cout<<"A classBass \n";}
        A(const A& obj)
        {
            cout<<"A copy constactor\n";
            *this = obj;
        }
        A&operator = (const A &obj)
        {
            cout<<"A copy asi operator\n";
            *this = obj;
            return(*this);
        }
};
class B : public A
{
    public:
    int data;
        B(): data(0){cout<<"B constarcor\n";};
        B(int val): data(val){cout<<"B constarcor\n";};
        ~B(){cout<<"B desstarcor\n";};
        void print()
        {cout<<"B classderived\n";}
        B(const B& obj):A()
        {
            data = obj.data;
            cout<<"B copy constactor\n";
            *this = obj;
        }
        B&operator = (const B &obj)
        {
            cout<<"B copy asi operator\n";
            *this = obj;
            return(*this);
        }
};

int main()
{
    // A a;
    //B b;

    B obj(10);
    cout<<obj.data;
    //A* ptr3 = &b;
    
    //A* ptr4 = new B();
    /////
    // ptr1->print();
    // ptr2->print();
    //ptr3->print();
    //ptr4->print();
    ///

}