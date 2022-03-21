#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *ins(Node *ptr, int x)
{
    if(ptr==NULL)
        return new Node(x);
    if(x< ptr->data)
        ptr->left = ins(ptr->left, x);
    else if (x> ptr->data)
        ptr->right = ins(ptr->right, x);
    return ptr;
}

void inorder(Node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void printinorder(Node* ptr)
{
    inorder(ptr);
    cout << endl;
}

void levelorder(Node *root)
{
    if (root == NULL)
        return;

    queue <Node*> q;
    Node *ptr;
    q.push(root);
    while(!q.empty())
    {
        ptr = q.front();
        cout << ptr->data << ", ";
        q.pop();

        if(ptr->left)
            q.push(ptr->left);
        if(ptr->right)
            q.push(ptr->right);
    }
    cout << "\b\b " << endl;
}

Node * LL (Node * ptr)
{
    Node * k = ptr->left;
    ptr->left = k->right;
    k->right = ptr;
    return k;
}

Node * RR(Node *ptr)
{
    Node *k = ptr->right;
    ptr->right = k->left;
    k->left = ptr;
    return k;
}

Node *bringto(Node * root, int x)
{
    if(root==NULL || root->data==x)
        return root;
    if(x< root->data)
    {
        if(root->left==NULL)
            return root;
        if(x < root->left->data)  //zig zig LL on root and LL on root
        {
            root->left->left = bringto(root->left->left, x);
            root = LL(root);
        }
        else if(x > root->left->data) //zig zag  LR
        {
            root->left->right = bringto(root->left->right, x);

            if(root->left->right!=NULL)
                root->left = RR(root->left);
        }
        if(root->left==NULL)
            return root;
        return LL(root);
    }
    else
    {
        if(root->right==NULL)
            return root;
        if(x < root->right->data)
        {
            //zag zig
            root->right->left= bringto(root->right->left, x);

            if(root->right->left!=NULL)
                root->right = LL(root->right);
        }
        else if(x > root->right->data) // zag zag
        {
            root->right->right = bringto(root->right->right, x);

            root = RR(root);
        }
        if(root->right==NULL)
            return root;
        return RR(root);
    }
}

Node * convert(Node *root1, Node *root2)
{
    if(root1==NULL || root2==NULL)
        return root1;
    root1 = bringto(root1, root2->data);
    root1->left= convert(root1->left, root2->left);
    root1->right= convert(root1->right, root2->right);
}

int main()
{
    Node *root1 = NULL, *root2 = NULL;
    root1= ins(root1, 11);
    root1= ins(root1, 3);
    root1= ins(root1, 20);
    root1= ins(root1, 1);
    root1= ins(root1, 12);
    root1= ins(root1, 45);
    root1= ins(root1, 24);

    root2 = ins(root2, 12);
    root2 = ins(root2, 45);
    root2 = ins(root2, 24);
    root2 = ins(root2, 1);
    root2 = ins(root2, 11);
    root2 = ins(root2, 20);
    root2 = ins(root2, 3);

    cout << "Tree 1:\n";
    cout << "Inorder: ";
    printinorder(root1);
    cout << "Level order: ";
    levelorder(root1);

    cout << "\n\nTree 2:\n";
    cout << "Inorder: ";
    printinorder(root2);
    cout << "Level order: ";
    levelorder(root2);

    cout << "\n\nAfter conversion , Tree 1 becomes  \n";
    root1 = convert(root1, root2);
    cout << "Inorder: ";
    printinorder(root1);
    cout << "Level order: ";
    levelorder(root1);
    return 0;
}
