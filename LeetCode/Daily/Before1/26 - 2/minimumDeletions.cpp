#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumDeletions(string s) {
    int cnt_a = 0, cnt_b = 0;
    for (char c : s) {
        (c == 'a' ? cnt_a : cnt_b) += 1;
    }
    
    int pre_a = 0, pre_b = 0, ans = INT_MAX;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i];
        if (c == 'a') {
            pre_a++;
            continue;
        }

        int res = pre_b + cnt_a - pre_a;
        ans = min(ans, res);
        pre_b++;
    }

    ans = min({ans, cnt_a, cnt_b});
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}