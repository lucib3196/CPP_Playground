#include <iostream>

int main()
{
    int x{5};
    int *address = &x;
    std::cout << x << "\n";
    std::cout << address << "\n";
    std::cout << *(&x) << '\n';
}