#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int num1, num2;
    while (cin >> num1 >> num2) {
        int n1 = sqrt(num1), n2 = sqrt(num2), sum1 = 1, sum2 = 1;

        for (int i = 2; i <= n1; i++) {
            if (num1 % i == 0) {
                sum1 += i;
                sum1 += num1 / i;
            }
        }

        for (int i = 2; i <= n2; i++) {
            if (num2 % i == 0) {
                sum2 += i;
                sum2 += num2 / i;
            }
        }

        cout << (((sum1 == num2 && sum2 == num1)) ? "YES" : "NO") << '\n'; 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
