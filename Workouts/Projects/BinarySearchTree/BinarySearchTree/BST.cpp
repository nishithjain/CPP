#include <iostream>
#include "BST.h"
using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}
void BinarySearchTree::insert(const int num)
{
	if (root == nullptr) 
	{
		std::unique_ptr<TreeNode> node(new TreeNode(num));
		root = std::move(node);
		return;
	}
	else
	{
		insert(root, num);
	}
}
void BinarySearchTree::insert(shared_ptr<TreeNode>& node, int value)
{
	if (node->data > value)
	{
		if (node->left == nullptr)
		{
			std::unique_ptr<TreeNode> newNode(new TreeNode(value));
			node->left = std::move(newNode);
		}
		else
			insert(node->left, value);
	}
	else
	{
		if (node->right == nullptr)
		{
			std::unique_ptr<TreeNode> newNode(new TreeNode(value));
			node->right = std::move(newNode);
		}
		else
			insert(node->right, value);
	}
}
bool BinarySearchTree::find(int value)
{
	shared_ptr<TreeNode> parent = nullptr;
	return findWithParent(value, parent) != nullptr;
}
shared_ptr<TreeNode> BinarySearchTree::findWithParent(int value, shared_ptr<TreeNode>& parent)
{
	parent = nullptr;
	shared_ptr<TreeNode> current = root;

	while (current != nullptr)
	{
		int result = current->data - value;

		if (result > 0)
		{
			parent = current;
			current = current->left;
		}
		else if (result < 0)
		{
			parent = current;
			current = current->right;
		}
		else
			break;
	}
	return current;
}
void BinarySearchTree::preorder(shared_ptr<TreeNode> node)
{
	if (node != nullptr)
	{
		cout << node->data << "  ";
		preorder(node->left);
		preorder(node->right);
	}
}
void BinarySearchTree::inorder(shared_ptr<TreeNode> node)
{
	if (node != nullptr)
	{
		inorder(node->left);
		cout << node->data << "  ";
		inorder(node->right);
	}
}
void BinarySearchTree::postorder(shared_ptr<TreeNode> node)
{
	
	if (node != nullptr)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->data << "  ";
	}
}
void BinarySearchTree::display(int level)
{
	if (root == nullptr)
	{
		cout << " Tree is EMPTY!!!\n";
		return;
	}
	display(root, level);
}
void BinarySearchTree::display(shared_ptr<TreeNode> ptr, int level)
{
	int i;
	if (ptr != nullptr)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}
void BinarySearchTree::preorder(void)
{
	if (root == nullptr)
	{
		cout << " Tree is EMPTY!!!\n";
		return;
	}
	preorder(root);
}
void BinarySearchTree::inorder(void)
{
	if (root == nullptr)
	{
		cout << " Tree is EMPTY!!!\n";
		return;
	}
	inorder(root);
}
void BinarySearchTree::postorder(void)
{
	if (root == nullptr)
	{
		cout << " Tree is EMPTY!!!\n";
		return;
	}
	postorder(root);
}