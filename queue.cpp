#include <iostream>
#include <string>

using namespace std;

typedef int data;

struct queue
{
	data key;
	queue* next;
	
	queue(data key0, queue* next0)
	{
		key = key0;
		next = next0;
	}
	queue()
	{
		key = (data)0;
		next = NULL;
	}
	
};

queue *first *last = NULL;

void enqueue(data);
data dequeue();
bool empty();
data top(); // Last data queued

int main(void)
{
	
	return 0;
}

void enqueue(data in)
{
	if (first == NULL)
		first = last = &(queue(in,NULL));// Would this destruct on exiting the function ?
	
	last->next = queue(in,NULL);
	last = last->next;
}

data dequeue()
{
	if (first == NULL)
		throw "Cannot dequeue: Queue empty";
	
	data out = first->key;
	first = first->next;
	return out;
}

bool empty()
{
	if(first == NULL)
		return true;
	else
	    return false;
}

data top() // Last data queued
{
	if (first == NULL)
		throw "Queue empty"
	else
	    return (first->key);
}