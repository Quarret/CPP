#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) {
    int n = digits.size();
    vector<int> vis(n);
    string path(3, ' ');
    unordered_set<int> st;

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == 3) {
            int num = stoi(path);
            if (num % 2 == 0) st.insert(num);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (i == 0 && digits[j] == 0) continue;
            if (vis[j]) continue;
            vis[j] = 1;
            path[i] = digits[j] + '0';
            dfs(i + 1);
            vis[j] = 0;
        }
    };

    dfs(0);
    vector<int> ans(st.begin(), st.end());
    sort(ans.begin(), ans.end());
    return ans;
}

// 特别判断三位
vector<int> findEvenNumbers(vector<int>& digits) {
    int cnt[10]{};
    for (int x : digits) {
        cnt[x]++;
    }

    vector<int> ans;
    auto dfs = [&](this auto&& dfs, int i, int x) -> void {
        if (i == 3) {
            ans.push_back(x);
            return;
        }

        for (int d = 0; d < 9; d++) {
            if (cnt[d] > 0 && ((i == 0 && d != 0) || (i == 1) || (i == 2 && d % 2 == 0))) {
                cnt[d]--;
                dfs(i + 1, 10 * x + d);
                cnt[d]++;
            }
        }
    };

    dfs(0, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
