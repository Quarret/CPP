#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int reverseBits(int n) {
    int ans = 0;

    for (int i = 31; i >= 0; i--) {
        ans |= ((n >> i) & 1) << (31 - i); 
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}