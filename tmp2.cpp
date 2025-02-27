#include <iostream>

int main()
{
    int a = 1, b = 2;
    int &ar = a;
    int &br = b;
    std::cout << a << b << std::endl;
    std::cout << ar << br << std::endl;
    std::swap(ar, br);
    std::cout << a << b << std::endl;
    std::cout << ar << br << std::endl;


    return 0;
}