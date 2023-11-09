#include"BitcoinExchange.hpp"


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

int BitcoinExchange::formatData(const std::string &date)
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
    {
        if(arr[0] % 4 == 0 && (arr[0] % 100 != 0 || arr[0] % 400 == 0))
            daysInMonth =  29;//leap year;
        else
            daysInMonth = 28; 
    }
    if (arr[2] < 1 || arr[2] > daysInMonth)
        return 1; 
    return 0;
}