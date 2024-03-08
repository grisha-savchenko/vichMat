#include "bits/stdc++.h"

using std::cin, std::cout, std::endl, std::vector, std::reverse;

template<typename T> T min(const T &x, const T &y);

template<typename T> T max(const T &x, const T &y);

template<typename T> T* read_array(const size_t &n);

template <typename T> int CompareFunc(const void *elem1, const void *elem2);

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2);

template <typename type> int funccompar(const void * key, const void * cmpelem);


long double func(long double x ,int Vp, int Vf, long double a)
{
    return sqrt((1-a)*(1-a)+x*x) / Vp + sqrt((1-x)*(1-x)+a*a) / Vf;
}

void _solve()
{
    int Vp, Vf;

    long double a;

    cin >> Vp >> Vf;

    cin >> a;

    long double e = 1e-8;

    long double left = 0, right = 1; 

    while (right - left >= e)
    {
        long double mid1 = left + (right - left)/3;
        long double mid2 = right - (right - left)/3;
        if(func(mid1, Vp, Vf, a) < func(mid2, Vp, Vf, a))
            right = mid2;
        else
            left = mid1;
    }
    

    cout << std::fixed << std::setprecision(11) << left << endl;

    
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    std::freopen("forest.in", "r", stdin);
    std::freopen("forest.out", "w", stdout);
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