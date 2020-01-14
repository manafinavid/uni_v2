#pragma once
#include<string>
struct u_p
{

public:
	
	void export_();
	void Edit(const int, const char*);
	void import_();
	int num_();
	void delete_(char ch[]);
	int Access_level;
	bool check_data( char  *,  char  *, int i);
	bool check_data( char  *, int i);
	void add_user(char[] , char[],int );
	u_p();
};