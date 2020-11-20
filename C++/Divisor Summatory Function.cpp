#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int n = 10, res = 0, sqrtn ;
    sqrtn = sqrt(n) ;
    printf("sqr = %d\n", sqrtn) ;
    for(int i = 1 ; i <= sqrtn ; i++)
    {
        res += (n / i) ;
        if(n/i != i)
            res += i ;
        cout << res << endl ;
    }
//    res *= 2 ;
//    res += sqrtn ;
    cout << res << endl ;
    return 0 ;
}
