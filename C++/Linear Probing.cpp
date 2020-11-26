#include <bits/stdc++.h>

using namespace std;
typedef long long int LL ;

string hashTable[21];
LL hashTableSize = 3;

LL hashFunc(string s)
{
    LL len = s.length()-1;
    len = (LL)s[len] % hashTableSize;
    return len;
}

void insert(string s)
{
    LL index = hashFunc(s);
    LL check_val = 0;
    while(hashTable[index] != "" && check_val < hashTableSize)
        index = (index+1) % hashTableSize, check_val++;

    if(hashTable[index] == "")
    hashTable[index] = s;
    else
        cout << "no space" << endl;
}

void search(string s)
{
    LL index = hashFunc(s);
    LL check_val = 0;
    while(hashTable[index] != s and hashTable[index] != "" and check_val < hashTableSize)
        index = (index + 1) % hashTableSize,check_val++;

    if(hashTable[index] == s)
        cout << s << " is found!" << endl;
        else
            cout << s << " is not found!" << endl;
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

