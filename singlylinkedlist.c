//singly linked stack
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*sp=(struct node*)0;
int flag;
void main()
{
void push(int);
int pop();
struct node*search(int),*t;
int d,c;
do
{
printf("1.push \n");
printf("2.pop \n");
printf("3.search \n");
printf("4.exit \n");
printf("enter your option  \n");
scanf("%d",&c);
switch(c)
{
case 1:printf("enter the data to push:\n");
       scanf("%d",&d);
       push(d);
       break;
case 2:d=pop();
   if(flag==1)
       printf("popped item is %d\n",d);
       break;
case 3:printf("enter the item to search\n");
       scanf("%d",&d);
       t=search(d);
       if(t==(struct node*)0)
       printf("not found\n");
   else
        printf("found\n");
      break;
case 4:exit(1);
}
}
while(1);
}
//function to push
void push(int x)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->next=sp;
sp=t;
}
//pop
int pop()
{
int a;
struct node*t;
if(sp==(struct node*)0)
{
printf("empty stack\n");
}
else
{
    a=sp->data;
    t=sp;
    sp=sp->next;
    free(t);
    flag=1;
    return a;
}
}
//search
struct node*search(int data)
{
struct node*t=sp;
while(t!=(struct node*)0 && t->data!=data)
	t=t->next;
return t;
}


