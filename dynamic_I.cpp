#include "bits/stdc++.h"

using std::cin, std::cout, std::endl, std::vector;

template<typename T> T min(const T &x, const T &y);

template<typename T> T* read_array(const size_t &n);

template <typename T> int CompareFunc(const void *elem1, const void *elem2);

template <typename T> int CompareFuncReverse(const void *elem1, const void *elem2);



void _solve()
{
    size_t s, n;
    cin >> s >> n;
    int *arr = read_array<int>(n);
    qsort(arr,n,sizeof(int),CompareFunc<int>);

    int massive[s+1] = {0};
    massive[0] = 1;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t k = s; k >= arr[i]; k--)
        {
            if(k >= arr[i])
                if(massive[k - arr[i]] == 1) massive[k] = 1;
        }
    }
    int i = s+1;
    while (massive[--i] == 0);
    cout << i;
    
    cout << endl;
    
    
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    // std::freopen("lepus.in", "r", stdin);
    // std::freopen("lepus.out", "w", stdout);
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
