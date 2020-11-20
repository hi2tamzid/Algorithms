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

LL ext_gcd(LL a, LL b, LL &x, LL &y)
{
    LL q, x1 = 1,y1 = 0,x2  = 0, y2 = 1, g = 1, g1 = 1;
    x=  x1;
    y = y1;
    printf("a = %lld b = %lld q = %lld r = %lld x = %lld y = %lld\n", a,b,q,g,x,y);
    for(; g != 0 ;)
    {
        g1 = g;
        q = a / b;
        g = a % b;
        a = b;
        b = g;
        x = x1 - q*x2;
        y = y1 - q*y2;
        x1 = x2;
        y1 = y2;
        x2 = x;
        y2 = y;
    printf("a = %lld b = %lld q = %lld r = %lld x = %lld y = %lld\n", a,b,q,g,x,y);
    }
    x = x1;
    y = y1;

    return g1;
}
int main()
{
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL x, y;
    LL g = ext_gcd(-46,240,x,y);
    cout <<g << ' ' << x << " " << y << endl;
    return 0;
}


