#include <bits/stdc++.h>

using namespace std;

vector<int> lis(int a[], int n)
{
    vector<vector<int>> li(n);
    li[0].push_back(a[0]);
    for(int i = 1  ; i < n ; i++)
    {
//        cout << "i = " << i << ":" << endl;
        for(int j = 0 ; j < i ; j++)
        {
            if(a[i] > a[j] && li[i].size() < li[j].size() + 1)
                li[i] = li[j];

        }
        li[i].push_back(a[i]);
        for(auto k : li[i])
            cout << k << " ";
        cout << endl;
    }
    vector<int> res = li[0];
    for(auto i : li)
        if(i.size() > res.size())
        res = i;
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
        vector<int> res = lis(a,n);
        for(auto i : res)
            cout << i << " ";
    }
    return 0;
}
