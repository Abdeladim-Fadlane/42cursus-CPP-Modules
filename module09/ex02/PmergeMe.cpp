#include"PmergeMe.hpp"

PmergeMe::PmergeMe():odd(-1),flag(0){}
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
            unsigned int n ;
            iss.putback(token);
            if(isdigit(token))
            {
                iss >> n;
                _vector.push_back(n);//Don't reapeat yourself
                _deque.push_back(n);
            }
            else
                throw ErrorException("Error .");
        }
        i++;
    }
}


void    PmergeMe::createPairs(std::vector<std::pair<unsigned int ,unsigned int> > &vec)
{
    std::vector<unsigned int >::iterator it;
    if(_vector.size() % 2 != 0)
    {
        odd = _vector.back();
        flag = 1;
    }
    for(it = _vector.begin();it != _vector.end() - flag ;it += 2)
    {
        vec.push_back(std::make_pair((*it),*(it + 1)));
    }
}

void    swapContainer(std::vector<std::pair<unsigned int ,unsigned int> > &vec)
{
    for (std::vector<std::pair<unsigned int ,unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if(it->first > it->second)
            std::swap(it->second,it->first); 
    }
}

void PmergeMe::findAndInsert(std::vector<unsigned int > &smallEst,std::vector<unsigned int > &largEst)
{
    std::vector<unsigned int>::iterator iterator;
    if (flag == 1)
    {
        iterator = std::lower_bound(smallEst.begin(), smallEst.end(),odd);
        smallEst.insert(iterator,odd);
    }
    for ( std::vector<unsigned int>::iterator it = largEst.begin(); it != largEst.end(); ++it)
    {
        iterator = std::lower_bound(smallEst.begin(), smallEst.end(),*it);
        smallEst.insert(iterator,*it);
    }
}
double getTime()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return((currentTime.tv_sec *1000.0  ) + (currentTime.tv_usec/1000.0 ));
}

void PmergeMe::mergeInsert()//DIVEDE AND CONQUER[...]//
{
    std::vector<std::pair<unsigned int ,unsigned int> > vec;
    createPairs(vec);
    swapContainer(vec);
    current_time = getTime();
    std::vector<unsigned int > largEst;
    for (std::vector<std::pair<unsigned int ,unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        smallEst.push_back(it->first);
        largEst.push_back(it->second);
    }

    recursivelySort(smallEst);
    findAndInsert(smallEst,largEst);
}

void recursivelySwap(std::vector<unsigned int> &vec, std::vector<unsigned int>::iterator it)
{
    if (it != vec.begin() && *it < *(it - 1))
    {
        std::swap(*(it - 1), *it);
        recursivelySwap(vec, it - 1);
    }
}

void recursivelySort(std::vector<unsigned int> &vec)
{
    for (std::vector<unsigned int>::iterator it = vec.begin() + 1; it != vec.end(); ++it)
    {
        recursivelySwap(vec, it);
    }
}


void PmergeMe::displayInfo()
{
    std::cout <<"Befor: ";
    for ( std::vector<unsigned int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
    {
         std::cout << "\033[31m" << *it << " \033[0m";
    }
    std::cout<<"\n"<<"After: ";
    for ( std::vector<unsigned int>::iterator it = smallEst.begin(); it != smallEst.end(); ++it)
    {
        std::cout << "\033[32m" << *it << " \033[0m";
    }
    std::cout<<"\n";
    std::cout<<"Time to process a range of "<< _vector.size() <<" elements with std::vector: "
    << (getTime() - current_time) <<" us\n";
}