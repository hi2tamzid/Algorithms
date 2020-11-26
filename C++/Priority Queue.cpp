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

class priorityqueue
{
public:
    LL maximum(LL Arr[ ])
    {
        return Arr[ 1 ];  //as the maximum element is the root element in the max heap.
    }
    LL extract_maximum (LL Arr[ ], LL length)
    {
        if(length == 0)
        {
            cout<< "Can’t remove element as queue is empty";
            return -1;
        }
        LL max = Arr[1];
        Arr[1] = Arr[length];
        length = length -1;
        max_heapify(Arr, 1, length);
        return max;
    }
    void increase_value (LL Arr[ ], LL i, LL val)
    {
        if(val < Arr[ i ])
        {
            cout<<"New value is less than current value, can’t be inserted" <<endl;
            return;
        }
        Arr[ i ] = val;
        while( i > 1 and Arr[ i/2 ] < Arr[ i ])
        {
            swap(Arr[ i/2 ], Arr[ i ]);
            i = i/2;
        }
    }
    void insert_value (LL Arr[ ], LL val, LL length)
    {
        length = length + 1;
        Arr[ length ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
        increase_value(Arr, length, val);
    }
};

int main()
{

    return 0;
}
