#include "easyfind.hpp"

int main()
{
    try 
{
    int arr[] = {1, 3, 86, 44, 25, -5, 0};
    std::vector<int> ints(arr, arr + 7);

    std::vector<int>::iterator test;
    test = easyfind(ints, 0);
    std::cout << "value " << *test << std::endl;
    test = easyfind(ints, 2345678);
    std::cout << "value " << *test << std::endl;
}
catch (std::exception &e)
{
    std::cout << e.what() ;
}

}