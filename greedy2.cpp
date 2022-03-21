#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;

    int mat[N][M];

    //getting input for matrix
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> mat[i][j];
        }
    }

    int ans=1;

    vector <int> ind;

    for(int j=0; j<M; j++)
    {
        if(ind.size()==0)
        {
            for(int i=0; i<N; i++)
            {
                if(mat[i][j]==1)
                    ind.push_back(i);
            }
        }
        else
        {
            vector <int> cpy=ind;
            ind.clear();

            for(int i=0; i<cpy.size(); i++)
            {
                if(mat[cpy[i]][j]==1)
                {
                    ind.push_back(cpy[i]);
                }
            }
            if(ind.size()==0)
                ind = cpy;
        }

        if(ind.size()==1)     // found max row index
            break;
    }
    if(ind.size())
        ans= ind[0]+1;

    cout << ans;
    return 0;
}

