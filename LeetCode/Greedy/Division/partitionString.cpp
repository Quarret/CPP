#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int partitionString(string s) {
    unordered_map<char, int> mp;
    int ans = 0;
    
    for (char c : s) {
        if (mp[c]) {
            ans++;
            mp.clear();
            mp[c] = 1;
        } else {
            mp[c] = 1;
        }
    }

    return ans + 1;
}

// 位运算状态压缩
int partitionString(string s) {
    int ans = 1, vis = 0;
    for (char c : s) {
        if (vis >> (c & 31) & 1) {
            vis = 0;
            ans++;
        }
        vis |= 1 << (c & 31);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
