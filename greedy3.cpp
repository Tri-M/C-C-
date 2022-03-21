#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, p;
    cout << "n:= ";
    cin >> n;
    cout << "p:= ";
    cin >> p;

    int arr[p][3];
    int s[n];
    int d[n];
    int e[n];

    vector<int> a;
    vector<int> b;
    vector<int> c;


    memset(s, -1, sizeof(s));
    memset(d, -1, sizeof(d));
    memset(e, -1, sizeof(e));

    for(int i=0; i<p; i++)
    {
        for(int j=0; j<3; j++)
            cin >> arr[i][j];
    }

    for(int i=0; i<p; i++)
    {
        s[arr[i][0]-1]= arr[i][1]-1;
        d[arr[i][0]-1]= arr[i][2];
        e[arr[i][1]-1]= arr[i][0]-1;
    }

    for(int i=0; i<n; i++)
    {
        if(e[i]==-1 && s[i]!=-1)
        {
            int dia= d[i];
            int j=s[i];
            while(s[j]!=-1)
            {
                if (dia> d[j])
                    dia = d[j];
                j=s[j];
            }
            a.push_back(i+1);
            b.push_back(j+1);
            c.push_back(dia);
        }
    }


    int cou= a.size();
    cout << cou << endl;
    for(int i=0; i<cou; i++)
    {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }

    return 0;
}


