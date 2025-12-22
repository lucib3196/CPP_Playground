#include <iostream>
using namespace std;

void linearSearch(int a[], int n)
{
    int temp = -1;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == n)
        {
            cout << "Found the value n: " << n << " At position i: " << i;
            temp = 0;
        }
    }
    if (temp == -1)
    {
        cout << "Value n: " << n << "Not found in array";
    }
}
int main()
{
    int arr[5] = {1, 22, 34, 5, 7};
    cout << "Please enter an element to search \n";

    int num;
    cin >> num;
    linearSearch(arr, num);
}