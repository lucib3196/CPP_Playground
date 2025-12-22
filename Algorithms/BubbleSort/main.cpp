#include "iostream"

void printArray(const int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << " " << arr[i] << " ";
    }
    std::cout << "\n";
}

int main()

{
    int myArr[] = {9, 7, 3, 6, 2};
    int size = 5;
    uint8_t len = sizeof(myArr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (myArr[j] > myArr[j + 1])
            {
                std::swap(myArr[j], myArr[j + 1]);
            }
        }
        std::cout << "Completed Iteration" << i << "\n";
        printArray(myArr, len);
    }
    return 0;
}