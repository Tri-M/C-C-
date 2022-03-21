#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, p;
    cout << "n:= ";
    cin >> n;
    p = n-2;
    while(__gcd(n, p)!=1)
        p--;

    cout << p << endl;
    return 0;
}
