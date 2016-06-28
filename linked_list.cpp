#include <iostream>

using namespace std;

typdef int data_type;

class linked_list
{
    private:
        stuct list_node
        {
            data_type node_value;
            list_node *next;

            list_node(data_type in)
            {
                node_value = in;
                next = NULL;
                //	prev = NULL;
            }

        };

        list_node *head;
        list_node* merge_sort_combine(list_node*, list_node*);
        list_node* merge_sort(list_node*);

    public:
        linked_list()
        {
            head = NULL;
        }
        bool search(data_type);
        void sort_list()
        {
            head = merge_sort(head);
        }
        void reverse_list();
        void insert(data_type);
        void insert(data_type, int);
        int remove(data_type);
        list_node* tail();
        {
            if (head == NULL)
            return head;
            list_node* current = head;
            while(current->next != NULL)
            current = current->next;
            return current;
        }
};

int main(void)
{
    return 0;
}

bool linked_list::search(data_type search_value)
{
    list_node *current = head;

    while (current != NULL)
    {
        if (current->node_value == search_value)
            return true;
        current = current->next;
    }
    return false;
}

list_node* linked_list::merge_sort(list_node *start1)
{
    if (start1 == NULL || start1->next == NULL)
        return;

    list_node *end = start1;
    list_node *middle = start1;

    while (end->next != NULL)
    {
        if (end->next->next == NULL)
            break;	// checking for end case where
        end = end->next->next;
        middle = middle->next;
    }

    list_node* start2 = middle->next;
    middle->next = NULL;
    return merge_sort_combine(merge_sort(start1), merge_sort(start2));
}

list_node* merge_sort_combine(list_node* start1, list_node* start2)
{
    if (start2 == NULL)
        return start1;
    if (start1 == NULL)
        return start2;

    list_node* sorted_current;
    list_node* head_sorted;
    if (start1->node_value <= start2->node_value)
    {
        sorted_current = head_sorted = start1;
        start1 = start1->next;
    } else 	//(start2->node_value < start1->node_value)
    {
        sorted_current = head_sorted = start2;
        start2 = start2->next;
    }

    while ((start1 != NULL) && (start2 != NULL))
    {
        if (start1->node_value <= start2->node_value)
        {
            sorted_current->next = start1;
            start1 = start1->next;
        } else 		//(start2->node_value < start1->node_value)
        {
            sorted_current->next = start2;
            start2 = start2->next;
        }

    }
    if (start2 == NULL)
        sorted_currernt->next = start1;
    else
        //((start2 != NULL) && (start2 == NULL)) [Both are never NULL]
        sorted_currernt->next = start2;

    return head_sorted;
}

void linked_list::reverse_list()
{
    if (head == NULL)
        return;

    list_node *current = head;
    list_node *after_current = current->next;
    current->next = NULL;
    while (after_current != NULL)
    {
        head = after_current;
        after_current = after_current->next;
        head->next = current;
        current = head;
    }

}

void linked_list::insert(data_type in)
{
    list_node *temp = head;
    head = new list_node(in);
    head->next = temp;
}

bool linked_list::remove(data_type out)
{
    if (head == NULL)
        return false;
    if (head->node_value == out)
    {
        list_node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    list_node *current = head;
    list_node *after_current = current->next;

    while (after_current != NULL)
    {
        if (after_current->node_value == out)
        {
            current->next = after_current->next;
            delete after_current;
            return true;
        }
        current = current->next;
        after_current = after_current->next;
    }
    return false;
}
