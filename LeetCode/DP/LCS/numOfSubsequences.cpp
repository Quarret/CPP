#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long numOfSubsequences(string s) {
    int n = s.size();
    string t = "LCT";
    vector memo(n, vector<array<long long, 2>>(3, {-1, -1}));
    
    auto dfs = [&](this auto&& dfs, int i, int j, int flag) -> long long {
        if (j < 0) return 1;
        if (i < 0) return 0;

        long long &res = memo[i][j][flag];
        if (res != -1) return res;
        return res;
    };

    return dfs(n - 1, 2, 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
