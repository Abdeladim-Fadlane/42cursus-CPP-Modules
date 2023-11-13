#include"PmergeMe.hpp"

int main(int ac,char *argv[])
{
    if(ac > 1)
    { 
        try
        {   
            PmergeMe Pmg;
            Pmg.parcingData(argv,ac);
            
            double vec_start = Pmg.getTime();
            Pmg.mergeInsertVector();
            double vec_end = Pmg.getTime();

            double deq_start = Pmg.getTime();
            Pmg.mergeInsertDeque();
            double deq_end = Pmg.getTime();

            Pmg.displayInfo();

            std::cout<<"Time to process a range of "<< Pmg.getSise() <<" elements with std::vector: "
            << vec_end - vec_start <<" us\n";
            std::cout<<"Time to process a range of "<< Pmg.getSise() <<" elements with std::deque: "
            << (deq_end - deq_start) <<" us\n";
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr<<"Error invalid argv"<<std::endl;
}
