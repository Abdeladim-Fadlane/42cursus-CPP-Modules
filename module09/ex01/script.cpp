#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>


int main() {
    std::stack<double> stack;
    std::istringstream iss("            -1   95 - 5 *");
    std::string token;

    while(iss >> token)
        std::cout<<token<<"\n";

}

