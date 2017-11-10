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
cout<<"1)¹Ë¿Í\n"<<"2)¹ÜÀíÔ±"<<endl<<"µÇÂ¼Îª:";
cin>>choice;
cin.get(); 
if(choice==1)
{userload();
 cout<<"1)µÇÂ½2)×¢²á:";
 cin>>choice;
 cin.get();
 if(choice==1)
 {step1:
 cout<<"ÕËºÅ:";
 cin>>userID;
 cout<<"ÃÜÂë:";
 cin>>userkey;
 for(k=0;k<Usersum;k++)
 {if(B[k].check(userID,userkey))
   {cout<<"µÇÂ½³É¹¦!"<<endl; 
    break;
   }
 }
 if(k==Usersum)
 {
 cout<<"ÕËºÅÓëÃÜÂë²»Æ¥Åä!"<<endl;
 goto step1;
}
 B[k].way();
 }
 else if(choice==2)
 { step2:
   cout<<"ÕËºÅ:";
   cin>>userID;
   if(userID[0]<='9'&&userID[0]>='0')
   {cout<<"Ê×Î»²»ÄÜÎªÊý×Ö!"<<endl;
    goto step2;
   }
   if(same(userID))
   {cout<<"¸ÃÕËºÅÒÑ¾­×¢²á!"<<endl;
    goto step2;
   }
   cout<<"ÃÜÂë:";
   cin>>userkey;
   B[Usersum].create(userID,userkey);
   useradd();
   cout<<"×¢²á³É¹¦!"<<endl;
   B[Usersum-1].way();
 } 
}
 else if(choice==2)
 {step3:
 cout<<"ÕËºÅ:";
 cin>>ID;
 cout<<"ÃÜÂë:";
 cin>>key;
 if(A.check(ID,key))
 A.way();
 else
 {
 cout<<"ÕËºÅÓëÃÜÂë²»Æ¥Åä!";
 goto step3;
 }
 }
 return 0;
}

