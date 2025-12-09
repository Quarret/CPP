#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void solve() {
    int num, cnt = 0, ans;
    int a[10001] = {0};

    for (int i = 0; i < n; i++) {
        cin >> num;
        a[num]++;

        if (a[num] > cnt) {
            cnt = a[num];
            ans = num;  
        } 
    }

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    while (1) {
        cin >> n;
        if (!n) {
            return 0;
        }
        solve();
    }
}
