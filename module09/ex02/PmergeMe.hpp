#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <sys/time.h>
#include <iostream>
#include <vector>
#include<deque>
#include <sstream>
#include<vector>
#include <algorithm>
// #include <ctime>
class PmergeMe
{
    private:
        int _size;
        static int flag;
        static unsigned int odd;
        std::deque<unsigned int> _deque;
        std::vector<unsigned int> _vector;
        std::vector<unsigned int > smallEst;
        void    createPairsVec(std::vector<std::pair<unsigned int ,unsigned int> > &vec);
        void    createPairsDeq(std::deque<std::pair<unsigned int ,unsigned int> > &vec);
    public:
        PmergeMe();
        ~PmergeMe();
        double getTime();
        int getSise()const;
        void displayInfo();
        static int getflage();
        void mergeInsertDeque();
        void mergeInsertVector();
        static unsigned int getOdd();
        PmergeMe(const PmergeMe& other);
        void vecParcingData(char **argv ,int ac);
        void dequeParcingData(char **argv ,int ac);
        PmergeMe& operator=(const PmergeMe& other);
    
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