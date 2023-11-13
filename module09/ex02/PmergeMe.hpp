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
        static double odd;
        static int flag;
        int _size;
        std::vector<unsigned int> _vector;
        std::vector<unsigned int > smallEst;
        std::deque<unsigned int> _deque;
        void    createPairsVec(std::vector<std::pair<unsigned int ,unsigned int> > &vec);
        void    createPairsDeq(std::deque<std::pair<unsigned int ,unsigned int> > &vec);
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void parcingData(char **argv ,int ac);
        static double getOdd()
        {
            return odd;
        }
        static int getflage()
        {
            return flag;
        }
        int getSise()const
        {
            return _size;
        }
        void mergeInsertVector();
        void mergeInsertDeque();
        void displayInfo();
        double getTime();
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