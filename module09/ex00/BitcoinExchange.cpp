#include"BitcoinExchange.hpp"

int year = 1;
int month = 1;
BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::~BitcoinExchange()
{
};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other)
{
    this->_map.clear();
    this->_map = other._map; 
    return *this;
}

void BitcoinExchange::scrapingData()
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

void BitcoinExchange::openFile(char *file)
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
std::map<std::string,std::string>::const_iterator BitcoinExchange::findKey(const std::string &key)
{
    std::map<std::string,std::string>::const_iterator it;
    it = this->_map.lower_bound(key);
    if (it == _map.begin())
        return it;
    if (it->first == key)
        return it;
    return --it;
}

int    BitcoinExchange::checkError(const std::string &key,const std::string &data)
{
    size_t i  = 0;
    int flag = 0;
    if(data[0] == ' ')
        i++;
    else
    {
        std::cout<<"Error: bad value ."<<std::endl;
        return(1);
    }
    if(data[1] == '+')
        i++;
    while(i <  data.size())
    {    
        if(!isdigit(i) && atof(data .c_str()) < 0)
        {
            std::cout<<"Error: not a positive number.\n";
            return(1);
        }
        if((data[i] != '.' && !isdigit(data[i])) || atof(data .c_str()) == 0 )
        {
            std::cout<<"Error: bad value ."<<std::endl;
            return(1);
        }
        if(data[i] == '.')
            flag++;
        i++;
    }
    if(atof(data .c_str()) >= 1000)
    {
        std::cout<<"Error: too large a number.\n";
        return (1);
    }

    if(formatData(key) || data[i-1] == ' ' || flag > 1 )
    {
        std::cout<<"Error: bad input => " <<key<<std::endl;
        return(1);
    }

    return(0);
}
int checkYear(const std::string &date)
{
    int i = 0;
    if(date.size() == 4)
    {
        while(i < 4)
        {
            if(!isdigit(date[i]))
                return 1;
             i++;
        }
    }
    else    
        return 1;
    if(atoi(date.c_str()) < 1 || atoi(date.c_str()) > 2023)
        return 1;
    year = atoi(date.c_str());
    return 0;
}

int checkMonth(const std::string &date)
{
    int i = 0;
    if(date.size() == 2)
    {
        while(i < 2)
        {
            if(!isdigit(date[i]))
                return 1;
            i++;
        }
    }
    else    
        return 1;
    if(atoi(date.c_str()) < 1 || atoi(date.c_str()) > 12)
        return 1;
    month = atoi(date.c_str());
    return 0;
}

int checkday(const std::string &date)
{
    int i = 0;
    int daysInMonth = 31; 
    
    if(date.size() == 3)
    {
        while(i < 2)
        {
            if(!isdigit(date[i]))
                return 1;
             i++;
        }
        if(date[2] != ' ')
            return 1;
    }
    else    
        return 1;
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30; 
    else if (month == 2)
    {
        if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            daysInMonth =  29;//leap year;
        else
            daysInMonth = 28; 
    }
    if (atoi(date.c_str()) < 1 || atoi(date.c_str() ) > daysInMonth)
        return 1; 
    return 0;
}

int BitcoinExchange::formatData(const std::string &date)
{
    size_t i = 0;
    size_t j = 0;
 
    while (i < date.size() && date[i] != '-')
        i++;
    j = i  + 1;
    if (checkYear(date.substr(0, i)) != 0)
            return 1;
    i ++;
    while (i < date.size() && date[i] != '-')
        i++;
    i++;
    if (checkMonth(date.substr(j , i - j - 1 )) != 0)
            return 1; 
    if (checkday(date.substr(i)) != 0)
            return 1;
    return 0;
}
