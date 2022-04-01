#include<iostream>
using namespace std;
class Matrix1D
{
int a[3];
public:
Matrix1D();
Matrix1D(int);
void display();
};
Matrix1D m;
void Matrix1D::display()
{
for(int i=0;i<3;i++)
cout<<a[i];
}
int main()
{
cout<<"\nEnter the array : ";
for(int i=0;i<3;i++)
cin>>m.a[i];
Matrix1D();
Matrix1D(3);
}

