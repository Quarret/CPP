#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, tmp;
    cin >> n;
    vector<int> a1(n);
    int sum = 0;
    double sum1 = 0., GPA;
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
        sum +=a1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp <= 100 && tmp >= 90) {
            sum1 += a1[i] * 4.0;
        } else if (tmp >= 85) {
            sum1 += a1[i] * 3.7;
        } else if (tmp >= 82) {
            sum1 += a1[i] * 3.3;
        } else if (tmp >= 78) {
            sum1 += a1[i] * 3.0;
        } else if (tmp >= 75) {
            sum1 += a1[i] * 2.7;
        } else if (tmp >= 72) {
            sum1 += a1[i] * 2.3;
        } else if (tmp >= 68) {
            sum1 += a1[i] * 2.0;
        } else if (tmp >= 64) {
            sum1 += a1[i] * 1.5;
        } else if (tmp >= 60) {
            sum1 += a1[i] * 1.0;
        } else {
            sum1 += a1[i] * 0.;
        }
    }

    GPA = sum1 / sum;

    cout << fixed << setprecision(2) << GPA << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
