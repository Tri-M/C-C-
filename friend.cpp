#include<iostream>
class Ex
{
int x;
friend void fun()const ;
public:
Ex()
{

    x=25;
}
};
void fun()
{ Ex e;
std::cout<<e.x;
}
int main()
{
fun();
}
