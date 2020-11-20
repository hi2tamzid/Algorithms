#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL Z, I, M, L;
LL f(LL L)
{
    return ((Z*L+I)%M);
}

pair<LL, LL> floydcycleFinding(LL x0)
{
    LL tortoise = f(x0), hare = f(f(x0));
    while(tortoise != hare)
    {
        tortoise = f(tortoise);
        hare = f(f(hare));

    }
    LL mu = 0;
    hare = x0;
    while(tortoise != hare)
    {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    LL lambda = 1;
    hare = f(tortoise);
    while(tortoise != hare){
        hare = f(hare);
        lambda++;
    }
    return {mu, lambda};
}
int main()
{
    LL cas = 1;
    while(scanf("%lld %lld %lld %lld", &Z, &I, &M, &L) && (Z != 0 || I != 0 || M != 0 || L != 0))
    {
        pair<LL, LL> result = floydcycleFinding(L);
        printf("Case %lld: %lld\n", cas++, result.second);
    }
}
