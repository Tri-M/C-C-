#include <stdio.h>
#include<stdlib.h>
 
struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};
 
struct Tree*  create(struct Tree *node, int data)
  {
  if (node == NULL)
  {
  struct Tree *temp;
  temp= (struct Tree*)malloc(sizeof(struct Tree));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
  }
  if (data < (node->data))
  {
  node->left = create(node->left, data);
  }
  else if (data > node->data)
  {
  node -> right = create(node->right, data);
  }
  return node;
  }

int count_leaves(struct Tree *root){
    if(root == NULL)
        return 0;
        if(root->left == NULL && root->right == NULL)
        return 1;
        return count_leaves(root->left) + count_leaves(root->right);
}
 
int main() 
{
    int data,n;
    struct Tree *root=NULL;
    printf("\nEnter how many elements : " );
			scanf("%d", &n);
			int i;
			printf("\nEnter %d values  \n",n);
			for(i=0; i<n; i++)
			{
			scanf("%d", &data);
			root=create(root, data);
            }
    
    printf("Number of leaf Node(s) : %d", count_leaves(root));    
    getchar();
    return 0; 
}
