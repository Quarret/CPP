#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    int n = words.size();
    
    vector<int> mp(26, 0);
    for (char c : letters) {
        mp[c - 'a']++;
    }

    int ans = 0;
    auto dfs = [&](this auto&& dfs, int i, vector<int> cnt, int res) -> void {
        if (i == n) {
            ans = max(ans, res);
            return;
        }

        int ok = 1;
        vector<int> a(26, 0);
        for(char ch : words[i]) {
            a[ch - 'a']++;
        }

        int new_res = res;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] + a[i] > mp[i]) {
                ok = 0;
            }
            new_res += a[i] * score[i];
            a[i] += cnt[i];
        }

        if (ok) {
            dfs(i + 1, a, new_res);
        }
        dfs(i + 1, cnt, res);
    };

    vector<int> b(26, 0);
    dfs(0, b, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
