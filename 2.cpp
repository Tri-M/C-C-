#include <iostream>

using namespace std;

class Set
{
    int n;
    int s[100];
    public:
        Set();
        Set(int num);
        void ins_elt(int arr[]);
        void add(int);
        void remove(int);
        Set operator | (Set s2);
        Set operator & (Set s2);
        void display();
};

Set :: Set()
{
    n = 0;
}

Set :: Set(int num)
{
    n = num;
    for(int i=0;i<n;i++)
        s[i] = 0;
}

void Set :: ins_elt(int arr[])
{
    for(int i=0;i<n;i++)
    {
        s[i]=arr[i];
    }
}

void Set :: add(int elt)
{
    s[n]=elt;
    n++;
}

void Set :: remove(int elt)
{
    for(int i=0;i<n;i++)
    {
        if(s[i]==elt)
        {
            for(int j=i;j<n-1;j++)
            {
                s[j]=s[j+1];
            }
            n = n-1;
        }
    }
}

void Set :: display()
{
    cout<<"{";
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<",";
    }
    cout<<"\b"<<"}"<<"\n";
}

Set Set :: operator | (Set s2)
{
    Set s3;
    int c=0,flag=1;

    for(int i=0;i<this->n;i++)
    {
        s3.s[i] = this->s[i];
        c++;
    }
    for(int i=0;i<s2.n;i++)
    {
        flag = 1;
        for(int j=0;j<this->n;j++)
        {
            if(s2.s[i]==this->s[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            s3.s[c] = s2.s[i];
            c++;
        }
    }
    s3.n = c;
    return s3;
}

Set Set :: operator &(Set s2)
{
    int c = 0;
    Set s4;
    for(int i=0;i<this->n;i++)
    {
        for(int j=0;j<s2.n;j++)
        {
            if(this->s[i]==s2.s[j])
            {
                s4.s[c]=s2.s[j];
                c++;
                break;
            }
        }
    }
    s4.n = c;
    return s4;
}
int main()
{
    int n1,n2;
    cout<<"Enter the number of elements of set 1 : ";
    cin>>n1;
    int arr1[n1];
    cout<<"Enter the elements of set 1 :\n";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }

    cout<<"Enter the number of elements of set 2 : ";
    cin>>n2;
    int arr2[n2];
    cout<<"Enter the elements of set 1 :\n";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    Set s1(n1),s2(n2);
    s1.ins_elt(arr1);
    s2.ins_elt(arr2);
    cout<<"SET 1 : ";
    s1.display();
    cout<<"SET 2 : ";
    s2.display();

    int choice=1,flag=0,elt,n;
    while(choice)
    {
        cout<<"1.Add element\n2.Remove element\n3.Union\n4.Intersection\nWhat to perform ? : ";
        cin>>flag;
        switch(flag)
        {
            case 1:
                cout<<"Which set do you want to add (1 or 2) : ";
                cin>>n;
                cout<<"Enter an element to add : ";
                cin>>elt;
                if(n==1)
                    s1.add(elt);
                else
                    s2.add(elt);
                cout<<"After adding element :\n";
                if(n==1)
                    s1.display();
                else
                    s2.display();
                break;
            case 2:
                cout<<"Which set do you want to add (1 or 2) : ";
                cin>>n;
                cout<<"Enter an element to remove : ";
                cin>>elt;
                if(n==1)
                    s1.remove(elt);
                else
                    s2.remove(elt);
                cout<<"After removing element :\n";
                if(n==1)
                    s1.display();
                else
                    s2.display();
                break;
            case 3:
            {
                Set s3(3);
                s3 = s1|s2;
                s3.display();
                break;
            }
            case 4:
            {
                Set s4;
                s4 = s1&s2;
                s4.display();
                break;
            }
            default:
              cout<<"Invalid choice...\n";
        }
        cout<<"Do you want to continue ? (0 for no) :";
        cin>>choice;
    }
    return 0;
}