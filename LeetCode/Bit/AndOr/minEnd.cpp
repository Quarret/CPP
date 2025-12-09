#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minEnd(int n, int x) {
    long long ans = x, idx = 0;
    n--;

    while (n) {
        long long num = n % 2;
        if ((ans & (1 << idx)) != (1 << idx)) {
            ans |= (num << idx);
            n /= 2; 
        }
        idx++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
