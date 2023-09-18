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

Node* Enqueue(Node* head, int value)
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

Node* Dequeue(Node* head)
{
    if (head -> next == NULL) return NULL;
    return head -> next;
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

Node* Push(Node* head1, Node* head2, int value)
{
    if (head1 == NULL)
    {
        head1 = Enqueue(head1, value);
        return head1;
    }
    else
    {
        while (head1 != NULL)
        {
            head2 = Enqueue(head2, head1 -> value);
            head1 = Dequeue(head1);
        }
        head1 = Enqueue(head1, value);
        while (head2 != NULL)
        {
            head1 = Enqueue(head1, head2 -> value);
            head2 = Dequeue(head2);
        }
        return head1;
    }
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

        if (m == "push")
        {
            int vitri, value;

            value = int(s[j+1]) - 48;
            head1 = Push(head1, head2, value);
        }
        else if (m == "pop")
        {
            head1 = Dequeue(head1);
        }
    }


    printReverse(head1);
    return 0;

}

