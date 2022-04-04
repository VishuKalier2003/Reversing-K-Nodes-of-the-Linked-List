/*Given a linked list write a program to reverse first k nodes of the Linked List in which value of k is entered by the user...
Input  = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> for k = 3, then
Output = 3 -> 2 -> 1 -> 4 -> 5 -> 6 -> */
#include <iostream>
using namespace std;
class Node                // Node class for defining attributes of the Linked List
{
    public:      // Data members
    int data;
    Node* next;
    public:
    Node(int value)     // Parametrized Constructor
    {
        data = value; next = NULL;
    }
};
class LinkedList    // Linked List class for Implementing Linked Lists
{
    public:
    void InsertAtTail(Node* &head, int value)   //  Inserting Node at End
    {
        Node* n = new Node(value);   // new Node creation ( dynamic allocation of memory )
        if(head == NULL)
        {
            head = n;   // If List is empty
            return;          // The function moves out of the function
        }
        Node* temp = head;
        while(temp -> next != NULL)    // Iterating through the end
            temp = temp -> next;
        temp -> next = n;           // Changing the new Node pointer
    }
    public:
    void DisplayList(Node* &head)   // Displaying Nodes of the Linked List
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout << temp -> data << " --> ";  // Printing statement for proper visualization
            temp = temp -> next;                 // Incrementing the pointer reference
        }
        cout << "NULL" << endl;
    }
    void ReverseKNodes(Node* &head, int k)   // Reversing K Nodes of the Linked List
    {
        Node* prev = NULL;      // Previous pointer reference set to NULL
        Node* current = head;   // Current pointer set to head
        Node* successor;        // Successor pointer created but set uninitialized
        int iter = 0;   
        while(iter < k)
        {
            successor = current -> next;   // Setting successor as next of current Node
            current -> next = prev;        // Changing the current pointer to previous Node
            head = current;
            prev = current;        // Assigning head and previous pointer with the current
            current = successor;       // Making current jump to the successor
            iter++;                  // Incrementing iterator
        }
        Node* temp = head;
        while(temp -> next != NULL)     // Iterating over the Reversed Nodes
            temp = temp -> next; 
        temp -> next = current;       // Setting the last reversed node to the original list
    }
};
int main()    // main method begins
{
    Node* head = NULL;   // head pointer creation
    LinkedList object;      // Object creation to Implement Linked List
    int s, x;
    cout << "Enter the number of Nodes to create in a Linked List : ";
    cin >> s;
    for(int i = 0; i < s; i++)    // Loop for entering Node data
    {
        cout << "Enter Node data : ";
        cin >> x;
        object.InsertAtTail(head, x);     // Calling Linked List insert function
    }
    object.DisplayList(head);     // Displaying the Linked List
    cout << "Enter the value of k to reverse first k Nodes : ";
    cin >> x;
    object.ReverseKNodes(head, x);    // Reversing the first k nodes of the Linked List
    object.DisplayList(head);               // Displaying the changed Linked List
    return 0;     // End of the program
}