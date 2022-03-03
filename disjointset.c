#include<stdio.h>
#include<stdlib.h>
typedef struct
{
int value;
struct rep *repptr;
struct node *next;
}node;

typedef struct
{
node *head;
node *tail;
}rep;

typedef struct
{
int key;
rep *repptr;
struct nodaddr *next;
}nodaddr;

nodaddr *ndr=0;

void main()
{
void makeset();
rep *find(int);
void unionset(int,int);
 
makeset(10);
makeset(20);
makeset(30);
makeset(40);

printf("find(10)=%x\n",find(10));
printf("find(20)=%x\n",find(20));
printf("find(30)=%x\n",find(30));
printf("find(40)=%x\n",find(40));

unionset(10,20);
printf("After union of 10 and 20 find(20)=%x\n",find(20));
unionset(30,40);
printf("After union of 30 and 40 find(40)=%x\n",find(40));
unionset(20,40);
printf("After union of 20 and 40 find(40)=%x\n",find(40));
}

void makeset(int a)
{
nodaddr *t=(nodaddr *)malloc(sizeof(nodaddr));
rep *newset=(rep *)malloc(sizeof(rep));
newset->head=(node *)malloc(sizeof(node));
newset->tail=newset->head;
newset->head->value=a;
newset->head->repptr=newset;
newset->head->next=0;
t->repptr=newset;
t->key=a;
t->next=ndr;
ndr=t;
}

rep *find(int x)
{
nodaddr *t=ndr;
while(t!=0 && t->key!=x)
t=t->next;
return t->repptr;
}

void unionset(int key1,int key2)
{
rep *set1,*set2;
nodaddr *t=ndr;
node *t1;
set1=find(key1);
set2=find(key2);
while(t!=0)
{
if(t->repptr==set2)
t->repptr=set1;
t=t->next;
}
t1=set2->head;
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail->next=set2->head;
set1->tail=set2->tail;
free(set2);
}
