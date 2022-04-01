#include<iostream>

using namespace std;

//declare class (will be define later)

class Salesperson;

//class Sale

class Sale

{

  //private members of class

  private:

      string day;

      double amtOfSale;

      int salesPersonId;

 //public methods

  public:

      //constructor that takes day,amount of sale and salesPersonId as parameters

      Sale(string date,double sale,int id)

      {

          //set the private members to the initial values passed

          day=date;

          amtOfSale=sale;

          salesPersonId=id;

      }

      //declare a friend function that takes objects of the two classes as parameters

      friend void display(Sale,Salesperson);

};

//define class Salesperson

class Salesperson

{

  //private members of the class

  private:

      int salesPersonId;

      string lastName;

  //public methods

  public:

      //constructor that takes name and id as parameters

      Salesperson(int id,string name)

      {

          //set the members of the class with the parameters passed

          salesPersonId=id;

          lastName=name;

      }

      //declare a friend function that takes objects of the two classes as parameters

      friend void display(Sale,Salesperson);

};

//define the friend funtion

void display(Sale saleObj,Salesperson personObj)

{

  //display the sales info using the objects of the two classes

  cout<<"\nSale #"<<saleObj.salesPersonId<<" on "<<saleObj.day<<" for $"<<saleObj.amtOfSale<<" sold by #"<<personObj.salesPersonId<<" "<<personObj.lastName;

}

int main()

{

  //create object for Sale class and pass default values

  Sale sObj1("12/25/2016",559.95,103);

  //create object for Salesperson class and pass default values

  Salesperson pObj1(103,"Woods");



  //create another object for Sale class and pass default values

  Sale sObj2("11/15/2016",359.95,106);

  //create another object for Salesperson class and pass default values

  Salesperson pObj2(106,"Hansen");

  //using the friend function dislay the sales info

  display(sObj1,pObj1);

  display(sObj2,pObj2);

  return 0;

}
