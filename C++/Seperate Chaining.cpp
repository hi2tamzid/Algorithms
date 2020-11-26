#include <bits/stdc++.h>

using namespace std;
typedef long long int LL ;
vector<string> hashTable[20];
LL  hashTableSize = 20;

LL hashFunc(string s)
{
    LL len = s.length()-1;
    len = (LL)s[len] % 20;
    return len;
}

void insert(string s)
{
    LL index = hashFunc(s);
    hashTable[index].push_back(s);

}

void search(string s)
{
    LL index = hashFunc(s);
    for(LL i = 0 ; i < hashTable[index].size() ; i++)
    {
        if(hashTable[index][i] == s)
        {
            cout << s << " is found!" << endl;
            return ;
        }

    }
    cout << s << " is found!" << endl;
}
int main()
{
    LL n;
    cin >> n;
    string s;
    printf("Input:\n");
    for(LL i = 0 ; i < n ; i++)
    {
        cin >> s;
        insert(s);

    }
    printf("Search Item:");
    cin >> s;
    search(s);
    return 0;
}

