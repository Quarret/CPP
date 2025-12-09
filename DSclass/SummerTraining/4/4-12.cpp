#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    int num = 1, num3 = 2, num4 = 1;
    for (int i = 1; i <= n; i++) {
        cout << num << ' ';
        int tmp = num;
        for (int j = num3; j <= n; j++)
        {
            tmp = tmp + j;
            cout << tmp << ' ';
        }
        num += num4;
        num3++;
        num4++;
        cout << '\n';
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
