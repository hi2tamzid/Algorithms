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
LL hashFunc1(string s)
{
    LL len = 0;
    len = (LL)s[len] % hashTableSize;
    return len;
}

void insert(string s)
{
    //Compute the index using the hash function
    LL index = hashFunc(s);
    LL indexH = hashFunc1(s);
    //Search for an unused slot and if the index will exceed the hashTableSize roll back
    LL h = 1;
    while(hashTable[index] != "" && h <= hashTableSize)
    {
        index = (index + h * indexH) % hashTableSize;
        h++;
    }
    if(hashTable[index] == "")
        hashTable[index] = s;
    else
        cout << "no space" << endl;
}


void search(string s)
{
    //Compute the index using the Hash Function
    int index = hashFunc(s);
    LL indexH = hashFunc1(s);
    //Search for an unused slot and if the index will exceed the hashTableSize roll back
    int h = 1;
    while(hashTable[index] != s and hashTable[index] != "" && h <= hashTableSize)
    {
        index = (index + h* indexH) % hashTableSize;
        h++;
    }
    //Is the element present in the hash table
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

