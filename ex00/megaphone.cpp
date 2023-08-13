
#include <iostream>
#include <string>



int main(int ac ,char **av)
{
    int i = 1;
    int j = 0;
    char c ;
    if(ac > 1)
    {
        while(av[i])
        {
            j = 0;
            while(av[i][j])
            {
                c = std::toupper(av[i][j]);
                std::cout<< c ;
                j++;
            }
            std::cout <<"\n";
            i++;
        }
    }
    else
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
}

