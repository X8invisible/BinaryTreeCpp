#include "BinarySearchTree.h"

using namespace std;
// **Constructors **
BinarySearchTree::BinarySearchTree()
{
	
}


BinarySearchTree::BinarySearchTree(std::string word)
{
	root = new Node;
	root->word = word;
}
void helpInsert(Node **ptr, string s)
{
	if(*ptr == nullptr)
	{
		*ptr = new Node;
		(*ptr)->word = s;
	}else
	{
		if((*ptr)->word.compare(s)!=0)
		{
			if((*ptr)->word.compare(s)>0)
				helpInsert(&((*ptr)->left),s);
			else
				helpInsert(&((*ptr)->right),s);
			
		}
	}
}
void helpCopy(Node *to, Node *from)
{
	if(from != nullptr)
	{
		helpInsert(&to, from->word);
		helpCopy(to,from->left);
		helpCopy(to,from->right);
	}
}
BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
	helpCopy(root, rhs.root);
}


BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	for(int i = 0; i < words.size(); i++)
	{
		insert(words[i]);
	}
	
}
//destructor
BinarySearchTree::~BinarySearchTree()
{

}

// **Methods**
void BinarySearchTree::insert(std::string word)
{
	helpInsert(&root, word);
}
bool helpExists(Node *ptr, string s)
{
	if(ptr != nullptr)
	{
		if(ptr->word.compare(s) == 0)
			return true;
		else
		{
			if(ptr->word.compare(s)>0)
				return helpExists(ptr->left,s);
			else
				return helpExists(ptr->right,s);
			
		}
	}
	
	return false;
}
bool BinarySearchTree::exists(std::string word) const
{
	bool result;
	result = helpExists(root, word);
	return result; // change this to implement the method, returning true if word exists
}

string helpInOrder(Node *ptr)
{
	string s = "";
	if(ptr != nullptr)
	{
		s+= helpInOrder(ptr->left);
		s+= (ptr->word + " ");
		s+= helpInOrder(ptr->right);
	}
	return s;
}
std::string BinarySearchTree::inorder() const
{
	string result = "";
	if(this != nullptr)
	{
		result = helpInOrder(root);
		
	}
	if(result != "")
		result.pop_back();
	return result; // change this to return a string representation of the words
	// in the tree inorder.
}


std::string BinarySearchTree::preorder() const
{
	return std::string(""); // change this to return a string representation of the words
	// in the tree preorder.
}


std::string BinarySearchTree::postorder() const
{
	return std::string(""); // change this to return a string representation of the words
	// in the tree postorder.
}
    
// **Operator overloads**
    

BinarySearchTree& BinarySearchTree::operator+(std::string word)
{
	return *this; // returns a reference to the modified tree
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	return *this;
}


