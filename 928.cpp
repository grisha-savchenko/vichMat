#include <bits/stdc++.h>
 
using i64 = long long;
 
long long countDigits(long long n, int digit) {
    long long count = 0;
    long long base = 1;
    long long remainder = 0;

    while (n > 0) {
        long long quotient = n / 10;
        long long lastDigit = n % 10;

        if (lastDigit < digit) {
            count += quotient * base;
        } else if (lastDigit == digit) {
            count += quotient * base + remainder + 1;
        } else {
            count += (quotient + 1) * base;
        }

        remainder += lastDigit * base;
        if (digit == 0) {
            remainder--;
        }

        base *= 10;
        n /= 10;
    }

    return count;
}

long long sumOfDigitsInRange(long long n) {
    long long sum = 0;

    for (int i = 0; i <= 9; ++i) {
        sum += countDigits(n, i) * i;
    }

    return sum;
}

void solve() {
    int n;
    std::cin >> n;
    std::cout << sumOfDigitsInRange(n) << std::endl;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}