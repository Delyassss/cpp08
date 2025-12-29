#include "Span.hpp"


Span::Span(unsigned int n) : sizeLimit(n)
{
}

Span::~Span()
{
}

Span::Span(const Span &other)
{
        this->sizeLimit = other.sizeLimit;
        this->data = other.data;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->sizeLimit = other.sizeLimit;
        this->data = other.data;
    } 
    return (*this);
}

void Span::addNumber(int number)
{
    std::vector<int>::iterator it;

    if (data.size() >= sizeLimit)
    {
        throw std::runtime_error("Can't add more items, No space!");
    }
    this->data.push_back(number);
}

unsigned long Span::longestSpan() const
{
    if (data.size() >= 2)
    {
        unsigned long min = *std::min_element(data.begin(), data.end());
        unsigned long max = *std::max_element(data.begin(), data.end());
        return ((max - min));
    }
    else
    {
        throw std::runtime_error("No span can be found !");
    }
}

unsigned long Span::shortestSpan() const
{
    typedef unsigned long ul;
    if (data.size() >= 2)
    {
        std::vector<int> sorted = data;
        std::sort(sorted.begin(), sorted.end());
        std::vector<int>::iterator i = sorted.begin();
        int  span = (*(i + 1) - *i);

        while ((i + 1) != sorted.end())
        {

            if ((*(i + 1) - *i) < span)
                span = (*(i + 1) - *i);
            i++;
        }
        return (static_cast<ul> (span));
    }
    else
    {
        throw std::runtime_error("No span can be found !");
    }
}