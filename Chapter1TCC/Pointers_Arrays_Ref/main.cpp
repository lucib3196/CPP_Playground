#include <iostream>

void print()
{
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto i = 0; i != 10; i++)
    {
        std::cout << v1[i] << "\n";
    }
}

void print2()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto x : v) // Copies value in x and prints it
    {
        std::cout << x << "\n";
    }
}

void print3()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto &x : v)
    {
        std::cout << x << "\n";
        ++x;
    }
}

int main()
{
    print();
    print2();
    print3();

    return 0;
}