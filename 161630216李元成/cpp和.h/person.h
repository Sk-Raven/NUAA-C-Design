#ifndef PERSON_H
#define PERSON_H
class person
{protected:
	char ID[50];
	char key[50];
public:
 bool check(char a[50],char b[50]);
 virtual void ls(){;}
 
};
#endif
