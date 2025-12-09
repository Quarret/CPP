#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll M, sum = 0;
    cin >> M;
    
    ll res = 0;
    vector<ll> ans;
    while (M) {
        int num = M % 3;

        if (num == 1) {
            ans.push_back(res);
            M -= 1;
        } else if (num == 2) {
            ans.push_back(res);
            ans.push_back(res);
            M -= 2;
        }
        M /= 3;
        res++;
    }

    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }
    return 0;
}
