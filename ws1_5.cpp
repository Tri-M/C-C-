#include<iostream>
using namespace std;

struct node
{
	node *lc,*rc;//left child and right child
	int data;
}*root = NULL,*ptr = NULL;

node* getNode(int data)
{
    node *n = new node();
    n->data = data;
    n->lc = NULL;
    n->rc = NULL;
    return n;
}

node* insertnode(node* ptr,int data)
{
    if(ptr == NULL)
    {
    	return getNode(data);
    }

    else if (data < ptr -> data)
    {
        ptr -> lc = insertnode(ptr -> lc, data);
    }
    else if (data > ptr -> data)
    {
         ptr -> rc = insertnode(ptr -> rc ,data);
    }
    return ptr;
}

node* isSame(node* ptr,int num)
{
    if(ptr==NULL)
    {
        cout<<"NO"<<endl;
        ptr=root;
        return ptr;
    }
    if(ptr -> data < num)
    {
        return isSame(ptr -> rc , num);
    }
    else if(ptr -> data > num)
    {
        return isSame(ptr -> lc , num);
    }
    else if(ptr -> data == num)
    {
        cout<<"YES"<<endl;
        ptr = root;
        return ptr;
    }

}

int main()
{
    int n;
    cout<<"Enter number of students : ";
    cin>>n;
    int student[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number of chocolates got by student"<<i+1<<" : ";
        cin>>student[i];
        root = insertnode(root,student[i]);
    }

    int extra;
    cout<<"Enter number of extra students : ";
    cin>>extra;
    int extraStudents[extra];
    for(int i=0;i<extra;i++)
    {
        cout<<"Enter number of Candies got by M"<<i+1<<" : ";
        cin>>extraStudents[i];
        root = isSame(root,extraStudents[i]);
    }
    return 0;
}
