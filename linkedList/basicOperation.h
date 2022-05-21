//this header file contains basic operation's declaration of linked list 
#ifndef LinkedList
#define LinkedList

class Node
{
    public:
    Node *nextPtr;
    int data;

    Node(int data);
};

class singlyLinkedList
{
    public:
    Node *m_head;
    singlyLinkedList();

    //insertion
    void insertAtHead(int data); //done
    void insertAtTail(int data); //done

    //deletion
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtKthIndex();
    void deleteNodeAtGivenIndex(int index);
    void deleteNodeWithGivenKey(int index);

    //traversal
    void printData(Node *head); //done
    int getLengthOfLinkedList(); //done
    Node *getNodeAtGivenIndex(int index);
};

#endif