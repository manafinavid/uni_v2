#include "pch.h"
#include "login.h"
#include <string>
#include <iostream>
#include "u_p.h"
//1-800-345-7669
using namespace std;
u_p *Data;
int MAX = 0;
bool login::check( char *_n_, char *_p_)
{
	int i;
	for (i= 0; i <= Data->num_(); i++) {
		if (Data->check_data(_n_,_p_,i)==true) {
			id = i;
			return true;
		}
	}
	return false;
}
bool login::check(char *_p_,int i)
{
	if (Data->check_data(_p_,i) == true) {
		id = i;
		return true;
	}
	return false;
}
int login::login_()
{
	char _n_[60];
	char _p_[60];
	cout << "Welcome to University Management Program (V2.0)" << endl;
s:	cout << "Enter username: ";
	cin >> _n_;
	cout << "Enter password: ";
	cin >> _p_;
	if (check(_n_,_p_) != true) {
		system("cls");
		cout << "Welcome to University Management Program (V2.0)" << endl;
		cout << "Your data is incorrect." << endl;
		goto s;
	}
	else
	{
		system("cls");
		cout << "Welcome " << _n_ << " ." << endl;
		return Data->Access_level;
	}
}

login::login(u_p *data)
{
	Data = data;
}

/*login::~login()
{

}*/
