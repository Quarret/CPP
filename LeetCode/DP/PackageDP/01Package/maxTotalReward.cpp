#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxTotalReward(vector<int>& rewardValues) {
    int n = rewardValues.size(), s = reduce(rewardValues.begin(), rewardValues.end());
    sort(rewardValues.begin(), rewardValues.end(), greater());
    vector memo(n, vector<int>(s + 1, -1));

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0) return 0;

        int &res = memo[i][j];
        if (res != -1) return res;
        res = dfs(i - 1, j);
        int x = s - j;
        if (rewardValues[i] > x && j >= rewardValues[i]) res = max(res, dfs(i - 1, j - rewardValues[i]) + rewardValues[i]);
        
        return res;
    };

    return dfs(n - 1, s);
}


int maxTotalReward(vector<int>& rewardValues) {
    int n = rewardValues.size(), s = reduce(rewardValues.begin(), rewardValues.end());
    //s too big so that late
    sort(rewardValues.begin(), rewardValues.end());
    vector<int> f(s + 1);

    for (int x : rewardValues) {
        for (int c = s; c >= 0; c--) {
            if (x > s - c && c >= x) f[c] = max(f[c], f[c - x] + x);
        }
    }

    return f[s];
}

int maxTotalReward(vector<int>& rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    int n = rewardValues.size(), m = rewardValues.back() * 2;
    vector<int> f(m + 1);

    f[0] = 1;
    for (int x : rewardValues) {
        for (int c = 2 * x - 1; c >= x; c--) {
            f[c] |= f[c - x];
        }
    }
    
    for (int i = m; i >= 0; i--) {
        if (f[i]) return i;
    }
}

//bitset
int maxTotalReward(vector<int>& rewardValues) {
    sort(rewardValues.begin(), rewardValues.end());
    int m = rewardValues.back() * 2 - 1;
    
    bitset<100000> f{1};
    for (int v : rewardValues) {
        int shift = f.size() - v;
        f |= (f << shift >> shift) << v;
    }

    for (int i = m; i >= 0; i--) {
        if (f.test(i)) return i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
