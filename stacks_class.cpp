#include <iostream>
// Q. should try catch be defined in class instead of main?
// Q. member variable and member function same name! is it possible?
//
//
using namespace std;

typedef int data_type;

class stack
{
private:
	struct stack_node
	{
		data_type node_val;
		stack_node* next;
		stack_node(data_type node_val0)
		{
			node_val = node_val0;
			next = NULL;
		}	
		stack_node()
		{
			node_val = (data_type)0;
			next = NULL;
		}
	};

	stack_node* top;

public:

	stack(void) { top = NULL; }

	void push(data_type in)
	{
		if (top == NULL)
		{
			top = new stack_node(in);
		}
		else
		{
			stack_node* current = top;
			top = new stack_node(in);
			top->next = current;
			
		}
	}

	data_type pop()
	{
		data_type out;
		if (top == NULL)
			throw "Cannot pop: Stack empty";
		out = top->node_val;
		stack_node* temp = top;
		top = top->next;
		delete temp;
		
		return out;
	}

	data_type top()
	{
		if (top == NULL)
			throw "Stack empty";
		return top->node_val;
	}

	bool empty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

};

int main(void)
{
	try
	{
		stack a,b;
		a.push(24);
		b.push(4);
		a.push(2);
		cout<<a.pop()<<endl;
		cout<<b.top()<<endl;

		cout<<"Is the stack empty?: "<<a.empty();
		
	}
	catch(const char* s) // This will catch any throw statemens
    {
        cout<<"Error:"<<s<<endl;
    }

	return 0;
}

