#include"bankwindow.h"

class OfficialBankWindow :public bankWindow {
public:
	OfficialBankWindow(int id);
	void handleUser();
	void check_finish();
};

OfficialBankWindow ::OfficialBankWindow(int id):bankWindow(id) {
	this->type = "Official Window";
}

void OfficialBankWindow::handleUser() {
	if (this->client != NULL && !this->is_busy)
	{
		cout << " Official Window " << this->identification << " is Busy :";
		this->begin_time = time(NULL);
		this->client->serving();
		this->is_busy = true;
		this->finished = false;
	}
}

void OfficialBankWindow::check_finish() {
	if (this->is_busy&&time(NULL) - this->begin_time >= 1)
	{
		cout << " Official Window " << this->identification << " Finishes serving" << endl;
		this->finished = true;
		this->is_busy = false;
		this->client = NULL;
	}
}
#pragma once
