#include<iostream>
#include<string>
using namespace std;
class Salesperson;
class Sale
{
 private:
      string day;
      double amtOfSale;
      int salesPersonId;

  public:
      Sale(string date,double sale,int id)
      {
          day=date;
          amtOfSale=sale;
          salesPersonId=id;
      }
      friend void display(Sale,Salesperson);
};
class Salesperson
{  private:
      int salesPersonId;
      string lastName;
  public:
   Salesperson(int id,string name)
      {
          salesPersonId=id;
          lastName=name;
      }
      friend void display(Sale,Salesperson);

};

void display(Sale saleObj,Salesperson personObj)
{
 cout<<" \nSale no."<<saleObj.salesPersonId<<" on "<<saleObj.day<<" for Rs. "<<saleObj.amtOfSale<<"  sold by id no :"<<personObj.salesPersonId<<" "<<personObj.lastName;
}
int main()
{
 Sale sObj1("Monday",230.50,100);
  Salesperson pObj1(103,"Jersha");
Sale sObj2("Tuesday",550,101);
  Salesperson pObj2(102,"Hema");
  display(sObj1,pObj1);
  display(sObj2,pObj2);
  return 0;
}
