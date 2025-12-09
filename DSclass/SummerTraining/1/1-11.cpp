#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, sum;
void solve() {
    vector<int> a(n);
    ll num1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        num1 += a[i] * a[i];
    }

    double ans = 0.;
    ans = (n * num1 - sum * sum) / (n * n);
    cout << floor(ans) << '\n';     
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    while (1) {
    sum = 0;
    cin >> n;
    if (!n) return 0;
    solve();
    }
}
