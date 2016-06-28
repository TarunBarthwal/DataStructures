#include <iostream>
#include <assert>

using namespace std;

typedef int data_type;

class binary_search_tree
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

	bool isBinarySearchTree0(tree_node* current, data_type& max, data_type& min)
	{
		assert(current != NULL);
		data_type min_right = current->node_value, min_left = current->node_value,
		    max_right = current->node_value, max_left = current->node_value;
		
		bool left_check = true, right_check = true;
		
		if (current -> left != NULL)
			left_check = isBinarySearchTree0(current -> left, max_left, min_left);
		
		if (left_check) && (current -> right != NULL)
			right_check = isBinarySearchTree0(current -> right, max_right, min_right);


		if (right_check && left_check) && (current->node_val >= max_left) && (current->node_val =< min_right)
		{
			min = min_left; max = max_right;
			return true;
		}

		return false;
	}

	
	tree_node* root;
	void insert_node(tree_node* in, tree_node*& current)
	{
		if (current == NULL)
		{
			current = in;
			return;
		}	
		if (in->node_value <= current->node_value)
			insert_node(in, current->left);
		else
			insert_node(in, current->right);
		
	}
public:

	binary_tree()
	{
		root = new tree;
	}
	
	tree_node* minima(tree_node* current = root)
	{
		if (current == NULL)
			return current;
		while (current->left != NULL)
			current = current->left;
		return current;
	}
	
	tree_node* maxima(tree_node* current = root)
	{
		if (current == NULL)
			return current;
		while (current->right != NULL)
			current = current->right;
		return current;
	}
	
	bool isBinarySearchTree(void)
	{
		data_type min,max; // To be ignored
		return isBinarySearchTree0(root, min, max);
	}
	
	
	void insert(data_type in)
	{
		tree_node* input = new tree_node(in);
		insert_node(input, root);
	}
	
	void printPrevious(tree_node* current)
	{
		assert(current != NULL);
		
		if (current->left != NULL)
		{
			current = maxima(current->right);
			cout<<current->node_value;
			return;
		}

		while(current->parent != NULL)
		{
			if((current->parent)->right != current)
				current = current->parent;
			else
			{
				cout<<current->node_value;
				return;
			}	
		}
		cout<<"Previous node does not exist";
		return;	
	}
	
	void printNext(tree_node* current)
	{	
		assert (current != NULL);
		
		if (current->right != NULL)
		{
			current = minima(current->right);
			cout<<current->node_value;
			return;
		}

		while(current->parent!=NULL)
		{
			if((current->parent)->left != current)
				current = current->parent;
			else
			{
				cout<<current->node_value;
				return;
			}
		}
		cout<<"Next node does not exist";
		return;
	}	
};
