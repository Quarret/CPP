#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
分组
利用xorall某一位的值为1的位来把两个个数为1的数组分到两组
xor产生1的原因是奇数个数位1，这奇数1是由于这两个个数为1的数组在这个数位上的不同导致的
*/
vector<int> singleNumber(vector<int>& nums) {
    unsigned int xor_all = 0;
    for (int x: nums) {
        xor_all ^= x;
    }
    int lowbit = xor_all & - xor_all;//取最低位1
    
    vector<int> ans(2, 0);
    for (int x: nums) {
        if ((x & lowbit) == lowbit) ans[0] ^= x;
        else ans[1] ^= x;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
