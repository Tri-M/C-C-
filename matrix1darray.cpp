#include<iostream>
using namespace std;
class Matrix1D
{
int a[3];
public:
Matrix1D();
Matrix1D(int array[]);
void display();
};
Matrix1D::Matrix1D()
{
    int array[3]={0,0,0};
}
Matrix1D::Matrix1D(int array[])
{

for(int i=0;i<3;i++)
a[i]=array[i];
}
void Matrix1D::display()
{
for(int i=0;i<3;i++)
cout<<a[i];
}
int main()
{
Matrix1D m;
int array[3]={1,2,3};
Matrix1D m2(array);
}

