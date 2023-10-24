#include"B.hpp"
#include"C.hpp"

Base::~Base()
{
    
}

Base * generate(void)
{
    switch (time(NULL) % 3)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p)!= NULL)
        std::cout<<"A"<< std::endl;
    else if(dynamic_cast<B*>(p)!= NULL)
        std::cout<<"B"<< std::endl;
    else if(dynamic_cast<C*>(p)!= NULL)
        std::cout<<"C"<< std::endl;
    else
        std::cout<<"Unknown type \n";
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
		std::cout << e.what() << std::endl;
	}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
		std::cout << e.what() << std::endl;
	}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
		std::cout << e.what() << std::endl;
	}
    std::cout << "Unknown Type" << std::endl;
}




