#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct SplayTree
{
    int data;
    SplayTree* right;
    SplayTree* left;
    SplayTree *root;
};


SplayTree* create(int val)
{
    SplayTree* newnode=new SplayTree;
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    return(newnode);
}
SplayTree* insert_node(SplayTree* ptr, int elt)
{
    if(ptr==NULL)
        return create(elt);
    if(elt < ptr->data)
        ptr->left = insert_node(ptr->left, elt);
    else if(elt > ptr->data)
        ptr->right = insert_node(ptr->right, elt);
    return ptr;
}
SplayTree *rotateright(SplayTree *ptr)
{
    SplayTree *temp=ptr->left;
    ptr->left=temp->right;
    temp->right=ptr;
    return temp;    
}

SplayTree *rotateleft(SplayTree *ptr)
{
    SplayTree *temp=ptr->right;
    ptr->right=temp->left;
    temp->left=ptr;
    return temp;
}

SplayTree *splay(SplayTree *root,int key)
{
    if(root==NULL||root->data==key)
    return root;

    if(key<root->data)
    {
        if(root->left==NULL)
        return root;

        if(root->left->data>key)  //zig-zig
        {
            root->left->left=splay(root->left->left,key);
            root=rotateright(root);
        }
        else if(root->left->data<key) //zig-zag
        {
            root->left->right=splay(root->left->right,key);
            if(root->left->right!=NULL)
            root->left=rotateleft(root->left);
        }
        return(root->left==NULL)?root:rotateright(root);
    }
    else
    {
        if(root->right==NULL)
        return root;
        if(root->right->data>key)  //zag-zig
        {
            root->right->left=splay(root->right->left,key);
            if(root->right->left!=NULL)
            root->right=rotateright(root->right);
        }
        else if(root->right->data<key) //zag-zag
        {
            root->right->right=splay(root->right->right,key);
            root=rotateleft(root);
        }
        return (root->right==NULL)?root:rotateleft(root);
        }

    }

SplayTree *search(SplayTree *root,int key)
{
    return splay(root,key);
}
void preorder(SplayTree *root)
{
    if(root!=NULL)
    {
        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

SplayTree* deletion(SplayTree *root, int key)
{
    struct SplayTree *temp;
    if (!root)
        return NULL;
      
    root = splay(root, key);
    if (key != root->data)
        return root;
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }
    else
    {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }
    free(temp);
    return root;
    
}

void printInorder(SplayTree* root)

{
    if(root!=NULL)
    {
    printInorder(root->left);
    cout<<root->data<<" | ";
    printInorder(root->right);
    }

}

int calheight(SplayTree* node)
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

SplayTree* minValueNode(SplayTree *ptr)
{
    SplayTree * current = ptr;
    while(current->left!=NULL)
    {
        current = current->left;
    }
    return current;
}

int largestKey(SplayTree *root)
{
    SplayTree * current = root;
    while(current->right!=NULL)
    {
        current = current->right;
    }
    return current->data;
}

int countkeys(SplayTree *ptr,int k1,int k2)
{
    if(ptr==NULL)
        return 0;
    if(ptr->data >=k1 && ptr->data <=k2)
        return 1 + countkeys(ptr->left, k1, k2) + countkeys(ptr->right, k1, k2);
    if(ptr->data < k1)
        return countkeys(ptr->right, k1, k2);
    if(ptr->data > k2)
        return countkeys(ptr->left,k1,k2);
}

int num_of_nodes(SplayTree *ptr)
{
    if(ptr==NULL)
        return 0;
    return 1 + num_of_nodes(ptr->left) + num_of_nodes(ptr->right);
}


int main()
{
    SplayTree *root=NULL;
    int choice;
    int k1,k2,val,n,i;
    do
    {
        cout<<"\n\nSPLAY TREES\n";
        cout<<"\n1)Create Splay Tree .  ";
        cout<<"\n2)Delete element ";
        cout<<"\n3)Traverse the tree in inorder ";
        cout<<"\n4)Calculate the height of the tree ";
        cout<<"\n5)Search for an element ";
        cout<<"\n6)Count the number of keys between two given Keys ";
        cout<<"\n7)Delete the largest key ";
        cout<<"\n8)Delete the elememts in the splay tree until the splay tree has only three elements ";
        cout<<"\n9)Exit program ";
        cout<<"\n\nEnter your choice : " <<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"\nEnter the number of elements : ";
            cin>>n;
            cout<<endl;
            cout<<"\nEnter the tree elements : ";
            for(i=0;i<n;i++)
            {
            cin>>val;
            root=insert_node(root,val);
            printInorder(root);
            }
            break;
            case 2:
            cout<<"\nEnter the value to be deleted :";
            cin>>val;
            root=deletion(root,val);
            cout<<"\nAfter deletion ";
            printInorder(root);
            break;
            case 3:
            cout<<"\nInorder sequence ";
            printInorder(root);
            cout<<"\n";
            break;
            case 4:
            cout<<"\nCalculating the height of the tree ";
            int h;
            h = calheight(root);
            cout<<h;
            break;
            case 5:
            cout<<"Enter value to be searched: ";
            cin>>val;
            root = search(root,val);
            cout<<"\nAfter Search "<<val<<endl;
            printInorder(root);
            break;
            case 6:
            cout<<"\nEnter 2 keys k1 and k2. ( count of keys includes k1 and k2 also. )";
            cin>>k1>>k2;
            cout<<" "<<countkeys(root,k1,k2);
            break;
            case 7:
            cout<<"\nDeletion of the largest key from the SplayTree ";
            root=deletion(root,largestKey(root));     
            printInorder(root);
            break; 
            case 8:
            while(num_of_nodes(root)>3)
            {
                root =deletion(root, root->data);
                
            }
            printInorder(root);
            break;
            case 9:
            cout<<"\nExiting the program ";
            exit(0);
            break;

        }


    } while (choice!=9);
    
    return 0;

}
