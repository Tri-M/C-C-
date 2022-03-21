#include<stdio.h>
#include<stdlib.h> 
typedef struct AVL
{
int data;
struct AVL *left,*right;
int ht;
}AVL;
 
AVL *insert(AVL *,int);
AVL *Delete(AVL *,int);
void preorder(AVL *);
void inorder(AVL *);
int height( AVL *);
AVL *rotateright(AVL *);
AVL *rotateleft(AVL *);
AVL *RR(AVL *);
AVL *LL(AVL *);
AVL *LR(AVL *);
AVL *RL(AVL *);
int balfac(AVL *);
 
 
AVL * insert(AVL *newnode,int val)
{
if(newnode==NULL)
{
newnode=(AVL*)malloc(sizeof(AVL));
newnode->data=val;
newnode->left=NULL;
newnode->right=NULL;
}

else
if(val > newnode->data) 
{
newnode->right=insert(newnode->right,val);
if(balfac(newnode)==-2)
if(val>newnode->right->data)
newnode=RR(newnode);
else
newnode=RL(newnode);
}
else
if(val<newnode->data)
{
newnode->left=insert(newnode->left,val);
if(balfac(newnode)==2)
if(val < newnode->left->data)
newnode=LL(newnode);
else
newnode=LR(newnode);
}
newnode->ht=height(newnode);
return(newnode);
}
 
AVL * Delete(AVL *newnode,int val)
{
AVL *p;
if(newnode==NULL)
{
return NULL;
}
else
if(val > newnode->data) 
{
newnode->right=Delete(newnode->right,val);
if(balfac(newnode)==2)
if(balfac(newnode->left)>=0)
newnode=LL(newnode);
else
newnode=LR(newnode);
}
else
if(val<newnode->data)
{
newnode->left=Delete(newnode->left,val);
if(balfac(newnode)==-2) 
if(balfac(newnode->right)<=0)
newnode=RR(newnode);
else
newnode=RL(newnode);
}
else
{

if(newnode->right!=NULL)
{ 
p=newnode->right;
while(p->left!= NULL)
p=p->left;
newnode->data=p->data;
newnode->right=Delete(newnode->right,p->data);
if(balfac(newnode)==2)
if(balfac(newnode->left)>=0)
newnode=LL(newnode);
else
newnode=LR(newnode);
}
else
return(newnode->left);
}
newnode->ht=height(newnode);
return(newnode);
}
 
int height(AVL *newnode)
{
int lh,rh;
if(newnode==NULL)
return(0);
if(newnode->left==NULL)
lh=0;
else
lh=1+newnode->left->ht;
if(newnode->right==NULL)
rh=0;
else
rh=1+newnode->right->ht;
if(lh>rh)
return(lh);
return(rh);
}
 
AVL * rotateright(AVL *val)
{
AVL *y;
y=val->left;
val->left=y->right;
y->right=val;
val->ht=height(val);
y->ht=height(y);
return(y);
}
 
AVL * rotateleft(AVL *val)
{
AVL *y;
y=val->right;
val->right=y->left;
y->left=val;
val->ht=height(val);
y->ht=height(y);
return(y);
}
 
AVL * RR(AVL *newnode)
{
newnode=rotateleft(newnode);
return(newnode);
}
 
AVL * LL(AVL *newnode)
{
newnode=rotateright(newnode);
return(newnode);
}
 
AVL * LR(AVL *newnode)
{
newnode->left=rotateleft(newnode->left);
newnode=rotateright(newnode);
return(newnode);
}
 
AVL * RL(AVL *T)
{
T->right=rotateright(T->right);
T=rotateleft(T);
return(T);
}
 
int BF(AVL *T)
{
int lh,rh;
if(T==NULL)
return(0);
 
if(T->left==NULL)
lh=0;
else
lh=1+T->left->ht;
 
if(T->right==NULL)
rh=0;
else
rh=1+T->right->ht;
 
return(lh-rh);
}
 
void preorder(AVL *T)
{
if(T!=NULL)
{
printf("%d(Bf=%d)",T->data,BF(T));
preorder(T->left);
preorder(T->right);
}
}
 
void inorder(AVL *T)
{
if(T!=NULL)
{
inorder(T->left);
printf("%d(Bf=%d)",T->data,BF(T));
inorder(T->right);
}
}



int main()
{
AVL *root=NULL;
int val,n,i,op;
do
{
printf("\n1)Create:");
printf("\n2)Insert:");
printf("\n3)Delete:");
printf("\n4)Print:");
printf("\n5)Quit:");
printf("\n\nEnter Your Choice:");
scanf("%d",&op);
switch(op)
{
case 1: printf("\nEnter no. of elements:");
scanf("%d",&n);
printf("\nEnter tree data:");
root=NULL;
for(i=0;i<n;i++)
{
scanf("%d",&val);
root=insert(root,val);
}
break;
case 2: printf("\nEnter a data:");
scanf("%d",&val);
root=insert(root,val);
break;
case 3: printf("\nEnter a data:");
scanf("%d",&val);
root=Delete(root,val);
break;
case 4: printf("\nPreorder sequence:\n");
preorder(root);
printf("\n\nInorder sequence:\n");
inorder(root);
printf("\n");
break;
}
}while(op!=5);
return 0;
}

