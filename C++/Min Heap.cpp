#include <bits/stdc++.h>

using namespace std;
typedef long long int LL ;

void min_heapify (LL Arr[], LL i, LL N)
{
    LL left = 2*i;              //left child
    LL right = 2*i +1;         //right child
    LL smallest;
     if(left<= N and Arr[left] < Arr[i] )
         smallest = left;
    else
        smallest = i;
    if(right <= N and Arr[right] < Arr[smallest] )
        smallest = right;
    if(smallest != i )
    {
        swap (Arr[i] , Arr[smallest]);
        min_heapify (Arr, smallest,N);
    }
}


void build_minheap (LL Arr[ ], LL N)
{
    for(LL i = N/2 ; i >= 1 ; i-- )
    {
        min_heapify(Arr, i, N) ;
    }
}

int main()
{
    LL n;
    scanf("%lld", &n);
    LL a[n+2];
    for(LL i = 1 ; i <= n ; i++)
        scanf("%lld", &a[i]);


    build_minheap(a, n);

    printf("\n");

    for(LL i = 1 ; i <= n ; i++)
    printf("%lld ", a[i]);

}

/**
Sample Input:
7
10 8 9 7 6 5 4

Sample Output:
4 6 5 7 8 10 9
*/
