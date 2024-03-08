#include "bits/stdc++.h"

using std::cin, std::cout, std::endl, std::vector, std::reverse;

template<typename T> T min(const T &x, const T &y);

template<typename T> T max(const T &x, const T &y);

template<typename T> T* read_array(const size_t &n);

template <typename T> int CompareFunc(const void *elem1, const void *elem2);

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2);

template <typename type> int funccompar(const void * key, const void * cmpelem);

long double f(int a, int b, int c, int d, long double x)
{
    return a*x*x*x + b*x*x + c*x + d; 
}


long double func(int a, int b, int c, int d, long double e)
{
    long double r = 1;

    while(f(a,b,c,d,r) * f(a,b,c,d,-r) >= 0) r *= 2;
    long double l = -r;

    long double x = 0;

   while (r - l >= e)
    {
        x = (l + r) / 2;
        if (f(a,b,c,d,x) * f(a,b,c,d,r) > 0) r = x; 
        else l = x;
    }
    return x;
    
}


void _solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    long double e = 1e-12;

    long double ans = func(a, b, c, d, e);

    cout << std::fixed << std::setprecision(6) << ans << endl;


    
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    std::freopen("cubroot.in", "r", stdin);
    std::freopen("cubroot.out", "w", stdout);
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; ++i)
    // {
    //     _solve();
    // }
    _solve();
    
    return 0;
}

template<typename T> T* read_array(const size_t &n)
{
    T* array = new T[n];
    for (size_t i = 0; i < n; ++i)
        cin >> array[i];
        
    return array;
}

template<typename T> T min(const T &x, const T &y)
{
    if(x < y)
        return x;
    else
        return y;
}

template<typename T> T max(const T &x, const T &y)
{
    if(x > y)
        return x;
    else
        return y;
}

template <typename T> int CompareFunc(const void *elem1, const void *elem2)
{
 if ( *(T*)elem1 == *(T*)elem2 ) return 0;
 return ( *(T*)elem1 > *(T*)elem2 ) ? 1 : -1;
}

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2)
{
 if ( *(T*)elem1 == *(T*)elem2 ) return 0;
 return ( *(T*)elem1 < *(T*)elem2 ) ? 1 : -1;
}

template <typename type> int funccompar(const void * key, const void * cmpelem)
{
  if ( *(type*)key >  *(type*)cmpelem ) return 1;
  if ( *(type*)key == *(type*)cmpelem ) return 0;
  if ( *(type*)key <  *(type*)cmpelem ) return -1;
}