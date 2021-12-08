//queue operations
#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=0, rear=0;
int s;
int q[size];
void main()
{
void insert(int);
int delete();
int search(int);
int c,d,k=0;
do
{
printf("1.insert \n");
printf("2.delete \n");
printf("3.search\n");
printf("4.exit \n");                                                                                                             
printf("enter your option \n");
scanf("%d",&c);
switch(c)
{
case 1:printf("enter a value to insert:");
       scanf("%d",&d);
       insert(d);
       break;
case 2:d=delete();
       if(s==1)
       {
       printf("deleted item is:%d\n",d);
       }
       break;
case 3:printf("enter a value to search\n");
       scanf("%d",&d);
       k=search(d);
       if(k==0)
       printf("item not found\n");
       break;
case 4:exit(1);
}
}
while(1);
}
void insert(int x)
{
int t;
t=(rear+1)%size;
if(front==t)
{
printf("queue is full!\n");
return;
}
else
{
rear=t;
q[rear]=x;
printf("item inserted\n");
}
}
int delete()
{
int r;
if(front==rear)
{
printf("queue is empty\n");
s=0;
}
else
{
front=(front+1)%size;
s=1;
return q[front];
}
}
int search(int item)
{
int f,r;
f=front;
r=rear;
while(f!=r)
{
f=(f+1)%size;
if(q[f]==item)
{
printf("item found\n");
return 1;
}
}
return 0;
}



