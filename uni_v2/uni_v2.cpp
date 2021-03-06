#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "lesson.h"
#include "student.h"
#include "teacher.h"
#include "login.h"
#include "u_p.h"
#include <memory>
#include<direct.h>
using namespace std;
int main()
{
	int Access_level = 0;
	int ch;
	string str;
	lesson lee;
	teacher t(&lee);
	u_p np;
	np.import_();
	login log(&np);
	Access_level=log.login_();
	t.import_();
	lee.import_();
i:	system("cls");
	cout << "                      Main Menu"<<endl;
	cout << "1 : Manage Lessons"<<endl;
	cout << "2 : Manage Teachers"<<endl;
	cout << "3 : Manage Students" << endl;
	cout << "4 : Manage Users" << endl;
	cout << "5 : Import & Export Data" << endl;
	cout << "0 : For Exit"<<endl;
	cout << "Enter your operation number:";
	cin >> ch;

	switch (ch)
	{
	case 1:
	{
		{
		t:			system("cls");
			cout << "                      Manage Lessons" << endl << "1 : Add Lessons" << endl;
			cout << "2 : Rename Lessons" << endl;
			cout << "3 : Get Lessons" << endl;
			cout << "0 : Back" << endl;
			cout << "Enter your operation number:"; }
		cin >> ch;

		switch (ch)
		{
		case 1:
			lee.add_lesson();
			goto t;
			break;
		case 2:
			lee.Edit();
			system("pause");
			goto t;
		case 3:
			lee.get_list();
			system("pause");
			goto t;
			break;
		case 0:
			goto i;
			break;
		default:
			goto t;
		}
	}
	case 2:
	{

	h:	system("cls");
		cout << "                      Manage Teachers" << endl << "1 : Add Teachers" << endl;
		cout << "2 : Edit Teachers" << endl;
		cout << "3 : Delete Teachers" << endl;
		cout << "4 : Get Teachers List" << endl;
		cout << "0 : Back" << endl;
		cout << "Enter your operation number:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			t.add_teacher();
			goto h;
		case 2:
			t.Edit();
			goto h;
		case 4:
			t.get_list();
			goto h;
		case 0:
			goto i;
		default:
			break;
		}

	}
	case 4:
wer:	system("cls");
		cout << "                      Manage Users" << endl;
		cout << "1 : Add User" << endl;
		cout << "2 : Change Password" << endl;
		cout << "3 : Delete User" << endl;
		cout << "0 : Back" << endl;
		cout << "Enter your operation number:";
		cin >> ch;
		char u[60];
		char p[60];
		int ia;
		switch (ch)
		{
		case 1:
			if (4 > Access_level > 2 || Access_level == 1000) {
				cout << "Enter Username(0 for back): ";
				cin >> u;
				if (u[0] == '0'&&u[1] == '\0')
					goto wer;
				cout << "Enter password(0 for back): ";
				cin >> p;
				if (p[0] == '0'&&p[1] == '\0')
					goto wer;
			sdf:			cout << "Enter user access(1 or 2 or 3)(0 for back):";
				cin >> ia;
				if (ia == 0)
					goto wer;
				if (ia > Access_level) {
					cout << "you cant create this access!!" << endl;
					system("pause");
					goto sdf;
				}
				np.add_user(u, p, ia);
				cout << "The Operation Was Successfully" << endl;
				system("pause");
				goto wer;
			}
			else
			{
				cout << "You Do Not Have Permission To Access This Function" << endl;
				system("pause");
				goto wer;
			}
		case 2: 
		{
			if (4 > Access_level > 2||Access_level==1000) {
				cout << "Enter Username(0 for back): ";
				cin >> u;
				if (u[0] == '0'&&u[1]=='\0')
					goto wer;
				cout << "Enter Old Password(0 for back): ";
				cin >> p;
				if (p[0] == '0'&&p[1]=='\0')
					goto wer;
				log.check(u, p);
				int LL = log.GET_ID();
				if (LL != -1) {
					cout << "Enter New Password(0 for back): ";
					cin >> p;
					if (p[0] == '0'&&p[1]=='\0')
						goto wer;
					np.Edit(LL, p);
				}
				else
				{
					cout << "Not Found." << endl;
					system("pause");

				}
				goto wer;
			}
			else {
				cout << "Enter Old Password(0 for back): ";
				cin >> p;
				if (p[0] == '0'&&p[1]=='\0')
					goto wer;
				if (log.check(p, log.GET_ID())==true) {
					cout << "Enter New Password(0 for back): ";
					cin >> p;
					if (p[0] == '0'&&p[1]=='\0')
						goto wer;
					np.Edit(log.GET_ID(), p);
				}
				else
				{
					cout << "Not Found." << endl;
					system("pause");

				}
				goto wer;
			}
		}
		case 3:
			cout << "You Do Not Have Permission To Access This Function" << endl;
			system("pause");
			goto wer;
		case 0:
			goto i;
		default:
			break;
			goto wer;
		}
		
	case 5:
	{
	tt:	system("cls");
		cout << "                      Import & Export Data" << endl;
		cout << "1 : Import Data" << endl << "2 : Export Data" << endl<<"0 : Back" <<endl<< "Enter your operation number :"; cin >> ch;
		string patch;
		switch (ch)
		{
		case 1:
			cout << "                      Import Data" << endl << "Enter your path as an example (C:\\) (and 0 for back):"<<endl;
			cin>> patch;
			if (patch=="0")
				goto tt;
		DE:	cout << "Are you sure?(y/n): ";
			char a; cin >> a;
			patch += "data.data";
			switch (a)
			{
			case 'y':
			case 'Y':
				_mkdir("Temp");
				t.import_();
				lee.import_(); np.import_();
				
				cout << "The Operation Was Successfully" << endl;
				system("pause");
				goto tt;
			case 'n':
			case 'N':
				cout << "The Operation Was Canceled" << endl;
				system("pause");
				goto tt;
			default:
				goto DE;
			}
		case 2:
			cout << "                      Export Data" << endl << "Enter your path as an example (C:\\) (and 0 for back):" << endl;
			cin>> patch;
			if (patch == "0")
				goto i;

		e:	cout << "Are you sure?(y/n): ";
			char dda; cin >> dda;
			patch += "data.data";
			switch (dda)
			{
			case 'y':
			case 'Y':
				_mkdir("Temp");
				lee.export_();
				t.export_(); np.export_();
				cout << "The Operation Was Successfully" << endl;
				system("pause");
				goto tt;
			case 'n':
			case 'N':
				cout << "The Operation Was Canceled" << endl;
				system("pause");
				goto tt;
			default:
				goto e;
			}
		case 0:
			goto i;
		default:
			goto tt;
		}
	}
	case 0:
		exit;
		break;
	default:
		goto i;
	}
}