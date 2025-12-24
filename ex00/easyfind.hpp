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
        typename T::iterator start = data.begin();
        typename T::iterator end = data.end();
        typename T::iterator res = find(start, end, value);

        if (res != end)
        {
            return (res);
        }
        else
        {
            throw std::runtime_error("Element not found\n");
        }
}

#endif