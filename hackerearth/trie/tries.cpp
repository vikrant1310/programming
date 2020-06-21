#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		char data;
		int	count; // this variable counts te number of times this node comes in other words..means common in other words
		bool terminal;
		unordered_map<char,Node*>	hashMapForChildNodes;

		Node(char ch) : data(ch),count(0),terminal(false)
		{}
};

class Trie
{
	public:
		Node *root;
		Trie()
		{
			root = new Node('\0');
		}
		void addWord(string word);
		int findMaxCountWithPrefix(string word);
};

void Trie::addWord(string word)
{
	Node *nodePtr = root;
	for(const auto &ch : word)
	{
		if(nodePtr->hashMapForChildNodes.find(ch) == nodePtr->hashMapForChildNodes.end())
		{
			Node *tmp = new Node(ch);
			nodePtr->hashMapForChildNodes[ch] = tmp;
		}
		nodePtr = nodePtr->hashMapForChildNodes[ch];
		nodePtr->count++;
	}
}

int Trie::findMaxCountWithPrefix(string word)
{
	Node *nodePtr = root;
	for(const auto &ch : word)
	{
		if(nodePtr->hashMapForChildNodes.find(ch) == nodePtr->hashMapForChildNodes.end())
			return 0;
		nodePtr = nodePtr->hashMapForChildNodes[ch];
	}
	return nodePtr->count;
}

int main()
{
	Trie t;
	int n;
	cin >> n;
	while(n--)
	{
		string operation;
		string word;
		cin >> operation >> word;
		
		if(operation == "add")
			t.addWord(word);
		else
			cout << t.findMaxCountWithPrefix(word) << endl;
	}
	return 0;
}
