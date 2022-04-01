#include <iostream>



using namespace std;



class fractionType

{

  friend ostream& operator << (ostream&, const fractionType&);

  friend istream& operator >> (istream&, fractionType&);



public:

  const fractionType& operator=(const fractionType&);



  fractionType();

  fractionType(const fractionType&);

  fractionType(const int&, const int&);



  ~fractionType();



  bool operator==(const fractionType&) const;

  bool operator!=(const fractionType&) const;

  bool operator<=(const fractionType&) const;

  bool operator< (const fractionType&) const;

  bool operator>=(const fractionType&) const;

  bool operator> (const fractionType&) const;



 fractionType operator + (const fractionType&) const;

 fractionType operator - (const fractionType&) const;

 fractionType operator * (const fractionType&) const;

 fractionType operator / (const fractionType&) const;




  int a;

  int b;

};

fractionType::fractionType(const int& nu, const int& de)

{

  a = nu;



  if (de == 0)

  {

    cout << "ntInvalid denominator. "

    << "Default value considered for denominator. ";

    b = 1;

  }

  else

    b = de;

}



fractionType::fractionType()

{

  a = 0;

  b = 1;

}



fractionType::fractionType(const fractionType& rightFraction)

{

  a = rightFraction.a;

  b = rightFraction.b;

}



fractionType::~fractionType()

{



}



bool fractionType::operator==(const fractionType& rightFraction) const

{

  return ((a == rightFraction.a) && (b == rightFraction.b));

}



bool fractionType::operator != (const fractionType& rightFraction) const

{

  return ((a != rightFraction.a) || (b != rightFraction.b));

}



bool fractionType::operator<(const fractionType& rightFraction) const

{

  return (a * rightFraction.b < b * rightFraction.a);

}



bool fractionType::operator<=(const fractionType& rightFraction) const

{

  return (a * rightFraction.b <= b * rightFraction.a);

}



bool fractionType::operator>(const fractionType& rightFraction) const

{

  return (a * rightFraction.b > b * rightFraction.a);

}



bool fractionType::operator>=(const fractionType& rightFraction) const

{

  return (a * rightFraction.b >= b * rightFraction.a);

}



fractionType fractionType::operator + (const fractionType & rightFraction) const

{

  fractionType temp;

  temp.a = (a * rightFraction.b) + (b * rightFraction.a);

  temp.b = b * rightFraction.b;

  return temp;

}



fractionType fractionType::operator - (const fractionType & rightFraction) const

{

  fractionType temp;

  temp.a = (a * rightFraction.b) - (b * rightFraction.a);

  temp.b = b * rightFraction.b;

  return temp;

}



fractionType fractionType::operator*(const fractionType& rightFraction) const

{

  fractionType temp;

  temp.a = a * rightFraction.a;

  temp.b = b * rightFraction.b;

  return temp;

}



fractionType fractionType::operator/(const fractionType& rightFraction) const

{

  fractionType temp;

  if ((rightFraction.a == 0) || (rightFraction.b == 0))

  {

    temp.a = 0;

    temp.b = 1;

    cout << "ntInvalid to perform division. ";

  }

  else

  {

    temp.a = a * rightFraction.b;

    temp.b = b * rightFraction.b;

  }

  return temp;

}



ostream& operator<<(ostream& osObject, const fractionType& myFraction)

{

  osObject << myFraction.a << "/" << myFraction.b;

  return osObject;

}



istream& operator>>(istream &isObject, fractionType& myFraction)

{

  char ch;

  isObject >> myFraction.a >> ch >> myFraction.b;

  return isObject;

}

int main ()

{

  cout << "A program to check the functionality"

  << "\nof the class fractionType. \n";



  fractionType myFraction1;

  fractionType myFraction2;



  cout << "\nEnter a fraction in the form of a/b: ";

  cin >> myFraction1;



  cout << "\nEnter another fraction in the form a/b: ";

  cin >> myFraction2;



  cout << "\n" << myFraction1 << " + " << myFraction2 <<" = " << myFraction1 + myFraction2;

  cout << "\n" << myFraction1 << " - " << myFraction2 <<" = " << myFraction1 - myFraction2;

  cout << "\n" << myFraction1 << " * " << myFraction2 <<" = " << myFraction1 * myFraction2;

  cout << "\n" << myFraction1 << " / " << myFraction2 <<" = " << myFraction1 / myFraction2;



  cout << "\n" << myFraction1 << " == " << myFraction2;

  if (myFraction1 == myFraction2)

  {

    cout << " is true.";

  }

  else

    cout << " is false.";



  cout << "\n" << myFraction1 << " != " << myFraction2;

  if (myFraction1 != myFraction2)

  {

    cout << " is true. ";

  }

  else

  {

    cout << " is false. ";

  }



  cout << "\n" << myFraction1 << " < " << myFraction2;

  if (myFraction1 < myFraction2)

  {

    cout << " is true. ";

  }

  else

  {

    cout << " is false. ";

  }



  cout << "\n" << myFraction1 << " <= " << myFraction2;

  if (myFraction1 <= myFraction2)

  {

    cout << " is true. ";

  }

  else

  {

    cout << " is false. ";

  }



  cout << "\n" << myFraction1 << " > " << myFraction2;

  if (myFraction1 > myFraction2)

  {

    cout << " is true. ";

  }

  else

  {

    cout << " is false. ";

  }



  cout << "\n" << myFraction1 << " >= " << myFraction2;

  if (myFraction1 != myFraction2)

  {

    cout << " is true. ";

  }

  else

  {

    cout << " is false. ";

  }



  cout << "\n";

  return 0;



}
