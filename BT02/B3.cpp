#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node* before;
    Node* next;

};

Node* getNode(int value, Node* prev)
{
    Node* newNode = new Node;
    newNode -> value = value;
    newNode -> before = prev;
    newNode -> next = NULL;
    return newNode;
}

Node* Insert(Node* head, int value)
{
    Node* p = head;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = getNode(value, p);
    return head;
}

void printList( Node* head)
{
    while (head != NULL) {
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << endl;
}

int Dem(Node* head)
{
    if (head == NULL) return 0;
    int dem = 0;
    while (head -> next != NULL)
    {
        if (!(head -> value + head -> next -> value + head -> before -> value))
            {
                dem++;
            }
        head = head -> next;
    }
    return dem;
}

int main()
{
    Node* head = new Node;
    int n;
    cin >> n;
    int t;
    cin >> t;
    head -> value = t;
    head -> next = NULL;
    head -> before = NULL;
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        head = Insert(head, t);
    }
    printList(head);
    cout << Dem(head -> next);
    return 0;

}
