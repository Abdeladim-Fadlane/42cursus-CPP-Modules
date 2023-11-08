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
        ~BitcoinExchange(){};
        //BitcoinExchange(const BitcoinExchange &other);
        // BitcoinExchange &operator=(const BitcoinExchange& other);
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
            std::getline(_inputFile,line);
            if(line == "date | value")
            {
                while(std::getline(_inputFile,line))
                {
                    std::size_t pos = line.find("|");
                    
                    if(pos != std::string::npos)
                    { 
                        std::string key = line.substr(0,pos);
                        std::string value = line.substr(pos+1);

                        if(!checkError(key,value))
                        {
                            std::map<std::string,std::string>::const_iterator it;
                            it = findKey(key);
                            
                            float num = atof(it->second .c_str()) * atof(value.c_str());
                            std::cout<<key<<" => " << value <<" = "<< num<<std::endl; 
                        }
                    }
                    else
                        std::cout<<"Error: bad input => " <<line.substr(pos+1)<<std::endl;
                }
            }
            else
                std::cout<<"Error: Check your input file.\n";
            _inputFile.close();
        }
        std::map<std::string,std::string>::const_iterator findKey(const std::string &key)
        {
            
            std::map<std::string,std::string>::const_iterator it;
            it = this->_map.lower_bound(key);

            if (it == _map.begin())
                return it;
            if (it == _map.end())
                return --it;

            std::map<std::string,std::string>::const_iterator beforeLower = it;
            --beforeLower;

            if (( atof(key .c_str()) - atof( beforeLower->first.c_str())) <=
             (atof( it->first.c_str()) - atof(key .c_str()))) {
                return beforeLower;
            } 
            else 
                return it;
        }

        int    checkError(const std::string &key,const std::string &data)
        {
            if(formatData(key))
            {
                std::cout<<"Error: bad input => " <<key<<std::endl;
                return(1);
            }
            if(atof(data .c_str()) >= 1000)
            {
                std::cout<<"Error: too large a number.\n";
                return (1);
            }
            if(atof(data .c_str()) <= 0 )
            {
                std::cout<<"Error: not a positive number.\n";
                return(1);
            }
            return(0);
        }

        int formatData(const std::string &date)
        {
            int i = 0;
            int arr[3];
            size_t pos = 0;
            size_t tmp = 0;

            while (i < 3)
            {
                pos = date.find("-", tmp);
                if (pos != std::string::npos)
                    arr[i] = std::atoi(date.substr(tmp, pos).c_str());
                else
                    arr[i] = std::atoi(date.substr(tmp).c_str());
                tmp = pos + 1; 
                i++;
            }
            if(arr[0] < 1970 || arr[0] > 2022)
                return 1;
            if(arr[1] < 1 || arr[1] > 12)
                return 1;
            int daysInMonth = 31; 
            if (arr[1] == 4 || arr[1] == 6 || arr[1] == 9 || arr[1] == 11)
                daysInMonth = 30; 
            else if (arr[1] == 2) 
                daysInMonth = (arr[0] % 4 == 0 && (arr[0] % 100 != 0 || arr[0] % 400 == 0)) ? 29 : 28; 
            if (arr[2] < 1 || arr[2] > daysInMonth)
                return 1; 
            return 0;
        }

};
#endif