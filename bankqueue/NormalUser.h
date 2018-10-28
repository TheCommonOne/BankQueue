#include<iostream>
#include"user.h"
using namespace std;

class NormalUser :public User {
public:
	NormalUser(const char name, int id);
	NormalUser(int id);
	void printInfo();
	void getServed();
	void serving();
};

NormalUser::NormalUser(const char  name, int id = 0): User(name,id) {
	
}

NormalUser::NormalUser(int id):User(id) {

}

void NormalUser::printInfo() {
	cout << "Normal User : " << this->user_name<<" ";
}

void NormalUser::serving() {
	cout << "Normal User " << this->user_name << "(" << this->identification << ")" << " is Drawing Money" << endl;
	this->serve_time = time(NULL);
}

void NormalUser::getServed() {
	cout << "Get Money Successfully. ";
	this->leave_time = time(NULL);
	cout << "Time Consume: " << this->leave_time - this->arrive_time << endl;
}
#pragma once
