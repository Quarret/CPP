#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string clearStars(string s) {
    unordered_map<int, vector<int>> mp;
    vector<int> deleted;
    
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') {
            mp[s[i] - 'a'].push_back(i);
            continue;
        }
        
        for (int j = 0; j < 26; j++) {
            if (mp[j].empty()) continue;
            deleted.push_back(mp[j].back());
            mp[j].pop_back();
            break;
        }

        deleted.push_back(i);
    }

    int m = deleted.size();
    if (!m) return s;
    ranges::sort(deleted);

    string ans;
    for (int i = 0, j = 0; i < n; i++) {
        if (j < m && i == deleted[j]) {
            j++;
            continue;
        }

        ans += s[i];
    }

    return ans;
}

// 位运算 + 栈
string clearStars(string s) {
    vector<int> stacks[26];
    uint32_t mask = 0;
    
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') {
            stacks[s[i] - 'a'].push_back(i);
            mask |= 1 << (s[i] - 'a');
        } else {
            int k = countr_zero(mask);
            auto &st = stacks[k];
            s[st.back()] = '*';
            st.pop_back();
            if (st.empty()) {
                mask ^= 1 << k;
            }
        }
    }

    erase(s, '*');
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
