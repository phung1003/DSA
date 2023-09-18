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

void printList( Node* head)
{
    while (head != NULL) {
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;

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
            head = Push(head, value);
        }
        else if (m == "pop")
        {
            head = Pop(head);
        }
    }


    printList(head);
    return 0;

}
