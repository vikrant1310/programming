#ifndef TREE_HEADER

#define TREE_HEADER 1

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>

using namespace std;

class Node
{
    public:
    int data;
    Node *leftChildPtr;
    Node *rightChildPtr;

    Node(int data): data(data), 
                    leftChildPtr(nullptr), 
                    rightChildPtr(nullptr)
    {}
};

class Tree
{    
    Node* m_root;

    public:
    inline Node* getRoot() const
    {
        return m_root;
    }
    inline void setRoot(Node* root)
    {
        m_root = root;
    }
    Node* buildTree();
    void inorderTraversal(Node *root);
    void preorderTraversal(Node *root);
    void postorderTraversal(Node *root);
    int heightOfTree(Node *root);
    void printKthLevelNodes(Node* root,int level);
    void levelOrderTraversal();
    void levelOrderTraversal_usingBFS();
    void rightView(Node *root,int level,int &maxLevel);
    Node* LCA(Node* root,int a,int b);
};

#endif
