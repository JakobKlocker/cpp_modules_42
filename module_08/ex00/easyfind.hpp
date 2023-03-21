#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

class NotFound : public std::exception
{
    public:
    const char* what() const throw();
};

template<typename T>
void easyfind(T arr, int i)
{
    if(std::find(arr.begin(), arr.end(), i) != arr.end())
        std::cout << i << " found" << std::endl;
    else
        throw NotFound();
    std::vector<int> num;
}


#endif