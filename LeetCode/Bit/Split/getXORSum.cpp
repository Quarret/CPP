#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// (a & b) ^ (a & c) = a & (b ^ c)
// [a & c] ^ [a & d] ^ [b & c] ^ [b & d] = [a & (c ^ d)] ^ [b & (c ^ d)] = (a ^ b) & (c ^ d)
// 利用上面恒等式可以转换本题为 xor1 & xor2 
int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    int xor1 = 0, xor2 = 0;
    for (int x : arr1) xor1 ^= x;
    for (int y : arr2) xor2 ^= y;

    return xor1 & xor2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
