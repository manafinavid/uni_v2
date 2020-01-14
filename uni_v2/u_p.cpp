#include "pch.h"
#include "u_p.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
int num = 1;
string* username = new string[1];
string* password = new string[1];
int* access = new int[1];
bool u_p::check_data(char  *name,  char  *pass,int i)
{
	string name_, pass_;
	for (int i = 0; name[i] != '\0'; i++) {
		name_ += name[i];
	}
	for (int i = 0; pass[i] != '\0'; i++) {
		pass_ += pass[i];
	}
	if (username[i] == name_) {
		if (password[i] == pass_) {
			Access_level = access[i];
			return true;
		}
	}
	return false;
}
bool u_p::check_data( char  *pass, int i)
{
	string pass_;
	for (int i = 0; pass[i] != '\0'; i++) {
		pass_ += pass[i];
	}
	if (password[i] == pass_) {
		Access_level = access[i];
		return true;
	}
	return false;
}
void u_p::add_user(char name[], char  pass[],int acc )
{
		string*u = new string[num + 1];
		string*p = new string[num + 1];
		int*a = new int[num + 1];
		for (int i = 0; i < num; i++) {
			u[i] = username[i];
			p[i] = password[i];
			a[i] = access[i];
		}
		u[num] = name;
		p[num] = pass;
		a[num] = acc;
		num++;
		username = u;
		password = p;
		access = a;
}
u_p::u_p()
{
	username[0] = "navid.m";
	password[0] = "11apple11";
	access[0] = 1000;
}
void u_p::export_() {
	system("del Temp\\Temp3.T");
	ofstream F("Temp\\Temp3.T", fstream::out | fstream::in | fstream::ate | fstream::app);
	string ss = "";
	F.clear();
	for (int i = 1; i <= num-1; i++) {
		if (access[i] != -1) {
			ss += username[i] + " " + password[i] + " " + (char)access[i] + "\n";
		}
	}
	F << ss;
	F.close();
}
void u_p::Edit(const int a, const char *p)
{
	int i = 0;
	string l;
	while (p[i]!='\0')
	{
		l += p[i];
		i++;
	}
	password[a] = l;
	cout << "Password Changed Successfully." << endl;
	system("pause");
}
void go_bigger_() {
	string* n_ = new string[num + 1];
	string* p_ = new string[num + 1];
	int* a_=new int[num+2];
	for (int i = 0; i < num; i++) {
		n_[i] = username[i];
		p_[i] = password[i];
		a_[i] = access[i];
	}
	delete[]username;
	delete[]password;
	delete[]access;
	username = n_;
	password = p_;
	access = a_;
}
void u_p::import_()
{
	ifstream F("Temp\\Temp3.T", fstream::in);
	string s1,s2;
	char s3;
	while (F >>s1>>s2>>s3) {
		go_bigger_();
		password[num] = s2;
		username[num] = s1;
		access[num] =(int) s3;
		num++;
	}
	F.close();
}
int u_p::num_()
{
	return num;
}
void u_p::delete_(char ch[]) {
	string f;
	int k;
	int flag = 0;
	for (int ij = 0; ch[ij] != '\0'; ij++) {
		f += ch[ij];
	}
	for (int ij = 1;ij <num; ij++) {
		if (f == username[ij]) {
			k = ij;
			flag = 1;
			goto j;
		}
	}
j:if (flag == 1) {
q:	cout << "Are you sure?(y/n): "; char ch;
	cin >> ch;
	switch (ch)
	{
	case 'y':
	case 'Y':
		access[k] = -1;
		cout << "The operation was successfully" << endl;
		system("pause");
		break;
	case 'n':
	case 'N':
		cout << "The Operation Was Canceled" << endl;
		system("pause");
		break;
	default:
		goto q;
	}

}
  else {
	cout << "The User Not Found" << endl;

}
}