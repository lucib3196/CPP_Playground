#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    // Pointers
    Node *next;
    Node *prev;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{

public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    // Traverses the linked list to determine if a node exist with a given key
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

    // Append Node to the end of the list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << " Node already exist with key value : " << n->key
                 << "Append another node with a differnet key value \n";
        }
        else
        {
            // Node becomes head if head is null
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended";
            }
            // traverse the list and append the end
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                // new node points to previous
                n->prev = ptr;
                // ptr next points to the new node
                ptr->next = n;
                cout << "Node Appended \n";
            }
        }
    }
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << " Node already exist with key value : " << n->key
                 << "Append another node with a differnet key value \n";
        }
        else
        {
            head->prev = n;
            n->next = head;
            head = n;
            cout << "Node Prepended \n";
        }
    }

    void insertNode(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "Pointer with key " << k << "Does not Exist";
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << " Node already exist with key value : " << n->key
                     << "Append another node with a differnet key value \n";
            }
            else
            {
                Node *nextNode = ptr->next;
                if (nextNode == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node insertedat the END \n";
                }
                else
                {
                    ptr->next = n;
                    n->prev = ptr;
                    n->next = nextNode;
                    nextNode->prev = n;
                    cout << "Node inserted in between \n";
                }
            }
        }
    }
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "Singly Linked List already empty cannot delete";
        }
        else if (head != NULL)
        {
            // First case we delete the current head
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with key value " << k << "\n";
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->prev;

                // Handle the case where the node to be delete is at the end
                if (nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout << "Deleted node at the end";
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    cout << "Node Deleted in Between";
                }
            }
        }
    }
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
                 << " Doubly Linked List Values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") <-->";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList s;
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

            s.insertNode(k1, n1);
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