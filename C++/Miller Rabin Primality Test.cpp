// C++ program Miller-Rabin primality test
#include <bits/stdc++.h>
using namespace std;

// Utility function to do modular exponentiation.
// It returns (x^y) % p
int modulo(int a,int b,int c){
    // res is kept as long long because intermediate results might overflow in "int"
    long long res = 1;
    for(int i=0;i<b;i++){
        res *= a;
        res %= c; // this step is valid because (a*b)%c = ((a%c)*(b%c))%c
    }
    return res%c;
}
long long mulmod(long long a,long long b,long long c)
{
    long long x = 0,y=a%c;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p,int iteration)
{
    if(p<2)
    {
        return false;
    }
    if(p!=2 && p%2==0)
    {
        return false;
    }
    long long s=p-1;
    while(s%2==0)
    {
        s/=2;
    }
    for(int i=0; i<iteration; i++)
    {
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
        {
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0)
        {
            return false;
        }
    }
    return true;
}

// Driver program
int main()
{
    long long n ;
    while(cin >> n)
    {
        if(Miller(n, 20))
            cout << "prime number" << endl ;
        else
            cout << "composite number" << endl ;
    }

    return 0;
}
