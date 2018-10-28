#include<iostream>
#include"listnode.h"
using namespace std;

template<class dataType>
class bankList {
private:
	listNode<dataType> * front_point;
	listNode<dataType>* rear_point;
	int nodeNum;
public:
	bankList();
	~bankList();
	bool empty();
	dataType append(dataType);
	bool deleteAll(dataType &);
	dataType deleteData(dataType & dt);
	dataType deleteMinReplace();
	int deleteAllMin();
	int deleteIndex(int index);
	dataType operator [](int index);
	template<class dataType>
	friend iostream& operator <<(iostream&, bankList<dataType> &);
};

template<class dataType>
bankList<dataType>::bankList() {
	this->front_point = new listNode<dataType>;
	this->front_point->identification = 1;
	this->rear_point = new listNode< dataType >;
	this->rear_point->identification = -1;
	this->front_point->next_node_point = this->rear_point;
	this->nodeNum = 2;
	this->front_point->node_data = NULL;
	this->rear_point->node_data = NULL;
}

template<class dataType>
bankList<dataType>::~bankList() {
	/*listNode< dataType > * now = this->front_point;
	listNode< dataType >	*now_next =NULL;
	if(now != NULL&&now->next_node_point != NULL)
	now_next = now->next_node_point;
	//if(this->front_point->node_data!=NULL)
	for (int i = 0; i < this->nodeNum; i++)
	{
	delete now;
	now = now_next;
	if(now != NULL)
	now_next = now->next_node_point;
	}
	this->front_point = this->rear_point = NULL;*/
}

template<class dataType>
bool bankList<dataType>::empty() {
	if (this->nodeNum <= 2 && this->front_point->node_data == NULL)
		return true;
	else
		return false;
}

template<class dataType>
dataType bankList<dataType>::append(dataType dt) {
	listNode< dataType > * now = this->front_point;
	if (this->nodeNum >= 2 && this->front_point->node_data == NULL)
	{
		for (int i = 0; i < this->nodeNum - 2; i++)
		{
			now = now->next_node_point;
		}
		now->next_node_point = new listNode<dataType>(dt);
		now->next_node_point->next_node_point = rear_point;
		now->next_node_point->identification = 0;
		this->nodeNum += 1;
	}
	else
	{
		if (this->nodeNum == 0)
		{
			front_point = new listNode<dataType>(dt);
			front_point->next_node_point = NULL;
			rear_point = front_point;
			front_point->identification = 0;
			this->nodeNum += 1;
		}
		else
		{
			rear_point->next_node_point = new listNode<dataType>(dt);
			rear_point = rear_point->next_node_point;
			rear_point->next_node_point = NULL;
			rear_point->identification = 0;
			this->nodeNum += 1;
		}
	}
	return dt;
}

template<class dataType>
iostream& operator << (iostream& out, bankList<dataType> &mlst) {
	listNode<dataType> *iteration_point = NULL;
	if (mlst.empty())
	{
		cout << "This List is EMPTY" << endl;
		return out;
	}
	if (mlst.front_point->node_data == NULL)
	{
		iteration_point = mlst.front_point->next_node_point;
		for (int iteration_num = 0; iteration_num < mlst.nodeNum - 2 && iteration_point != NULL; iteration_num++)
		{
			cout << *(iteration_point->node_data);
			iteration_point = iteration_point->next_node_point;
		}
	}
	else
	{
		iteration_point = mlst.front_point;
		for (int iteration_num = 0; iteration_num < mlst.nodeNum; iteration_num++)
		{
			cout << *(iteration_point->node_data);
			iteration_point = iteration_point->next_node_point;
		}
	}
	return out;
}

template<class dataType>
bool bankList<dataType>::deleteAll(dataType & dt) {
	listNode<dataType> *iteration_point = this->front_point->next_node_point;
	listNode<dataType> *iteration_point_before = this->front_point;
	if (this->empty() && this->front_point->node_data != NULL)
	{
		cout << "The List is EMPTY. Delete Fail" << endl;
		return false;
	}
	for (; !(iteration_point->identification);)
	{
		if (dt == *(iteration_point->node_data))
		{
			iteration_point_before->next_node_point = iteration_point->next_node_point;
			delete iteration_point;
			this->nodeNum = this->nodeNum - 1;
			iteration_point = iteration_point_before->next_node_point;
		}
		else
		{
			iteration_point_before = iteration_point_before->next_node_point;
			iteration_point = iteration_point_before->next_node_point;
		}
	}
	return true;
}

template<class dataType>
int bankList<dataType>::deleteIndex(int index) {
	listNode<dataType> *iteration_point = this->front_point;
	listNode<dataType> *iteration_point_before = this->rear_point;
	int sum, temp_id;
	if (this->nodeNum == 1)
	{
		this->nodeNum -= 1;
		temp_id = front_point->identification;
		delete front_point;
		front_point = rear_point = NULL;
		return temp_id;
	}
	if (this->empty())
	{
		cout << "The List is EMPTY. Delete Fail" << endl;
		return 0;
	}
	if (this->front_point != this->rear_point->next_node_point)
	{
		cout << "Wrong List Type" << endl;
		return -1;
	}
	for (sum = 0; ; sum++)
	{
		if (sum == index)
		{
			if (sum == 0)
			{
				temp_id = iteration_point->identification;
				iteration_point = this->front_point;
				iteration_point_before = this->rear_point;
				iteration_point_before->next_node_point = iteration_point->next_node_point;
				delete iteration_point;
				front_point = iteration_point_before->next_node_point;
				rear_point = iteration_point_before;
				this->nodeNum -= 1;
				return temp_id;
			}
			else if (sum == this->nodeNum - 1)
			{
				this->rear_point = iteration_point_before;
				iteration_point_before->next_node_point = this->front_point;
				temp_id = iteration_point->identification;
				delete iteration_point;
				this->nodeNum -= 1;
				return temp_id;
			}
			else
			{
				iteration_point_before->next_node_point = iteration_point->next_node_point;
				temp_id = iteration_point->identification;
				delete iteration_point;
				this->nodeNum -= 1;
				return temp_id;
			}
		}
		else {
			iteration_point_before = iteration_point;
			iteration_point = iteration_point->next_node_point;
		}
	}
}

template<class dataType>
dataType bankList<dataType>::deleteData(dataType & dt) {
	listNode<dataType> *iteration_point = this->front_point->next_node_point;
	listNode<dataType> *iteration_point_before = this->front_point;
	if (this->empty() && this->front_point->node_data != NULL)
	{
		cout << "The List is EMPTY. Delete Fail" << endl;
		return 0;
	}
	for (; !(iteration_point->identification);)
	{
		if (dt == *(iteration_point->node_data))
		{
			iteration_point_before->next_node_point = iteration_point->next_node_point;
			delete iteration_point;
			this->nodeNum = this->nodeNum - 1;
			iteration_point = iteration_point_before->next_node_point;
			return dt;
		}
		else {
			iteration_point_before = iteration_point;
			iteration_point = iteration_point->next_node_point;
		}
	}
}

template<class dataType>
dataType bankList<dataType>::deleteMinReplace() {
	listNode<dataType> *iteration_point_before = this->front_point->next_node_point;
	listNode<dataType> *iteration_point = iteration_point_before->next_node_point;
	listNode<dataType> *it_p = NULL;
	listNode<dataType> *rear_before = NULL;
	int sum, flag = 1;
	dataType minute_data = *(iteration_point_before->node_data);
	if (this->empty() && this->front_point->node_data != NULL)
	{
		cout << "The List is EMPTY. Delete Fail" << endl;
		return NULL;
	}
	for (sum = 0; sum<this->nodeNum - 3; sum++)//Ñ°ÕÒ×îÐ¡Öµ
	{
		if (*(iteration_point->node_data) < minute_data)
		{
			minute_data = *(iteration_point->node_data);
		}
		iteration_point = iteration_point->next_node_point;
	}
	iteration_point_before = this->front_point;
	iteration_point = iteration_point_before->next_node_point;
	for (sum = 0; iteration_point_before->next_node_point->node_data != NULL;)
	{
		for (it_p = front_point->next_node_point; flag;)
		{
			if (it_p->next_node_point->next_node_point->identification == -1)
			{
				rear_before = it_p;
				flag = 0;
				break;
			}
			it_p = it_p->next_node_point;
		}
		if (*(iteration_point->node_data) == minute_data)
		{
			if (iteration_point == rear_before)
			{
				iteration_point_before->next_node_point = rear_before->next_node_point;
			}
			else {
				iteration_point_before->next_node_point = rear_before->next_node_point;
				rear_before->next_node_point->next_node_point = iteration_point->next_node_point;
				rear_before->next_node_point = rear_point;
			}
			delete iteration_point;
			this->nodeNum = this->nodeNum - 1;
			flag = 1;
		}
		iteration_point_before = iteration_point_before->next_node_point;
		iteration_point = iteration_point_before->next_node_point;
		sum++;
	}
	return minute_data;
}

template<class dataType>
int bankList<dataType>::deleteAllMin() {
	listNode<dataType> *iteration_point_before = this->front_point->next_node_point;
	listNode<dataType> *iteration_point = iteration_point_before->next_node_point;
	dataType minute_data = *(iteration_point_before->node_data);
	if (this->empty() && this->front_point->node_data != NULL)
	{
		cout << "The List is EMPTY. Delete Fail" << endl;
		return false;
	}
	for (; !(iteration_point->identification);)
	{
		if (*(iteration_point->node_data) < minute_data)
		{
			minute_data = *(iteration_point->node_data);
		}
		iteration_point = iteration_point->next_node_point;
	}
	this->deleteAll(minute_data);
}

template<class dataType>
dataType bankList<dataType>::operator [](int index) {
	int i;
	listNode<dataType> *temp = this->front_point;
	if (index<0 || index >this->nodeNum - 2)
	{
		cout << "Index Wrong" << endl;
		return 0;
	}
	for (i = 0; i<this->nodeNum; i++)
	{
		if (i - 1 == index)
		{
			return *temp->node_data;
		}
		temp = temp->next_node_point;
	}
	return NULL;
}
#pragma once