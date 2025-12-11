#include <iostream>
#include <string>
using namespace std;
class Queue
{
private:
    // Indexes for the queue
    int rear;
    int front;
    // Size of the array fixed
    int arr[4];

public:
    Queue()
    {
        rear = -1;
        front = -1;

        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    // Checks
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        // Hardcoded 3
        return rear == 3;
    }
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is overflow\n";
            return;
        }
        else if (isEmpty())

        {
            // Set both rear and front to the front of the queue
            rear = front = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return;
    }
    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        // This only occurs when there is only
        // one item in the queue essentially a reset
        else if (front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        }
        // Regurla case return this value
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }
    // Simple display of values
    void display()
    {
        cout << "[";
        for (int x : arr)
        {
            cout << " " << x;
        }
        cout << "]" << "\n";
    }
    // Return how many elements are in the queue
    int count()
    {
        return front - rear + 1;
    }
};

int main()
{
    int option;
    int value = {};
    string flag = {};
    Queue myQueue;
    do
    {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter a value to add to the queue " << "\n";
            cin >> value;
            myQueue.enqueue(value);
            break;
        case 2:
            cout << "Removed item from queue" << myQueue.dequeue() << "\n";
            break;
        case 3:
            flag = myQueue.isEmpty() ? "True" : "False";
            cout << "Queue is empty: " << flag << "\n";
            flag = "";
            break;
        case 4:
            flag = myQueue.isFull() ? "True" : "False";
            cout << "Queue is full: " << flag << "\n";
            flag = "";
            break;
        case 5:
            cout << "Total Items in Queue " << myQueue.count() << "\n";
            break;
        case 6:
            myQueue.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            break;
        }
    } while (option != 0);
    return 0;
}