#include <bits/stdc++.h>

using namespace std;

int lis(int a[], int n)
{
    int ans[n], res = INT_MIN;
    memset(ans,0,sizeof(ans));
    ans[0] = 1;
    for(int i = 1  ; i < n ; i++)
    {
        ans[i] = 1;
        for(int j = 0 ; j < i ; j++)
        {
            if(a[i] > a[j] && ans[i] < ans[j]+1)
                ans[i] = ans[j]+1;
        }
        res = max(ans[i], res);
    }
    return res;

}
int main()
{
    int n;
    while(cin >> n)
    {
        int a[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i];
        }
        int result = lis(a, n);
        cout << result << endl;
    }
    return 0;
}
