#include <iostream>
#include <queue>
using namespace std;

typedef int data_type;

class binary_tree
{
private:
	struct tree_node
	{
		data_type node_value;
		tree_node* left, right, parent;	
		
		tree_node(data_type in)
		{
			node_value = in;
			left = right = parent = NULL;
		}
	};
	
	tree_node* root;

public:
	binary_tree()
	{
		root = new tree;
	}
	
	void print_inorder(tree_node* current_node = root)
	{
		if (current_node == NULL)
			return;
		print_inorder(current_node->left);
		cout<<current_node->node_value;
		print_inorder(current_node->right);	
	}
	void print_preorder(tree_node* current_node = root)
	{
		if (current_node == NULL)
			return;
		cout<<current_node->node_value;
		print_inorder(current_node->left);
		print_inorder(current_node->right);
	}	
	
	void print_postorder(tree_node* current_node = root)
	{
		if (current_node == NULL)
			return;
		print_inorder(current_node->left);
		print_inorder(current_node->right);
		cout<<current_node->node_value;
		
	}	
	
	void print_breadth_first()
	{
		if (root == NULL)
			return;
		int level = 0;
		queue<tree_node*> qptr;
		
		qptr.push(root);
		qptr.push(NULL);
		
		while(!qptr.empty())
		{
			if (qptr.front() == NULL)
			{
				level++;
				qptr.pop();
				if(!qptr.empty())
					qptr.push(NULL);
			}
			else
			{
				cout<<(qptr.front())->node_value<<", ";
				if((qptr.front())->left != NULL)
					qptr.push((qptr.front())->left);
				if((qptr.front())->right != NULL)
					qptr.push((qptr.front())->right);
				qptr.pop();
			}
		}
	}
	
	void right_rotation()
	{
		if (root == NULL)
			return;
		tree_node* temp = root;
		if(root->left == NULL)
			throw ("tree right rotation will lose the tree");
		root = root->left;
		temp->left = root->right;
		root->right = temp;
		
	}
	
	void left_rotation()
	{
		tree_node* temp = root;
		if(root->right == NULL)
			throw ("tree left rotation will lose the tree");
		root = root->right;
		temp->right = root->left;
		root->left = temp;
	}

};
