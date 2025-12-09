#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> memo(n, -1);
    
    auto dfs = [&](this auto&& dfs, int i) -> long long {
        if (i >= n) return 0;

        long long &res = memo[i];
        if (res != -1) return res;
        res = max(dfs(i + 1), dfs(i + questions[i][1] + 1) + questions[i][0]);

        return res;
    };

    return dfs(0);
}

//dp
//from small to big, enumrate dp frome big to small!!!
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> f(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        f[i] = max(f[i + 1], f[min(n, i + questions[i][1] + 1)] + questions[i][0]);
    }

    return f[0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
