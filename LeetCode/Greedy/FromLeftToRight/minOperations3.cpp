#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(int n) {
    int ans = 1;
    while (n & (n - 1)) {
        int lowbit = n & -n;
        if (n & (lowbit << 1)) n += lowbit; // 多一个 1 连续采用加操作
        else n -= lowbit; // 单个 1 采用减操作
        ans++;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
