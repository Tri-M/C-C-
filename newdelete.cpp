#include <iostream>
using namespace std;
int main ()
 {
   int *ptr1 = new int ;
   float *ptr2 = new float(4.5);
   int *ptr3 = new int[30];
   *ptr1 = 10;
   cout << "Value of *ptr1: " << *ptr1 << endl;
   cout << "Value of *ptr2 : " << *ptr2 << endl;
   if (!ptr3)
   cout << "Allocation of memory failed\n";
   else
   {
      for (int i = 10; i < 15; i++)
      ptr3[i] = i+2;
      cout << "Value in memory : ";
      for (int i = 10; i < 15; i++)
      cout << ptr3[i] << " ";
   }

}
