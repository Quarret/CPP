#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    ll num = 1 << n;
    
    vector<int> a(num);
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }

    ll mid = num / 2;
    while (mid) {
        int l = *max_element(a.begin(), a.begin() + mid);
        int r = *max_element(a.begin() + mid + 1, a.end());

        
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
