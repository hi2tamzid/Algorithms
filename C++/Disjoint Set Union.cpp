#include <bits/stdc++.h>

using namespace std;
typedef long long int LL ;
typedef vector<LL> VLL;
class union_find
{
private:
    VLL p, rank, setSize;
    LL numSets;
public:
    union_find(LL val)
    {
        p.assign(val, 0);
        rank.assign(val, 0);
        setSize.assign(val, 1);
        numSets = val;
        for(LL i = 0 ; i < val ; i++)
            p[i] = i;
    }

    LL findSet(LL i)
    {
        if(p[i] == i)
            return i;
        else
        {
            p[i] = findSet(p[i]);
            return p[i];
        }
    }
    bool isSameSet(LL i, LL j)
    {
        return (findSet(i) == findSet(j));
    }
    void unionSet(LL i, LL j)
    {
        if(!isSameSet(i, j))
        {
            numSets--;
            LL x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    LL numOfDisjointSets()
    {
        return numSets;
    }
    LL sizeOfSet(LL i)
    {
        return (setSize[findSet(i)]);
    }
    LL rankOfSet(LL i)
    {
        return (rank[findSet(i)]);
    }
};
int main()
{
    LL noOfVertices, noOfEdges;
    scanf("%lld %lld", &noOfVertices, &noOfEdges);
    union_find mp(noOfVertices);

    LL a, b;
    for(LL i = 0 ; i < noOfEdges ; i++)
    {
        scanf("%lld %lld", &a, &b);
        mp.unionSet(a, b);
    }

    for(LL i = 0 ; i < noOfVertices ; i++)
    {
        printf("%lld -> %lld\n", i, mp.rankOfSet(i));
    }
    return 0;
}

/**
Sample Input:
8 7
0 1
2 3
4 5
6 7
0 2
3 5
4 7


*/
