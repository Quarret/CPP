#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string reorganizeString(string s) {
    int cnt[26]{};
    int n = s.size(), m = 0;
    for (char c : s) {
        cnt[c - 'a']++;
        m = max(m, cnt[c - 'a']);
    }
    
    if (m - 1 > n - m) {
        return "";
    }

    vector<int> idxs(26);
    ranges::iota(idxs, 0);
    ranges::sort(idxs, {}, [&](int i) {
        return -cnt[i];
    });

    vector<string> strs(m);
    int i = 0;
    for (int idx : idxs) {
        while (cnt[idx]) {
            strs[i % m].push_back(idx + 'a');
            cnt[idx]--;
            i++;
        }
    }

    string ans;
    for (string s : strs) {
        ans += s;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
