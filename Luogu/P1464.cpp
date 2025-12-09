#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }

    if (a < b && b < c) {
        return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }

    return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    ll a = 0, b = 0, c = 0;
    while (1) {
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) {
            break;
        }

    ll ans = w(a, b, c);

    cout << "w(" << a << ", " << b << ", " << c  << ") = " <<  ans << '\n';
    }
}
