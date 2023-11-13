#include"PmergeMe.hpp"

unsigned int PmergeMe::odd = 0;
int PmergeMe::flag = 0; 
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
    this->odd = other.odd;
    this->flag = other.flag;
    this->_size = other._size;
    this->smallEst = other.smallEst;
    return *this;
}

void PmergeMe::vecParcingData(char **argv ,int ac)
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
            }
            else
                throw ErrorException("Error .");
        }
        i++;
    }
    this->_size = _vector.size();
}

void PmergeMe::dequeParcingData(char **argv ,int ac)
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
                iss >> n;//Don't reapeat yourself
                _deque.push_back(n);
            }
            else
                throw ErrorException("Error .");
        }
        i++;
    }
    this->_size = _deque.size();
}

void    PmergeMe::createPairsVec(std::vector<std::pair<unsigned int ,unsigned int> > &vec)
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

void    PmergeMe::createPairsDeq(std::deque<std::pair<unsigned int ,unsigned int> > &vec)
{
    std::deque<unsigned int >::iterator it;
    if(_deque.size() % 2 != 0)
    {
        odd = _deque.back();
        flag = 1;
    }
    for(it = _deque.begin();it != _deque.end() - flag ;it += 2)
    {
        vec.push_back(std::make_pair((*it),*(it + 1)));
    }
}

template<class T> void    swapContainer(T &vec)
{
    for (typename T::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if(it->first > it->second)
            std::swap(it->second,it->first); 
    }
}

template<class T>void  findAndInsert(T&smallEst,T&largEst)
{
    typename T::iterator iterator;
    if (PmergeMe::getflage() == 1)
    {
        iterator = std::lower_bound(smallEst.begin(), smallEst.end(),PmergeMe::getOdd());
        smallEst.insert(iterator,PmergeMe::getOdd());
    }
    for ( typename T::iterator it = largEst.begin(); it != largEst.end(); ++it)
    {
        iterator = std::lower_bound(smallEst.begin(), smallEst.end(),*it);
        smallEst.insert(iterator,*it);
    }
}

template<class T>void recursivelySwap(T &vec,typename T::iterator it)
{
    if (it != vec.begin() && *it < *(it - 1))
    {
        std::swap(*(it - 1), *it);
        recursivelySwap(vec, it - 1);
    }
}

template<class T> void recursivelySort(T &vec)
{
    for (typename T::iterator it = vec.begin() + 1; it != vec.end(); ++it)
    {
        recursivelySwap(vec, it);
    }
}

double PmergeMe::getTime()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return((currentTime.tv_sec * 1000.0 ) + (currentTime.tv_usec / 1000.0));
}

void PmergeMe::mergeInsertVector()//DIVEDE AND CONQUER[...]//
{
    std::vector<std::pair<unsigned int ,unsigned int> > vec;
    createPairsVec(vec);
    swapContainer(vec);
    std::vector<unsigned int > largEst;
    for (std::vector<std::pair<unsigned int ,unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        smallEst.push_back(it->first);
        largEst.push_back(it->second);
    }
    recursivelySort(smallEst);
    findAndInsert(smallEst,largEst);
}

void PmergeMe::mergeInsertDeque()//DIVEDE AND CONQUER[...]//
{
    std::deque<std::pair<unsigned int ,unsigned int> > vec;
    createPairsDeq(vec);
    swapContainer(vec);
    std::deque<unsigned int > largEst;
    std::deque<unsigned int > smallEst;
    for (std::deque<std::pair<unsigned int ,unsigned int> >::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        smallEst.push_back(it->first);
        largEst.push_back(it->second);
    }
    recursivelySort(smallEst);
    findAndInsert(smallEst,largEst);
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
}

unsigned int  PmergeMe::getOdd()
{
    return odd;
}
int  PmergeMe::getflage()
{
    return flag;
}
int  PmergeMe::getSise()const
{
    return _size;
}