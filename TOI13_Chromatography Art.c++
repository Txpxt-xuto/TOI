/*
TASK: art.cpp
LANG: C++
AUTHOR: Tapat Toungsakul
Center: Home
*/
#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data)
{
    Node* node = new Node(data);
    node ->data = data;
    node ->left = nullptr;
    node->right = nullptr;
    return node;
}
void addNode(Node *&root,int data)
{
    if(root==nullptr)
    {
        root = newNode(data);
    }
    else if(root==nullptr)
    {
        root = newNode(data);
    }
}
int main()
{
    
}