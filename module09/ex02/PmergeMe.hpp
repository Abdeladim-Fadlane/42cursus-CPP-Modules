#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include<deque>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void parcingData(char **argv ,int ac);
        class ErrorException : public std::exception
        {
            private :
                std::string error;
            public :
                ErrorException();
                ErrorException(const std::string &str);
                ErrorException(const ErrorException &other);
                ErrorException&operator=(const ErrorException &other);
                const char *what() const throw();
                virtual ~ErrorException() throw();
        };
};
#endif