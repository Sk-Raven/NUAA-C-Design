#ifndef ADM_H
#define ADM_H
#include"StdAfx.h"
#include<iostream>
#include"person.h"
#include<string.h>
#include"globalfunction.h"
#include"book.h"
using namespace std;
class adm :public person
{
public:
 adm();
 void ls();
 bool check(char a[50],char b[50]);
 void way();
};
#endif
