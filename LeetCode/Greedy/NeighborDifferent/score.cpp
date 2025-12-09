#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 累死累活计算不如直接枚举 xx 到不同数组的个数
int score(vector<string>& cards, char x) {
    unordered_map<string, int> cnt1, cnt2;
    int n1 = 0, n2 = 0, m1 = 0, m2 = 0, cnt = 0;

    for (string card : cards) {
        if (card[0] == x && card[1] != x) {
            n1++;
            cnt1[card]++;
            m1 = max(m1, cnt1[card]);
        } else if (card[0] != x && card[1] == x) {
            n2++;
            cnt2[card]++;
            m2 = max(m2, cnt2[card]);    
        } else if (card[0] == x && card[1] == x) {
            cnt++;
        }
    }

    int ans = 0;
    for (int k = 0; k <= cnt; k++) {
        int new_n1 = n1 + k, new_m1 = max(m1, k);
        int new_n2 = n2 + cnt - k, new_m2 = max(m2, cnt - k);
        int ans1 = min(new_n1 / 2, new_n1 - new_m1);
        int ans2 = min(new_n2 / 2, new_n2 - new_m2);
        ans = max(ans, ans1 + ans2);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
