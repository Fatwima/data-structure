#include<stdio.h>
//2 way merging
void main()
{
void readarr(int[],int);
void disparr(int[],int);
void merge(int[],int[],int[],int,int);
int s1[50],s2[50],s3[100],n,m;
printf("enter the no.of elements in 1st array[1-50]\n");
scanf("%d",&n);
printf("enter the  elements in 1st array:\n");
readarr(s1,n);
printf("enter the no.of elements in 2nd array[1-50]\n");
scanf("%d",&m);
printf("enter the  elements in 2nd array:\n");
readarr(s2,m);
merge(s1,s2,s3,n,m);
printf("merged array:\n");
disparr(s3,m+n);
}
// function for read an array
void readarr(int s[],int n)
{
int i;
printf("enter nos in non decreesing order\n");
for(i=0;i<n;i++)
{
scanf("%d",&s[i]);
}
return;
}
// function for display an array
void disparr(int s[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d\n",s[i]);
}
return;
}
//merge
void merge(int s1[],int s2[],int s3[],int n,int m)
{
int i,j,k;
i=j=k=0;
//compare
while(i<n&&j<m)
{
if(s1[i]<s2[j])
{
s3[k]=s1[i];
i=i+1;
k=k+1;
}
else
{
s3[k]=s2[j];
j=j+1;

k=k+1;
}
}
//copy remaining elmt frm s1
while(i<n)
s3[k++]=s1[i++];
//copy frm s2
while(j<m)
s3[k++]=s2[j++];
return;
}
