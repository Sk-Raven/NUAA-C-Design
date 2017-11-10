
#ifndef BOOK_H
#define BOOK_H
#include"globalfunction.h"
#include"user.h"
#include"adm.h"
#include<iostream>
using namespace std; 
class book
{private :
	int price;
	int sum;
	int ID;
	char name[50];
	char author[50];
	char publish[50];
	char brief[50];
 public:	
 friend void add();
 friend void change();	
 friend void check();
 friend void load();
 friend void del();
 friend int search(char a[50],int choice);
 friend int search(int choice);
 friend void userls();
 friend class user;
 friend class adm;
 friend void bookwrite();
 friend void comment(int);
 friend void seek(string a);
 friend void tab();
 friend void vieworder();
};
#endif

