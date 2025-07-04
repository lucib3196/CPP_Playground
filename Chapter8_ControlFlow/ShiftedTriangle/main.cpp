#include <iostream>

int main()
{
    int outer{1};
    while (outer <= 5)
    {
        int inner{outer};
        while (inner < 5)
        {
            std::cout << ' ' << " ";
            ++inner;
        }

        std::cout << outer << " ";
        int inner2{outer};
        while (inner2 > 1)
        {
            --inner2;
            std::cout << inner2 << " ";
        }
        ++outer;
        std::cout << '\n';
    }
}