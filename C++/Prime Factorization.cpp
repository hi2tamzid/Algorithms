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
#define num 46342
bitset<num+1000> prime;
VLL primes, factors;

void sieve()
{
    LL n = num + 10;
    LL sqrtn = sqrt(n);
    prime.set();
    prime[0] = prime[1] = 0;
    for(LL i = 4 ; i <= n ; i += 2)
        prime[i] = 0;
    for(LL i = 3 ; i <= sqrtn ; i+= 2)
        if(prime[i])
            for(LL j = i * i ; j <= n ; j += (2 * i))
                prime[j] = 0;
    primes.push_back(2);
    for(LL i = 3 ; i <= n ; i += 2)
        if(prime[i])
            primes.push_back(i);
}
B isprime(LL n)
{
    if(n <= num)
        return prime[n];
    LL sqrtn = sqrt(n);
    for(LL i = 0 ; i < primes.size() && primes[i] <= sqrtn ; i++)
    {
        if(n% primes[i] == 0)
            return false;
    }
    return true;
}
void primefactorization(LL n)
{
    n = ABS(n);
    LL sqrtn = sqrt(n);
    for(LL i = 0 ; i < (LL)primes.size() && primes[i] <= sqrtn ; i++)
    {
        if(n <= num)
            if(isprime(n))
                break;
        if(n % primes[i] == 0)
        {
            while(n % primes[i] == 0)
            {
                factors.push_back(primes[i]);
                n /= primes[i];
            }
            sqrtn = sqrt(n);
        }
    }
    if(n != 1)
        factors.push_back(n);
}
int main()
{
    sieve();
#if test
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LL n ;
    while(cin >> n && n != 0)
    {
        factors.clear();
        primefactorization(n);
        for(LL i = 0 ; i < factors.size() ; i++)
            cout << factors[i] << endl;
    }
    return 0 ;
}
