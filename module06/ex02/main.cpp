#include"A.hpp"
#include"B.hpp"
#include"C.hpp"

int main()
{
    Base *Baseptr = generate();
    identify(Baseptr);

    std::cout<<"********************\n";
    
    Base *ptrBase = new Base;
    identify(ptrBase);

    std::cout<<"********************\n";
   
    B refB;
    identify(refB);

    delete Baseptr;
    return 0;
}