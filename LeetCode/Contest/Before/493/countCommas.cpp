#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countCommas(int n) {
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        if (x >= 1000 && x < 1000000) {
            ans++;
        } else if (x >= 1000000) {
            ans += 2;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}