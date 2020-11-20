#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

void insertion_sort(LL a[], LL n)
{
    LL i, j, item ;
    for(i = 1 ; i < n ; i++)
    {
        item = a[i] ;
        j = i - 1 ;

        while(j >= 0 && a[j] > item)
        {
            a[j+1] = a[j] ;
            j = j - 1 ;
        }

        a[j+1] = item ;
    }
}
int main()
{
    LL a[10] = {1,5,4,3,2,8,7,6,9,10} ;
    insertion_sort(a, 10) ;
    for(int i = 0 ; i < 10 ; i++)
        printf("%lld\n", a[i]) ;
    return 0 ;
}
