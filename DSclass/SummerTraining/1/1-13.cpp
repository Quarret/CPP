#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll num;
    cin >> num;
    
    ll ans = 0, num2 = 1;
    while (num) {
        int num1 = num % 10;
        num /= 10;
        
        if (num1 >= 4 && num1 <= 7) {
            num1--;
        } else if (num1 == 9) {
            num1 -= 2;
        }
        ans += num1 * num2;
        num2 *= 8;
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
