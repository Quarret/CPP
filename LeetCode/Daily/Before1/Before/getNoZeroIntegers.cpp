#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n - 1; i++) {
        int ans = i, ans1 = n - i;
        string s = to_string(ans), s1 = to_string(ans1);
        if (s.find('0') == s.npos && s1.find('0') == s1.npos) return {ans1, ans};
    }

    return {0, 0};
}

//greedy build
vector<int> getNoZeroIntegers(int n) {
    int a = 0;
    int base = 1;

    // x >= 1 确保最高位的1是按1来分，而不是11来分
    for (int x = n; x > 1; x /= 10) {
        int d = x % 10;
        if (d < 2) {
            d += 10;
            x -= 10;
        }

        a += d / 2 * base;
        base *= 10;
    }

    return {a, n - a};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
