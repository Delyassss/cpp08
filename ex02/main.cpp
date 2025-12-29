#include "MutantStack.hpp"

int main()
{
    int save;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top of the stack : " << mstack.top() << std::endl;
    save = mstack.top();
    mstack.pop();
    std::cout << "the value popped from the stack : " << save << std::endl;
    std::cout << "Size now is : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "let's print the current stack" << std::endl; // since we iterate we do not use the concept of stack like LIFO we use (the linear walk) 
    mstack.printstack(mstack);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it; // we did nothing here 
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "let's test the copy constructor for std::stack" << std::endl;
    std::cout << "the size is : " << s.size() << "top value" << s.top() << std::endl;
    if (!s.empty())
        std::cout << "stack is done (not empty)" << std::endl;
    std::cout << "let's try std::list" << std::endl;
    MutantStack<int , std::list<int> > copy_list;
    copy_list.push(0);
    copy_list.push(1);
    copy_list.push(2);
    copy_list.push(3);
    copy_list.push(4);
    std::cout << "let's print the current stack" << std::endl;
    MutantStack<int, std::list<int> >::printstack(copy_list);


    return 0;
}