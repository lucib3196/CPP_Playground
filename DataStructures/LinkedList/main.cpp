#include <iostream>
using namespace std;

/*
// Operation sot add
1. AppendNode
2. PreappendNode
3. InsertNodeAfter
4. DeleteNodeByKey
5. UpdateNodeByKey
6. Print

*/

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

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    // Traverses the linked list to determine if a node
    // Exist using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // Append node to a list (to the end)
    void appendNode(Node *n)
    {
        // If not null there is already a node
        // with the key
        if (nodeExists(n->key) != NULL)
        {
            cout << " Node already exist with key value : " << n->key
                 << "Append another node with a differnet key value \n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended";
            }
            else
            {

                Node *ptr = head;
                // Traverse the list
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended \n";
            }
        }
    }
    // 3. Prepend Node Attach node to the start
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << " Node already exist with key value : " << n->key
                 << "Append another node with a differnet key value \n";
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended \n";
        }
    }
    // Insert node after a particular node in the list
    void InsertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "Pointer with key: " << k << "Does not exist! \n";
        }
        // Handle the insert and change the pointer
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << " Node already exist with key value : " << n->key
                     << "Append another node with a differnet key value \n";
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node Inserted \n";
            }
        }
    }

    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Singly Linked List already empty cannot delete";
        }
        // Handle case where key is the head
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with key value " << k << "\n";
            }
            else
            {
                Node *temp = NULL;
                Node *prevPtr = head;
                Node *currentPtr = head->next;
                while (currentPtr != NULL)

                {
                    // Traversing
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
                // The node with the key actually exist
                // Proceed to unlink
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
        Node *ptr = nodeExists(k);

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
            cout << "No Nodes in Singly Linked List";
        }
        else
        {
            cout << "\n"
                 << " Singly Linked List Values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") -->";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
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