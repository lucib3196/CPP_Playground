#include <iostream>
using namespace std;
int BinarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 12, 14, 23, 34, 55, 65, 75, 78};
    int left = 0;
    int right = 9;
    int target = 75;

    int index = BinarySearch(arr, left, right, target);

    if (index != -1)
    {
        cout << "Found index for target:  " << index;
    }
    else
    {
        cout << "Target " << target << " Does not exist in array ";
    }

    return 0;
}