#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string minWindow(string s, string t) {
    int n = s.size();
    unordered_map<int, int> cnt1, cnt2;
    for (char c : t) {
        cnt2[c - 'A']++;
    }

    auto check = [&]() -> bool {
        for (auto [x, c] : cnt2) {
            if (cnt1[x] < c) {
                return false;
            }
        }
        return true;
    };
    
    int minn = INT_MAX, ans_left = INT_MIN, ans_right = -1;
    for (int r = 0, l = 0; r < n; r++) {
        cnt1[s[r] - 'A']++;
        while (check()) {
            if (r - l < ans_right - ans_left) {
                ans_left = l;
                ans_right = r;
            }            
            cnt1[s[l] - 'A']--;
            l++;
        }
    }

    return ans_left != INT_MIN ? s.substr(ans_left, ans_right - ans_left + 1) : "";
}

// 记录 less 种出现次数小于 t 的字母
// O(1) 检查字符串是否合法
string minWindow(string s, string t) {
    int n = s.size();
    int less = 0;
    int cnt[128]{};
    
    for (char c : t) {
        if (cnt[c] == 0) {
            less++;
        }
        cnt[c]++;
    }
    
    int ans_left = -1, ans_right = n;
    for (int r = 0, l = 0; r < n; r++) {
        cnt[s[r]]--;
        if (cnt[s[r]] == 0) {
            less--;
        }
        
        while (less == 0) {
            if (r - l < ans_right - ans_left) {
                ans_left = l;
                ans_right = r;
            }
            
            if (cnt[s[l]] == 0) {
                less++;
            }
            cnt[s[l]]++;
            l++;
        }
    }
    
    return ans_left != -1 ? s.substr(ans_left, ans_right - ans_left + 1) : "";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
