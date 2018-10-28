#include<iostream>
#include"user.h"
using namespace std;

class VipUser:public User {
public:
	VipUser(const char name, int id);
	VipUser(int id);
	void printInfo();
	void getServed();
	void serving();
};

VipUser::VipUser(const char  name, int id = 0):User(name,id) {

}
VipUser::VipUser(int id):User(id) {

}

void VipUser ::printInfo() {
	cout << "Vip User : " << this->user_name << endl;
}

void VipUser::serving() {
	cout << "Vip User " << this->user_name<<"("<<this->identification<<")" << " is Having Tea" << endl;
	this->serve_time = time(NULL);
}

void VipUser ::getServed() {
	cout << "Finished. ";
	this->leave_time = time(NULL);
	cout << "Time Consume: " << this->leave_time - this->arrive_time << endl;
}

#pragma once
