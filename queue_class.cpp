#include <iostream>
#include <assert>

using namespace std;

typedef int data_type;

class queue
{
private:
	struct queue_node
	{
		data_type node_val;
		queue_node* next;
	
		queue_node(data_type node_val0)
		{
			node_val = node_val0;
			next = NULL;
		}
	
	};
	queue_node *head;
	
public:
	queue()
	{
		head = NULL;
	}
	void enqueue(data_type);
	data_type dequeue();
	bool empty();
	data_type top();
};


int main(void)
{
	try
	{
		queue a, b;
		a.enqueue(12);
		b.enqueue(14);
		a.enqueue(8);
		cout<<"Deleted value = "<<b.dequeue()<<endl;
		cout<<"Queue b is empty: "<<b.empty()<<endl;
		cout<<"Queue a is empty: "<<a.empty()<<endl;
	
	}
	catch (const char*s) cout<<"Error: "<<s<<endl;
	
	return 0;
}

void queue::enqueue(data_type in)
{
	if (head == NULL)
		head = new queue_node(in);
	else
	{
		stack_node *old_head = head;
		head = new queue_node(in);
		head->next = old_head;
	}
}

data_type queue::dequeue()
{
	data_type out;
	if (head == NULL)
		throw "Cannot dequeue: Queue empty";
	
	if (head->next == NULL)
	{
		out = head->node_val;
		delete head;
		head = NULL;
	}
	else
	{
		queue_node* current = head;
		assert(current->next != NULL);
		
		while (current->next->next)
			current = current->next;
		
		out = current->next->node_val;
		delete current->next;
		current->next = NULL;
	}
	
	return out;
}

bool queue::empty()
{
	if(head == NULL)
		return true;
	else
	    return false;
}

data_type queue::head()
{
	if (head == NULL)
		throw "Queue empty"
	else
	    return (head->node_val);
}
