#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    char c;

    for (int i = 1; i <= n; i++) {
        cin >> c;
        int temp = c - '0';
        a.push_back(temp + a.back());
    }
    
    double num = (double)n / 2, minn = 1e9;
    int pos = -1e9, ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i - a[i] >= ceil((double) i / 2) && a.back() - a[i] >= ceil((double) (n - i) / 2)) {
            //cout << i << ' ' << i - a[i] << ' ' << ceil((double)i / 2) << ' ' << a.back() - a[i] << ' ' << ceil((double)(n - i) / 2) << ' ' << '\n';
            pos = i;
        }

        if (fabs((double)pos - num) < minn) {
            ans = pos;
            minn = fabs((double)pos - num);
            //cout << pos << ' ' << minn << '\n';
        }

        if ((double)pos >= num + 1) {
            break;
        }
    }

    cout << ans << '\n';
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
