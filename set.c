#include<stdio.h>
struct bit{
unsigned char x:1;
};

int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main()
{
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void intersectset(struct bit[],struct bit[],struct bit[]);
void diffset(struct bit[],struct bit[],struct bit[]);
struct bit a[9]={0};
struct bit b[9]={0};
struct bit c[9]={0};
int x,y;
printf("enter no.of elements in set A:");
scanf("%d",&x);
readset(a,x);
printf("enter no.of elements in set B:");
scanf("%d",&y);
readset(b,y);

printf("set A:");
printset(a);

printf("set B:");
printset(b);

unionset(a,b,c);
printf("AUB=");
printset(c);

intersectset(a,b,c);
printf("A^B=");
printset(c);


diffset(a,b,c);
printf("A-B=");
printset(c);
}

//to read a set and store as bit string
void readset(struct bit a[],int n)
{
int i,x,k,d;
printf("enter %d  elements:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&d);
for(k=0;k<size;++k)
if(uset[k]==d)//if x is a set currusponding to x in a[]
{
a[k].x=1;
break;
}
}
return;
}
//to print a set from bit string representation
void printset(struct bit a[])
{
int k;
printf("{");
for(k=0;k<size;k++)
if(a[k].x==1)
printf("%d,",uset[k]);
printf("\b}\n");
return;
}
//union of two set
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
c[k].x=a[k].x | b[k].x;
return;
}
//intersection
void intersectset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;++k)
c[k].x=a[k].x & b[k].x;
return;
}
//differenceset
void diffset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;++k)
if(a[k].x==1)
c[k].x=a[k].x ^ b[k].x;
return;
}                





