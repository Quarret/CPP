#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n;
    int cnt1 = 0, cnt0 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        //cout << a << ' ' << b << '\n';
        if(a > 0) cnt1++;
        else if (a < 0) cnt0++;
    }
    
    //cout << cnt1 << ' ' << cnt0 << '\n';
    if (cnt1 > 1 && cnt0 > 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
