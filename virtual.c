#include<iostream>
using namespace std;

class Base
{
    protected:
    int x;
    public:
    Base():x(10){}
  virtual void disp()
    {
        cout<<"from base"<<x<<endl;
    }
};
class Derived:public Base
{
    public:
    int y;
    Derived():y(20){}

   void disp()
    {
        cout<<"from derived"<< "x="<<x << "y="<<y<<endl;
    }
};
int main()
{
    Derived d;
    Base *p=&d;

    //p=&d;
    p->disp();//derived
    cout<<sizeof(d);
    cout<<sizeof(p);
}