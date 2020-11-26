#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;

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

void heap_sort(LL Arr[ ], LL N)
{
    LL heap_size = N;
    build_maxheap(Arr, N);
    for(LL i = N; i>=2 ; i-- )
    {
        swap(Arr[ 1 ], Arr[ i ]);
        heap_size = heap_size-1;
        max_heapify(Arr, 1, heap_size);
    }
}
int main()
{
    LL n;
    scanf("%lld", &n);
    LL a[n+2];
    for(LL i = 1 ; i <= n ; i++)
        scanf("%lld", &a[i]);

    heap_sort(a, n);

    printf("\n");

    for(LL i = 1 ; i <= n ; i++)
    printf("%lld ", a[i]);

}
/**
Sample Input
6
4 3 7 1 8 5

Sample Output
1 3 4 5 7 8
*/
