#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int xorOperation(int n, int start) {
    long long ans = start;
    for (int i = 1; i < n; i++) {
        ans = ans ^ (start + 2 * i);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
