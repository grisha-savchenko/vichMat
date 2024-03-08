#include "bits/stdc++.h"

using std::cin, std::cout, std::endl;

long long stavka(long long k, long long z)
{
    long long y = int(ceil(double(z+1)/double(k-1)));
    while (y*(k-1)<=z)
    {
        y += 1;
    }
    
    return y;
}

void _solve()
{
    long long k, x , a;
    cin >> k;
    cin >> x;
    cin >> a;
    long long izn_a = a;
    long long step = 0;
    long long z = 0, y = 1;
    while(step < x && a > 0)
    {
        ++step;
        z += y;
        a -= y;
        y = stavka(k, z);
    }
    a = a*k;
    if(a > izn_a)
        cout << "YES"  << endl;
    else
        cout << "NO"<< endl;
    
}

int main()
{
    long long t;
    cin >> t;
    for (size_t i = 0; i < t; ++i)
    {
        _solve();
    }
    
    return 0;
}