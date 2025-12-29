#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <string>
#include <list>

template < typename T, typename dstruct = std::deque<T> >
class MutantStack : public std::stack<T, dstruct>
{
    public :
     typedef typename dstruct::iterator iterator;// you can  use container_type as defined in the std::stack class but duuh !!
        MutantStack() : std::stack<T, dstruct>()
        { 
            // std::stack<T, dstruct>(); if you put it here you will create a temp objetc that will be destroyed at the end the fun 
        }
        MutantStack(const MutantStack &real) : std::stack<T, dstruct>(real)
        {  
        }
        MutantStack &operator=(const MutantStack &real)
        {
            if (this != &real)
            {
                std::stack<T, dstruct>::operator=(real);
            }
            return *this;
        }
    ~MutantStack(){}
    iterator begin() {return this->c.begin();}
    iterator end() {return this->c.end();}
    static void printstack(MutantStack<T, dstruct> &mt)
    {
        iterator start = mt.c.begin();
        iterator last = mt.c.end();

        for (; start != last; start++)
        {
            std::cout << "value : "<< *start << std::endl;
        }
    }

};












#endif