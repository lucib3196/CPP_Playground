#include <vector>
#include <iostream>
int main()
{
    std::vector<int> primes{2, 3, 5, 7};
    std::cout << "An int is " << sizeof(int) << " bytes\n";

    for (int i = 0; i < static_cast<int>(primes.size()); i++)
    {
        std::cout << &(primes[i]) << "\n";
    };
    return 0;
};