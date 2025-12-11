#include <iostream>

int main()
{
    int x = 5;
    int *xPtr = &x;

    std::cout << "The value of x" << x <<'\n';
    std::cout << "The memory address of x" << xPtr<<'\n';
    std::cout<< "Using the member of the value of x is" << xPtr->;

    return 0;
}