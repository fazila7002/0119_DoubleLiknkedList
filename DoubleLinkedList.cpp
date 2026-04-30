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

            newNode->next = START;

            if (START != NULL)
            START->prev = newNode;

            newNode->prev = NULL;

            START = newNode;
            return;

        }

        Node *current = START;
        while (current->next != NULL && current->next->NoMhs < nim){
            current = current->next;
        }
        if (current->next != NULL && nim == current->next->NoMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
        current->next->prev = newNode;

        current->next = newNode;
    }

    void hapus()
    {
      if (START == NULL)
    {
        cout << "\nList is empty" << endl;
        return;
    }

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    int rollNo;
    cin >> rollNo;

    Node *current = START;

  
    while (current != NULL && current->NoMhs != rollNo)
        current = current->next;

    if (current == NULL)
    {
        cout << "Record not found" << endl;
        return;
    }


    if (current == START)
    {
        START = current->next;
        if (START != NULL)
            START->prev = NULL;
    }
    else
    {
        
        current->prev->next = current->next;

        // Step 4: kalau bukan node terakhir
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    delete current;

    cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = START;

        cout << "\nRecords in ascending order of roll number are;\n" ;
        int i= 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->NoMhs << " " << endl;

            currentNode = currentNode->next;

        }
    }

    void retraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {currentNode = currentNode-> next;
        i++;}

        cout << "\nRecords in descending order of roll number are\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->NoMhs << " " << endl;

            currentNode = currentNode->prev;
            i--;
        }
    }

    void serachData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;

        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->NoMhs != rollNo)
        current = current->next;

        if (current == NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll Number: " << current->NoMhs << endl;
        }
    }

    int main() 
    {

    
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.retraverse();
            break;
        case '5':
            list.serachData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }


        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;

    }while (choice != '6');
    }
    



};