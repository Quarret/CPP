#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findCoins(vector<int>& numWays) {
    int n = numWays.size(), ok = 0;
    vector<int> f(n + 1), ans;
    
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (numWays[i - 1] == 0 || f[i] + f[0] != numWays[i - 1]) {
            if (f[i] + f[0] > numWays[i - 1]) ok = 1;
            continue;
        }
        for (int j = i; j <= n; j++) {
            f[j] += f[j - i];
            cout << f[j] << ' ';
        }
        cout << '\n';
        ans.push_back(i);
    }

}


vector<int> findCoins(vector<int>& numWays) {
    int n = numWays.size(), ok = 0;
    vector<int> f(n + 1), ans;
    
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        ok = 0;
        vector<int> f1(f.begin(), f.end());
        for (int j = i; j <= n; j++) {
            if (f1[j] + f1[j - i] > numWays[j - 1]) ok = 1;
            f1[j] += f1[j - i];
        }
        if (ok) continue;
        
        f = f1;
        ans.push_back(i);
    }

    return ans;
}

vector<int> findCoins(vector<int>& numWays) {
    int n = numWays.size();
    vector<int> f(n + 1), ans;

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int way = numWays[i - 1];
        if (f[i] == way) continue;

        // 子问题： 若目前不满足，则前面就没有任何一种完全背包满足
        if (f[i] != way - 1) return {};

        ans.push_back(i);
        for (int j = i; j <= n; j++) {
            f[j] += f[j - i];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
