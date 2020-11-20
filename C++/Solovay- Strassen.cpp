#include <bits/stdc++.h>
using namespace std ;
//calculates Jacobian(a/n) n>0 and n is odd
int modulo(int a,int b,int c){
    // res is kept as long long because intermediate results might overflow in "int"
    long long res = 1;
    for(int i=0;i<b;i++){
        res *= a;
        res %= c; // this step is valid because (a*b)%c = ((a%c)*(b%c))%c
    }
    return res%c;
}
int calculateJacobian(long long a,long long n)
{
    if(!a) return 0; // (0/n) = 0
    int ans=1;
    long long temp;
    if(a<0)
    {
        a=-a;    // (a/n) = (-a/n)*(-1/n)
        if(n%4==3) ans=-ans; // (-1/n) = -1 if n = 3 ( mod 4 )
    }
    if(a==1) return ans; // (1/n) = 1
    while(a)
    {
        if(a<0)
        {
            a=-a;    // (a/n) = (-a/n)*(-1/n)
            if(n%4==3) ans=-ans;    // (-1/n) = -1 if n = 3 ( mod 4 )
        }
        while(a%2==0)
        {
            a=a/2;    // Property (iii)
            if(n%8==3||n%8==5) ans=-ans;
        }
        swap(a,n);    // Property (iv)
        if(a%4==3 && n%4==3) ans=-ans; // Property (iv)
        a=a%n; // because (a/p) = (a%p / p ) and a%pi = (a%n)%pi if n % pi = 0
        if(a>n/2) a=a-n;
    }
    if(n==1) return ans;
    return 0;
}

/* Iterations determine the accuracy of the test */
bool Solovoy(long long p,int iteration)
{
    if(p<2) return false;
    if(p!=2 && p%2==0) return false;
    for(int i=0; i<iteration; i++)
    {
        long long a=rand()%(p-1)+1;
        long long jacobian=(p+calculateJacobian(a,p))%p;
        long long mod=modulo(a,(p-1)/2,p);
        if(!jacobian || mod!=jacobian)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long n ;
    while(cin >> n)
    {
        if(Solovoy(n, 20))
            cout << "prime number" << endl ;
        else
            cout << "composite number" << endl ;

    }
}
