#ifndef USER_H
#define USER_H
#include"globalfunction.h"
#include"book.h"
class user
{   private:
	char ID[50];
	char key[50];
	char history[50][50];
	char buy[50][50];
	int buyprice[50];
	int buysum[50];
	int number;
	
 public:
 	void create(char a[50],char b[50]);
	bool check(char a[50],char b[50]);
	void way();
	friend void userload();
	friend void useradd();
	friend void userwrite();
	friend bool same(char ID[50]);
	
	friend void userlook();
};
#endif
