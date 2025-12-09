#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxSubstrings(string word) {
    int n = word.size();
    vector<int> idx(26, -1);
    
    int ans = 0, r = -1;
    for (int i = 0; i < n; i++) {
        int c = word[i] - 'a';
        if (idx[c] == -1) {
            idx[c] = i;
        } else {
            if (idx[c] < r) {
                idx[c] = i;
            }

            if (i - idx[c] + 1 >= 4) {
                ans++;
                r = i;
                idx[c] = -1;
            }
        }
    }

    return ans;
}

// 迭代 
// 假如第 s[i] 为右端点满足, 则问题范围变为 [i + 1, n - 1]
int maxSubstrings(string word) {
    int n = word.size(), ans = 0;
    vector<int> pos(26, -1);
    
    for (int i = 0; i < n; i++) {
        int c = word[i] - 'a';
        if (pos[c] == -1) {
            pos[c] = i;
        } else if (i - pos[c] > 2) { // 子问题
            ans++;
            ranges::fill(pos, -1);
        }
    }

    return ans;
}

// 位运算优化
int maxSubstrings(string word) {
    int n = word.size(), ans = 0;
    int seen = 0;

    for (int i = 3; i < n; i++) {
        int c = word[i - 3] - 'a';
        seen |= 1 << c;
        if (seen >> (word[i] - 'a') & 1) {
            ans++;
            seen = 0;
            i += 3;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
