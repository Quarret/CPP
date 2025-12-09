#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int numberOfSubstrings(string s) {
    vector<int> pos0 = {-1};
    int total1 = 0;
    int ans = 0;
    
    for (int r = 0; r < s.size(); r++) {
        if (s[r] == '0') {
            pos0.push_back(r);
        } else {
            total1++;
            ans += r - pos0.back(); // 全 1 字符串
        }

        
        int m = pos0.size();
        for (int i = m - 1; i > 0 && (m - i) * (m - i) <= total1; i--) {
            int p = pos0[i - 1], q = pos0[i];
            int cnt0 = m - i;
            int cnt1 = r - q + 1 - cnt0; // [q, r] - cnt0
            ans += max(q - max(cnt0 * cnt0 - cnt1, 0) - p, 0);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
