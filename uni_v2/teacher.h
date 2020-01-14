#pragma once
#include <string>
#include "lesson.h"
using namespace std;
struct teacher
{
protected:
	int MAX = 10;
	string* Name ;
	string* Last_Name;
	int* Lesson ;
	int Last_added;
	lesson* lesson_list;
	void go_bigger();
public:
	void get_list();
	void import_();
	void export_();
	void add_teacher();
	void Edit();
	teacher(lesson* l);
	//~teacher();
};