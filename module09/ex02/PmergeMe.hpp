#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <sys/time.h>
#include <iostream>
#include <vector>
#include<deque>
#include <sstream>
#include<vector>
#include <algorithm>
#include <ctime>
class PmergeMe
{
    private:
        double odd;
        int flag;
        std::vector<unsigned int> _vector;
        std::vector<unsigned int > smallEst;
        std::deque<unsigned int> _deque;
        std::time_t current_time;
        void    createPairs(std::vector<std::pair<unsigned int ,unsigned int> > &vec);
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void parcingData(char **argv ,int ac);
        void mergeInsert();
        void findAndInsert(std::vector<unsigned int > &smallEst,std::vector<unsigned int > &largEst);
        void displayInfo();
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
void recursivelySort(std::vector<unsigned int> &vec);
#endif