#include <iostream>

int main()
{
    int max{20};
    for (int val = 0; val <= max; val += 2)
        std::cout << val << '\n';
}