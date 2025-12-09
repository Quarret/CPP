#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countKConstraintSubstrings(string s, int k) {
    int n = s.size(), l = 0, ans = 0;
    vector<int> cnt(2, 0);

    for (int r = 0; r < n; r++) {
        cnt[s[r] - '0']++;

        while (cnt[0] > k || cnt[1] > k) {
            cnt[s[l] - '0']--;
            l++;
        }

        ans += r - l + 1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
