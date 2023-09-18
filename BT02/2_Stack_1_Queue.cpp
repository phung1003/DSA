#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* next;
};

Node* getNode(int value)
{
    Node* newNode = new Node();
    newNode -> value = value;
    newNode -> next = NULL;
    return newNode;
}

Node* Push(Node* head, int value)
{
    Node* a = getNode(value);
    if (head == NULL) return a;
    Node *p = head;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = a;
    return head;
}

Node* Pop(Node* head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        return NULL;
    }

    Node* p = head;
    while (p -> next -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = NULL;
    return head;
}

int getTop(Node* head)
{
    Node* p = head;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    return p -> value;
}

Node* Enqueue(Node* head1, Node* head2, int value)
{
    if (head1 == NULL)
    {
        head1 = Push(head1, value);
        return head1;
    }
    else
    {
        while (head1 != NULL)
        {
            head2 = Push(head2, getTop(head1));
            head1 = Pop(head1);
        }
        head1 = Push(head1, value);
        while (head2 != NULL)
        {
            head1 = Push(head1, getTop(head2));
            head2 = Pop(head2);
        }
        return head1;
    }
}

void printList( Node* head)
{
    while (head != NULL) {
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << endl;
}

void printReverse(Node* head)
{
    if (head == NULL)
    return;
    printReverse(head->next);
    cout << head->value << " ";
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n;
    cin >> n;
    string s;
    getline(std :: cin, s);
    for (int i = 0; i < n; i++)
    {

        getline(std :: cin, s);
        int j = 0;
        string m = "";

        while (s[j] != ' ' && j < s.length())
        {
            m = m + s[j];
            j++;
        }

        if (m == "enqueue")
        {
            int vitri, value;

            value = int(s[j+1]) - 48;
            head1 = Enqueue(head1, head2,  value);
        }
        else if (m == "dequeue")
        {
            head1 = Pop(head1);
        }
    }
    printReverse(head1);
    return 0;

}

