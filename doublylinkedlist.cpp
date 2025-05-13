#include <iostream>
using namespace std;

// membuat  struktur untuk object double linkedlist
struct Node
{
    // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    // deklarassi pointer next dan pref untuk penujukan data sebelum dan sesudah
    Node *next;
    Node *prev;
};

// deklarasi pointer START dan pemberian nilai
Node *START = NULL;

// deklarasi prosedu addNode
void addNode()
{

    // pembuatan node dan pemberian value untuk data noMhs dan name
    Node *newNode = new Node(); // step 1 buat node baru
    cout << "\nEmter the roll number of the student: ";
    cin >> newNode->noMhs; // assign value to the data field of the new node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name; // assign value to the data field of th

    // insert the new node in the list
    // kondisi jika star == null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning
        // kondisi jika start tidak kosong dan noMhs node baru sama dengan noMhs
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
        // if the list is empty, make the new node the START
        newNode->next = START; // step 3: make the new point to the first node
        // kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL)
        {
            START->prev = newNode; // step 4: make the first node point the
        }

        // memberi nilai prev = null dan start = node baru
        newNode->prev = NULL; // step 5 make the new node point to NULL
        START = newNode;      // Step 6: make the new node the first node
    }
    // kondisi jika semua kondisi if tidak terpenuhi
    else
    {

        // insert the new node in the middle or at the end
        //  set nilai current = start dan nilai previous = null
        Node *current = START; // step 1.a: start from the first node
        Node *previous = NULL; // step 1.b: previous node is Null initially

        // Looping selama current != null dan noMhs dari current lebih kecil dari????
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                            // step 1.c: traverse the list to find the
            previous = current;      // step 1.d: mode the previous to the current
            current = current->next; // step 1.e: mode the current to the next
        }

        // set nilai next node baru = current dan prev node baru = previous
        newNode->next = current;  // step 4: make the next field of the new nodes
        newNode->prev = previous; // step 5: make the previous field of the new nodes

        // kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode; // step 6: make the previous field of the
        }

        // kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous->next = newNode; // step 7: make the next field of the previous
        }
        // konidisi jika if previous sama dengan null
        else
        {
            // if previous is sill NULL, it means newNode is nows the first node
            START = newNode;
        }
    }
}

// pembuatan function search untuk mencari data
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

// pembuatan prosedur delete untuk menghapus data


    // locate the node to be deleted
    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    // node to be deleted in the first node
    if (current = START)
    {
        START = START->next; // step 2: update the START pointer
        if (START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    { // node to the deleted is not the first node
        previous->next = current->next;
        if (current->next != NULL)
        { // if there's a successor, update its prev pointer
            current->next->prev = previous;
        }
    }
    // release the memory of the node marked as current
    delete current;
    cout << "\x1b[32mrecord with roll number " << rollNo << " deleted\x1b[0m" << endl;
}

// method untuk mengecek apakah list kosong
bool listEmpty()
{
    return (START == NULL);
}

// prosedur traverse untuk menampilkan data secara urut
void traverse()
{
    if (listEmpty())
    {
        cout << "\nList is empty\n";
    }
    else
    {
        cout << "\nnRecord in ascending order of roll number are:" << endl;
        Node *currentNode = START;
        while (currentNode != NULL)
            currentNode = currentNode->next;

        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " " << currentNode->name << endl;
            currentNode = currentNode->prev;
        }
    }
}

void retraverse()
{
    if(listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in descending order of roll number are: " <<endl;
        Node *currentnode = START;
        while ( currentnode ->next != NULL)
            currentnode = currentnode->next;

        while (currentnode != NULL)
        {
            cout << currentnode->noMhs << " " << currentnode->name <<endl;
            currentnode= currentnode ->prev;
        }
    }

}
void searchData()
{
    if (listEmpty() == true)
    {
        cout << "\nList is empty" << endl;
    }

    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin >> num;
    if (search(num, &prev, &curr) == false)
        cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->noMhs << endl;
        cout << "\nName: " << curr->name << endl;
    }
}

int main()
{
    // perulangan selama bernilai benar untuk program utama double linkedlist
    while (true)
    {
        try
        {
            cout << endl
                 << "Menu";
            cout << endl
                 << "1. Menambah data kedalam list" << endl;
            cout << "2. Menghapus data dari dalam list" << endl;
            cout << "3. Menampilkan semua data didalam list dengan meningkat" << endl;
            cout << "4. Menampilkan semua data didalam list dengan meningkat" << endl;
            cout << "5. Mencari data dalam list" << endl;
            cout << "6. keluar" << endl;
            cout << endl
                 << "Masukkan pilihan (1-5): "; 
                char ch;
            cin >> ch;

            switch (ch)
            {
            case '1':
                addNode();
                break;
            case '2':
                deleteNode();
                break;
            case '3':
                traverse();
                break; 
            case '4':
                retraverse();
                break;
            case '5':
                searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "\nInvalid option" << endl;
                break;
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
            
        }
    }


