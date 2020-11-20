#include <stdio.h>
#include <string.h>
#include <math.h>

int status[200000];
int ranking[200000];
void siv()
{
	int N = 170000, i, j;
	int sq=sqrt(N);

	for(i=4;i<=N;i+=2) status[i]=1;
	for(i = 3 ; i <= sq ; i += 2)
    {
		if(status[i] == 0)
		{
			for(j = i*i ; j <=N ; j += 2 * i)
                status[j]=1;
		}
	}
	status[1]=1;

    for (i = 2, j = 1 ; i < 165000 ;i++)
    {
        if(status[i] == 0)
            ranking[j++] = i;
    }
}

int main()
{

    return 0 ;
}
