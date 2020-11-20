/// Complexity : O(Log b).
#include <iostream>

using namespace std;

long long big_mod(long long a, long long b, long long p)
{
    long long result = 1 % p;

    a = a % p ;

    while(b > 0)
    {
        if(b & 1)
            result = (result * a) % p ;

        b = b >> 1 ;
        a = (a * a) % p ;
    }
    return result ;

}
int main()
{
    long long a, b, p ;
    while(cin >> a >> b >> p)
    {
        cout << power(a, b, p) << endl ;
    }
    return 0 ;
}
