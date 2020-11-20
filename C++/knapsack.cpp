#include <bits/stdc++.h>

using namespace std ;
int dp[199][199], cost[5] = {10,8,15,30,11}, weight[5] = {1,2,2,3,1}, n = 5;

int f(int m, int i)
{
    if(i == n || m == 0)
        return 0 ;
    if(dp[m][i] == -1)
    {
        int r = f(m, i + 1);
        if(weight[i] <= m)
            r = max(r, cost[i]+f(m - weight[i], i+1));
        dp[m][i] = r;
    }
    return dp[m][i];
}
int main()
{
    memset(dp, -1, sizeof dp);
    f(5, 0);
    for(int i = 0 ; i < 6 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

