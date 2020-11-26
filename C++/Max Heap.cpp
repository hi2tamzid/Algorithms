#include <bits/stdc++.h>

using namespace std;
typedef long long int LL ;

void max_heapify (LL Arr[ ], LL i, LL N)
{
    LL left = 2*i;              //left child
    LL right = 2*i +1;         //right child
    LL largest;
     if(left<= N and Arr[left] > Arr[i] )
         largest = left;
    else
        largest = i;
    if(right <= N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    }
}


void build_maxheap (LL Arr[ ], LL N)
{
    for(LL i = N/2 ; i >= 1 ; i-- )
    {
        max_heapify(Arr, i, N) ;
    }
}

int main()
{
    LL n;
    scanf("%lld", &n);
    LL a[n+2];
    for(LL i = 1 ; i <= n ; i++)
        scanf("%lld", &a[i]);

    build_maxheap(a, n);

    printf("\n");

    for(LL i = 1 ; i <= n ; i++)
    printf("%lld ", a[i]);

}

/**
Sample Input:
7
1 4 3 7 8 9 10

Sample Output:

*/
