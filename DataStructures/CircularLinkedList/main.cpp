#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList(Node *n)
    {
        head = n;
    }
    CircularLinkedList()
    {
        head = NULL;
    }

    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL)
        {
            return ptr;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }
    // Appends a node at the end
    void appendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << " Node already exist with key value : " << n->key
                 << "Append another node with a differnet key value \n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node Appended";
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
            }
        }
    }

    void prependNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << " Node already exist with key value : " << n->key
                 << "Append another node with a differnet key value \n";
        }
        else
        {
            // Case where head is null
            if (head == NULL)
            {
                head = n;
                n->next = head;
                cout << "Node Appended";
            }
            // General case
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                // Update the last node to point to the head
                ptr->next = n;
                // prepend node
                n->next = head;
                // Reasign
                head = n;
                cout << "Node Prepended" << "\n";
            }
        }
    }

    void InsertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "Pointer with key: " << k << "Does not exist! \n";
        }
        else
        {
            if (nodeExist(n->key) != NULL)
            {
                cout << " Node already exist with key value : " << n->key
                     << "Append another node with a differnet key value \n";
            }
            else
            // Case where node is in between values that are not
            {
                if (ptr->next != head)
                {

                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node Inserted in between values \n";
                }
                else
                {
                    ptr->next = n;
                    n->next = head;
                    cout << "Node Inserted at the end \n";
                }
            }
        }
    }

    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExist(k);

        if (ptr == NULL)
        {
            cout << "No Node exist with the key value of " << k;
        }
        else
        {
            // First Case when the ptr to delete is the head
            if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Head Node Unlinked List Empty";
                }
                else
                {
                    // Traverse
                    while (ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = head->next;
                    head = head->next;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prevPtr = head;
                Node *currentPtr = head->next;

                while (currentPtr != NULL)
                {
                    if (currentPtr->key == k)
                    {
                        temp = currentPtr;
                        currentPtr = NULL;
                    }
                    else
                    {
                        prevPtr = prevPtr->next;
                        currentPtr = currentPtr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevPtr->next = temp->next;
                    cout << "Node Unlinked with key value" << k << "\n";
                }
                else
                {
                    cout << "Node Doesn't Exist with key value" << k << "\n";
                }
            }
        }
    }
    // Update the node by key and value
    void updateNodeByKey(int k, int data)
    {
        Node *ptr = nodeExist(k);

        if (ptr != NULL)
        {
            ptr->data = data;
            cout << "Node Data Updated Successfully";
        }
        else
        {
            cout << "Node Doesn't Exist with key value: " << k << "\n";
        }
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "No Nodes in Circular Linked List";
        }
        else
        {
            cout << "\n"
                 << " Circular Linked List Values : ";
            Node *temp = head;
            do
            {
                cout << "(" << temp->key << "," << temp->data << ") -->";
                temp = temp->next;
            } while (temp!= head);
        }
    }
};

int main()
{
    CircularLinkedList s;
    int option;
    int key1, k1, data1;

    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \n Enter Key and Data of the Node to be Appended";
            cin >> key1;
            cin >> data1;

            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;

        case 2:
            cout << "Preappend Node Operation \n Enter Key and Data of the Node to PreAppend";
            cin >> key1;
            cin >> data1;

            n1->key = key1;
            n1->data = data1;

            s.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node after Operation \n Enter the key of existing Node after which you want to Insert this New Node \n";
            cin >> k1;
            cout << "Enter key and value of the New Node First";
            cin >> key1;
            cin >> data1;

            n1->key = key1;
            n1->data = data1;

            s.InsertNodeAfter(k1, n1);
            break;
        case 4:
            cout << "Delete Node by Key Operation \n Enter the key of the node to be delete";
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;

        case 5:
            cout << "Update Node Operation \n Enter the key and data for the node update";
            cin >> key1;
            cin >> data1;

            s.updateNodeByKey(key1, data1);
            break;

        case 6:
            s.print();
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