#include"StdAfx.h"
#include"globalfunction.h"
#include<string>
#include<string.h>
#include"book.h"
#include<fstream>
#include"adm.h"
#include"stdlib.h"
extern adm A;
extern book BOOK[1000];
extern user B[1000];
extern int Booksum;
extern int Usersum;
bool user::check(char a[50],char b[50])
{if(!strcmp(ID,a)&&!strcmp(key,b))
	 return true;
	 else
	 return false;
}
void user::create(char a[50],char b[50])
{strcpy(ID,a);
 	 strcpy(key,b);
 	 memset(history,0,2500*sizeof(char));
 	 memset(buy,0,2500*sizeof(char));
 	 for(int k=0;k<50;k++)
 	 {buyprice[k]=0;
	  buysum[k]=0;
     }
 	 number=0;
}
void user::way()
{
	 int choice;
	 int k;
	 start:
	 cout<<"1)����ͼ��2)����ͼ��3)�ҵĹ��ﳵ4)�ҵĶ���5)����ͼ��6)�˳�:";
	 cin>>choice;
	 cin.get();
	 if(choice!=0)
{
	if(choice==1)
	 {userls();
     }
	else if(choice==2)
	 {char name[50],author[50];
	  int ID;
	  step:
	 cout<<"1)��׼����2)ģ������:";
	 cin>>k;
	 if(k==1) 
	 {
	 cout<<"1)��������\n2)��������\n3)ID����:";
     cin>>k;
     if(k==1)
     {cout<<"����:";
      cin.get();
      cin.getline(name,50*sizeof(char));
      ID=search(name,k);
     }
      if(k==2)
      {cout<<"����:";
      cin.get();
      cin.getline(author,50*sizeof(char));
      ID=search(author,k);
      }
      if(k==3)
      {cout<<"ID:";
       cin>>k;
       ID=search(k);
      }
      if(ID==-1)
	 {cout<<"û���ҵ�!"<<endl;
	  goto step;
	 } 
	 else
	 {
      cout<<"����:"<<BOOK[ID].name<<endl<<"�۸�:"<<BOOK[ID].price<<endl<<"����:"<<BOOK[ID].sum<<endl;
      cout<<"����:"<<BOOK[ID].author<<endl<<"������:"<<BOOK[ID].publish<<endl<<"���:"<<BOOK[ID].brief<<endl;
      comment(ID);
      cout<<"���Ƿ��빺�����\n1)�Ѵ�����ӵ����ﳵ2)�뿪:";
      cin>>choice;
      if(choice==1)
      {int a;
	   cout<<"��������:";
	   cin>>a;
	   if(a>BOOK[ID].sum)
	   {cout<<"��������������ڿ��,�޷�����!"<<endl;
	    goto start;
	   }
	   if(a<0)
	   {cout<<"���������!"<<endl;
	    goto start;
	   }

	   strcpy(buy[number],BOOK[ID].name);
	   buyprice[number]=BOOK[ID].price;
       buysum[number]=a;
       number++;
       cout<<"��ӳɹ�!"<<endl;
	    
	  }
	  userwrite();
	  goto start;
      
	 }
     }
     else if(k==2)
     {cout<<"�����������:";
      string enter;
      cin>>enter;
      seek(enter); 
      goto start;
	 }
	 }
	else if(choice==3)
	 {int b=0;
	  for(int k=0;k<number;k++)
	  {cout<<buy[k]<<"    ����:"<<buyprice[k]<<"   ����:"<<buysum[k]<<endl;
	   b+=buyprice[k]*buysum[k];
      }
      cout<<"С��:"<<b<<"Ԫ"<<endl;
      if(b!=0)
	 {
	   cout<<"����?(Y/N):";
	  char choice;
	  cin>>choice;
	  if(choice=='y'||choice=='Y')
	  {fstream file;
	   file.open("order.txt",ios::out|ios::app);
	   int historynum=0;
	   for(historynum;history[historynum][0]!=0;historynum++)
	   ;
	   
	   for(int k=historynum;k<historynum+number;k++)
	   strcpy(history[k],buy[k-historynum]);
	   
	   
	   for(int l=0;l<number;l++)
	   {file.write(ID,50*sizeof(char));
	    file.write(buy[l],50*sizeof(char));
	    file.write((char *)&buysum[l],sizeof(int));
	   }
	   
       file.close();
	   int ID;
	   for(int m=0;m<number;m++)
 	   {ID=search(buy[m],1);
		BOOK[ID].sum-=buysum[m];
		buyprice[m]=0;
	    buysum[m]=0;
       }
       memset(buy,0,2500*sizeof(int));
 	   number=0;
 	   cout<<"��л���Ĺ���!"<<endl;
 	   bookwrite();
	  }
	  userwrite();
     }
	  goto start;
	 }
	else if(choice==4)
	 {for(int k=0;history[k][0]!=0;k++)
	  cout<<k+1<<": "<<history[k]<<endl;
	  if(history[0][0]==0)
	  cout<<"���Ĺ�����ʷΪ��!"<<endl; 
	  goto start;
	 }
	else if(choice==5)
	 {char name[50],author[50];
	  int ID;
	  
	 cout<<"1)��������\n2)��������\n3)ID����:";
     cin>>k;
     if(k==1)
     {cout<<"����:";
      cin.get();
      cin.getline(name,50*sizeof(char));
      ID=search(name,k);
     }
      if(k==2)
      {cout<<"����:";
      cin.get();
      cin.getline(author,50*sizeof(char));
      ID=search(author,k);
      }
      if(k==3)
      {cout<<"ID:";
       cin>>k;
       ID=search(k);
      }
      if(ID==-1)
	 {cout<<"û���ҵ�!"<<endl;
	  way();
	 }
	 else
	 {cout<<"��Ҫ���۵�����:"<<BOOK[ID].name<<endl;
	  int power=0;
	  for(int k=0;history[k][0]!=0;k++)
	  if(!strcmp(history[k],BOOK[ID].name))
	  {power=1;
	   break;
	  }
	  if(power==0)
	  {cout<<"��û�й��������,��Ȩ����!"<<endl;
	   goto start;
	  }
	  else 
	  {cout<<"��������������:"; 
	   char comment[1000];
	   cin>>comment;
	   fstream file;
	   file.open("comment.txt",ios::out|ios::app);
	   file.write(BOOK[ID].name,50*sizeof(char));
	   file.write(comment,1000*sizeof(char));
	   file.close();
	   goto start;
	  } 
	 }
	 }
	 else if(choice==6)
	 exit(0);
	
	
	 goto start;
}
	}
