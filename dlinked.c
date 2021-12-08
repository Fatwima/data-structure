#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;
};
struct node*start=(struct node*)0;
void main()
{
void insert(int);
void delete(int);
struct node*search(int),*t;
int data,c;
do
{
printf("1.insert \n");
printf("2. search\n");
printf("3.delete\n");
printf("4.exit \n");
printf("enter your option \n");
scanf("%d",&c);
switch(c)
{
case 1:printf("enter the data to INSERT:\n");
       scanf("%d",&data);
       insert(data);
break;
case 2:printf("enter a value to SEARCH\n");
       scanf("%d",&data);
       t=search(data);
       if(t==(struct node*)0)
       printf("item not found\n");
       else
 	 printf("item  found\n");
       break;
case 3:printf("enter a value to DELETE\n");
	scanf("%d",&data);
        delete(data);
       break;
case 4:exit(1);
}
}
while(1);
}
//insert
void insert(int data)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node*));
t->data=data;
if(start==(struct node*)0)
t->left=t->right=(struct node*)0;
else
{
t->left=(struct node*)0;
t->right=start;
start->left=t;
}
start=t;
}


//search
struct node*search(int data)
{
struct node*t=start;
while(t!=(struct node*)0&&t->data!=data)t=t->right;
return t;
}
//delete
void delete(int data)
{
struct node*t;
t=search(data);
if(t==0)
 printf("item not found\n");
else
{
if(t==start)//1st node
if (t->right==(struct node*)0)
start=(struct node*)0;
else
{
t->right->left=t->left;
start=t->right;
}
else if(t->right==(struct node*)0)
t->left->right=t->right;
else
{
t->left->right=t->right;
t->right->left=t->left;
}
}
free(t);
}
                               


