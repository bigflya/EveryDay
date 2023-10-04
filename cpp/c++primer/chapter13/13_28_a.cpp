#include <iostream>
#include <string>

using namespace std;

class TreeNode
{
	private:
		string value;
		int *count;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode() : value(string()),count(new int(1)),left(new TreeNode),right(new TreeNode){}
		TreeNode(const TreeNode &t) : value(t.value),count(t.count),left(t.left),right(t.right){++*count;}
		TreeNode &operator = (const TreeNode &rhs);
		~TreeNode();
};

TreeNode &TreeNode::operator =  (const TreeNode &rhs)
{
	++*rhs.count;
	if(--*count ==0)
	{
		delete count;
		delete left;
		delete right;
	}
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;

	return *this;
}
TreeNode::~TreeNode()
{
	if(--*count ==0)
	{
		delete count;
		delete left;
		delete right;

	}
}

int main(void)
{

	return 0;
}
