#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define md 720720
const int N=1E5+5;
int a[N];
ll dp[N][30+5];
 
 
int main(){
	cin.tie(NULL);
    int n;
    cin >> n;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i][0] = 1;
    }
    int k;
    cin >> k;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= k; j ++) {
            if(j == 1 && a[i] == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i - 1][j - 1]) % md;
        }
    }
    cout << (k == 1 ? n : dp[n][k]);
    return 0;
}
