#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout << "N:= ";
    cin >> n;
    char arr[n];
    vector <int> p_ind;
    vector <int> t_ind;
    cout << "Type P: for police & T: for thief one by one" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        if(arr[i]=='P' || arr[i]=='p')
            p_ind.push_back(i);
        else if(arr[i]=='T' || arr[i]=='t')
            t_ind.push_back(i);
        else
        {
            cout << "Last input was invalid. Try again!";
            i--;
        }
    }

    int k;
    cout << "K:= ";
    cin >> k;

    int p=0, t=0, ans=0;
    while(p<p_ind.size() && t<t_ind.size())
    {
        if(abs(p_ind[p] - t_ind[t])<=k)
        {
            p++;
            t++;
            ans++;
        }
        else if( p_ind[p]< t_ind[t])
            p++;
        else
            t++;
    }
    cout << ans << endl;
    return 0;
}


