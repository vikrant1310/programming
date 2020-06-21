#include<iostream>
#include<unordered_map>

using namespace std;

//this class implements the node structure of tries data structure
class Node
{
    public:
    char data;
    bool terminal;
    unordered_map<char,Node*> hashMapOfChildren;

    Node(char data)
    {
        this->data = data;
        this->terminal = false;
    }
};

//this class implements trie data structure , this is very useful if we need to lookup some stings in the storage.
class Trie
{
    public:
    Node *root;
    int count;

    Trie()
    {
        //this constructor makes an trie with just the root || just an empty trie
        this->root = new Node('\0');
        this->count =0;
    }
    void addWord(string word);
    bool isWordPresent(string word);
};

void Trie::addWord(string word)
{
    Node *nodePtr = root;
    for(int i=0; i<word.size(); i++)
    {
        if( nodePtr->hashMapOfChildren.find(word[i]) != nodePtr->hashMapOfChildren.end() )
            nodePtr = nodePtr->hashMapOfChildren[word[i]];
        else
        {
            Node *tmp = new Node(word[i]);
            nodePtr->hashMapOfChildren[word[i]] = tmp;
            nodePtr = tmp;
        }
    }
    nodePtr->terminal = true;
}

bool Trie::isWordPresent(string word)
{
    Node *nodePtr = root;
    for(const auto &ch : word)
    {
        if(nodePtr->hashMapOfChildren.find(ch) == nodePtr->hashMapOfChildren.end())
            return false;
        nodePtr = nodePtr->hashMapOfChildren[ch];
    }
    return nodePtr->terminal;
}

int main(int argc, char const *argv[])
{
    Trie t;
    int words;
    string word;
    cin >> words;
    while(words--)
    {
        cin >> word;
        t.addWord(word);
    } 
    int q;
    string presentOrAbsent;
    cin >> q;
    while(q--)
    {
        cin >> word;
        presentOrAbsent =  (t.isWordPresent(word)) ? "present" : "absent";
        cout << word << " is " << presentOrAbsent << endl;
    }
    return 0;
}
