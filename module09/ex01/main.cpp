#include"RPN.hpp"

int main(int ac,char *argv[])
{
    if(ac == 2)
    {
        try
        {
            RPN rpn;
            rpn.ReversePolishNotation(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cerr<<"Error: argument.\n";
}
