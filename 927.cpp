#include "bits/stdc++.h"
// #define int_MAX  2147483647
// #define int_MIN -2147483647 - 1
// #define Uint_MAX 4294967295

// #define ULLONG_MAX 18446744073709551615
// #define LLONG_MAX   9223372036854775807
// #define LLONG_MIN  -9223372036854775807 - 1

using std::cin, std::cout, std::endl, std::vector;

template<typename T> T min(const T &x, const T &y);

template<typename T> T max(const T &x, const T &y);

template<typename T> T* read_array(const size_t &n);

template <typename T> int CompareFunc(const void *elem1, const void *elem2);

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2);


// qsort(arr,n,sizeof(int),CompareFunc<int>);
void _solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    char com[n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> com[i];
    }

    int proiz = 1;

    for (size_t i = 0; i < n; ++i)
        proiz *= arr[i];  

    int left = 0;
    int rigth = n-1;
    int idx = 0; 

    while (idx < n)
    {
        int tmp = 0;
        tmp = proiz % m;
        if(com[idx] == 'L')
        {
            proiz /= arr[left];
            ++left;
        }
        else
        {
            proiz /= arr[rigth];
            --rigth;
        }
        ++idx;
        cout << tmp << " ";
    }
    cout <<endl;
   
}
 
int main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
 
    int t;
    cin >> t;
    for (size_t i = 0; i < t; ++i)
    {
        _solve();
    }
    
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
