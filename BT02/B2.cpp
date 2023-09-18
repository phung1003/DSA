#include <iostream>
#include <string>
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

Node* InsertPos(Node* head, int value, int vitri)
{
    Node* p = head;
    Node* a = getNode(value);
    if (vitri == 0)
    {
        a -> next = head;
        return a;
    }
    for (int i = 0; i < vitri - 1; i++)
    {
        p = p -> next;
    }
    a -> next = p -> next;
    p -> next = a;
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

Node* deletePos(int vitri, Node* head)
{
    Node* p = head;
    if (vitri == 0) return head -> next;
    for (int i = 0; i < vitri - 1; i++)
    {
        p = p -> next;
    }
    p -> next = p -> next -> next;
    return p;
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
        while (s[j] != ' ')
        {
            m = m + s[j];
            j++;
        }
        if (m == "insert")
        {
            int vitri, value;
            vitri = int(s[j+1]) - 48;
            value = int(s[j+3]) - 48;
            head = InsertPos(head, value, vitri);
        }
        else if (m == "delete")
        {
            int vitri;
            vitri = int(s[j+1]) - 48;
            head = deletePos(vitri, head);
        }
    }


    printList(head);
    return 0;

}
