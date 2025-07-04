#include <iostream>

int main()
{
    std::cout << "Enter an Interger: ";
    int smaller{};
    std::cin >> smaller;

    std::cout << "Enter a larger Interger: ";
    int larger{};
    std::cin >> larger;

    if (larger < smaller)
    {
        std::cout << "Swapping values \n";

        int temp{larger};
        larger = smaller;
        smaller = temp;
    } // temp will die here

    std::cout << "The smaller value is: " << smaller << '\n';
    std::cout << "The larger value is: " << larger << '\n';

    return 0;
}