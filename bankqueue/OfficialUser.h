#include<iostream>
#include"user.h"
using namespace std;

class OfficialUser :public User {
public:
	OfficialUser(const char name, int id = 0);
	OfficialUser(int id);
	void printInfo();
	void getServed();
	void serving();
};

OfficialUser::OfficialUser(const char name, int id):User(name,id) {

}

OfficialUser::OfficialUser(int id):User(id) {

}

void OfficialUser::printInfo() {
	cout << "Official User : " << this->user_name << endl;
}

void OfficialUser::serving() {
	cout << "Official User " << this->user_name << "(" << this->identification << ")" << " is Talking" << endl;
	this->serve_time = time(NULL);
}

void OfficialUser::getServed() {
	cout << "Save Money Successfully. ";
	this->leave_time = time(NULL);
	cout << "Time Consume: " << this->leave_time - this->arrive_time << endl;
}


#pragma once
