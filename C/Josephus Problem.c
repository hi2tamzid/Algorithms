#include <stdio.h>

long long joseph_kakku(long long n, long long k)
{

    if(n == 1)
        return 0 ;
    else
    {
        printf("%lld ", n) ;
        return ((joseph_kakku(n-1, k) + k-1) % n+1) ;
    }

}

int main()
{
    long long a = 4, b = 5 ;

    printf("\n%lld\n", joseph_kakku(a, b)) ;
    return 0 ;
}
