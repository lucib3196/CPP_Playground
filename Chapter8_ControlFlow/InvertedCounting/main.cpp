#include <iostream>
// Creates an inverted trianlge like structure with two inner loops
int main()
{
    int outer{5};
    while (outer > 0)
    {
        std::cout << outer << " ";

        --outer;
        int inner{outer};
        while (inner > 0)
        {
            std::cout << inner << " ";
            --inner;
        }
        std::cout << '\n';
    }
}