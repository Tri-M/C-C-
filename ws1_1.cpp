#include<iostream>
#include<string>
using namespace std;

typedef struct bst
{
    int data;
    bst *right;
    bst *left;
}bst;

bst *ptr,*root,*par;

void create(int val)
{
    bst *n =new bst;
    n->data=val;
    n->right=NULL;
    n->left=NULL;
    root=n;
}
void Insert(int val)
{
    par=NULL;
    ptr=root;
    while(ptr!=NULL)
    {
        par=ptr;
        if(val<ptr->data)
           ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    bst*n=new bst;
    n->data=val;
    n->right=n->left=NULL;
    if(val<par->data)
        par->left=n;
    else
        par->right=n;
}
int findmin()
{
    int val;
    ptr=root;
    while(ptr->left!=NULL)
    {
        ptr=ptr->left;
    }
    val=ptr->data;
    cout<<val<<endl;
    return val;

}
int findmax()
{
    int val;
    ptr=root;
    while(ptr->right!=NULL)
    {
        ptr=ptr->right;
    }
    val=ptr->data;
    cout<<val<<endl;
    return val;

}
void search(int val)
{
    ptr=root;
    int i=0;
    while(ptr!=NULL)
    {
        if(val<ptr->data)
            ptr=ptr->left;
        else if(val>ptr->data)
            ptr=ptr->right;
        else
        {
            cout<<"Element found"<<endl;
            i=1;
            break;
        }
    }
    if(i==0)
        cout<<"Element not found"<<endl;
}
bst* del(bst* root, int k)
{

	if (root == NULL)
		return root;
	if (root->data > k) {
		root->left = del(root->left, k);
		return root;
	}
	else if (root->data < k) {
		root->right = del(root->right, k);
		return root;
	}
	if (root->left == NULL) {
		bst* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == NULL) {
		bst* temp = root->left;
		delete root;
		return temp;
	}

	else {
		bst* suc_par = root;
		bst* suc = root->right;
		while (suc->left != NULL) {
			suc_par=suc;
			suc = suc->left;
		}

		if (suc_par != root)
			suc_par->left = suc->right;
		else
			suc_par->right = suc->right;


		root->data= suc->data;


		delete suc;
		return root;
	}
}
int leftnode(int val)
{
    ptr=root;
    while(ptr!=NULL)
    {
        if(val<ptr->data)
            ptr=ptr->left;
        else if(val>ptr->data)
            ptr=ptr->right;
        else
        {
            if(ptr->left==NULL)
                return -1;
            else
                return (ptr->left)->data;
        }
}
}
int rightnode(int val)
{
    ptr=root;
    while(ptr!=NULL)
    {
        if(val<ptr->data)
            ptr=ptr->left;
        else if(val>ptr->data)
            ptr=ptr->right;
        else
        {
            if(ptr->right==NULL)
                return -1;
            else
                return (ptr->right)->data;
        }
}
}
void Inorder(bst *root)
{
    if(!root)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Preorder(bst *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(bst *root)
{
    if(!root)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int height(bst* root)
{
    if (root == NULL)
        return 0;
    else
    {

        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}
void CurrentLevel(bst* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        CurrentLevel(root->left, level-1);
        CurrentLevel(root->right, level-1);
    }
}
void LevelOrder(bst* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        CurrentLevel(root, i);
}

int main()
{
    create(12);
    Insert(24);
    Insert(3);
    Insert(45);
    Insert(16);
    Insert(21);
    Insert(19);
    Insert(26);
    cout<<"inorder"<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"preorder"<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"postorder"<<endl;
    Postorder(root);
    cout<<endl;
    int a;
    cout<<"\n minimum element : ";
    a=findmin();
    cout<<"\nDeletion ";
    del(root,a);
    Inorder(root);
    cout<<endl;
    int b;
    cout<<"\nMaximum element : ";
    b=findmax();
    cout<<"\nSearching ";
    search(100);
    int c,d;
    cout<<"\nRight node :  ";
    c=rightnode(45);
    cout<<c<<endl;
    cout<<"\nLeft node : ";
    d=leftnode(21);
    cout<<d<<endl;
    cout<<"\nLevel order ";
    LevelOrder(root);
    cout<<endl;
}
