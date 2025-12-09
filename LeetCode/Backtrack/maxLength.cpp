#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxLength(vector<string>& arr) {
    int n = arr.size();
    
    int ans = 0;
    auto dfs = [&](this auto&& dfs, int i, int path) -> void {
        if (i == n) {
            ans = max(ans, __builtin_popcount(path));
            return;
        }

        
        int ok = 1, num = 0;
        for (char c : arr[i]) {
            int x = c - 'a';
            if (path & (1 << x)) {
                ok = 0;
            } else if (num & (1 << x)) {
                ok = 0;
            }
            num |= 1 << x;
        }
        
        if (ok) {
            dfs(i + 1, path);
            dfs(i + 1, path | num);
        } else {
            dfs(i + 1, path);
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
