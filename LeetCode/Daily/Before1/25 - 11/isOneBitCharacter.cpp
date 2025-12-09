#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 从左到右 出现 1 一定是两位
bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size(), i = 0;

    while (i < n - 1) {
        i += bits[i] + 1;
    }

    return i == n - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
