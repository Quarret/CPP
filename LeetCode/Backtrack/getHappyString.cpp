#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string getHappyString(int n, int k) {
    vector<string> ans;
    string path(n, ' ');

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);
            return;
        }

        for (int j = 0; j < 3; j++) {
            if (i == 0 || (i > 0 && path[i - 1] != j + 'a')) {
                path[i] = j + 'a';
                dfs(i + 1);
            }
        }
    };

    dfs(0);
    return ans.size() >= k ? ans[k - 1] : "";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
