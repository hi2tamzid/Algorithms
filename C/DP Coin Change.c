#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define pi acos(-1.0)
typedef long long LL ;

int main()
{
    LL n, coin[5] = {1,1,1,1}, i, j, k;
    LL previous[10011], result[10011] ;
        for(i = 0 ; i <= 10010 ; i++)
            previous[i] = 1 ;
        result[0] = 1 ;

        for(i = 1 ; i < 4 ; i++)
        {
            for(j = 1 ; j <= 10010 ; j++)
            {
                if(j >= coin[i])
                {
                    result[j] = result[j - coin[i]] + previous[j] ;
                }
                else
                    result[j] = previous[j] ;
            }

            for(k = 1 ; k < j ; k++)
                previous[k] = result[k] ;
        }

    while(scanf("%lld", &n) != EOF)
    {
        printf("%lld\n", previous[n]) ;
    }
    return 0;
}
