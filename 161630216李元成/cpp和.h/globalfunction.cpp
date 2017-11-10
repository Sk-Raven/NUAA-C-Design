#include"StdAfx.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include"adm.h"
#include"book.h"
#include"order.h"
#include"user.h"
#include"globalfunction.h"
using namespace std;
adm A;
book BOOK[1000];
user B[1000];
int Booksum=0;
int Usersum=0;
void load()
{fstream file;
Booksum=0;
file.open("book.txt",ios::in);
if(!file.is_open())
{
cout<<"打开失败!"<<endl;
A.way(); 
}
while(file.peek()!=EOF)
{file.read((char *)&BOOK[Booksum].price,sizeof(int));
 file.read((char *)&BOOK[Booksum].sum,sizeof(int));
 file.read(BOOK[Booksum].name,50*sizeof(char));
 file.read(BOOK[Booksum].author,50*sizeof(char));
 file.read(BOOK[Booksum].publish,50*sizeof(char));
 file.read(BOOK[Booksum++].brief,50*sizeof(char));
}
file.close();
}

void userls(void)
{  load();
   fstream file;
   fstream com;
   com.open("comment.txt",ios::in);
   file.open("book.txt",ios::in);
   int k=0;
   while(k!=Booksum)
   {cout<<"ID:"<<k<<endl;
    cout<<"书名:"<<BOOK[k].name<<endl<<"价格:"<<BOOK[k].price<<endl<<"总数:"<<BOOK[k].sum<<endl;
    cout<<"作者:"<<BOOK[k].author<<endl<<"出版社:"<<BOOK[k].publish<<endl<<"简介:"<<BOOK[k].brief<<endl;
    k++;
   }
   cout<<"共计:"<<Booksum<<endl; 
   file.close();
}




void add(void)
{ fstream a;
  a.open("book.txt",ios::out|ios::app);
  int price,sum;
  char name[50],author[50],publish[50],biref[50];
  cout<<"单价:";
  cin>>price;
  cout<<"数量:";
  cin>>sum;
  cout<<"名字:";
  cin.get();
  cin.getline(name,50*sizeof(char));
  cout<<"作者:";
  cin.getline(author,50*sizeof(char));
  cout<<"出版社:";
  cin.getline(publish,50*sizeof(char));
  cout<<"简介:";
  cin.getline(biref,50*sizeof(char));
  
  a.write((char *)&price,sizeof(price));
  a.write((char *)&sum,sizeof(sum));
  a.write(name,50*sizeof(char));
  a.write(author,50*sizeof(char));
  a.write(publish,50*sizeof(char));
  a.write(biref,50*sizeof(char));
  a.close();
  cout<<"add success!\n";
  load();
 
}

void change(void)
{ load();
 char name[50],author[50];
 int ID,k;
 char choice;
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
	 A.way(); 
	}  
    else
   {cout<<"名字:"<<BOOK[ID].name<<endl<<"价格:"<<BOOK[ID].price<<endl<<"总数:"<<BOOK[ID].sum<<endl;
    cout<<"是否修改名字？(Y or N):";
    cin>>choice;
    if(choice=='y'||choice=='Y')
    {cout<<"修改后的名字:";
     cin.get();
     cin>>BOOK[ID].name;
    }
	cout<<"修改后的价格:";
	cin>>BOOK[ID].price;
	cout<<"修改后的总数:";
	cin>>BOOK[ID].sum; 
   }
  fstream file;
  file.open("book.txt",ios::out);
  for(int j=0;j<Booksum;j++)
  {file.write((char *)&BOOK[j].price,sizeof(int));
   file.write((char *)&BOOK[j].sum,sizeof(int));
   file.write(BOOK[j].name,50*sizeof(char));
   file.write(BOOK[j].author,50*sizeof(char));
   file.write(BOOK[j].publish,50*sizeof(char));
   file.write(BOOK[j].brief,50*sizeof(char));
  }
  file.close();
   cout<<"change success!"<<endl;
   load();
  
  }
  void bookwrite(void)
  {fstream file;
   file.open("book.txt",ios::out);
   for(int j=0;j<Booksum;j++)
   {file.write((char *)&BOOK[j].price,sizeof(int));
   file.write((char *)&BOOK[j].sum,sizeof(int));
   file.write(BOOK[j].name,50*sizeof(char));
   file.write(BOOK[j].author,50*sizeof(char));
   file.write(BOOK[j].publish,50*sizeof(char));
   file.write(BOOK[j].brief,50*sizeof(char));
   }
  file.close();
   }
   
  void del(void)
  {load();
   int ID;
   fstream file;
   int k;
   char name[50],author[50];
   cout<<"全部删除按1,部分删除按2:";
   int choice;
   cin>>choice;
   if(choice==1)
   {cout<<"输入1确认全部删除!!:";
    cin>>choice;
    if(choice==1)
    {
	file.open("book.txt",ios::out);
    file.close();
    } 
   }
   if(choice==2)
   {cout<<"1)书名搜索\n2)作者搜索\n3)ID搜索:";
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
   cout<<"没有找到!"<<endl;
	 
  else
  {cout<<BOOK[ID].name<<endl;
   BOOK[ID].sum=-1;
   file.open("book.txt",ios::out);
   k=0;
   while(k!=Booksum)
   {if(BOOK[k].sum!=-1)
   {file.write((char *)&BOOK[k].price,sizeof(int));
    file.write((char *)&BOOK[k].sum,sizeof(int));
    file.write(BOOK[k].name,50*sizeof(char));
    file.write(BOOK[k].author,50*sizeof(char));
    file.write(BOOK[k].publish,50*sizeof(char));
    file.write(BOOK[k].brief,50*sizeof(char));
   }
   k++;
  }
  cout<<"del success"<<endl;
 }
}  file.close();
   load();
}
int search(char *a,int choice)
{load();
 
 if(choice==1)
 {for(int j=0;j<Booksum;j++)
  {
   if(!strcmp(BOOK[j].name,a))
   return j;
  }
  return -1;
 }
 if(choice==2)
 {for(int j=0;j<Booksum;j++)
  {if(!strcmp(BOOK[j].author,a))
   return j;
  }
  return -1;
 }
 else
 return -1;  
}
int search(int choice)
{load();
 if(choice>=Booksum||choice<0)
 return -1;
 else
 return choice;
}
void userload()
{fstream file;
  Usersum=0;
 file.open("user.txt",ios::in);
 if(file.is_open())
 {while(file.peek()!=EOF)
  {file.read((char *)&B[Usersum].ID,50*sizeof(char));
   file.read((char *)&B[Usersum].key,50*sizeof(char));
   file.read((char *)&B[Usersum].history,2500*sizeof(char));
   file.read((char *)&B[Usersum].buy,2500*sizeof(char));
   file.read((char *)&B[Usersum].buyprice,50*sizeof(int));
   file.read((char *)&B[Usersum].buysum,50*sizeof(int));
   file.read((char *)&B[Usersum].number,sizeof(int));
   Usersum++;
  }
 }  
 file.close();
}
void useradd()
{  fstream file;
   file.open("user.txt",ios::out|ios::app);
   file.write((char *)&B[Usersum].ID,50*sizeof(char));
   file.write((char *)&B[Usersum].key,50*sizeof(char));
   file.write((char *)&B[Usersum].history,2500*sizeof(char));
   file.write((char *)&B[Usersum].buy,2500*sizeof(char));
   file.write((char *)&B[Usersum].buyprice,50*sizeof(int));
   file.write((char *)&B[Usersum].buysum,50*sizeof(int));
   file.write((char *)&B[Usersum].number,sizeof(int));
   Usersum++;
   file.close(); 
}
void userwrite()
{
 fstream file;
 file.open("user.txt",ios::out);
 for(int k=0;k<Usersum;k++)
{  file.write((char *)&B[k].ID,50*sizeof(char));
   file.write((char *)&B[k].key,50*sizeof(char));
   file.write((char *)&B[k].history,2500*sizeof(char));
   file.write((char *)&B[k].buy,2500*sizeof(char));
   file.write((char *)&B[k].buyprice,50*sizeof(int));
   file.write((char *)&B[k].buysum,50*sizeof(int));
   file.write((char *)&B[k].number,sizeof(int));
}
file.close();
userload();
}
void userlook()
{userload();
 for(int j=0;j<Usersum;j++)
 cout<<"ID:"<<B[j].ID<<endl;
 cout<<"共计"<<Usersum<<"个用户"<<endl;
}
bool same(char ID[50])
{userload();
 for(int j=0;j<Usersum;j++)
 if(!strcmp(ID,B[j].ID))
 return true;
 return false;
}
void comment(int ID)
{fstream file;
 file.open("comment.txt",ios::in);
 char name[50];
 char comment[1000];
 cout<<"评论区:"<<endl;
 while(file.peek()!=EOF)
 {file.read(name,50*sizeof(char));
 file.read(comment,1000*sizeof(char));
 if(!strcmp(name,BOOK[ID].name))
 cout<<comment<<endl;
 }
}
void seek(string a)
{load();
string b;
cout<<"在书名中查找中..."<<endl;
for(int k=0;k<Booksum;k++)
{ 
 b=BOOK[k].name;
 if(b.find(a)!=string::npos)
 cout<<"ID:"<<k<<endl<<"书名:"<<BOOK[k].name<<endl<<"作者:"<<BOOK[k].author<<endl<<endl;
}
cout<<"在作者中查找..."<<endl;
for(int l=0;l<Booksum;l++)
{ 
 b=BOOK[l].author;
 if(b.find(a)!=string::npos)
 cout<<"ID:"<<l<<endl<<"书名:"<<BOOK[l].name<<endl<<"作者:"<<BOOK[l].author<<endl<<endl;
}
cout<<"在出版社中查找..."<<endl;
for(int m=0;m<Booksum;m++)
{ 
 b=BOOK[m].publish;
 if(b.find(a)!=string::npos)
 cout<<"ID:"<<m<<endl<<"书名:"<<BOOK[m].name<<endl<<"作者:"<<BOOK[m].author<<endl<<endl;
}
}
void tab()
{load();
 cout<<"1)售价制表2)数量制表3)销量制表"<<endl;
 int choice;
 cin>>choice;
 if(choice==1)
 {int temp[1000][2];
  int t;
  for(int k=0;k<Booksum;k++)
  {temp[k][0]=k;
   temp[k][1]=BOOK[k].price;
  }
  for(int i=0;i<Booksum;i++)
  for(int j=0;j<Booksum-j-1;j++)
  {if(temp[j][1]<temp[j+1][1])
   {t=temp[j][1];
    temp[j][1]=temp[j+1][1];
    temp[j+1][1]=t;
    
    t=temp[j][0];
    temp[j][0]=temp[j+1][0];
    temp[j+1][0]=t;
   }
  }
 for(int l=0;l<Booksum;l++)
 for(int j=0;j<Booksum;j++)
 {if(j==temp[l][0])
  {cout<<l+1<<":"<<BOOK[j].name<<"    价格:"<<BOOK[j].price<<endl;
   break;
  }
 }  
 }
 else if(choice==2)
 {int temp[1000][2];
  int t;
  for(int k=0;k<Booksum;k++)
  {temp[k][0]=k;
   temp[k][1]=BOOK[k].sum;
  }
  for(int m=0;m<Booksum;m++)
  for(int j=0;j<Booksum-m-1;j++)
  {if(temp[j][1]<temp[j+1][1])
   {t=temp[j][1];
    temp[j][1]=temp[j+1][1];
    temp[j+1][1]=t;
    
    t=temp[j][0];
    temp[j][0]=temp[j+1][0];
    temp[j+1][0]=t;
   }
  }
 for(int n=0;n<Booksum;n++)
 for(int j=0;j<Booksum;j++)
 {if(j==temp[n][0])
  cout<<n+1<<":"<<BOOK[j].name<<"    数量:"<<BOOK[j].sum<<endl;
 }  
 }
 else if(choice==3)
 {fstream file;
  file.open("order.txt",ios::in);
  int sum[1000][2];
  int ID,temp,num=0;
  int k;
  for(int l=0;l<10;l++)
  {sum[l][0]=-1;
  sum[l][1]=0;
  }
  bool flag=false;
  char b[50],a[50];
  while(file.peek()!=-1)
  {file.read(b,50*sizeof(char));
   file.read(a,50*sizeof(char));
   for(k=0;k<10;k++)
   {if(sum[k][0]==search(a,1))
    {
    flag=true;
    break;
    }
   }
   file.read((char *)&temp,sizeof(int));
   if(flag)
   sum[k][1]+=temp;
   else
   {sum[num][0]=search(a,1);
   sum[num][1]+=temp;
   num++;
   }
   flag=false;
  }
  for( k=0;k<num;k++)
  for(int j=0;j<num-k-1;j++)
  {
   if(sum[j][1]<sum[j+1][1])
   {temp=sum[j][0];
    sum[j][0]=sum[j+1][0];
    sum[j+1][0]=temp;

    temp=sum[j][1];
    sum[j][1]=sum[j+1][1];
    sum[j+1][1]=temp;
   }
  }
  for(int n=0;n<num;n++)
  {ID=search(sum[n][0]);
  strcpy(a,BOOK[ID].name);
   cout<<a<<"    "<<sum[n][1]<<"本"<<endl;
  }
   file.close();
 }
 
}

void vieworder()
{fstream file;
 file.open("order.txt",ios::in);
 char ID[50],name[50];
 int sum;
 while(file.peek()!=-1)
 {file.read(ID,50*sizeof(char));
  file.read(name,50*sizeof(char));
  file.read((char *)&sum,sizeof(int));
  cout<<"ID:"<<ID<<"   书名:"<<name<<"   数量"<<sum<<endl;
 }
 file.close();
}
