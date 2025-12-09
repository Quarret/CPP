#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int monotoneIncreasingDigits(int n) {
    string s = to_string(n);
    int m = s.size();
    unordered_map<char, int> mp;

    for (int i = 0; i < m - 1; i++) {
        if (!mp.contains(s[i])) {
            mp[s[i]] = i;
        }

        if (s[i] > s[i + 1]) {
            int idx = mp[s[i]];
            string s1 = s.substr(0, idx);
            s1 += s[idx] - 1;
            s1 += string(m - idx - 1, '9');
            return stoi(s1);
        }
    }

    return n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
