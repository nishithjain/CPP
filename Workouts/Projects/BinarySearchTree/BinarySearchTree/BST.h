#include <memory>
using namespace std;

struct TreeNode
{
	int data;
	shared_ptr<TreeNode>  left;
	shared_ptr<TreeNode>  right;
	TreeNode(int value) : data(value), left(nullptr), right(nullptr){}
};

class BinarySearchTree
{
	shared_ptr<TreeNode> root = nullptr;
	void print(const shared_ptr<TreeNode> node) const;
	void insert(shared_ptr<TreeNode>& node, int value);
	shared_ptr<TreeNode> findWithParent(int value, shared_ptr<TreeNode>& parent);
	void preorder(shared_ptr<TreeNode> node);
	void inorder(shared_ptr<TreeNode> node);
	void postorder(shared_ptr<TreeNode> node);
	void display(shared_ptr<TreeNode> node, int level);
public:
	BinarySearchTree();
	void insert(const int num);
	void print()const;
	bool find(int value);
	void preorder(void);
	void inorder(void);
	void postorder(void);
	void display(int level);
};