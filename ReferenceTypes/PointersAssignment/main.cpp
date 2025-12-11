#include <iostream>

int main()
{
    int x = 5;

    int *myPtr = &x;

    // dereference pointer
    std::cout << "X pointer"<< *myPtr << '\n';
    std::cout << "Current memory address " << (void *)myPtr << '\n';
    

    int y = 10;
    // Assign the pointer to reference y
    myPtr = &y;
    // dereference pointer
    std::cout << "Y pointer"<<*myPtr << '\n';
    std::cout << "Current memory address" << (void *)myPtr << '\n';
    

    return 0;
}