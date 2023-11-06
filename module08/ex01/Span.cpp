#include"Span.hpp"

Span::Span()
{
    this->_N = UINT_MAX;
}

Span::Span(const Span & other)
{
    *this = other;
}

Span& Span::operator=(const Span &other)
{
    this->_N = other._N;
    this->_container = other._container;
    return *this;
}

Span::~Span()
{
    
}
Span::Span(unsigned int N)
{
    this->_N = N;
}

void    Span::addNumber(unsigned int N)
{    
    if( _container.size() >= _N)
        throw std::out_of_range("container is full.");
    std::vector<unsigned int>::const_iterator it ;
    it = std::find(_container.begin(),_container.end(),N);
    if(it !=_container.end())
        throw std::out_of_range("The element is already exit .");
     _container.push_back(N);   
}

unsigned int Span::longestSpan()
{
    if(_container.size() <= 1)
        throw std::out_of_range("no span can be found.");
    std::vector<unsigned int> tmp = _container;
    std::sort(tmp.begin(),tmp.end());
    return(*(tmp.end() - 1) - *(tmp.begin()));
}

unsigned int Span::shortestSpan() 
{    
    unsigned int shortestSpan = UINT_MAX; 
    unsigned int someSpan;
    
    if(_container.size() <= 1)
        throw std::out_of_range("No span can be found\n");

    std::vector<unsigned int> tmp = _container;
    std::sort(tmp.begin(), tmp.end());

    std::vector<unsigned int>::const_iterator it;
    for (it  = tmp.begin() + 1; it != tmp.end(); it++)
    {
        someSpan = *it - *(it - 1);
        if (someSpan < shortestSpan)
            shortestSpan = someSpan;
    }
    return shortestSpan;
}

void Span::display()
{
    std::vector<unsigned int >::const_iterator it;
     std::cout<<"Element : ";
    for(it = _container.begin();it != _container.end();it++)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}


void Span::addRangeNumber(unsigned int arr[],unsigned int len)
{
    if(_N < _container.size() + len)
        throw std::out_of_range("container is full.");
    _container.insert(_container.end(),arr,arr + len);
}