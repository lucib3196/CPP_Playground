#include <iostream>

int main()
{
    int val{5};
    int count{};
    for (int i{0}; i <= val; i++)
    {
        if (i == val)
        {
            count+=i;
            std::cout << i << "="<<count;
        }
        else
        {
            std::cout << i << "+";
            count+=i;
        }
    }
}