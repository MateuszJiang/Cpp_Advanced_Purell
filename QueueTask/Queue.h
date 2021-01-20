#pragma once
#include "Customer.h"

typedef Customer Item;

class Queue
{
private:
	enum {Q_SIZE = 10};
	struct Node
	{
		Item item;
		Node* next;
	};
private:
	Node* front;
	Node* rear;
	int items;
	const int qsize;
public:
	Queue(int size = Q_SIZE);
	~Queue();
	Queue(Queue&) = delete;
	Queue operator=(Queue&) = delete;

	bool isEmpty() const;
	bool isFull() const;
	int queueCount() const;
	bool addToQueue(const Item& item);
	bool removeFromQueue();
};