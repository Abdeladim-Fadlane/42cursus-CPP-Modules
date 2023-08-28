
#include"sed.hpp"

int main(int ac ,char *av[])
{
    if(ac == 4)
    { 
        std::string line;
        std::ifstream inputFile(av[1]);
        if (!inputFile.is_open())
        {
            std::cout << "Error opening the file.\n";
            exit(1);
        }
        char str[strlen(av[1])+9];
        strcpy(str,av[1]);
        strcat(str,".replace");
        std:: ofstream outputFile(str);
        if (!outputFile.is_open())
        {
            std::cout << "Error creating the file.\n" ;
            exit(1);
        }
        while (std::getline(inputFile, line)) 
            outputFile << replace(line,av[2],av[3])<<'\n';
        inputFile.close();
        outputFile.close();
    }
    else
        std::cout<<"Enter three parametres.\n";
}