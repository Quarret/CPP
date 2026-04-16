#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string getHappyString(int n, int k) {
    vector<string> ans;
    string path(n + 1, ' ');

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n + 1) {
            ans.push_back(path.substr(1));
            return;
        }

        if (path[i - 1] != 'a') {
            path[i] = 'a';
            dfs(i + 1);
        }
        if (path[i - 1] != 'b') {
            path[i] = 'b';
            dfs(i + 1);
        }
        if (path[i - 1] != 'c') {
            path[i] = 'c';
            dfs(i + 1);
        }
    };

    dfs(1);
    ranges::sort(ans);
    return k > ans.size() ? "" : ans[k - 1];
}


// O(n) 数学做法
string getHappyString(int n, int k) {
    if (k > 3 << (n - 1)) {
        return "";
    }

    k--; // 从 0 开始, 方便计算
    string ans(n, 'a');
    ans[0] += k >> (n - 1);
    for (int i = 1; i < n; i++) {
        ans[i] += k >> (n - 1 - i) & 1;
        if (ans[i] >= ans[i - 1]) {
            ans[i] += 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}