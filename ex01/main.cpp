#include "Span.hpp"

void randomNB(std::vector<int> &myvec)
{
    int  mynb;
    int  sign = 1;
    std::vector<int>::iterator st = myvec.begin();
    std::vector<int>::iterator ls = myvec.end();

    for (; st != ls; st++)
    {
        sign = (rand() % 2 == 0) ? -1 : 1;
        mynb = rand() % ((rand() + 1 / 2));
        *st = (mynb * sign) ;
    }
}

int main()
{
    try 
    {
        srand(time(NULL));
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
/*      sp.addNumber(132); should throw ! no more space   */  
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        
        Span sp2 = Span(20000);
        std::vector<int> myVec(20000);
        randomNB(myVec);
        sp2.add_range(myVec.begin(), myVec.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        sp2.add_range(myVec.begin(), myVec.end());// should throw ! no more space
        sp2.addNumber(-1);// should throw ! no more space
        sp2.addNumber(-1);// should throw ! no more space
        sp.addNumber(4); // should throw ! no more space
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}