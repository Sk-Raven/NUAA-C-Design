#ifndef ORDER_H
#define ORDER_H
#include"adm.h"
#include"user.h"
class order
{private:
	char ID[50];
	char name[50];
	int sum;
 public:
 void set(char a[50],char b[50],int c);
 friend class user;
 friend class adm;
};
#endif

