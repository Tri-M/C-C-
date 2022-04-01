#ifndef ADDRESS_H_INCLUDED
#define ADDRESS_H_INCLUDED
#include<string>

class Address
{
    public:
    int houseno;
    string street;
    int aptno;
    std::string city;
    std::string state;
    int code;
    Address();
    Address(int);
    void print();
    void comes_before();

};
#endif // ADDRESS_H_INCLUDED
