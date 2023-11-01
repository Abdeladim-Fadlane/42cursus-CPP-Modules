#include"Array.hpp"
#define MAX_VAL 750

int __main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}


int main()
{
    Array<char> str(26);
    for(int i = 0 ;i < 26;i++)
    {
        str[i] = 'a' + i;
    }
    for(int i = 0 ;i < 26;i++)
    {
        std::cout<<str[i]<<" ";
    }
    std::cout<<"\n";
    try
    {
        str[0] = '$';
        str[25] = '$';
        str[55] = '0';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for(int i = 0 ;i < 26;i++)
    {
        std::cout<<str[i]<<" ";
    }
    
    std::cout<<std::endl<<str.size()<<"\n";
    
    // {
    //     __main();
    // }

    return(0);
}