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
    this->_container = other._container;// Using the assignment operator of std::vector for a deep copy
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
    std::vector<unsigned int>::const_iterator it;
    for(it = _container.begin();it != _container.end();it++)
    { 
        if(*it == N)
            throw std::out_of_range("The element is already exit .");
    }
     _container.push_back(N);
    
}

unsigned int Span::longestSpan()const
{
    if(_container.size() <= 1)
        throw std::out_of_range("no span can be found.");
    std::vector<unsigned int> sortedContainer = _container;
    std::sort(sortedContainer.begin(),sortedContainer.end());
    return(sortedContainer[sortedContainer.size() -1] - sortedContainer[0]);
}

unsigned int Span::shortestSpan() const
{
    if(_container.size() <= 1)
        throw std::out_of_range("No span can be found\n");

    std::vector<unsigned int> sortedContainer = _container;
    std::sort(sortedContainer.begin(), sortedContainer.end());
    
    unsigned int shortestSpan = UINT_MAX; 
    unsigned int currentSpan;
    std::vector<unsigned int>::const_iterator it;
    for (it  = sortedContainer.begin() + 1; it != sortedContainer.end(); it++)
    {
        currentSpan = *it - *(it - 1);
        if (currentSpan < shortestSpan)
            shortestSpan = currentSpan;
    }
    return shortestSpan;
}


void Span::display()
{
    std::vector<unsigned int >::const_iterator it;
    for(it = _container.begin();it != _container.end();it++)
        std::cout<<*it<<" ";
    std::cout<<"\n";
}