#include <iostream>

using namespace std;

typedef int data_type;

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
            node_val = (data_type) 0;
            next = NULL;
        }
};

typedef stack_node* stack;

void push(stack_node *, data_type);
data_type pop(stack_node *);
bool empty(stack_node *);
data_type top(stack_node *);

int main(void)
{
    try
    {
        stack a, b;
        push(a, 24);
        push(b, 4);
        push(a, 2);
        cout << pop(a) << endl;
        cout << top(b) << endl;

        cout << "Is the stack empty?: " << empty(a);

    }
    catch (const char* s)
    {
        cout << "Error:" << s << endl;
    }
    return 0;
}

void push(stack_node *top, data_type in)
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

data_type pop(stack_node *top)
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

data_type top(stack_node *top)
{
    if (top == NULL)
        throw "Stack empty";

    return top->node_val;
}

bool empty(stack_node *top)
{
    if (top == NULL)
        return true;
    else
        return false;
}

