
#include"sed.hpp"
#include <string>


std::string replace(std::string line, std::string s1, std::string s2)
{
    size_t pos = line.find(s1);
    while (pos != std::string::npos)
    {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos = line.find(s1, pos + s2.length());
    }
    return line;
}