#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &data, int value)
{
    if (data.empty())
    {
        throw std::runtime_error("probably there is no data (null)!\n");
    }
        
        typename T::iterator start = data.begin();
        typename T::iterator end = data.end();
        typename T::iterator res = std::find(start, end, value);

        if (res != end)
        {
            std::cout << "i found it " << std::endl;
            return (res);
        }
        else
        {
            throw std::runtime_error("Element not found\n");
        }
}

#endif