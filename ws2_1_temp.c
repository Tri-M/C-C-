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
int deletemin(AVL *);

AVL * rotateright(AVL *val)
{
AVL *temp;
temp=val->left;
val->left=temp->right;
temp->right=val;
val->ht=height(val);
temp->ht=height(temp);
return(temp);
}
 
AVL * rotateleft(AVL *val)
{
AVL *temp;
temp=val->right;
val->right=temp->left;
temp->left=val;
val->ht=height(val);
temp->ht=height(temp);
return(temp);
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
 
AVL * RL(AVL *newnode)
{
newnode->right=rotateright(newnode->right);
newnode=rotateleft(newnode);
return(newnode);
}
 
int balfac(AVL *newnode)
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
 
return(lh-rh);
}
 
void preorder(AVL *newnode)
{
if(newnode!=NULL)
{
printf("%d(Balance Factor =%d)",newnode->data,balfac(newnode));
preorder(newnode->left);
preorder(newnode->right);
}
}

 
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

int minValue(AVL* node)
{      
    AVL* ptr = node;
    while (ptr->left != NULL)
        ptr = ptr->left;     
    return (ptr->data);
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
 
 
void inorder(AVL *newnode)
{
if(newnode!=NULL)
{
inorder(newnode->left);
printf("%d(B.F=%d)",newnode->data,balfac(newnode));
inorder(newnode->right);
}
}

AVL* search(AVL *node, int data)
{
if(node == NULL)
printf("\nElement not found.");
else if(data < node->data)
{
node->left=search(node->left, data);
}
else if(data > node->data)
{
node->right=search(node->right, data);
}
else
printf("\nElement found is: %d", node->data);
return node;
}

int deletemin(AVL *root)
{
    AVL *ptr;
    ptr=root;
    while(ptr->left!=NULL)
    {
        ptr = ptr->left;
    }
    return ptr->data;

}

void deleteleft(AVL *ptr,AVL *root)
{
    if(ptr!=NULL)
    {
        deleteleft(ptr->left, root);
        if(ptr->left!= NULL && ptr->right==NULL)
        {
            root = Delete(root, ptr->data);
            return;
        }
        deleteleft(ptr->right, root);
    }
}


void printbetween(struct AVL *root, int k1, int k2)
{
      if ( NULL == root )
      return;
    if ( k1 < root->data )
     printbetween(root->left, k1, k2);
    if ( k1 <= root->data && k2 >= root->data )
     printf("%d ", root->data );
    if ( k2 > root->data )
     printbetween(root->right, k1, k2);
}

void printInorder(AVL* ptr)
{
    if (ptr == NULL)
        return;
 
    printInorder(ptr->left);
     printf("%d ", ptr->data); 
    printInorder(ptr->right);
}
int calheight(AVL* node)
{
    if (node==NULL)
        return 0;
    else
    {
        
        int lheight = calheight(node->left);
        int rheight = calheight(node->right);
 
        
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

int count_leaves(struct AVL *root){
    if(root == NULL)
        return 0;
        if(root->left == NULL && root->right == NULL)
        return 1;
        return count_leaves(root->left) + count_leaves(root->right);
}


int main()
{
AVL *root=NULL;
int val,n,i,choice;
int k1,k2;


do
{
printf("\n\n1)Create AVL tree ");
printf("\n2)Insert elements into AVL Tree");
printf("\n3)Delete element from AVL tree ");
printf("\n4)Print AVL tree");
printf("\n5)Delete the minimum node from AVL tree");
printf("\n6)Delete the node with only left child ");
printf("\n7)Delete the root node :");
printf("\n8)Search for an element");
printf("\n9)Traverse the tree in inorder");
printf("\n10)Find the height of the tree ");
printf("\n11)Print the list of all keys between 2 nodes in the AVL tree ");
printf("\n12)Count the number of leaves ");
printf("\n13)Quit program ");
printf("\n\nEnter Your Choice:");
scanf("%d",&choice);
switch(choice)
{

case 1:
 printf("\nEnter no. of elements:");
scanf("%d",&n);
printf("\nEnter tree data:");
root=NULL;
for(i=0;i<n;i++)
{
scanf("%d",&val);
root=insert(root,val);
}
break;

case 2:
 printf("\nEnter a data:");
scanf("%d",&val);
root=insert(root,val);
break;

case 3:
 printf("\nEnter a data:");
scanf("%d",&val);
root=Delete(root,val);
break;

case 4: 
printf("\nPreorder sequence:\n");
preorder(root);
printf("\n\nInorder sequence:\n");
inorder(root);
printf("\n");
break;


case 5:
printf("\nThe minimum value to be deleted ",deletemin(root));
Delete(root,deletemin(root));
printf("\n");
printInorder(root);
break;

case 6:
printf("\nDeleting node with only left child ");
deleteleft(root,root);
printf("\n");
printInorder(root);
break;

case 7:
printf("\nDeleting root node ");
root = Delete(root, root->data);
break;


case 8:
printf("\nEnter the element to be searched for : ");
scanf("%d",&val);
root=search(root,val);
break;

case 9:
printf("\nThe inorder traversal of the tree is : ");
printInorder(root);
break;

case 10:
printf("\nCalculating the height of the tree : ");
int h;
h = calheight(root);
printf("%d",h);
break;


case 11:
printf("\nEnter two keys k1 and k2. This function will print all the nodes between k1 and k2  :  \n");
scanf("%d %d",&k1,&k2);
printbetween(root,k1,k2);
break;

case 12:
printf("Number of leaf Node : %d", count_leaves(root));    
break;

case 13:
printf("\nExiting program ");
exit(0);
break;

}
}
while(choice!=13);
return 0;
}
