#include <iostream>
#include <string>

using namespace std;
//下面是浅拷贝实现 的类
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
//下面是深拷贝实现
class BinStrTree
{
	private:
		TreeNode *root;
	public:
		BinStrTree() : root(new TreeNode()){}
		BinStrTree(const BinStrTree &b){root = new TreeNode(*b.root);}
		BinStrTree &operator = (const BinStrTree &rhs);
		~BinStrTree(){delete root;}
};

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs)
{
	TreeNode *n_root = new TreeNode(*rhs.root);
	delete root;
	root = n_root;
	return *this;

}
int main(void)
{

	return 0;
}
