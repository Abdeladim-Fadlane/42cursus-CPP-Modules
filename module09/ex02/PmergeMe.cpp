#include"PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){};
PmergeMe::ErrorException::ErrorException(){};
PmergeMe::ErrorException::~ErrorException() throw() {};
PmergeMe::PmergeMe(const PmergeMe &other){*this = other;}
PmergeMe::ErrorException::ErrorException(const std::string &str) : error(str) {}
const char * PmergeMe::ErrorException::what() const throw(){return error.c_str();}
PmergeMe::ErrorException::ErrorException(const ErrorException &other) {*this=other;}
PmergeMe::ErrorException& PmergeMe::ErrorException::operator=(const ErrorException &other)
{
    this->error = other.error;
    return *this;
};
PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
    this->_vector.clear();
    this->_vector = other._vector; 
    this->_deque = other._deque;
    return *this;
}

void PmergeMe::parcingData(char **argv ,int ac)
{
    int i = 1;
    char token ;
    while(i < ac)
    {
        std::istringstream iss(argv[i]);
        while(iss >> token)
        {
            // std::cout<<token<<"\n";
            if(isdigit(token))
            {
                _vector.push_back(token - 48);//Don'treapeat yourself
                _deque.push_back(token - 48);
            }
            else
                throw ErrorException("Error .");
        }
        i++;
    }
}

void mergInsert()//Divide and conquer .
{

}