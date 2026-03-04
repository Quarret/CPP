#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    using ll = long long;
    hFences.push_back(1);
    vFences.push_back(1);
    hFences.push_back(m);
    vFences.push_back(n);
    ranges::sort(hFences);
    ranges::sort(vFences);

    priority_queue<ll> pq;
    for (int i = 0; i < hFences.size(); i++) {
        for (int j = i + 1; j < hFences.size(); j++) {
            ll d = hFences[j] - hFences[i];
            pq.push(d);
        }
    }
    
    ll ans = -1;
    unordered_map<ll, int> mp;
    for (int i = 0; i < vFences.size(); i++) {
        for (int j = i + 1; j < vFences.size(); j++) {
            ll d = vFences[j] - vFences[i];
            mp[d] = 1;
        }
    }

    const int MOD = 1e9 + 7;
    while (!pq.empty()) {
        ll d = pq.top();
        pq.pop();
        if (mp[d]) {
            ans = (d % MOD) * (d % MOD) % MOD;
            break;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}