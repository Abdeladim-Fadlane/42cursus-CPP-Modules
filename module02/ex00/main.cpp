#include<iostream>

class A
{
    private:
        int *x;
        int *y;
    public:
        A();
        void __printf()
        {
            std::cout<<*(this->x )<<" , ";
            std::cout<<*(this->y )<<"\n";
        }
        A&operator=(const A& abdo)//copy assignment operator
        {
            this->x = abdo.x;
            //this->y = abdo.y;
            return *this;
        }
        void    setPoint(int i , int j)
        {
            *(this->x ) = i;
            *(this->y ) = j;
        }
};
A::A()
{
    this->x = new int;
    *(this->x )= 0;
    this->y = new int;
    *(this->y )= 0;  
}

int main()
{
    A a,s;
    s = a;
    a.setPoint(12,23);
    a.__printf();
    s.__printf();
}