#include <iostream>

using namespace std;

typedef int data;

class stack
{
    private:
        struct stack_node
        {
                data node_data;
                stack_node* next;
                stack_node(data node_data0)
                {
                    node_data = node_data0;
                    next = NULL;
                }
                stack_node()
                {
                    node_data = (data) 0;
                    next = NULL;
                }
        };

        stack_node* s;

    public:

        stack(void)
        {
            s = NULL;
        }

        void push(data in)
        {
            if (s == NULL)
            {
                s = new stack_node(in);
            } else
            {
                stack_node* current = s;

                while (current->next != NULL)
                    current = current->next;
                current->next = new stack_node(in);
            }
        }

        data pop()
        {
            data out;
            if (s == NULL)
                throw "Cannot pop: Stack empty";
            out = s->node_data;
            stack_node* tmp = s;
            s = s->next;
            free(tmp); //delete tmp;
            return out;
        }

        data top()
        {
            if (s == NULL)
                throw "Stack empty";
            return s->node_data;
        }

        bool empty()
        {
            if (s == NULL)
                return true;
            else
                return false;
        }

};

int main(void)
{
    try
    {
        stack a, b;
        a.push(24);
        b.push(4);
        a.push(2);
        cout << a.pop() << endl;
        cout << b.top() << endl;

        cout << "Is the stack empty?: " << a.empty();

    }
    catch (const char* s) // This will catch any throw statemens
    {
        cout << "Error:" << s << endl;
    }
    return 0;
}

