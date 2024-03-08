#include "bits/stdc++.h"



using std::cin, std::cout, std::endl, std::vector;

void _solve();

void _solve()
{
    size_t n;
    cin >> n;
    vector<size_t> arr2(n);
    
    for (size_t i = 0; i < n; ++i)
    {
        cin >> arr2[i];
        arr2[i] = arr2[i] + i + 1;
    }
    std::sort(rbegin(arr2), rend(arr2));
    for (size_t i = 0; i < n-1; ++i)
    {
        size_t temp = arr2[i];
        int k = i;
        while (temp == arr2[k+1])
        {
            --arr2[k+1];
            ++k;
        }
    }
    bool flag = false;
    
    for (size_t i = 0; i < n; ++i)
    {
        if(flag)
            cout << " " << arr2[i]; 
        else{
           cout << arr2[i];
            flag = true;
        }
    }
    cout <<endl;
 
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    int t;
    cin >> t;
    for (size_t i = 0; i < t; ++i)
    {
        _solve();
    }
    
    return 0;
}

