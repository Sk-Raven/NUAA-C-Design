#include"StdAfx.h"
#include <iostream>
#include<fstream>
#include<string.h>
#include"globalfunction.h"
#include"adm.h"
#include"book.h"
#include"order.h"
#include"user.h"
extern user B[1000];
extern int Usersum;
extern adm A;
int main(int argc, char** argv) {
int choice,k;
char ID[50];
char key[50];
char userID[50];
char userkey[50];
cout<<"1)�˿�\n"<<"2)����Ա"<<endl<<"��¼Ϊ:";
cin>>choice;
cin.get(); 
if(choice==1)
{userload();
 cout<<"1)��½2)ע��:";
 cin>>choice;
 cin.get();
 if(choice==1)
 {step1:
 cout<<"�˺�:";
 cin>>userID;
 cout<<"����:";
 cin>>userkey;
 for(k=0;k<Usersum;k++)
 {if(B[k].check(userID,userkey))
   {cout<<"��½�ɹ�!"<<endl; 
    break;
   }
 }
 if(k==Usersum)
 {
 cout<<"�˺������벻ƥ��!"<<endl;
 goto step1;
}
 B[k].way();
 }
 else if(choice==2)
 { step2:
   cout<<"�˺�:";
   cin>>userID;
   if(userID[0]<='9'&&userID[0]>='0')
   {cout<<"��λ����Ϊ����!"<<endl;
    goto step2;
   }
   if(same(userID))
   {cout<<"���˺��Ѿ�ע��!"<<endl;
    goto step2;
   }
   cout<<"����:";
   cin>>userkey;
   B[Usersum].create(userID,userkey);
   useradd();
   cout<<"ע��ɹ�!"<<endl;
   B[Usersum-1].way();
 } 
}
 else if(choice==2)
 {step3:
 cout<<"�˺�:";
 cin>>ID;
 cout<<"����:";
 cin>>key;
 if(A.check(ID,key))
 A.way();
 else
 {
 cout<<"�˺������벻ƥ��!";
 goto step3;
 }
 }
 return 0;
}

