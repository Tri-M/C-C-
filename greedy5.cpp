#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout << "n:= ";
    cin >> n;
    int start[n], finish[n];
    cout << "start times:\n";
    for(int i=0; i<n; i++)
    {
        cin >> start[i];
    }
    cout << "finish times:\n";
    for(int i=0; i<n; i++)
    {
        cin >> finish[i];
    }

    vector <int> ans;

    int i=0, j=0;

    ans.push_back(i); //first activity always gets selected

    for(int i=1; i<n; i++)
    {

        if(start[i]>= finish[j])
        {
            ans.push_back(i);
            j=i;
        }
    }

    cout << "\n{";
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    cout << "\b\b}" << endl;
    return 0;
}
