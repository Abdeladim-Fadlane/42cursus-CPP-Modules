#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
class BitcoinExchange
{
    private:
        std::map<std::string,std::string> _map;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void scrapingData();
        void openFile(char *file);
        std::map<std::string,std::string>::const_iterator findKey(const std::string &key);
        int checkError(const std::string &key,const std::string &data);
        int formatData(const std::string &date);
};
#endif