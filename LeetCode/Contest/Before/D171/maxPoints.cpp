#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
    int n = technique1.size();
    vector<int> idxs(n);
    ranges::iota(idxs, 0);
    ranges::sort(idxs, {}, [&](int i) {
        return -technique1[i];
    });
    
    long long ans = 0;
    vector<int> vis(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;

    for (int i = 0; i < n; i++) {
        if (i < k) {
            vis[idxs[i]] = 1;
            ans += 1LL * technique1[idxs[i]];
        } else {
            pq.emplace(technique1[idxs[i]], idxs[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            pq.emplace(technique2[i], i);
        }
    }
    
    int cnt = n - k;
    while (cnt) {
        auto [score, idx] = pq.top();
        pq.pop();
        if (vis[idx]) continue;
        vis[idx] = 1;
        ans += 1LL * score;
        cnt--; 
    }

    return ans;
}

long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
    int n = technique1.size();
    
    vector memo(n, vector<long long>(n + 1, -1));
    auto dfs = [&](this auto&& dfs, int i, int cnt) -> int {
        if (i < 0) {
            return cnt >= k ? 0 : INT_MIN / 2;
        }

        long long &res = memo[i][cnt];
        if (res != -1) {
            return res;
        }
        res = max(dfs(i - 1, cnt + 1) + technique1[i], dfs(i - 1, cnt) + technique2[i]);
        return res;
    };

    return dfs(n - 1, 0);
}

long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
    int cnt1 = 0, cnt2 = 0;
    long long ans = 0;
    int n = technique1.size();
    vector<int> idxs;
    
    for (int i = 0; i < n; i++) {
        if (technique1[i] >= technique2[i]) {
            cnt1++;
            ans += 1LL * technique1[i];
        } else {
            cnt2++;
            ans += 1LL * technique2[i];
            idxs.push_back(i);
        }
    }

    ranges::sort(idxs, {}, [&](int &i) {
        return technique1[i];
    });

    int i = 0;
    cnt1 = k - cnt1;
    while (cnt1 > 0) {
        ans += 1LL * technique1[idxs[i]] - technique2[idxs[i]];
        i++;
        cnt1--;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
