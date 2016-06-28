#include <iostream>
#include <assert>

using namespace std;

typedef int data_type;

struct queue_node
{
	data_type node_val;
	struct queue_node* next;
	
	queue_node(data_type node_val0)
	{
		node_val = node_val0;
		next = NULL;
	}	
};

typedef queue_node* queue ;

void enqueue(queue_node * & , data_type); //Forward declartion
data_type dequeue(queue_node * &);
bool empty(queue_node *);
data_type top(queue_node *);

int main(void)
{
	try
	{
		queue a, b;
		push(a,12);
		push(b,14);
		push(a,8);
		cout<<"Deleted value = "<<pop(b)<<endl;
		cout<<"Queue b is empty: "<<empty(b)<<endl;
		cout<<"Queue a is empty: "<<empty(a)<<endl;
	
	}
	catch (const char*s) cout<<"Error: "<<s<<endl;
	
	return 0;
}

void enqueue(queue_node* & top, data_type in)
{
	if (top == NULL)
		top = new queue_node(in);
	else
	{
		stack_node *old_top = top;
		top = new queue_node(in);
		top->next = old_top;
	}
}

data_type dequeue(queue_node * &top)
{
	data_type out;

	if (top == NULL) throw "Cannot dequeue: Queue empty";
	
	if (top->next == NULL)
	{
		out = top->node_val;
		delete top;
		top = NULL; //Missing
	}
	else
	{
		queue_node *current = top;
		assert(current->next != NULL);
		if (current->next == NULL) throw "This should not happen"; // Exception

		while (current->next->next) // If p pointer is NULL, the while(p) is false 
			current=current->next;
	
		out = current->next;
		delete (current->next);
		current->next = NULL;
	}
	
	return out;
}

bool empty(queue_node* top)
{
	if(top == NULL)
		return true;
	else
	    return false;
}

data_type top(queue_node *top)
{
	if (top == NULL)
		throw "Queue empty"
	else
	    return (top->node_val);
}
