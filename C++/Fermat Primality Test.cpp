/// Complexity : O(k Log n)

#include <iostream>
#include <cstdlib>

using namespace std ;

long long power(long long a, long long b, long long p)
{
    long long result = 1 ;
    a = a % p ;

    while(b > 0)
    {
        if(b % 2 == 1)
            result = (a * result ) % p ;

        b /= 2 ;
        a = (a * a) % p ;
    }

    return result ;
}

bool isprime(long long n, long long k)
{
    if(n <= 1 || n == 4)
        return false ;

    if(n == 3 || n == 2)
        return true ;

    while(k > 0)
    {
        long long a = 2 + rand() % (n - 4 ) ;

        if(power(a, n - 1, n) != 1)
        {
            return false ;
        }
        k-- ;
    }

    return true ;
}
int main()
{
    long long k = 50, n ;
    while(cin >> n)
    {
        if(isprime(n, k))
            cout << "prime number" << endl ;
        else
            cout << "composite number" << endl ;
    }
    return 0 ;
}
