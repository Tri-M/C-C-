#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct Tree
{
int data;
struct Tree *left;
struct Tree *right;
};

typedef struct Tree NODE;
NODE *node;
NODE* ptr;
void currentlevel(NODE* root, int level);
int calheight( NODE* node);



NODE* createtree(NODE *node, int data)
{
if (node == NULL)
{
NODE *temp;
temp= (NODE*)malloc(sizeof(NODE));
temp->data = data;
temp->left = temp->right = NULL;
return temp;
}
if (data < (node->data))
{
node->left = createtree(node->left, data);
}
else if (data > node->data)
{
node -> right = createtree(node->right, data);
}
return node;
}


void deleteMin()
{
    struct NODE *temp;
    if(ptr!=NULL){
        while(ptr->left->left!=NULL)
            ptr=ptr->left;
 
        if(ptr->left->right!=NULL)
        {
            temp=ptr->left;
            ptr->left=ptr->left->right;
            free(temp);
        }else{
            free(ptr->left->left);
            ptr->left = NULL;
        }
    }
}


NODE* search(NODE *node, int data)
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

void leftchild(NODE *rot,int elt)
{
    NODE *ptr=rot,*par;
    while(ptr!=NULL && ptr->data!=elt)
    {
        par=ptr;
        if(elt > ptr->data)
        {
            ptr= ptr->right;
        }
        else
        {
            ptr= ptr->left;
        }
    }
    if(ptr!=NULL)
    {
        if(ptr->left==NULL)
        {
            printf("The given node does not contain left node");
        }
        else
            printf("Left node of the given node is : %d",(ptr->left)->data);
    }
}
void rightchild(NODE *rot,int elt)
{
    NODE *ptr=rot,*par;
    while(ptr!=NULL && ptr->data!=elt)
    {
        par=ptr;
        if(elt > ptr->data)
        {
            ptr= ptr->right;
        }
        else
        {
            ptr= ptr->left;
        }
    }
    if(ptr!=NULL)
    {
        if(ptr->right==NULL)
        {
            printf("The given node does not contain right node");
        }
        else
            printf("Left node of the given node is : %d",(ptr->right)->data);
    }
}

int maxValue(NODE* node)
{      
    NODE* ptr = node;
    while (ptr->right != NULL)
        ptr = ptr->right;     
    return (ptr->data);
}


void printInorder(NODE* ptr)
{
    if (ptr == NULL)
        return;
 
    printInorder(ptr->left);
     printf("%d ", ptr->data); 
    printInorder(ptr->right);
}


void printPreorder(NODE* node)
{
    if (node == NULL)
        return;
 
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}


void printPostorder(NODE* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}


void printLevelOrder(NODE* root)
{
    int h = calheight(root);
    int i;
    for (i=1; i<=h; i++)
        printCurrentLevel(root, i);
}


void printCurrentLevel(NODE* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}


int calheight(NODE* node)
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


void main()
{
    int data,ch,n;
    NODE *root=NULL;
    
    while(1)
    {
        printf("\n\n\n");
        printf("\n\n\n0.Insertion of elements into the tree  ");
        printf("\n\n1. Deletion of the minimum node  ");
        printf("\n\n2.Finding an elememt  ");
        printf("\n\n3.Finding the maximum element  ");
        printf("\n\n4.Left child of a node ");
        printf("\n\n5.Right Child of a node   ");
        printf("\n\n6.Inorder traversal  ");
        printf("\n\n7.preorder traversal  ");
        printf("\n\n8.postorder traversal  ");
        printf("\n\n9.level order traversal  ");
        printf("\n\n10.exit  ");
        int i;
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        	case 0: printf("\nEnter N value: " );
			scanf("%d", &n);
			printf("\nEnter the values to create Tree \n");
			for(i=0; i<n; i++)
			{
			scanf("%d", &data);
			root=createtree(root, data);
		}
		break;
            case 1: printf("The minimum node to be deleted is : ");
            deleteMin();
            break;
            case 2:printf("\nEnter the element to be searched for : ");
            scanf("%d",&data);
            root=search(root,data);
            break;
            case 3:
            printf("\nThe node with maximum value : ");
            maxValue(root);
            break;
            case 4:
            printf("\nYou need to find the left child of ? : ");
            scanf("%d",&data);
            leftchild(root,data);
            case 5:
            printf("\nYou need to find the right child of ? : ");
            scanf("%d",&data);
            rightchild(root,data);
            case 6:
            printf("\nThe inorder traversal of the tree is : ");
            printInorder(root);
            break;
            case 7:printf("\nThe preorder traversal of the tree is :");
            printPreorder(root);
            break;
            case 8:printf("\nThe postorder traversal of the tree is : ");
            printPostorder(root);
            break;
            case 9: printf("\nThe level order traversal of the tree is : ");
            printLevelOrder(root);
            break;
            case 10: 
            exit(0);
            default: printf("\n----INVALID OPTION----");
            break;
        }
    }
    
}
