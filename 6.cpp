#include <iostream>
using std::istream;
using std::ostream;
using namespace std;

class Complex
{

        friend istream & operator>>(istream &, Complex &); //overloading input stream operator
        friend ostream & operator<<(ostream &, const Complex &); //overloading output stream operator

public:

Complex();  //default constructor
Complex(double, double); //constructor

             ~Complex();//destructor

                Complex add(const Complex &) const;

                Complex operator+(const Complex &) const ;

                Complex operator+(double) const;
                void operator+=(Complex &);
               Complex subtract(const Complex &) const;
                Complex operator-(const Complex &) const;

                //copy a complex number
                void copy(const Complex &);
                void operator=(const Complex &);
                void operator=(const double);

                //compare two complex numbers
                bool operator==(Complex &) const;

void print();    //print complex number format

double getReal() const;//getters
double getImaginary() const;


void setReal(double);  //setters
void setImaginary(double);

private:

double real;
double imaginary;

};  //end of class


Complex operator+(double realNumber, Complex & right) ;
Complex::Complex()
{
     setReal(0);
     setImaginary(0);
}

/**
 * Creates a new Complex with user-specified values.
 */
Complex::Complex(double real, double imaginary)
{
setReal(real);
setImaginary (imaginary);
}

/**
 * Default destructor of Complex.
 */
Complex::~Complex()
{
}

/**
 * Return the value of the real portion of the complex number.
 */
double Complex::getReal() const
{
return real;
}

/**
 * Return the value of the imaginary portion of the complex number.
 */
double Complex::getImaginary() const
{
return imaginary;
}

/**
 * Set the value of the real portion to a new value.
 */
void Complex::setReal(double real)
{
this->real = real;
}

/**
 * Set the value of the imaginary portion to a new value.
 */
void Complex::setImaginary(double imaginary)
{
this->imaginary = imaginary;
}

/**
 * Adds two Complex numbers together and returns the sum.
 */
Complex Complex::add(const Complex & right) const
{
      Complex sum(getReal() + right.getReal(),
 getImaginary() + right.getImaginary());

return sum;
}

/**
 * Adds two Complex numbers together and returns the sum.
 */
Complex Complex::operator+(const Complex & right) const
{
     cout<<"Complex::operator+(const Complex & right) const is called"<<endl;
      Complex sum(getReal() + right.getReal(),
 getImaginary() + right.getImaginary());

return sum;
}


/**
 * Adds a real number and a Complex numbers together and returns the sum.
 */
Complex Complex::operator+(double realNumber) const
{
     cout<<"Complex::operator+(double realNumber) const is called"<<endl;

      Complex sum(getReal() + realNumber, getImaginary());

return sum;
}


/**
 * The global function performs complexObject3 = realNumber + complexObject1
 */
Complex operator+(double realNumber, Complex & right)
{

     cout<<"operator+(double realNumber, const Complex & right) is called"<<endl;
     Complex sum(realNumber+right.getReal(), right.getImaginary());

     return sum;
}


/**
 * The overloading +=
 */
void Complex::operator+=(Complex & right)
{

    cout<<"Complex::operator+=(const Complex & right) is called"<<endl;
     setReal(getReal( )+right.getReal());
     setImaginary(getImaginary()+right.getImaginary());
}


/**
 * Subtracts two Complex numbers together and returns the result.
 */
Complex Complex::subtract(const Complex & right) const
{
return Complex (getReal() - right.getReal(),
getImaginary() - right.getImaginary());

}

/**
 * Subtracts two Complex numbers together and returns the result.
 */
Complex Complex::operator-(const Complex & right) const
{
        cout<<"Complex::operator-(const Complex & right) const is called"<<endl;

return Complex (getReal() - right.getReal(),
getImaginary() - right.getImaginary());

}

/**
 * copy a complex number.
 */
void Complex::copy(const Complex & right)
{
     setReal(right.getReal());
     setImaginary(right.getImaginary());
}

/**
 * copy a complex number.
 */
void Complex::operator=(const Complex & right)
{
   cout<<"Complex::operator=(const Complex & right) is called"<<endl;
    setReal(right.getReal());
    setImaginary(right.getImaginary());
}



void Complex::operator=(const double h)
{
   setReal(h);
   setImaginary(0);
}

/**
 * Compare two complex numbers
 */
bool Complex::operator== (Complex & right) const
{

   cout<<"Complex::operator==(const Complex & right) const is called"<<endl;

    if (getReal() == right.getReal()  &&
        getImaginary() == right.getImaginary())
        return true;
    else
        return false;
}

/**
 * Prints the complex number in the form (real, imaginary)
 */
void Complex::print()
{
cout << "(" << getReal() << ", " << getImaginary() << ")" << endl;
}
istream& operator>>(istream & input, Complex & cNumber)
{
   double real, imaginary;

   input.ignore(256, '('); //ignor (

   input>>real;  //read real part

   input.ignore(256,','); //white spaces up to next "," are ignored.

   input>>imaginary;  //read imaginary part

   input.ignore(256,')');  //ignore white spaces after it.

   if (input.good())
   {
       cNumber.real = real;
       cNumber.imaginary = imaginary;
   }

   return input;  // enable cin >> c1 >> c2 >> c3
}

/**
 * Overloading input stream operator
 * Complex class could perform I/O like built-in type.
 * The format is "(real, imaginary)"
 */
ostream& operator<<(ostream & output, const Complex & cNumber)
{
    output<<"(" <<cNumber.real<<", "<<cNumber.imaginary<<")";

    return output;  //enable cout << c1 << c2 << c3
}
int main()
{
Complex a( 1, 7), b(0, 2), c;

a.print();
cout << " + ";
b.print();
cout << " = ";
cout<<a.add( b );
c.print();

}
