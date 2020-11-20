#include <iostream>
#include <cmath>

using namespace std ;
int factorialDigit ( int n ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i );
    }
    int res = ( (int) x ) + 1;
    return res;
}

int main()
{
    long long n ;
    long long result ;
    double x ;
    while(cin >> n)
    {
        cout << factorialDigit(n) << endl ;
        x = 0 ;
        for(int i = 1 ; i <= n ; i++)
        {
            x += log10(i) /** /log10(base) */;
            cout << x << endl ;
        }

        result  = ((int)x) + 1 ;
        cout << result << endl ;
    }
    return 0 ;
}

