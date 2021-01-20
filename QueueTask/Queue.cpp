#include "Queue.h"

Queue::Queue(int qs): items(0), qsize(qs)
{
	front = rear = nullptr;
}
Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::addToQueue(const Item& item)
{
	if (isFull())
	{
		return false;
	}
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = nullptr;

	if (front == nullptr)
	{
		front = newNode;
	}
	else
	{
		rear->next = newNode;
	}

	rear = newNode;
	items++;
	return true;
}
bool Queue::removeFromQueue()
{
	if (isEmpty())
	{
		return false;
	}
	items--;

	Node* temp = front;
	front = front->next;
	delete temp;

	if (isEmpty())
	{
		rear = nullptr;
	}
	return true;
}

bool Queue::isEmpty() const
{
	return items == 0;
}
bool Queue::isFull() const 
{
	return items == qsize;
}
int Queue::queueCount() const
{
	return items;
}