#include <stdio.h>

int binary_search(int array[], int, int );
int  k = 0;
int main()
{
    int array[100], i, n, key, result;
    printf("Enter Number of Element: ");
    scanf("%d", &n);
    for (i = 0 ; i < n ; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the Number to Search: ");
    scanf("%d", &key);
    result = binary_search(array, n, key);
    printf("%d\n", result);
    return 0;
}

int binary_search(int array[], int size, int key)
{
    int low = 0, high = size-1, mid = 0;

    while(low <= high)
    {
        mid = (low+high)/2;

        if(key==array[mid])
            return mid;

		if(key>array[mid])
            low=mid+1;

		if(key<array[mid])
            high=mid-1;
        printf("%d bar cholse\n", ++k);
    }
    return 0;
}
