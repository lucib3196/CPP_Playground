#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        // Intialize the stack to be all 0
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack is overflow" << "\n";
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Underflown!" << "/n";
            return 0;
        }
        else
        {
            int popVal = arr[top];
            arr[top] = 0;
            top--;
            return popVal;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
        {
            return true;
        }
        else
            return false;
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack is Underflown!" << "/n";
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    int count()
    {
        return top + 1;
    }
    void change(int val, int pos)
    {
        if (isEmpty())
        {
            {
                cout << "Stack is Underflown!" << "/n";
            }
        }
        arr[pos] = val;
        cout << "Item changed at location" << pos << "\n";
    }
    void display()
    {
        cout << "[";
        for (int x : arr)
        {
            cout << " " << x;
        }
        cout << "]" << "\n";
    }
};

int main()
{

    Stack myStack;
    int option = {};
    int position = {};
    int value = {};
    string flag = {};

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter a value to add to the stack " << "\n";
            cin >> value;
            myStack.push(value);
            break;
        case 2:
            cout << "Poped Value" << myStack.pop() << "\n";
            break;
        case 3:
            flag = myStack.isEmpty() ? "True" : "False";
            cout << "Stack is empty: " << flag << "\n";
            flag = "";
            break;
        case 4:
            flag = myStack.isFull() ? "True" : "False";
            cout << "Stack is full: " << flag << "\n";
            flag = "";
            break;
        case 5:
        {
            cout << "Enter a value to peek in the stack " << "\n";
            cin >> position;
            cout << "Peak Value" << myStack.peek(position);
            break;
        }
        case 6:
            cout << "Total stack count" << myStack.count();
            break;
        case 7:
            cout << "Enter a value you want to add in the stack " << "\n";
            cin >> value;
            cout << "\n Enter the position where you want to this value (0 index)" << "\n";
            cin >> position;
            myStack.change(value, position);
            break;
        case 8:
            myStack.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            break;
        }
    } while (option != 0);

    return 0;
}