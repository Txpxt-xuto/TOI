/*
TASK: express
LANG: C++
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
        
};
void printlist(Node *n)
{
    while(n != nullptr)
    {
        cout << n->data << " ";
        n = n -> next;
    }
}
void printBacklist(Node *n)
{
    while(n != nullptr)
    {
        cout << n->data << " ";
        n = n -> prev;
    }
}
int main()
{   
    Node *head1 = new Node(1);
    Node *head2 = new Node(2);
    Node *head3 = new Node(3);

    head1 -> next = head2;
    head2 -> next = head3;
    head2 -> prev = head1;
    head3 -> prev = head2;
    printlist(head1);
    printBacklist(head3);
}