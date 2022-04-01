#include<iostream>
using namespace std;
#include <stdlib.h>

class BankAccount
{
friend ostream& operator<<(ostream&, BankAccount);
friend istream& operator>>(istream&, BankAccount&);
private:
int acctNum;
double balance;
double annualRate;
public:
BankAccount(int, double = 0.0, double = 0.0);
BankAccount();
void enterAccountData();

void computeInterest(int);
void displayAccount();
void displayaccount();
BankAccount operator+=(double);
BankAccount operator-=(double);
BankAccount operator+(const BankAccount&);
bool operator<(BankAccount);
bool operator>(BankAccount);
bool operator==(BankAccount);
};

BankAccount::BankAccount(int acct, double bal, double rate)
{
acctNum=acct;
balance=bal;
annualRate=rate;
}
BankAccount::BankAccount()
{

}

void BankAccount::enterAccountData()
{

}

void BankAccount::computeInterest(int years)
{

}

void BankAccount::displayAccount()
{

}


BankAccount BankAccount::operator+=(double deposit)
{

cout << "How much would you like to deposit?" << endl;
cin >> deposit;
balance = balance + deposit;
return balance;
}

BankAccount BankAccount::operator-=(double withdrawal)
{

cout << "How much would you like to withdrawal?" << endl;
cin >> withdrawal;
balance = balance - withdrawal;
return balance;
}

BankAccount BankAccount::operator+(const BankAccount &acct)
{
BankAccount sum(9999, 0);
sum.balance = BankAccount::balance + acct.balance;
return sum;
}

bool BankAccount::operator>(BankAccount account)
{
float yourAccount;
if (account > yourAccount)
cout << "My account has more than your account" << endl;
}
bool BankAccount::operator<(BankAccount account)
{
float yourAccount;
if (account < yourAccount)
cout << "Your account has more than mine" << endl;
}
bool BankAccount::operator==(BankAccount account)
{
float yourAccount;
if (account == yourAccount)
cout << "Our accounrds have the same amount" << endl;
}

ostream& operator<<(ostream& out, BankAccount account)
{

}
istream& operator>>(istream& in, BankAccount& account)
{

}


int main()
{
BankAccount myAccount, yourAccount (1111, 100, 0.12);
double increment = 4.50; int val = 2;


cout << myAccount <<endl;
cout <<yourAccount<<endl;

cin >> myAccount;


myAccount += increment;
cout <<myAccount;
myAccount -= increment;
cout <<myAccount;


BankAccount temp;
temp = myAccount + yourAccount;
cout <<temp;


cout <<(myAccount<yourAccount);


cout <<(myAccount>yourAccount);


cout <<(myAccount==yourAccount);
system ("PAUSE");
return 0;
}
