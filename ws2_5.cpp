#include<iostream>
using namespace std;
typedef struct Bst
{
    int key;
    int r;
   Bst *left;
   Bst *right;
}Bst;

Bst *root;
void print_Tree(const std::string& prefix, const Bst* node, bool isLeft)
{
    if( node != NULL )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|" : "|" );
        std::cout << node->key << std::endl;
        print_Tree( prefix + (isLeft ? "|   " : "    "), node->left, true);
        print_Tree( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void print_Tree(const Bst* node)
{
    print_Tree("", node, false);
}

Bst* BSTnode(int a,int r)
{
   Bst *node= new Bst;
    node->key=a;
    node->left=NULL;
    node->right=NULL;
    node->r=r;
    return node;
}

void InsertNode(int key,int r)
{
    if(root==NULL)
    {
        root=BSTnode(key,r);
    }
    else
    {
       Bst *temp=root;
        while(temp!=NULL)
        {
            if(key==temp->key)
            {
                cout<<"\nValue already exists!";
                return;
            }
           
            else if((key<temp->key)&&(temp->left==NULL))
            {
                temp->left=BSTnode(key,r);
                break;
            }
            
            else if(key<temp->key)
            {
                temp=temp->left;
            }
            
            else if((key>temp->key)&&(temp->right==NULL))
            {
                temp->right=BSTnode(key,r);
                break;
            }
            
            else if(key>temp->key)
            {
                temp=temp->right;
            }
        }
    }
}

int Search(int key)
{
    if (root==NULL)
        return 0;
    else
    {
       Bst *temp=root;
        while(temp!=NULL)
        {
            if(key==temp->key)
            {
                cout<<"\n\nroll number  "<<temp->r<<" having "<<key<<" candies . "<<endl;
                return temp->r;
            }
            else if(key<temp->key)
            {
                temp=temp->left;
            }
            else if(key>temp->key)
            {
                temp=temp->right;
            }
        }
        cout<<"\n\nNo matching "<<endl;
        return 0;
    }
}
int main()
{
    int n,candy,m;
    int i=1;
    cout<<"\nTotal students :";
    cin>>n;

    for(i=1;i<=n;i++)
    {
        cout<<"\nnumber of candies received by roll number "<<i<<" of the class : ";
        cin>>candy;
        InsertNode(candy,i);
    }

  print_Tree(root);
    cout<<"\nHow many incoming students ? : ";
    cin>>m;

    for(;i<=n+m;i++)
    {
        cout<<"\nNumber of candies received by roll number "<<i<<" of the class : ";
        cin>>candy;
        int f=Search(candy);
        if(f!=0)
        {
            cout<<"\nStudent with roll number "<<i<<" will be sitting beside "<<f<<endl;
        }
    }
}
