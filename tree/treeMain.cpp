#include "tree.h"

int main()
{
    Tree t1 ;
    Node *root = t1.buildTree();
    t1.setRoot(root);

    cout << "\nPreOrder Traversal : ";
    t1.preorderTraversal(root);

    cout << "\nInOrder Traversal : ";
    t1.inorderTraversal(root);

    cout << "\nPostOrder Traversal : ";
    t1.postorderTraversal(root);

    int height =  t1.heightOfTree(root);

    cout << "\nheight of tree : " << height << endl;

    cout << "\n\nLevel Order Traversal :\n";
    t1.levelOrderTraversal(); 

    cout << "\n\nLevel Order Traversal (using BFS) :\n";
    t1.levelOrderTraversal_usingBFS();

    int a,b;
    cout << "\nFinding LCA of : " ;
    cin >> a >> b;
    cout << "\n" << t1.LCA(root,a,b)->data  << "\n";

    delete root; //freeing up memory
    return 0;
}

/*
input :
1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
6 9

output :

PreOrder Traversal : 1	2	4	6	7	10	11	5	8	9	3	
InOrder Traversal : 6	4	10	7	11	2	8	5	9	1	3	
PostOrder Traversal : 6	10	11	7	4	8	9	5	2	3	1	

height of tree : 5

Level Order Traversal :
1 
2 3 
4 5 
6 7 8 9 
10 11 

Level Order Traversal (using BFS) :
1 
2 3 
4 5 
6 7 8 9 
10 11 

Finding LCA of : 6 9 
2

*/
