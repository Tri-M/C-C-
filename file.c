#include<stdio.h>
struct Node
{
    char x,y,z;
};

int main()
{
    struct Node p={'1','0','a'+2};
    struct Node *q=&p;
    printf("%c,%c",*((char*)q+1),*((char*)q+2));
    return 0;
}