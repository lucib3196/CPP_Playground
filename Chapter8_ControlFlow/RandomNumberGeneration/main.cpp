#include <iostream>
#include <random> // for std::mt19937
#include <chrono>

int main()
{
    std::mt19937 mt{
        static_cast<std::mt19937::result_type>(
            std::chrono::steady_clock::now().time_since_epoch().count())};
    std::uniform_int_distribution die{1, 6}; // Uniform dist for a die

    for (int i{0}; i < 40; i++)
    {
        std::cout << die(mt) << "\t";

        if (i % 10 == 0)
        {
            std::cout << "\n";
        }
    }
}