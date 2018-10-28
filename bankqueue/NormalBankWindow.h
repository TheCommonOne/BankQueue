#include"bankwindow.h"

class NormalBankWindow:public bankWindow{
public:
	NormalBankWindow(int id);
	void handleUser();
	void check_finish();
};

NormalBankWindow::NormalBankWindow(int id):bankWindow(id) {
	this->type = "Normal Window";
}

void NormalBankWindow::handleUser() {
	if (this->client != NULL && !this->is_busy)
	{
		cout << " Normal Window " << this->identification << " is Busy :";
		this->begin_time = time(NULL);
		this->client->serving();
		this->is_busy = true;
		this->finished = false;
	}
}

void NormalBankWindow::check_finish() {
	if (this->is_busy&&time(NULL) - this->begin_time >= 3)
	{
		cout << " Normal Window " << this->identification << " Finishes serving" << endl;
		this->finished = true;
		this->is_busy = false;
		this->client = NULL;
	}
}
#pragma once

