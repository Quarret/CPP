#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 分类讨论
int minOperations(string s) {
    int n = s.size();
    if (ranges::is_sorted(s)) return 0;

    if (n == 2) return -1;

    auto [mn, mx] = ranges::minmax(s);

    if (s[0] == mn || s.back() == mx) {
        return 1;
    }

    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == mn || s[i] == mx) {
            return 2;
        }
    }

    return 3;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}