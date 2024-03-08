#include "bits/stdc++.h"

using std::cin, std::cout, std::endl, std::vector, std::reverse;

template<typename T> T min(const T &x, const T &y);

template<typename T> T max(const T &x, const T &y);

template<typename T> T* read_array(const size_t &n);

template <typename T> int CompareFunc(const void *elem1, const void *elem2);

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2);

template <typename type> int funccompar(const void * key, const void * cmpelem);

void func(const int *col, const int &x, const int &n)
{
    int *y = (int*) bsearch(&x, col, n, sizeof (int), funccompar<int>);
    if(y == NULL)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

void _solve()
{
    size_t n, m;
    cin >> n;

    int *collection = read_array<int>(n);

    cin >> m;

    int *search = read_array<int>(m);

    for (size_t i = 0; i < m; i++)
    {
        func(collection, search[i], n);
    }
    
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    std::freopen("collect.in", "r", stdin);
    std::freopen("collect.out", "w", stdout);
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