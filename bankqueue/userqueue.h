#include"listNode.h"

template<class dataType>
class userQueue {
public:
	listNode<dataType> *front_p;
	listNode<dataType> *rear_p;
	int node_sum;
	userQueue();
	~userQueue();
	bool Empty();
	bool Clear();
	bool GeFront(dataType &);
	bool DeQueue(dataType& item = 0);
	bool EnQueue(const dataType  item);
	template<dataType>
	friend ostream& operator << (ostream &, userQueue<dataType>&);
};

template<class dataType>
userQueue<dataType>::userQueue() {
	this->front_p = this->rear_p = NULL;
	this->node_sum = 0;
}

template<class dataType>
bool userQueue<dataType>::DeQueue(dataType& item) {
	listNode<dataType> *temp;
	if (this->Empty())
	{
		cout << "Queue is Empty. DeQueue Wrong" << endl;
		return false;
	}
	temp = this->front_p->next_node_point;
	item = *(this->front_p->node_data);
	delete this->front_p;
	this->front_p = temp;
	if (this->front_p == NULL)
	{
		this->rear_p = NULL;
	}
	this->node_sum--;
	return true;
}

template<class dataType>
bool userQueue<dataType>::EnQueue(const dataType item) {
	if (this->Empty())
	{
		this->rear_p = this->front_p = new listNode<dataType>;
		*(this->front_p->node_data) = item;
		this->rear_p->next_node_point = NULL;
	}
	else
	{
		this->rear_p = this->rear_p->next_node_point = new listNode<dataType>;
		*(this->rear_p->node_data) = item;
		this->rear_p->next_node_point = NULL;
	}
	this->node_sum++;
	return true;
}

template<class dataType>
bool userQueue<dataType>::Empty() {
	if (this->node_sum == 0)
	{
		return true;
	}
	return false;
}

template<class dataType>
bool userQueue<dataType>::Clear() {
	this->node_sum = 0;
	listNode<dataType> *temp;
	for (temp = this->front_p; temp->next_node_point != NULL; temp = temp->next_node_point)
	{
		delete temp;
	}
	this->front_p = this->rear_p = NULL;
}

template<class dataType>
ostream& operator << (ostream &out, userQueue<dataType>&mque) {
	listNode<dataType> *temp = mque.front_p;
	int counter;
	if (mque.node_sum != 0)
	{
		for (counter = 0; counter < mque.node_sum; counter++)
		{
			cout << *temp;
			temp = temp->next_node_point;
		}
	}
	else
	{
		cout << "Queue Empty, Output Wrong! " << endl;
	}
	return out;
}

template<class dataType>
bool userQueue<dataType>::GeFront(dataType &item) {
	if (!this->Empty())
	{
		item = *(this->front_p->node_data);
		return true;
	}
	else
	{
		cout << "Queue Empty, Get Wrong!" << endl;
		return false;
	}
}
template<class dataType>
userQueue<dataType>::~userQueue() {
	if (this->node_sum > 0)
	{
		listNode<dataType> *temp = this->front_p->next_node_point;
		delete this->front_p;
		for (int counter = 0; counter < this->node_sum - 1; counter++)
		{
			this->front_p = temp->next_node_point;
			delete temp;
			temp = this->front_p;
		}
	}
}
#pragma once
