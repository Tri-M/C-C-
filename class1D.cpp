#include<iostream>
using namespace std;
class Matrix1D
{
int *a;

public:
Matrix1D();
Matrix1D(int array[], int n);
void display();
};
Matrix1D::Matrix1D(int array[], int n)
{
    int *p=a;
    p = new int [n];
for(int i=0;i<n;i++)
a[i]=array[i];
}
void Matrix1D::display()
{
for(int i=0;i<3;i++)
cout<<a[i];
}
int main()
{
int n;

cout<<"\nEnter size  :";
cin>>n;
int array[n];
for(int i=0;i<n;i++)
cin>>array[i];

Matrix1D m(array,n);
}

