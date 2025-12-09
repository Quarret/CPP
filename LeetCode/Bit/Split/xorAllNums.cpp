#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int xor1 = 0, xor2 = 0;
    for (int x : nums1) xor1 ^= x;
    for (int y : nums2) xor2 ^= y;

    int n = nums1.size(), m = nums2.size();

    if (n % 2 && m % 2) return xor1 ^ xor2;
    else if (n % 2 && !(m % 2)) return xor2;
    else if (!(n % 2) && m % 2) return xor1;
    else return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
