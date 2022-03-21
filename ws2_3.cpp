#include<iostream>
using namespace std;


typedef struct BST 
{
    int data;
    struct BST *right,*left;
}BST;

BST* Broot;


BST* newnodeBST(int item) 
{
	BST* temp = new BST;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

BST* BST_insertion(BST* node, int data) 
{
	if (node == NULL)
		return newnodeBST(data);
	if (data < node->data)
		node->left = BST_insertion(node->left, data);
	else if(data>node->data)
		node->right = BST_insertion(node->right, data);
    else
        return node;
	return node;
}


typedef struct AVL   
{
    int data;
    AVL *left;
    AVL *right;
    int ht;
}AVL;
AVL *root;


AVL* newAVLNode(int dat)  //AVL new node
{
    AVL *n=new AVL;
    n->data=dat;
    n->ht=1;
    n->left=n->right=NULL;
    return n;
}
int ht(AVL *node)
{
    if(node==NULL)
        return 0;
    else
    {
        return node->ht;
    }
}


int calc_BF(AVL *node) 
{
    if(node==NULL)
        return 0;
    else
    {
        int lh=0,rh=0;
        if(ht(node->left)!=0)
            lh=ht(node->left);
        if(ht(node->right)!=0)
            rh=ht(node->right);
        return lh-rh;
    }
}

int max(int a,int b)  
{
    return (a>b)?a:b;
}


AVL* LRot(AVL* node)  // Left rotation
{
    AVL* l=node->right;
    AVL* r=l->left;
    l->left=node;
    node->right=r;
    node->ht=max(ht(node->right),ht(node->left))+1;
    l->ht=max(ht(l->right),ht(l->left))+1;
    return l;
}



AVL* RRot(AVL* node) //Right rotation
{
    AVL* l=node->left;
    AVL* r=l->right;
    l->right=node;
    node->left=r;
    node->ht=max(ht(node->right),ht(node->left))+1;
    l->ht=max(ht(l->right),ht(l->left))+1;
    return l;
}

AVL* Left_right(AVL* p) // Left-Right rotation
{
    AVL* l = p->left;
    AVL* lr = l->right;

    l->right = lr->left;
    p->left = lr->right;

    lr->left = l;
    lr->right = p;

    l->ht = max(ht(l->right),ht(l->left))+1;
    p->ht = max(ht(p->right),ht(p->left))+1;
    lr->ht = max(ht(lr->right),ht(lr->left))+1;

    if (p == root)
    {
        root = lr;
    }
    return lr;
}
AVL* right_left(AVL* p) 
{
    AVL* r = p->right;
    AVL* rl = r->left;

    r->left = rl->right;
    p->right = rl->left;

    rl->right = r;
    rl->left = p;

    r->ht = max(ht(r->right),ht(r->left))+1;
    p->ht = max(ht(p->right),ht(p->left))+1;
    rl->ht = max(ht(rl->right),ht(rl->left))+1;

    if (root == p)
    {
        root = rl;
    }
    return rl;
}


AVL* AVL_insertion(AVL* node,int d) 
{
    if(node==NULL)
        return (newAVLNode(d));
    else if(node->data>d)
        node->left=AVL_insertion(node->left,d);
    else if(node->data<d)
        node->right=AVL_insertion(node->right,d);
    else
        return node;
    node->ht=max(ht(node->left),ht(node->right))+1;
    int bal_fac=calc_BF(node);
    if(bal_fac<-1 && d>node->right->data)
        return LRot(node);

    if(bal_fac>1 && d<node->left->data)
        return RRot(node);
    if(bal_fac<-1 && d<node->right->data)
    {
        node->right=RRot(node->right);
        return LRot(node);
    }
    if(bal_fac>1 && d>node->left->data)
    {
        node->left=LRot(node->left);
        return RRot(node);
    }
    return node;
}

void inorder_of_BST(BST *ptr) // Inorder traversal  of a BST
{
    if(ptr != NULL)
    {
        inorder_of_BST(ptr->left);
        cout << ptr->data <<" ";
        inorder_of_BST(ptr->right);
    }
}


void current_level(AVL* rot, int level) 
{
    if (rot == NULL)
        return;
    if (level == 1)
        cout << rot->data << " ";
    else if (level > 1)
    {
        current_level(rot->left, level-1);
        current_level(rot->right, level-1);
    }
}
void levelorder(AVL* rot)
{
    int h = ht(root);
    int i;
    for (i = 1; i <= h; i++)
        current_level(rot, i);
}



void avlInorder(AVL *root)
{
    if(root != NULL)
    {
        avlInorder(root->left);
        cout << root->data << " " << root->ht << endl;
        avlInorder(root->right);
    }
}


BST* merge_func(BST *r1,BST *r2)
{
    BST *ptr=r1;
    if(ptr!=NULL)
    {
        merge_func(ptr->left,r2);
        r2=BST_insertion(r2,ptr->data);
        merge_func(ptr->right,r2);
    }
    return r2;
}

AVL* createAVL(AVL *a, BST *b)
{
    BST *ptr=b;
    if(ptr!=NULL)
    {
        a=createAVL(a,ptr->left);
        a=AVL_insertion(a,ptr->data);
        a=createAVL(a,ptr->right);
    }
    return a;
}


int main()
{
    root=NULL;
    BST *r1=NULL,*r2=NULL,*r=NULL;
    
    
    cout<<"BST - 1"<<endl;
    r1=BST_insertion(r1,4);
    r1=BST_insertion(r1,8);
    r1=BST_insertion(r1,7);
    inorder_of_BST(r1);
    cout<<endl<<endl;
    
    
    cout<<"\nBST - 2"<<endl;
    r2=BST_insertion(r2,6);
    r2=BST_insertion(r2,5);
    r2=BST_insertion(r2,9);
    inorder_of_BST(r2);
    cout<<endl<<endl;
    
    
    cout<<"\nMerging BSTs"<<endl;
    r=merge_func(r1,r2);
    cout<<endl<<endl;
    
    
    cout<<"AVL tree : "<<endl;
    root=createAVL(root,r);
    levelorder(root);
    cout<<endl<<endl;

    return 0; 
}
