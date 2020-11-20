#include <bits/stdc++.h>
#define ABS(x) (((x) > 0) ? (x) : (-(x)))
using namespace std ;
short int prime[1000010] ;
long long prime_base[100010] ;
vector<int> primes;

void sieve() ;
long long segmented_sieve(long long , long long ) ;

int main()
{

    sieve() ;
    long long a, b ;

    while(cin >> a >> b)
    {
        long long result = segmented_sieve(a, b) ;
        cout << result << endl ;
    }
    return 0 ;
}

void sieve()
{
    memset(prime, 0, sizeof prime) ;
    long long n = 1000000 ;
    long long sqrt_n = sqrt(n) ;
    prime[0] = prime[1] = 1 ;
    for(int i = 4 ; i <= n ; i += 2)
        prime[i] = 1 ;
    for(int i = 3 ; i <= sqrt_n ; i += 2)
    {
        if(prime[i] == 0)
        {
            for(int j = i * i ; j <= n ; j += 2 * i)
                prime[j] = 1 ;
        }
    }
    primes.push_back(2) ;
    prime_base[0] = 2 ;
        for(int i = 3, j = 1 ; i <= n ; i += 2)
            if(prime[i] == 0)
            {
                primes.push_back(i) ;
                prime_base[j++] = i ;
            }
}


long long segmented_sieve(long long a, long long b)
{
    long long n = 1000000000000 ;
    if(a == 1)
        ++a ;
    long long sqrt_n = sqrt(b) ;
    long long dif = ABS(a - b) + 1 ;
    long long arr[dif] ;
    memset(arr, 0, sizeof arr) ;
    for(int i = 0 ; i < primes.size() && prime_base[i] <= sqrt_n ; i++)
    {
        long long p = prime_base[i] ;
        long long j = p * p ;

        if(j < a)
            j = ((a + p - 1) / p ) * p ;

        for( ; j <= b ; j += p)
        {
            arr[j - a] = 1 ;
        }
    }

    long long result = 0 ;
    for(long long i = a ; i <= b ; i++)
    {
        if(arr[i - a] == 0)
            result++ ;
    }
    return result ;
}
