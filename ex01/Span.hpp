#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <stdint.h>


class Span
{
    private :
        std::vector<int> data;
        unsigned int sizeLimit;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);

    void addNumber(int number);
    unsigned long shortestSpan() const;
    unsigned long  longestSpan() const;
    unsigned int size() const;
    template <typename T>
    void add_range(T begin, T end)
    {
        if (std::distance(begin, end) < 0)
            throw std::runtime_error("distance is negative");
        size_t newSize = static_cast<size_t>(std::distance(begin, end));
        size_t spaceleft = sizeLimit - data.size();
        if (newSize > spaceleft)
            throw std::runtime_error("No space left!");
        data.insert(data.end(), begin, end);
    }
};


#endif