#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int mid = ceil((double) ((double) n) / 2);
    //cout << mid << '\n';
    int num = a[mid], ans = 1;
    for (int i = mid + 1; i <= n; i++) {
        if (a[i] == num) {
            ans++;
        } else {
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
