#include<iostream>
#include<string.h>
using namespace std;

class Book
{
 string author,title,publisher;
 int price,stock;

 public:
  Book();
  void input();  //to input details 
  void display();   // to display details 
  int search(string s1,string s2);  //search for the book 
  float copies(int);
};
Book::Book()
{
    author="";
    title="";
    publisher="";
    price=0;
    stock=0;
}

void Book::input()
{
 cout<<"\nEnter name of the author: ";
 cin>>author;
 cout<<"\nEnter title of the Book: ";
 cin>>title;
 cout<<"\nEnter publisher of the Book: ";
 cin>>publisher;
 cout<<"\nEnter price of the Book: ";
 cin>>price;
 cout<<"\nEnter stock of Book: ";
 cin>>stock;
}

void Book::display()
{
 cout<<"\n";
 cout<<author<<"\t"<<title<<"\t"<<publisher<<"\t"<<price<<"\t"<<stock;
}

int Book::search(string s1,string s2)
{
 if(author==s1 && title==s2)
 {
  return 1;
 }
 else
  return 0;
}
float Book::copies(int copy)
{
 if(stock>=copy)
 {
  cout<<"\nPrice for "<<copy<<" copies is: "<<(price*copy);
  return price*copy;
 }
 else
  {
      cout<<"\n*Not available*";
      return 0;
  }
}
class Transaction
{
private:
  static int no_of_trans;
  int id;
  int no_Books_sold;
  double total;
  string date;
public:
  Transaction() : id(++no_of_trans)
  {
      date="";
    no_Books_sold = total = 0;
  }
  void bill(int copies, double totalCost, string purchaseDate)
  {
    no_Books_sold += copies;
    total += totalCost;
    date = purchaseDate;
  }
  void display()
  {
      cout<<"Transaction ID : "<<id<<endl;
      cout<<"Date : "<<date<<endl;
      cout<<"No of copies : "<<no_Books_sold<<endl;
      cout<<"Total Amount : "<<total<<endl;
  }
};
class Sales 
{
    float incentive;
    string name;
    string id;
     float sales_amount;
public:
    Sales()
    {
        incentive=0;
        name="";
        id="";
        sales_amount=0;
    }
    void setfunc(float amount)
    {
        sales_amount=amount;
        incentive=0.05*sales_amount;

    }
    void display_sales()
    {
        cout<<"\nEnter name and id  :";
        cin>>endl>>id;
        cout<<"Name :"<<name<<endl<<"ID :"<<id<<"Sales amount : "<<sales_amount<<endl<<"Incentive :"<<incentive;
    }
};


int Transaction::no_of_trans=0;
int main()
{
 int i=0,choice=0,flag=0,data=0,c=0;
 static int no_trans=0,n=0;
 float flag2=0;
 char con;
 string author,title,date;
 Book b[50];
 Transaction z[50];
 Sales s[20];
 do
 {
     
  cout<<"\tBook Inventory";
  cout<<"\n1)Update the inventory\n2)Display\n3)Search the Book\n4)Buy the Book";
  cout<<"\nEnter your choice: ";
  cin>>choice;
  switch(choice)
  {
   case 1:
   {
      
    cout<<"\nHow many Books : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
     b[i].input();
    }
    break;
   }
   case 2:
   {
       
    cout<<"\nAuthor\tTitle\tPublisher\tPrice\tStock";
    for(i=0;i<n;i++)
    {
     b[i].display();
    }
    break;
   }
   case 3:
   {
       system("cls");
    cout<<"\nEnter the name of the author: ";
    cin>>author;
    cout<<"\nEnter the title of the Book: ";
    cin>>title;
    for(i=0;i<n;i++)
    {

     if(b[i].search(author,title))
     {
      data=i;
      flag=1;
      if(flag==1)
      {
       cout<<"\nBook is available";
      }}

    }
     if(flag==0)
     {
       cout<<"\nNo such Book in the inventory";
       break;
      }
    if(flag==1)
    {
     cout<<"\nEnter no. of copies you want: ";
     cin>>c;
     flag2=b[data].copies(c);
    }
    break;
   }
   case 4:
    {
        system("cls");
        no_trans++;

            if(flag2>0)
            {
                cout<<"Enter the date of transaction\n";
                cin>>date;
                z[no_trans].bill(c,flag2,date);
                z[no_trans].display();
            }
    }
    case 5:
    {
        cout<<"Calculate incentive : ";
        for(int i=0;i<n;i++)
        {
            s[i].display_sales();
        }

    }
  }
  cout<<"\n Press y to continue for other options and n if you do not want to continue : ";
  cin>>con;
 }
 while(con!='n');
 return 0;
}

