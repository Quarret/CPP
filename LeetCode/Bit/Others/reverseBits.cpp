#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int reverseBits(int n) {
    unsigned long long x = n, ans = 0;
    string s = bitset<32>(x).to_string();
    reverse(s.begin(), s.end());

    for (int i = 31; i >= 0; i--) {
        if (s[i] == '1') ans |= 1 << (31 - i);
    }

    return ans;
}

/*
位运算反转
*/
int reverseBits(int n) {
    unsigned int ans = 0;
    for (int i = 0; i < 32; i++) {
        ans = (ans << 1) + (n & 1);
        n /= 2;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
