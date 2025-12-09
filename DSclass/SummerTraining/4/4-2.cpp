#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int num = 0, minn = 1e9;
    vector<int> a;
    while (cin >> num) {
        if (num) minn = min(minn, num);
        a.push_back(num);
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == minn) {
            a.erase(a.begin() + i);
            break;
        }
    }

    sort(a.begin(), a.end());
    cout << minn;
    for (auto &it : a) {
        cout << it; 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
