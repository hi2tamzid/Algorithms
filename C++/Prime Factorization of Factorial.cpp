#include <bits/stdc++.h>

using namespace std ;
vector<int> prime ;
int primefactor[1000100] ;
int primes[1000100] ;
void siv()
{
    memset(primes, 0, sizeof(primes)) ;
    long long n = 1000000 ;
    long long sqrt_n = sqrt(n) ;
    primes[1] = 1 ;
    prime.push_back(2) ;
    for(long long i = 4 ; i <= n ; i += 2)
    {
        primes[i] = 1 ;
    }

    for(long long i = 3 ; i <= sqrt_n ; i += 2)
    {
        if(primes[i] == 0)
        {
            for(long long j = i * i ; j <= n ; j += (2 * i))
            {
                primes[j] = 1 ;
            }
        }
    }

    for(long long i = 3 ; i <= n ; i++)
    {
        if(primes[i] == 0)
            prime.push_back(i) ;
    }
}

void factfactorize(long long n)
{
    long long k = 0 ;
    for(long long i = 0 ; i < prime.size() && prime[i] <= n ; i++)
    {
        if(k != 0)
        cout << ", " ;
        k++ ;
        long long fre = 0, copy_n = n ;
        while(n/prime[i])
        {
            fre += (n / prime[i]) ;
            n /= prime[i] ;
        }
        cout << prime[i] << "^" << fre ;
        n = copy_n ;
    }
}
int main()
{
    siv() ;
    factfactorize(5) ;
    return 0 ;
}
