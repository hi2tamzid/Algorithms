#include <bits/stdc++.h>
using namespace std ;
typedef long long int LL;
LL ext_gcd ( LL A, LL B, LL &X, LL &Y )
{
    LL x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2; Y = y2;
    return r2;
}
int main()
{
    LL a , b, x, y, g ;
    while(cin >> a >> b){
    g = ext_gcd(a, b, x, y) ;
    cout << a << " " << b << " " << x << " " << y << endl ;
    cout << a * x + b * y << " = " << g << endl ;
    }
    return 0 ;
}
