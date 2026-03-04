#include <bits/stdc++.h>
using ll = long long;
using namespace std;

unordered_map<int, string> mp;
int init = [] {
    string s = "0";
    mp[1] = s;
    for (int i = 2; i <= 20; i++) {
        string t = s;
        s += '1';
        for (char &c : t) {
            c = (c == '1' ? '0' : '1');
        }
        ranges::reverse(t);
        s += t;

        mp[i] = s;
    }
    return 0;
}();

class Solution {
public:
    char findKthBit(int n, int k) {
        return mp[n][k - 1];   
    }
};

// 递归写法, 判断 k 在左, 中, 右那个字符串上
char findKthBit(int n, int k) {
    if (k == 1) {
        return '0';
    }
    
    if (k == (1 << (n - 1))) {
        return '1';
    }
    
    if (k < (1 << (n - 1))) {
        return findKthBit(n - 1, k);
    }

    return findKthBit(n - 1, (1 << n) - k) ^ 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}