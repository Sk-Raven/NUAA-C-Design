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
    cout<<"����:"<<BOOK[k].name<<endl<<"�۸�:"<<BOOK[k].price<<endl<<"����:"<<BOOK[k].sum<<endl;
    cout<<"����:"<<BOOK[k].author<<endl<<"������:"<<BOOK[k].publish<<endl<<"���:"<<BOOK[k].brief<<endl;
    if(BOOK[k].sum==0)
    cout<<"������Ϊ0,�뾡�첹����!!!"<<endl;
    k++;
   }
   cout<<"����:"<<Booksum<<endl;  
  }
void adm::way()
{start:
	cout<<"1:����ͼ��"<<endl;
	cout<<"2:���ͼ��"<<endl;
	cout<<"3:�޸�ͼ��"<<endl;
	cout<<"4:ɾ��ͼ��"<<endl; 
	cout<<"5:�����û�"<<endl;
	cout<<"6:�Ʊ�"<<endl;
	cout<<"7:����"<<endl;
	cout<<"8:�˳�"<<endl;
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
