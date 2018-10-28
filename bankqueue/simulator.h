#include<iostream>
#include"banklist.h"
#include"UserAll.h"
#include"BankAll.h"
#include"Structure.h"
#include<Windows.h>
using namespace std;

class simulator {
public:
	userQueue<User*> NormalQueue;
	userQueue<User*> VipQueue;
	userQueue<User*> OfficialQueue;
	bankList<bankWindow*> WindowList;
	int window_sum;
	int user_sum;
	void customerEnter(int sum);
	void simulateCallCustomer(int);
	void simulateCall();
	void simulateServe();
	void check_finish();
	void start();
	simulator();
};

void printLine() {
	cout << endl;
	for (int i = 0; i < 40; i++)
		cout << "- ";
	cout << endl;
}
void printStr(const char * str) {
	for (int i = 0; i <(80-strlen(str))/2 ; i++)
		cout << " ";
	cout << str<<endl;
}

simulator::simulator() {
	int i;
	this->window_sum = 5;
	srand((unsigned)time(NULL));
	// Window Initiate
	printLine();
	for ( i = 1; i <= this->window_sum-2; i++)
	{
			WindowList.append(new NormalBankWindow(i));
	}
	WindowList.append(new VipBankWindow(i++));
	WindowList.append(new OfficialBankWindow(i));
	
}

void simulator::customerEnter(int sum) {
	int index,counter;
	char name;
	printStr("New Customers Entering");
	for (counter = 0; counter < sum; counter++)
	{
		index = rand() % 8;
		name =65+ rand() % 26;
		if (index <=3)
		{
			cout << " A Normal Customer Enters" << endl;
			NormalQueue.EnQueue(new NormalUser(name,++this->user_sum));
			cout << " Number is " << this->user_sum << endl;
		}
		else if(index <= 5)
		{
			cout << " An Official Customer Enters" << endl;
			OfficialQueue.EnQueue(new OfficialUser(name,++this->user_sum));
			cout << " Number is " << this->user_sum << endl;
		}
		else if (index <= 7)
		{
			cout<<" A Vip Customer Enters" << endl;
			VipQueue.EnQueue(new VipUser(name, ++this->user_sum));
			cout << " Number is " << this->user_sum << endl;
		}
	}
}

void simulator::simulateCallCustomer(int window_index) {
	//int window_index = 0;
	User * temp = NULL;
	if (!WindowList[window_index]->is_busy)
	{
		// Normal Window
		if (WindowList[window_index]->type[0] == 'N')
		{
			if (!this->NormalQueue.Empty())
			{
				this->NormalQueue.DeQueue(temp);
				cout << " Normal Client " << temp->identification << " Please come to Window " << window_index + 1 << endl;
				WindowList[window_index]->setClient(temp);
			}
		}
		// Official Window
		else if (WindowList[window_index]->type[0] == 'O')
		{
			if (!this->OfficialQueue.Empty())
			{
				this->OfficialQueue.DeQueue(temp);
				cout << " Official Client " << temp->identification << " Please come to Window " << window_index + 1 << endl;
				WindowList[window_index]->setClient(temp);
			}
			else if (!this->NormalQueue.Empty())
			{
				this->NormalQueue.DeQueue(temp);
				cout << " Normal Client " << temp->identification << " Please come to Window " << window_index + 1 << endl;
				WindowList[window_index]->setClient(temp);
			}
		}
		// Vip Window
		else if (WindowList[window_index]->type[0] == 'V')
		{
			if (!this->VipQueue.Empty())
			{
				this->VipQueue.DeQueue(temp);
				cout << " Vip Client " << temp->identification << " Please come to Window " << window_index + 1 << endl;
				WindowList[window_index]->setClient(temp);
			}
			else if (!this->NormalQueue.Empty())
			{
				this->NormalQueue.DeQueue(temp);
				cout << " Normal Client " << temp->identification << " Please come to Window " << window_index + 1 << endl;
				WindowList[window_index]->setClient(temp);
			}
		}
	}
}

void simulator::start() {
	int window_index;
	int tm = time(NULL);
	bool flag = 1;
	while (1)
	{	
		// Enter
		if (flag && time(NULL) - tm <= 6)
		{
			this->customerEnter(6);
			printLine();
		}
		flag = ~flag;
		this->check_finish();

		// Call
		this->simulateCall();

		// Serve
		this->simulateServe();
		if ((this->NormalQueue.Empty() && this->OfficialQueue.Empty() && this->VipQueue.Empty()))
		{
			this->check_finish();
			printStr("Simulation Finishes");
			break;
		}
		Sleep(2000);
	}
}

void simulator::check_finish() {
	// Check Finish
	int window_index;
	printStr("Check Finish");
	for (window_index = 0; window_index < window_sum; window_index++)
	{
		WindowList[window_index]->check_finish();
	}
	printLine();
}

void simulator::simulateCall() {
	// Every Winow Call Customers
	printStr("Call Customers");
	int window_index;
	for (window_index = 0; window_index < window_sum; window_index++)
	{
		this->simulateCallCustomer(window_index);
	}
	printLine();
}

void simulator::simulateServe() {
	// Start Serving;
	int window_index;
	printStr("Begin Serving");
	for (window_index = 0; window_index < this->window_sum; window_index++)
	{
		WindowList[window_index]->handleUser();
	}
	printLine();
}