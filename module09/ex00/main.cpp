#include"BitcoinExchange.hpp"

int main(int ac,char *argv[])
{
    if(ac == 2)
    {
        BitcoinExchange btc;
        btc.scrapingData();
        btc.openFile(argv[1]);
    }
    else
        std::cerr<<"Error could not open file.\n";
}
