#include<iostream>
#include"user.h"
using namespace std;

class bankWindow {
public:
	bool is_busy;
	int identification;
	long long begin_time;
	User* client;
	const char* type;
	int finished;
	bankWindow(int id);
	void setClient(User *);
	virtual void handleUser() = 0;
	virtual void check_finish() = 0;
};

bankWindow::bankWindow(int id) {
	this->identification = id;
	this->is_busy = false;
	this->finished = true;
}

void bankWindow::setClient(User *user) {
	this->client = user;
}

#pragma once