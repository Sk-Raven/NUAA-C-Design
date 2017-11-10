#include"StdAfx.h"
#include<iostream>
#include"person.h"
#include<string.h>
#include"globalfunction.h"
#include"book.h"
using namespace std;
#include"adm.h"
extern book BOOK[1000];
extern int Booksum;
bool adm::check(char a[50],char b[50])
{{if(!strcmp(ID,a)&&!strcmp(key,b))
	 return true;
	 else
	 return false;
}
}
adm::adm()
{strcpy(ID,"161630216");
 strcpy(key,"161630216");
}
   
void adm::ls()
   {
   load();
   int k=0;
   while(k!=Booksum)
   {cout<<"ID:"<<k<<endl;
    cout<<"书名:"<<BOOK[k].name<<endl<<"价格:"<<BOOK[k].price<<endl<<"总数:"<<BOOK[k].sum<<endl;
    cout<<"作者:"<<BOOK[k].author<<endl<<"出版社:"<<BOOK[k].publish<<endl<<"简介:"<<BOOK[k].brief<<endl;
    if(BOOK[k].sum==0)
    cout<<"该书库存为0,请尽快补充库存!!!"<<endl;
    k++;
   }
   cout<<"共计:"<<Booksum<<endl;  
  }
void adm::way()
{start:
	cout<<"1:遍历图书"<<endl;
	cout<<"2:添加图书"<<endl;
	cout<<"3:修改图书"<<endl;
	cout<<"4:删除图书"<<endl; 
	cout<<"5:遍历用户"<<endl;
	cout<<"6:制表"<<endl;
	cout<<"7:订单"<<endl;
	cout<<"8:退出"<<endl;
	cout<<"choice:";
	int choice;
	cin>>choice;
	if(choice==8)
	exit(0);
	if(choice==1)
	ls();
	else if(choice==2)
	add();
	else if(choice==3)
	change();
	else if(choice==4)
	del();
	else if(choice==5)
	userlook();
	else if(choice==6)
	tab();
	else if(choice==7)
	vieworder();
	goto start;   
}
