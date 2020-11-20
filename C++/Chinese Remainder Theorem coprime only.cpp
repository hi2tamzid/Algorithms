#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <cctype>
#include <climits>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <exception>
#include <fstream>
#include <algorithm>
#include <ios>
#include <bitset>
#include <sstream>
#include <set>
#include <list>

#define test 0
#define pi acos(-1.0)
#define eps 1e-8
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
using namespace std ;

typedef int I ;
typedef short int SI ;
typedef long L ;
typedef long long LL ;
typedef unsigned long long ULL ;
typedef float F ;
typedef double D ;
typedef long double LD ;
typedef char C ;
typedef bool B ;
typedef string S ;
typedef vector<I> VI ;
typedef vector<I>::iterator VIT ;
typedef vector<L> VL ;
typedef vector<L>::iterator VLT ;
typedef vector<LL> VLL ;
typedef vector<LL>::iterator VLLT ;
typedef vector<C> VC ;
typedef vector<C>::iterator VCT ;
template<typename a>
void SWAP(a &b, a &c)
{
    a d = b ;
    b = c ;
    c = d ;
}

LL power(LL a, LL b)
{
   LL result = 1 ;
   while(b)
   {
       if(b&1)
        result = a * result ;
       a *= a ;
       b >>= 1 ;
   }
   return result ;
}
LL gcd(LL a, LL b)
{
    while(b)
    {
        a = a % b;
        SWAP(a,b);
    }
    return a;

}

LL lcm(LL a, LL b)
{
    return (a * (b / gcd(a,b)));
}
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
pair<LL, LL> chinese_remainder_theorem(LL A[], LL M[], LL a, LL m)
{
    if(a != m)
    return {-1,-1};

    LL n = a;
    LL a1 = A[0], m1 = M[0];
    for(LL i = 1 ; i < n ; i++)
    {
        LL a2 = A[i],m2 = M[i];

        LL p, q;
        LL g = ext_gcd(m1, m2, p, q);
        LL x = (a1 * m2 * q + a2 * m1 * p) % (m1 * m2);

        a1 = x;
        m1 = m1 * m2;
    }
    if(a1 < 0 )
        a1 += m1;
    return {a1,m1};
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL a,x;
    scanf("%lld %lld", &a, &x);
    LL a1[a],x1[x];
    for(LL i = 0 ; i < a; i++)
        scanf("%lld", &a1[i]);
    for(LL i = 0 ; i < x ; i++)
    {
        scanf("%lld", &x1[i]);
    }
    pair<LL, LL> result = chinese_remainder_theorem(a1,x1, a, x);
    printf("adfasdf\n");
    cout << result.first << " " << result.second << endl;
    return 0;
}


