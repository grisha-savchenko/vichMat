#include "bits/stdc++.h"

using std::cin, std::cout, std::endl, std::vector, std::reverse;

template<typename T> T min(const T &x, const T &y);

template<typename T> T max(const T &x, const T &y);

template<typename T> T* read_array(const size_t &n);

template <typename T> int CompareFunc(const void *elem1, const void *elem2);

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2);

template <typename type> int funccompar(const void * key, const void * cmpelem);

int perestanovki(int* stoyla, int n, int cows, int minrast)
{
    bool flag = false;
    int count = 1;
    int last = stoyla[0];
    for (size_t i = 1; i < n; i++)
    {
       if(stoyla[i] - last >= minrast)
       {
            count++;
            last = stoyla[i];
            if(count == cows)
                return 1;
       }
    }
    return 0;
}

void biSearch(int* stoyla, int n, int cows)
{
    int min = 0;
    int max = stoyla[n-1] - stoyla[0];
    int res = 0;
    while (min <= max)
    {
        int mid = min + (max-min) / 2;
        if(perestanovki(stoyla, n, cows, mid))
        {
            res = mid;
            min = mid + 1;
        }
        else
            max = mid - 1;

    }


    cout << res << endl;
     
}

void _solve()
{
    size_t n, m;
    cin >> n >> m;

    int *stoyla = read_array<int>(n);
    int *lenght = new int[n-1];

    biSearch(stoyla, n, m);
    


    
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    std::freopen("cows.in", "r", stdin);
    std::freopen("cows.out", "w", stdout);
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