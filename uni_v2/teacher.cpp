#include "pch.h"
#include "teacher.h"
#include <string>
#include <iostream>
#include "lesson.h"
#include <fstream>
using namespace std;
void teacher::go_bigger()
{
	if (MAX == Last_added + 1) {
		MAX += 10;
		string* Name_ = new string[MAX];
		string* Last_Name_ = new string[MAX];
		int* Lesson_ = new int[MAX];
		for (int i = 0; i < MAX; i++) {
			Name_[i] = Name[i];
			Last_Name_[i] = Last_Name[i];
			Lesson_[i] = Lesson[i];
		}
		delete[] Lesson;
		delete[] Name;
		delete[] Last_Name;
		Lesson = Lesson_;
		Last_Name = Last_Name_;
		Lesson = Lesson_;
	}
}
void teacher::get_list()
{
	if (Last_added > -1) {
		cout << "code " << "Lesson names" << endl;
		for (int i = 0; i <= Last_added; i++) {
			cout << i + 1 << "     " << Name[i] << "," << Last_Name[i]<<"   "; 
			lesson_list->get_list(i);
		}
	}
	else
	{
		cout << "No lessons found" << endl;
	}
	system("pause");
}
void teacher::import_() {
	ifstream F("Temp\\Temp2.T", fstream::in);
	string s1,s2;
	char s3;
	while (F >> s1 >> s2 >> s3) {
		Last_added++;
		Name[Last_added] = s1;
		Last_Name[Last_added] = s2;
		Lesson[Last_added] = (int)s3;
		go_bigger();
	}
	F.close();
}
void teacher::export_()
{
	system("del Temp\\Temp2.T");
	ofstream F("Temp\\Temp2.T", fstream::out | fstream::in | fstream::ate | fstream::app);
	string ss = "";
	F.clear();
	for (int i = 0; i <= Last_added; i++) {
		ss += Name[i]+" "+Last_Name[i]+ " " + (char)Lesson[i] + "\n";
	}
	F << ss;
	F.close();
}

void teacher::add_teacher(void)
{
	if (Last_added != MAX) {
b:		string name; string last_name; int lesson_;
f:		cout << "name: "; cin >> name;
		if (name == "") {
			goto f;
		}
r:		cout << "last name: "; cin >> last_name;
		if (last_name == "") {
			goto r;
		}
	a:		cout << "lesson(0 for see list of lessons and -1 for back): "; cin >> lesson_;
		if (lesson_ == -1) {
			goto z;
		}
		if (lesson_ == 0)
		{
			lesson_list->get_list();
			goto a;
		}
		else if(lesson_<=lesson_list->get_last_lesson()+1)
		{
m:			cout << "Are you sure you want to add?(y/n): ";
			char sure;
			cin >> sure;
			if (sure == 'Y' || sure == 'y') {
				Last_added++;
				Name[Last_added] = name;
				Last_Name[Last_added] = last_name;
				Lesson[Last_added] = lesson_-1;
				cout << "Teacher successfully added." << endl;
				cout << "Teacher Id:" << Last_added + 1<<endl;
				system("Pause");
			}
			else if(sure=='N'||sure=='n')
			{
				cout << "The operation was canceled" << endl;
				system("Pause");
			}
			else
			{
				goto m;
			}
		}
		else
		{
			cout << "This lesson was not found" << endl;
			system("pause");
			goto a;
		}
	}
	else { 
		go_bigger();
	goto b;
	}
z:;
}

void teacher::Edit()
{
	int i; string n, l;int LL;
	cout << "Enter Teacher Id:"; cin >> i;
	i--;
	cout << Name[i] <<"," <<Last_Name[i] << endl;
	cout << "Enter new name(0 for back):";
	cin>> n;
	if (n == "0") {
		cout << "Operation stopped"<<endl ;
		system("Pause");
		goto z;
	}
	cout << "Enter new last name(0 for back):";
	cin >> l;
	if (l == "0") {
	c:		cout << "Operation stopped";
		system("Pause");;
		goto z;
	}
p:	cout << "Enter new last name(0 for back and -1 for seelist of lessons):";
	cin >> LL;
	if (LL == 0) {
		cout << "Operation stopped";
		system("Pause");
		goto z;
	}
	if (LL == -1) {
		lesson_list->get_list();
		goto p;
	}
	if (LL-1 <= lesson_list->get_last_lesson() && LL-1 >= 0) {
	d:	cout << "Are you sure ?(y/n):";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			Name[i] = n;
			Last_Name[i] = l;
			Lesson[i] = LL;
		}
		else if (ch == 'n' || ch == 'N') {
			goto c;
		}
		else { goto d; }
	z:	cout << "." << endl;
	}
	else
	{
		goto p;
	}
}

teacher::teacher(lesson* l)
{
	lesson_list = l;
	Name=new string[MAX];
	Last_Name = new string[MAX];
	Lesson = new int[MAX];
	Last_added=-1;
}
/*teacher::~teacher()
{
	delete[] Name;
	delete[] lesson_list;
	delete[] Lesson;
	delete[] Last_Name;
}*/