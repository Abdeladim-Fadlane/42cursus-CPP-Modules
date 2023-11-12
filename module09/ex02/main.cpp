#include"PmergeMe.hpp"

int main(int ac,char *argv[])
{
    if(ac > 1)
    { 
        try
        {   
            PmergeMe Pmg;
            Pmg.parcingData(argv,ac);
            Pmg.mergeInsert();
            Pmg.displayInfo();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr<<"Error invalid argv"<<std::endl;
}
