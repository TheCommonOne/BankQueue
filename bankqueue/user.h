#include<iostream>
#include<random>
#include<time.h>
using namespace std;

class User {
public:
	char user_name;
	int identification;
	int is_waiting;
	long long arrive_time;
	long long serve_time;
	long long leave_time;
	User(const char name, int id);
	User(int id);
	User();
	virtual void printInfo() = 0;
	virtual void getServed() = 0;
	virtual void serving() = 0;
};

User::User(const char name, int id) {
	this->user_name = name;
	this->identification = id;
	this->arrive_time = time(NULL);
	this->is_waiting = 1;
	this->serve_time = 0;
}

User::User(int id) {
	this->identification = id;
	this->arrive_time = time(NULL);
}

User::User() {

}
#pragma once