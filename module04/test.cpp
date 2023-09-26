using namespace std;
#include<iostream>
// class A
// {
//     public:
//         A(){cout<<"A constarcor\n";};
//         ~A(){cout<<"A desstarcor\n";};
//         void print(){cout<<"A classBass \n";}
//         A(const A& obj)
//         {
//             cout<<"A copy constactor\n";
//             *this = obj;
//         }
//         A&operator = (const A &obj)
//         {
//             cout<<"A copy asi operator\n";
//             *this = obj;
//             return(*this);
//         }
// };
// class B : public A
// {
//     public:
//     int data;
//         B(): data(0){cout<<"B constarcor\n";};
//         B(int val): data(val){cout<<"B constarcor\n";};
//         ~B(){cout<<"B desstarcor\n";};
//         void print()
//         {cout<<"B classderived\n";}
//         B(const B& obj):A()
//         {
//             data = obj.data;
//             cout<<"B copy constactor\n";
//             *this = obj;
//         }
//         B&operator = (const B &obj)
//         {
//             cout<<"B copy asi operator\n";
//             *this = obj;
//             return(*this);
//         }
// };

class A
{
    int data;
    public:
        A(){cout<<"A constarcor\n";};
        ~A(){cout<<"A desstarcor\n";};
        void print(){cout<<"A classBass \n";}
        A(const A& obj)
        {
            (void)obj;
            cout<<"A copy constactor\n";
            *this = obj;
        }
        A&operator = (const A &obj)
        {
            cout<<"A copy asi operator\n";
            if (this != &obj) // Check for self-assignment
            {
                data = obj.data;
            }
            return(*this);
        }
};
int main()
{
    A f;
    //A d(f);
    A c;
    c = f;
}