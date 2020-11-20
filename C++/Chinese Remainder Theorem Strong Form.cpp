#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
template<typename a>
void SWAP(a &b, a &c)
{
    a d = b ;
    b = c ;
    c = d ;
}
LL gcd(LL a, LL b)
{
    while(b)
    {
        a = a % b;
        SWAP(a,b);
    }
    return a;

}

LL lcm(LL a, LL b)
{
    return (a * (b / gcd(a,b)));
}
LL ext_gcd ( LL A, LL B, LL &X, LL &Y )
{
    LL x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2; Y = y2;
    return r2;
}
pair<LL, LL> chinese_remainder_theorem(LL A[], LL M[], LL Asize, LL Msize)
{
    if(Asize != Msize)
    return {-1,-1};

    LL n = Asize;

    LL a1 = A[0], m1 = M[0];

    for(LL i = 1 ; i < n ; i++)
    {
        LL a2 = A[i], m2 = M[i];

        LL g = gcd(m1,m2);
        if(a1 % g != a2 % g)
        return {-1,-1};

        LL p, q;
        g = ext_gcd(m1/g,m2/g,p,q);

        LL mod = lcm(m1,m2);

        LL x = ((__int128)a1 * (m2/g) * q + (__int128)a2 * (m1/g) * p) % mod;

        a1 = x;
        if(a1 < 0)
            a1 += mod;
        m1 = mod;
    }
    return {a1, m1};
}
int main()
{
    LL t, cas = 1;
    scanf("%lld", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        LL p[n], r[n];
        for(LL i = 0 ; i < n; i++)
        {
            scanf("%lld %lld", &p[i], &r[i]);
        }

        pair<LL, LL> result = chinese_remainder_theorem(r, p, n, n);
        if(result.first == -1 || result.second == -1)
            printf("Case %lld: Impossible\n", cas);
        else
            printf("Case %lld: %lld\n", cas, result.first);
            cas++;
    }
    return 0;

}
