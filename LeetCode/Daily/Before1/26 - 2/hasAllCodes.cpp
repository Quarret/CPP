#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool hasAllCodes(string s, int k) {
    if (s.size() < k) return false;

    unordered_set<string> st;
    for (int i = 0; i <= s.size() - k; i++) {
        st.insert(s.substr(i, k));
    }

    for (int x = 0; x < (1 << k); x++) {
        string t(k, '0');
        for (int i = 0; i < k; i++) {
            if (x >> i & 1) t[k - 1 - i] = '1';
        }

        if (!st.contains(t)) return false;
    }

    return true;
}


bool hasAllCodes(string s, int k) {
    unordered_set<string> st;
    // unsigned s.size()
    for (int i = 0; i <= (int)s.size() - k; i++) {
        st.insert(s.substr(i, k));
    }

    return st.size() == (1 << k);
}


// 位运算
bool hasAllCodes(string s, int k) {
    const int MASK = (1 << k) - 1;
    vector<uint32_t> has(1 << k);
    int cnt = 0, x = 0;
    for (int i = 0; i < s.size() && cnt < (1 << k); i++) {
        // mask 的作用是去除超过 k 位的数字
        x = (x << 1 & MASK) | (s[i] & 1);
        if (i >= k - 1 && !has[x]) {
            cnt++;
            has[x] = 1;
        }
    }

    return cnt == (1 << k);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}