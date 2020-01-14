#pragma once
#include <string>
#include "u_p.h"
struct login
{
protected:
	int id = -1; 
public:
	int GET_ID() { int j = id; id = -1; return j; }
	bool check(char *, char *);
	bool check(char *,int);
	int login_();
	login(u_p *data);
	//~login();
};

