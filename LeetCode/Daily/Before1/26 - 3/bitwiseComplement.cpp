#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int bitwiseComplement(int n) {
    int len = __bit_width(n);
    string s = bitset<32>(n).to_string().substr(32 - len);
    
    for (char &c : s) {
        c = (c == '1' ? '0' : '1');
    }

    int ans = 0;
    for (char c : s) {
        ans = (ans << 1) | (c & 1);
    }
    return ans;
}

// 取反码 x ^= 111...1
int bitwiseComplement(int n) {
    unsigned int x = n;
    return n ? n ^ ((1 << bit_width(x)) - 1) : 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}