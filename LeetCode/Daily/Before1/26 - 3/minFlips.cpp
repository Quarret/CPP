#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 滑动窗口
int minFlips(string s) {
    int ans = INT_MAX, n = s.size(), cnt = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        // if (s[i % n] % 2 != i % 2) cnt++;
        if ((s[i % n] ^ i) & 1) cnt++;
        
        int left = i - n + 1;
        if (left < 0) continue;
        
        ans = min({ans, cnt, n - cnt});
        if ((s[left % n] ^left) & 1) cnt--;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}