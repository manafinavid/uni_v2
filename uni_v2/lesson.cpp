#include "pch.h"
#include "lesson.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int last_lesson = -1;
string* lesson_name;
void go_bigger() {
	string* n_ = new string[last_lesson + 2];
	for (int i = 0; i <= last_lesson; i++) {
		n_[i] = lesson_name[i];
	}
	delete[]lesson_name;
	lesson_name = n_;
}

void lesson::import_()
{
	ifstream F("Temp\\Temp1.T", fstream::in);
	string s1;
	while (F >> s1 ) {
		last_lesson++;
		lesson_name[last_lesson] = s1;
		go_bigger();
	}
	
	F.close();
}
void lesson::export_()
{
	system("del Temp\\Temp1.T");
	ofstream F("Temp\\Temp1.T", fstream::out | fstream::in | fstream::ate | fstream::app);
	string ss="";
	F.clear();
	for (int i = 0; i <= last_lesson; i++) {
		ss += lesson_name[i]+"\n";
	}
	F << ss;
	F.close();
}
int lesson::get_last_lesson()
{
	return last_lesson;
}
int lesson::add_lesson(){
	string a;
x:	cout << "enter your new lesson(dont use space and 0 for back):";
	cin>> a;
	if (a == "0") {
		goto n;
	}
if (a != "") {
	for (int i = 0; i <=last_lesson+1; i++) {
		if (a == lesson_name[i]) {
			cout << "The lesson is duplicate"<<endl;
z:			cout << "Do you want try again?(y/n):";
			char b;
			cin >> b;
			if (b == 'y' || b == 'Y') {
				goto x;
			}
			else if (b == 'n' || b == 'N')
			{
				goto n;
			}
			else { goto z; }
		}
	}
	last_lesson++;
	go_bigger();
	lesson_name[last_lesson] = a;

	cout << "New lesson added successfully"<<endl;
	system("Pause");
	return 0;
   }
n:	cout << "The operation was canceled" << endl;;
	system("Pause");
return -1;
}
int lesson::Edit()
{
	string rename;
j:	cout << "Enter the name of the lesson you want to rename:";
	cin >> rename;
	int c=-1;
	for (int i = 0; i <= last_lesson + 1; i++) {
		if (rename == lesson_name[i]) {
			c = i;
f:			cout << "Enter new name:";
			cin >> rename;
			for (int j = 0; j <= last_lesson + 1; j++) {
				if (lesson_name[i]==rename&&j!=i)
				{
					cout << "You can not rename this name because this name exists!!!" << endl;
w:					cout << "Do you want try again?(y/n):";
					char b;
					cin >> b;
					if (b == 'y' || b == 'Y') {
						goto f;
					}
					else if (b == 'n' || b == 'N')
					{
						goto l;
					}
					else { goto w; }
				}
			}
		}
	
	}
	if (c != -1) {
		lesson_name[c] = rename;
		cout << "Rename successfully" << endl;
	}
	else
	{
		cout << "Lesson not found." << endl;
o:		cout << "Do you want try again?(y/n):";
		char b;
		cin >> b;
		if (b == 'y' || b == 'Y') {
			goto j;
		}
		else if (b == 'n' || b == 'N')
		{
			goto l;
		}
		else { goto o; }

	}
l:	return 0;
}
void lesson::get_list()
{
	if (last_lesson > -1) {
		cout << "code " << "Lesson names" << endl;
		for (int i = 0; i <= last_lesson; i++) {
			cout <<i+1 <<"     "<<lesson_name[i]<< endl;
		}
	}
	else
	{
		cout << "No lessons found" << endl;
	}
}

void lesson::get_list(int i)
{
	cout << lesson_name[i] << endl;
}

lesson::lesson()
{
	lesson_name = new string[1];
}

/*lesson::~lesson()
{
}*/
