#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> ans;
    string path(n, ' ');
    
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(stoi(path));
            return;
        }

        if (i == 0) {
            for (int j = 1; j <= 9; j++) {
                path[i] = j + '0';
                dfs(i + 1);
            }
        } else {
            int x = path[i - 1] - '0' - k;
            int y = path[i - 1] - '0' + k;
            if (x >= 0) {
                path[i] = x + '0';
                dfs(i + 1);
            }

            if (x != y && y < 10) {
                path[i] = y + '0';
                dfs(i + 1);
            }
        }
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
