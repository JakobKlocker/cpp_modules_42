#include "iter.hpp"


int main()
{
    int arr[5];
    for(int i = 0; i < 5; i++)
    {
        arr[i] = i;
        std::cout <<  i << " array : " << arr[i] << std::endl;
    }
    iter(arr, 5, incr);
    std::cout << "After:" << std::endl;
    for(int i = 0; i < 5; i++)
    {
        std::cout <<  i << " array : " << arr[i] << std::endl;
    }

    std::cout << std::endl << "Char: " << std::endl;

    char a = 'a';
    char carr[5];
    for(int i = 0; i < 5; i++)
    {
        carr[i] = a;
        a++;
        std::cout <<  i << " array : " << carr[i] << std::endl;
    }
    iter(carr, 5, incr);
    std::cout << "After:" << std::endl;
    for(int i = 0; i < 5; i++)
    {
        std::cout <<  i << " array : " << carr[i] << std::endl;
    }
}