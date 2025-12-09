#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    //cout << a << ' ' << b << ' ' << c << '\n';

    int sum = a + b + c, sum1 = 2 * a + b, sum2 = a + b, num1, num2,ans, num;

    if (sum1 != sum - 1) {
        cout << -1 << '\n';
        return;
    }

    if (a == 0) {
        cout << b << '\n';
        return;
    }
    
    if (a == 1) {
        cout << 1 + b / 2 + (b % 2 != 0) << '\n';
        return;
    }

    for (int i = 0; i <= 100; i++) {
        if (a < (1 << (i + 1)) - 1) {
            num1 = ((1 << (i + 1)) - 1) - a;//第i + 1层空的节点数
            num2 = a - ((1 << i) - 1);//第i + 1层 2的个数
            ans = i;
            break;
        }
    }
    
    num = 2 * num2 + num1;
    if (b <= num1) {
        cout << ans + 1 << '\n';
    } else {
        b -= num1;
        cout << ans + 1 + b / num  + (b % num != 0)<< '\n';
    }   
   
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
