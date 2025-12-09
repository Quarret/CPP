#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> H(n + 1), res(n + 1);
    for (int i = 1; i <= n; i++) {  
        cin >> H[i];
    }

    vector<int> s;
    for (int i = n; i >= 1; i--) {
        res[i] = s.size();
        while (s.size() && s.back() < H[i]) {
            s.pop_back();
        }
        s.push_back(H[i]);
    }

    
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}
