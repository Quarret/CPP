#include <bits/stdc++.h>
#define ll long long
using namespace std;

int q, n, num;
map<int, int> mp;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        mp[num] = i;
    }

    vector<int> a;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    
    int pre[n] = {0}, suf[n] = {0};
    pre[0] = mp[a[0]], suf[n - 1] = mp[a[n - 1]];
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i - 1], mp[a[i]]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], mp[a[i]]);
    }

    for (int i = 1; i < n - 1; i++) {
        int maxl = pre[i - 1], maxr = suf[i + 1];
        if (maxl > mp[a[i]] && maxr > mp[a[i]] && maxl > maxr) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    cin >> q;
    while(q--) {
        solve();
    }
}
