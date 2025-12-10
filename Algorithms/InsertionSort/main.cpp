#include "iostream"

void printArray(const int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << " " << arr[i] << " ";
    }
    std::cout << "\n";
}

void InsertionSort(int arr[], size_t n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            // Swap the values
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Add the key to the position
        arr[j + 1] = key;

        std::cout << "\nIteration " << i << '\n';
        printArray(arr, n);
    }
}

int main()
{
    int numbers[6] = {5, 2, 4, 6, 1, 3};
    uint8_t len = sizeof(numbers) / sizeof(int);

    InsertionSort(numbers, len);
    std::cout << "This is the array after";
    printArray(numbers, len);
    return 0;
}