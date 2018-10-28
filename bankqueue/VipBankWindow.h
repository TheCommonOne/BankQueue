#include"bankwindow.h"

class VipBankWindow :public bankWindow {
public:
	VipBankWindow(int id);
	void handleUser();
	void check_finish();
};

VipBankWindow::VipBankWindow(int id) :bankWindow(id) {
	this->type = "Vip Window";
}

void VipBankWindow::handleUser()
{
	if (this->client != NULL&&!this->is_busy)
	{
		cout << " Vip Window " << this->identification << " is Busy :";
		this->begin_time = time(NULL);
		this->client->serving();
		this->is_busy = true;
		this->finished = false;
	}
}

void VipBankWindow::check_finish() {
	if (this->is_busy&&time(NULL) - this->begin_time >= 2)
	{
		cout << " Vip Window " << this->identification << " Finishes serving" << endl;
		this->finished = true;
		this->is_busy = false;
		this->client = NULL;
	}
}
#pragma once
