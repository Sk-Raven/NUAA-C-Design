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
	 cout<<"1)遍历图书2)购买图书3)我的购物车4)我的订单5)评价图书6)退出:";
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
	 cout<<"1)精准查找2)模糊查找:";
	 cin>>k;
	 if(k==1) 
	 {
	 cout<<"1)书名搜索\n2)作者搜索\n3)ID搜索:";
     cin>>k;
     if(k==1)
     {cout<<"书名:";
      cin.get();
      cin.getline(name,50*sizeof(char));
      ID=search(name,k);
     }
      if(k==2)
      {cout<<"作者:";
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
	 {cout<<"没有找到!"<<endl;
	  goto step;
	 } 
	 else
	 {
      cout<<"书名:"<<BOOK[ID].name<<endl<<"价格:"<<BOOK[ID].price<<endl<<"总数:"<<BOOK[ID].sum<<endl;
      cout<<"作者:"<<BOOK[ID].author<<endl<<"出版社:"<<BOOK[ID].publish<<endl<<"简介:"<<BOOK[ID].brief<<endl;
      comment(ID);
      cout<<"您是否想购买此书\n1)把此书添加到购物车2)离开:";
      cin>>choice;
      if(choice==1)
      {int a;
	   cout<<"购买数量:";
	   cin>>a;
	   if(a>BOOK[ID].sum)
	   {cout<<"您购买的数量大于库存,无法购买!"<<endl;
	    goto start;
	   }
	   if(a<0)
	   {cout<<"错误的数量!"<<endl;
	    goto start;
	   }

	   strcpy(buy[number],BOOK[ID].name);
	   buyprice[number]=BOOK[ID].price;
       buysum[number]=a;
       number++;
       cout<<"添加成功!"<<endl;
	    
	  }
	  userwrite();
	  goto start;
      
	 }
     }
     else if(k==2)
     {cout<<"输入查找内容:";
      string enter;
      cin>>enter;
      seek(enter); 
      goto start;
	 }
	 }
	else if(choice==3)
	 {int b=0;
	  for(int k=0;k<number;k++)
	  {cout<<buy[k]<<"    单价:"<<buyprice[k]<<"   数量:"<<buysum[k]<<endl;
	   b+=buyprice[k]*buysum[k];
      }
      cout<<"小计:"<<b<<"元"<<endl;
      if(b!=0)
	 {
	   cout<<"购买?(Y/N):";
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
 	   cout<<"感谢您的购买!"<<endl;
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
	  cout<<"您的购买历史为空!"<<endl; 
	  goto start;
	 }
	else if(choice==5)
	 {char name[50],author[50];
	  int ID;
	  
	 cout<<"1)书名搜索\n2)作者搜索\n3)ID搜索:";
     cin>>k;
     if(k==1)
     {cout<<"书名:";
      cin.get();
      cin.getline(name,50*sizeof(char));
      ID=search(name,k);
     }
      if(k==2)
      {cout<<"作者:";
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
	 {cout<<"没有找到!"<<endl;
	  way();
	 }
	 else
	 {cout<<"您要评价的书是:"<<BOOK[ID].name<<endl;
	  int power=0;
	  for(int k=0;history[k][0]!=0;k++)
	  if(!strcmp(history[k],BOOK[ID].name))
	  {power=1;
	   break;
	  }
	  if(power==0)
	  {cout<<"您没有购买过此书,无权评论!"<<endl;
	   goto start;
	  }
	  else 
	  {cout<<"请输入您的评论:"; 
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
