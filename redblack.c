#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
char color;
struct node *par;
struct node *left;
struct node *right;
};  

void main()
{
struct node *left_rotate(struct node*,struct node*);
struct node *right_rotate(struct node*,struct node*);
struct node *rb_insert_fixup(struct node*,struct node*);
struct node *rb_insert(struct node*,struct node*);
void inorder(struct node*);
struct node *T=0,*z,*k1,*k2;
int i,n,key;
printf("Enter no of keys to insert:");
scanf("%d",&n);
printf("Enter the values:\n");
for(i=0;i<n;i++)
{
scanf("%d",&key);
z=(struct node*)malloc(sizeof(struct node));
z->key=key;
T=rb_insert(T,z);
}
printf("Red Black tree:\n");
inorder(T);
}


//rotating node left
struct node * left_rotate(struct node *T,struct node *x)
{
struct node *y=x->right;
x->right=y->left;  //y is left subtree
if(y->left!=0)
{
y->left->par=x;
}
y->par=x->par; //store x's parent as y's parent
if(x->par==0)  //if x is root then
T=y;   //set y as root
else if(x==x->par->right)
x->par->right=y;
else
x->par->left=y;
y->left=x;
x->par=y;
return T; //returning new root
} //end of the left rotate


//function for rotating node right
struct node * right_rotate(struct node *T,struct node *x)
{
struct node *y=x->left;
x->left=y->right;
if(y->right!=0)
y->right->par=x;
y->par=x->par;
if(x->par==0)
T=y;
else if(x=x->par->left)
x->par->left=y;
else
x->par->right=y;
y->right=x;
x->par=y;
return T;
}  //end of the right rotation



//function for fixing nodes and its colos

struct node *rb_insert_fixup(struct node *T,struct node *z)
{
struct node *y;
while(z->par!=0 && z->par->color=='R')
{
if(z->par==z->par->par->left)
{
y=z->par->par->right;
if(y!=0 && y->color=='R') //uncle is red
{
z->par->color='B';
y->color='B';
z->par->par->color='R';
z=z->par->par;
}
else
{
if(z==z->par->right)
{
z=z->par;
T=left_rotate(T,z);
}
z->par->color='B';
z->par->par->color='R';
T=right_rotate(T,z->par->par);
}
}
else
{
y=z->par->par->left;
if(y!=0 && y->color=='R')
{
z->par->color='B';
y->color='B';
z->par->par->color='R';
z=z->par->par;
}
else
{
if(z=z->par->left)
{
z=z->par;
T=right_rotate(T,z);
}
z->par->color='B';
z->par->par->color='R';
T=left_rotate(T,z->par->par);
}
}
} //end of while
T->color='B';
return T;
}  //end pf fixup


//to insert a node z in a red bleck tree
struct node *rb_insert(struct node *T,struct node *z)
{
struct node *y=0,*x;
x=T;
while(x!=0)
{
y=x;
if(z->key<x->key)
x=x->left;      //move to left child
else
x=x->right;   //move to right child
}
z->par=y;     //if tree is null
if(y==0)      //first node insertion
T=z;
else if(z->key<y->key)
y->left=z;    //z is left child of its parent
else
y->right=z;   //z is right child of its parent
z->left=0;
z->right=0;
z->color='R';
T=rb_insert_fixup(T,z);    //fixing node and its color
return T;
}   //end of rb_insert


//inorder traversal
void inorder(struct node *x)
{
if(x!=NULL)
{
inorder(x->left);
printf("%d(%c)\n",x->key,x->color);
inorder(x->right);
}
}
