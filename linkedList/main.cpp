#include<iostream>
#include "basicOperation.h"
using namespace std;

int main()
{
    singlyLinkedList sLL; 
    sLL.insertAtHead(123);
    sLL.insertAtHead(124);
    sLL.insertAtHead(125);
    sLL.insertAtHead(126);
    sLL.insertAtTail(120);
    
    printf("SinglyLinkedList basic operations....\n");
    cout << "LinkedList has " << sLL.getLengthOfLinkedList() << " nodes" << endl;
    sLL.printData(sLL.m_head);

    return 0;
}
