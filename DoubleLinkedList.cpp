#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int NoMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
    private:
    Node *START;

    public :
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        Node *newNode = new Node();
        newNode->NoMhs = nim;

        if (START == NULL || nim <= START->NoMhs)
        {
            if (START != NULL && nim == START->NoMhs)
            { cout << "\nDuplicate number not allowed" << endl;
                return;
            }

        }
    }
};