#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minSensors(int n, int m, int k) {
    int r = 2 * k + 1;
    int cnt1 = (n + r - 1) / r, cnt2 = (m + r - 1) / r;
    return cnt1 * cnt2;      
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
