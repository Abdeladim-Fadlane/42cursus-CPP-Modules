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
        BitcoinExchange(){};
        ~BitcoinExchange()
        {
        
        }
        //BitcoinExchange(const BitcoinExchange &other);
        // BitcoinExchange &operator=(const BitcoinExchange& other);
        bool is_digits(const std::string &str)
        {
            for(size_t i = 0;i < str.size();++i)
            {
                if(!std::isdigit(str[i]))
                    return false;
            }
            return true;
        }
        void scrapingData()
        {
            std::string line;
            std::ifstream _dataBase("data.csv");
            if(!_dataBase.is_open())
            {
                std::cerr << "Error opening the file.\n";
                exit(1);
            }
            while(std::getline(_dataBase, line))
            {
                std::size_t pos = line.find(",");
                if(pos != std::string::npos)
                {
                    std::string key = line.substr(0,pos);
                    std::string value = line.substr(pos+1);
                     _map[key] = value;                
                }
            }
            _dataBase.close();
        }
        void openFile(char *file)
        {
            std::string line;
            std::ifstream _inputFile(file);
            if(!_inputFile.is_open())
            {
                std::cerr << "Error opening the file.\n";
                exit(1);
            }
            while(std::getline(_inputFile,line))
            {
                std::size_t pos = line.find("|");
                if(pos != std::string::npos)
                {
                    std::string key = line.substr(0,pos);
                    std::string value = line.substr(pos+1);
                    std::map<std::string,std::string>::const_iterator it;
                    it = this->_map.lower_bound(key);
                    float num = atof(it->second .c_str()) * atof(value.c_str());
                
                    std::cout<<key<<" => " << value <<" = "<< num<<std::endl;   
                }
            }
            _inputFile.close();
        }
        // void checkError(const std::string &line)
        // {

        // }
};
#endif