#include<iostream>
#include "basicOperation.h"

using namespace std;

Node::Node(int d) : data(d), nextPtr(nullptr)
{}

singlyLinkedList::singlyLinkedList() : m_head(nullptr)
{}

void singlyLinkedList::printData(Node *head)
{
    while(head!=nullptr)
    {
        cout << head->data << endl;
        head = head->nextPtr;
    }
}

void singlyLinkedList::insertAtHead(int data)
{
    Node *node = new Node(data);

    if(m_head == nullptr)
    {
        m_head = node;
    }
    else
    {
        node->nextPtr = m_head;
        m_head = node;
    }
}

void singlyLinkedList::insertAtTail(int data)
{
    Node *node = m_head;
    Node *newNode = new Node(data);
    while(node && node->nextPtr)
    {
        node = node->nextPtr;
    }
    node->nextPtr = newNode; 
}

int singlyLinkedList::getLengthOfLinkedList()
{
    int lengthOfLL = 0;
    Node *node = m_head;
    while(node)
    {
        lengthOfLL++;
        node = node->nextPtr;
    }
    return lengthOfLL;
}

Node *singlyLinkedList::getNodeAtGivenIndex(int index)
{
    Node *node = m_head;
    int len = getLengthOfLinkedList();

    if(index > len)
    {
        cout << "\nGiven index is more than length of linkedList" << endl;
        return 0;
    }

    int i = 1;
    while(i < index)
    {
        node = node->nextPtr;
        i++;    
    }

    return node;
}