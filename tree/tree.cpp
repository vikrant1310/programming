/*
author : vikrant tyagi
file : tree.cpp

this file contains definition of basic tree class methods
*/

#include "tree.h"

/*
inputting a tree:   an array containing nodes data.
                    if data is -1 then that is nullptr
                    else create node for that data
*/
Node* Tree::buildTree()
{
    int data;
    cin >> data;

    if(data == -1)//means null ptr
        return nullptr;

    Node *root = new Node(data);
    root->leftChildPtr = buildTree();
    root->rightChildPtr = buildTree(); 

    return root;
}

void Tree::preorderTraversal(Node* root)
{
    if(!root)   
        return;
    cout << root->data << "\t";
    preorderTraversal(root->leftChildPtr);
    preorderTraversal(root->rightChildPtr);
}

void Tree::inorderTraversal(Node* root)
{
    if(!root)   
        return;
    inorderTraversal(root->leftChildPtr);
    cout << root->data << "\t";
    inorderTraversal(root->rightChildPtr);
}

void Tree::postorderTraversal(Node* root)
{
    if(!root)   
        return;
    postorderTraversal(root->leftChildPtr);
    postorderTraversal(root->rightChildPtr);
    cout << root->data << "\t";
}

int Tree::heightOfTree(Node* root)
{
    int leftChildPtrHeight = (root->leftChildPtr != nullptr) ? heightOfTree(root->leftChildPtr) : 0;
    int rightChildPtrHeight = (root->rightChildPtr != nullptr) ? heightOfTree(root->rightChildPtr) : 0;
    if(root->leftChildPtr == nullptr && root->rightChildPtr == nullptr)
        return 1;

    return max(leftChildPtrHeight,rightChildPtrHeight) + 1;
}

void Tree::printKthLevelNodes(Node* root,int level)
{
    if(!root) return;
    if(level == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevelNodes(root->leftChildPtr,level-1);
    printKthLevelNodes(root->rightChildPtr,level-1);
    return;
}

//time complexity : O(N*N)
void Tree::levelOrderTraversal()
{
    int height = heightOfTree(m_root);

    for(int i = 1 ; i <= height ; i++)
    {
        printKthLevelNodes(m_root,i);
        cout << endl;
    }
}

//levelOrder traversal using BFS in O(N) time
void Tree::levelOrderTraversal_usingBFS()
{
    queue<Node *> q;
    if(m_root == nullptr)
        return;
    q.push(m_root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node *tmpNode = q.front();
        if(tmpNode == nullptr)
        {
            cout << endl;
            q.pop();
            if(!q.empty())
                q.push(nullptr);
        }//end if
        else
        {
            cout << tmpNode->data << " ";
            q.pop();

            if (tmpNode->leftChildPtr)
                q.push(tmpNode->leftChildPtr);
            if (tmpNode->rightChildPtr)
                q.push(tmpNode->rightChildPtr);
        }//end else
    }// end while
}//end levelOrderTraversal_usingBFS

/*
Assumption - Both a and b are present in the tree.
approach   - if C is the LCA of a and b then these two nodes belongs to the two subtrees \
             of the node C
*/
Node* Tree::LCA(Node* root, int a, int b)
{
  if(root==nullptr)
    return nullptr;

  //while finding nodes if we get any of the two nodes we return that node 
  if(root->data == a || root->data == b)
    return root;

  Node* rightSubTree = LCA(root->rightChildPtr,a,b);
  Node* leftSubTree = LCA(root->leftChildPtr,a,b);

  //this means we find a in one subtree and b in other subtree
  if(rightSubTree!=nullptr && leftSubTree!=nullptr)
    return root;

  if(leftSubTree!=nullptr)
    return leftSubTree;
  
  return rightSubTree;
}
